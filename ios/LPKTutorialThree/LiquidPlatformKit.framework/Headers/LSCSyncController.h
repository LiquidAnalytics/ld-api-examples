//
//  LSCSyncEngine.h
//  seaside
//
//  Created by Bryan Nagle on 7/10/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

#define ITEM_ACTION_UPDATE @"Update"
#define ITEM_ACTION_CREATE @"Create"
#define ITEM_ACTION_DELETE @"Delete"
#define ITEM_ACTION_SAVE   @"Save"

#define SEASIDE_WRITE_PAGESIZE 250
#define GET_ITEMS_PAGE_SIZE 5000
#define ITEM_WEIGHT_MULTIPLIER 50 //when performing weight based calculations, use (ITEM_WEIGHT_MULTIPLIER * some_count) for weight values

#define MAX_CONCURRENT_GETITEMS_REQUESTS 1
#define MAX_CONCURRENT_GETITEMS_PROCESSING 3

@class LSCSeasideDatabaseManager;
@class LSCStateHandler;

typedef void (^__nullable SynchronousRequestBlock)(NSError *__nullable error, id __nullable dataReceived);

@protocol LSCSyncControllerApplicationDelegate;
@protocol LSCSyncControllerInfoDelegate;
@protocol LSCSeasideApplicationDelegate;

@class LDMItem;
@class LDMItemSchema;
@class LSCGetItemsRESTHandler;

@interface LSCSyncController : NSObject

@property (strong) NSThread *__nonnull thread;
@property (strong) NSThread *__nonnull getItemsThread;
@property (strong) NSThread *__nonnull transactionThread;
@property (strong) NSThread *__nonnull syncSocketThread;

//Delegates
@property (strong) id<LSCSeasideApplicationDelegate> __nullable appDelegate;

//Used in command bean flow only
@property (readonly) NSTimeInterval timeout;
@property (strong, nullable) NSString *commandGroupId;

@property (readonly, nullable) NSURL *url;
@property (readonly, nullable) NSURL *relayUrl;

// State Modifiers
@property (strong, nullable) NSDate *timeOfLastSync;
@property (readonly, nullable) NSDate *timeOfNextSync;
@property (strong, nullable) NSDate *timeLastSyncEnded;
@property (strong, nullable) NSDate *timeToGetLoginStatus;
@property (strong, nullable) NSString *connectionType;
@property (strong, nullable) NSString *loginToken;

@property BOOL seasideHasSynced;
@property BOOL serverReachable;

@property (nonatomic) int pingInMS;

@property (readonly, nonnull) NSDictionary *authScope;
@property (readonly, nonnull) NSString *stringFromAuthScope;

@property BOOL tokenScopeIsSent;
@property BOOL manifestSetupRequested;
@property BOOL manifestSetupComplete;
@property BOOL optimizeComplete;

@property (strong, nullable) NSString *communityName;
@property (strong, nullable) NSDictionary *rolesByCommunity;
@property (strong, nullable) NSArray *loginAsUserList;
@property (strong, nullable) NSString *credentialedUserId;
@property (strong, nullable) NSString *seasideUserName;

+ (LSCSyncController *__nonnull)sharedInstance;
+ (void)showServerIsNotReachableInfoAlert;

- (void)serverNetworkError: (BOOL)immediateSwitch;
- (void)startWithDelegate:(id <LSCSeasideApplicationDelegate> __nullable)delegate;

- (BOOL)serverIsReachable:(NSURL *__nonnull)url;

- (void)requestLogin;
- (void)requestSync;
- (void)requestSyncWithCompletionHandler:(void (^__nullable)(BOOL syncSucceeded))completionHandler;
- (void)requestGetItemsWithCategory:(NSString *__nonnull)category andType:(NSString *__nonnull)type andFieldValues:(NSDictionary *__nullable)fieldValues andTimeRanges:(NSArray *__nullable)timeRanges adminMode:(BOOL)adminMode andCallback:(SynchronousRequestBlock)callback;
- (void)precacheItemsWithCategory:(NSString *)category andType:(NSString *__nonnull)type andFieldValues:(NSDictionary *__nullable)fieldValues andTimeRanges:(NSArray*__nullable)timeRanges adminMode:(BOOL)adminMode andCallback:(void (^__nonnull)(BOOL success))callback;
- (NSString *__nonnull)pingDescription;
- (void) setDisasterServers: (NSArray *__nullable) routingTable;
- (void) clearServerError;
- (BOOL) serverIsReachable;
- (NSString *__nullable) urlBase;
- (void) actOnState;
- (BOOL) willRequestAuthenticationOnStartup;

