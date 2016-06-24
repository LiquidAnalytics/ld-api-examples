//
//  ViewController.m
//  LPKTutorialTwo
//
//  Created by CARSON LI on 2016-06-20.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "ViewController.h"
#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMDataManager+Client.h>
#import <LiquidPlatformKit/LDMItem.h>

@interface ViewController ()

@property (weak) IBOutlet UITextField *usernameField;
@property (weak) IBOutlet UITextField *passwordField;
@property (weak) IBOutlet UILabel *infoLabel;
@property (weak) IBOutlet UIProgressView *progressBar;
@property (weak) IBOutlet UIButton *loginButton;
@property (strong) void (^authCallback)(NSString *username, NSString *password);

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.infoLabel.text = @"";
    self.progressBar.progress = 0.0f;
    self.progressBar.hidden = YES;
    
    //load the DB in the background, typically there is a loading screen that goes here
    //so we don't block the main thread
    
    [[LDMDataManager sharedInstance] executeAsynch:^{
        [[LDMDataManager sharedInstance] openDatabaseWithName:@"MovieCollection"];
        [[LSCSyncController sharedInstance] startWithDelegate:self];
        NSString *deviceId = [[NSUserDefaults standardUserDefaults] objectForKey:@"seasideCustomDeviceId"];
        NSLog(@"Device ID is: %@", deviceId);
        self.loginButton.enabled = YES;
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


-(IBAction)loginButtonPressed:(id)sender
{
    self.loginButton.enabled = NO;
    self.usernameField.enabled = NO;
    self.passwordField.enabled = NO;
    self.progressBar.hidden = NO;
    [[LDMDataManager sharedInstance] executeAsynch:^{
        self.authCallback(self.usernameField.text, self.passwordField.text);
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
        self.loginButton.enabled = YES;
        self.usernameField.enabled = YES;
        self.passwordField.enabled = YES;
        self.passwordField.text = @"";
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
        self.progressBar.progress = syncProgress;
    });
}

/**
 * The application should present the user with a list of communities to select from. Retrieve a list of communities from LDMDataManager and then respond with [syncController communitySelected:community].
 */
- (void) selectCommunity
{
    [[LSCSyncController sharedInstance] communitySelected:@"MovieCollection"];
}

- (void) registered
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self performSegueWithIdentifier:@"showMovieSegue" sender:nil];
    });
}

@end
