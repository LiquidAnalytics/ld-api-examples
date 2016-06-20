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
- (void)precacheItemsWithCategory:(NSString *)category andType:(NSString *)type andFieldValues:(NSDictionary *__nullable)fieldValues andTimeRanges:(NSArray*__nullable)timeRanges adminMode:(BOOL)adminMode andCallback:(void (^)(BOOL success))callback;
- (NSString *__nonnull)pingDescription;
- (void) setDisasterServers: (NSArray *__nullable) routingTable;
- (void) clearServerError;
- (BOOL)serverIsReachable;
- (NSString *__nullable)urlBase;
- (void)actOnState;
- (BOOL) willRequestAuthenticationOnStartup;

- (void)stateHandlerInitialized:(LSCStateHandler *__nonnull)handler;
- (void)stateHandlerDone:(LSCStateHandler *__nonnull)handler;
- (dispatch_queue_t __nonnull)dispatchQueueForThread:(NSThread *__nonnull)thread;
- (void)requestStarted:(LSCGetItemsRESTHandler *__nonnull)handler;
- (void)requestFinished:(LSCGetItemsRESTHandler *__nonnull)handler;
- (void)processingStarted:(LSCGetItemsRESTHandler *__nonnull)handler;
- (BOOL)processingFinished:(LSCGetItemsRESTHandler *__nonnull)handler count:(int)count weight:(int)weight;
- (void)requestFailed:(LSCGetItemsRESTHandler *__nonnull)handler;

-(void) authenitcateUsername:(NSString *__nonnull)username password:(NSString *__nonnull)password;
-(void) authenticationError:(NSString *__nonnull)error message:(NSString *__nonnull)message;
-(void) authenticationSuccessToken:accessToken;
-(void) communitySelected:(NSString *__nonnull)community;
-(void) manifestReadyWithCount:(int)count;
-(void) logoutWithMessage:(NSString *__nullable)authenticationMessage;
-(void) reset;
-(void) loginAsUserListReceived:(NSArray *__nullable)loginAsUserList;
-(void) loginAsUserSelected:(NSString *__nullable)loginAsUserId;
-(void) switchLoginAsUser;
-(BOOL) requiresOldstyleWordlookup;
-(BOOL) manifestRequired;

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

/**
 * The application must present an authentication screen to the user, if a message is passed it should be displayed. Respond to callback when complete.
 */
- (void) authenticateWithMessage:(NSString *__nullable)message userEditable:(BOOL)userEditable providePasscode:(BOOL)providePasscode callback:(void (^__nullable)(NSString * __nonnull username, NSString * __nonnull password))callback;

/**
 * Called when seaside is registering the device and performing an inital sync. This is a status update message only, and may be called multiple times.
 */
- (void) registeringWithMessage:(NSString *__nullable)message syncingData:(BOOL)syncingData syncProgress:(float)syncProgress;


- (void)updateLoginStatusLabel:(NSString *__nullable)status enable:(BOOL)enable;
/**
 * The application should present the user with a list of communities to select from. Retrieve a list of communities from LDMDataManager and then respond with [syncController communitySelected:community].
 */
- (void) selectCommunity;

/**
 * All seaside setup work is complete. The user us authenticated and registered and may use the application.
 */
- (void) registered;


@optional
- (BOOL) manifestRequired;
- (void) setRegistrationImage:(NSArray*__nullable)imagesUrls;
- (void) userHasLoggedOut;
- (BOOL) shouldKeepUsernameAndPasswordAfterReset;
- (void)deviceWillBeReset;
- (void) selectLoginAsUser;
- (BOOL) requiresOldstyleWordlookup;

@end