- (void) stateHandlerInitialized:(LSCStateHandler *__nonnull)handler;
- (void) stateHandlerDone:(LSCStateHandler *__nonnull)handler;
- (dispatch_queue_t __nonnull) dispatchQueueForThread:(NSThread *__nonnull)thread;
- (void) requestStarted:(LSCGetItemsRESTHandler *__nonnull)handler;
- (void) requestFinished:(LSCGetItemsRESTHandler *__nonnull)handler;
- (void) processingStarted:(LSCGetItemsRESTHandler *__nonnull)handler;
- (BOOL) processingFinished:(LSCGetItemsRESTHandler *__nonnull)handler count:(int)count weight:(int)weight;
- (void) requestFailed:(LSCGetItemsRESTHandler *__nonnull)handler;

- (void) authenitcateUsername:(NSString *__nonnull)username password:(NSString *__nonnull)password;
- (void) authenticationError:(NSString *__nonnull)error message:(NSString *__nonnull)message;
- (void) authenticationSuccessToken:accessToken;
- (void) communitySelected:(NSString *__nonnull)community;
- (void) manifestReadyWithCount:(int)count;
- (void) logoutWithMessage:(NSString *__nullable)authenticationMessage;
- (void) reset;
- (void) loginAsUserListReceived:(NSArray *__nullable)loginAsUserList;
- (void) loginAsUserSelected:(NSString *__nullable)loginAsUserId;
- (void) switchLoginAsUser;
- (BOOL) requiresOldstyleWordlookup;
- (BOOL) manifestRequired;

@end

/**
 * All LD family of iPad applications should implement this delegate instead of LSCSyncControllerApplicationDelegate. The following sync controller methods are use in conjunction with this delegate:
 *
 * -(void) startWithDelegate:(id<LSCSeasideApplicationDelegate>)delegate;
 * -(void) authenitcateUsername:(NSString *)clientId password:(NSString *)clientSecret;
 * -(void) communitySelected:(NSString *)community;
 *
 * The following delegates are now deprecated: LSCSyncControllerInfoDelegate, LSCSyncControllerApplicationDelegate
 */
@protocol LSCSeasideApplicationDelegate <NSObject>

/*!
 * @discussion The application must present an authentication screen to the user, if a message is passed it should be displayed. Respond to callback when complete
 * @param message A useful string to present to the user regarding current state of login
 * @param userEditable TRUE if the user credentials should be editable at this point, FALSE otherwise
 * @param providePasscode TRUE if the passcode was provided as a form of login, FALSE otherwise
 * @param callback block to execute after method is called
 */
- (void) authenticateWithMessage:(NSString *__nullable)message userEditable:(BOOL)userEditable providePasscode:(BOOL)providePasscode callback:(void (^__nullable)(NSString * __nonnull username, NSString * __nonnull password))callback;


/*!
 * @discussion Called when LPK is registering the device and performing an inital sync. This is a status update message only, and may be called multiple times.
 * @param message A useful string to present to the user regarding current state of login
 * @param syncingData TRUE if device is currently syncing data, FALSE otherwise
 * @param syncProgress Number between 0 and 1 to indicate current progress of sync. 1 represents that the device is 100% synced
 */
- (void) registeringWithMessage:(NSString *__nullable)message syncingData:(BOOL)syncingData syncProgress:(float)syncProgress;

/*!
 * @discussion Called when login process is unable to reach server
 * @param status A useful string to present to the user regarding current state of login
 * @param enable TRUE if the user credentials should be editable at this point, FALSE otherwise
 */
- (void) updateLoginStatusLabel:(NSString *__nullable)status enable:(BOOL)enable;

/*!
 * @discussion The application should present the user with a list of communities to select from. Retrieve a list of communities from LDMDataManager (with allItemsOfType or similar) and then respond with [[LSCSyncController sharedInstance] communitySelected:communityName]; when done
 */
- (void) selectCommunity;

/*!
 * @discussion All seaside setup work is complete. The user us authenticated and registered and may use the application.
 */
- (void) registered;


@optional
/*!
 * @discussion Implement to tell LP whether a manifest is required, YES by default
 */
- (BOOL) manifestRequired;

/*!
 * @discussion Called when [[LSCSyncController sharedInstance] logoutWithMessage:@""] is called. Use this callback to clear application specific things.
 */
- (void) userHasLoggedOut;

/*!
 * @discussion Return YES if you want the application to store your username and password. 
 * You can retrieve these via standardUserDefaults with seasideUserName and seasidePassword
 */
- (BOOL) shouldKeepUsernameAndPasswordAfterReset;

/*!
 * @discussion Called when [[LSCSyncController sharedInstance] reset] is called. User this callback to clear application specific things.
 */
- (void) deviceWillBeReset;

/*!
 * @discussion Called when user has login ability. Retrieve list of users with [LSCSyncController sharedInstance].loginAsUserList and 
 * call [[LSCSyncController sharedInstance] loginAsUserSelected:<userId> when done
 */
- (void) selectLoginAsUser;

/*!
 * @discussion Return NO if you want to do FTS searching (requires UTF8Lucene defined in schema)
 */
- (BOOL) requiresOldstyleWordlookup;

@end


