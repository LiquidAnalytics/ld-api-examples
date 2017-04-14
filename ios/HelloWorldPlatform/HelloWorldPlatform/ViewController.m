//
//  ViewController.m
//  HelloWorldPlatform
//
//  Created by CARSON LI on 2017-04-14.
//  Copyright © 2017 Liquid Analytics. All rights reserved.
//

#import "ViewController.h"
#import <LiquidPlatformKit/LiquidPlatformKit.h>

@interface ViewController ()

@property (weak) IBOutlet UILabel *infoLabel;
@property (weak) IBOutlet UILabel *debugLabel;
@property (weak) IBOutlet UILabel *serverLabel;
@property (weak) IBOutlet UIButton *loginButton;
@property (strong) void (^authCallback)(NSString *username, NSString *password);

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.debugLabel.text = @"";
    self.serverLabel.text = [[LDMDataManager sharedInstance] retrieveServerURL];
    
    if([LSCSyncController sharedInstance].loginToken){
        self.loginButton.enabled = NO;
        self.debugLabel.text = @"You logged in already!";
    }
    
    [[LDMDataManager sharedInstance] executeAsynch:^{
        [[LSCSyncController sharedInstance] startWithDelegate:self];
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

-(IBAction)loginButtonPressed:(id)sender
{
    //fill these values in
    __block NSString *username = @"";
    __block NSString *password = @"";
    [[LDMDataManager sharedInstance] executeAsynch:^{
        self.authCallback(username, password);
    }];
}

/**
 * Call to update login view as per connectivity state when logging in.
 */
- (void)updateLoginStatusLabel:(NSString *)status enable:(BOOL)enable
{
    dispatch_async(dispatch_get_main_queue(), ^{
        self.infoLabel.text = status;
    });
}

/**
 * The application must present an authentication screen to the user, if a message is passed it should be displayed. Respond to callback when complete.
 */
- (void) authenticateWithMessage:(NSString *)message userEditable:(BOOL)userEditable providePasscode:(BOOL)providePasscode callback:(void (^)(NSString *username, NSString *password))callback;
{
    self.authCallback = callback;
    dispatch_async(dispatch_get_main_queue(), ^{
        self.infoLabel.text = message;
    });
}

/**
 * Called when seaside is registering the device and performing an inital sync. This is a status update message only, and may be called multiple times.
 */
- (void) registeringWithMessage:(NSString *)message syncingData:(BOOL)syncingData syncProgress:(float)syncProgress
{
    dispatch_async(dispatch_get_main_queue(), ^{
        self.infoLabel.text = message;
    });
}

/**
 * The application should present the user with a list of communities to select from. Retrieve a list of communities from LDMDataManager and then respond with [syncController communitySelected:community].
 */
- (void) selectCommunity
{
    [[LSCSyncController sharedInstance] communitySelected:@"HelloWorldLiquid"];
}

- (void) registered
{
    self.loginButton.enabled = NO;
    
    //you are now registered, some basic code to show all contact IDs
    //please see documentation / other tutorials for proper / advanced ways to retrieve items
    NSArray *contacts = [[LDMDataManager sharedInstance] allItemsOfType:@"Contact"];
    NSMutableString *results = [NSMutableString string];
    for (LDMItem *contact in contacts)
    {
        [results appendFormat   :@"%@", contact.dataDict];
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.debugLabel.text = [NSString stringWithFormat:@"Contacts: %@", results];
    });
}

@end
