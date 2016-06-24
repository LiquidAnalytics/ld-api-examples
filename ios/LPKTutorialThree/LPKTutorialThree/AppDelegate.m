//
//  AppDelegate.m
//  LPKTutorialThree
//
//  Created by CARSON LI on 2016-06-23.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "AppDelegate.h"
#import <LiquidPlatformKit/LiquidPlatformKit.h>
#import <LiquidPlatformKit/LDCLoginSyncViewController.h>
#import <LiquidPlatformKit/LDCLoginCommunitySelectionViewController.h>
#import <LiquidPlatformKit/LDCSelectLoginAsUserViewController.h>
#import <LiquidPlatformKit/LDCLogging.h>
#import <LiquidPlatformKit/LDCDBSeasideLogWriter.h>
#import "MainViewController.h"

@interface AppDelegate ()

@property (weak) LDKSimpleLoginViewController *loginViewController;
@property (weak) LDCLoginSyncViewController *syncViewController;
@property (weak) LDCLoginCommunitySelectionViewController *communitySelectionViewController;
@property (weak) LDCSelectLoginAsUserViewController *loginAsViewController;

@end

@implementation AppDelegate


-(UIViewController *)enterMainApplicationWindow
{
    return [[MainViewController alloc] init];
}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[LDCLogging sharedInstance] setupLogging:@"Starting LDCLogging" dbWriter:[LDCDBSeasideLogWriter sharedInstance]];
    
    [[LDMDataManager sharedInstance] executeAsynch:^{
        [[LDMDataManager sharedInstance] openDatabaseWithName:@"MovieCollection"];
        [[LSCSyncController sharedInstance] startWithDelegate:self];
    }];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (void)updateLoginStatusLabel:(NSString *)status enable:(BOOL)enable
{
    if (self.loginViewController != nil)
    {
        [self.loginViewController updateStatusLabel:status enable:enable];
    }
}

- (void) authenticateWithMessage:(NSString *)message userEditable:(BOOL)userEditable providePasscode:(BOOL)providePasscode callback:(void (^)(NSString *username, NSString *password))callback;
{
    if(![NSThread isMainThread])
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self authenticateWithMessage:message userEditable:userEditable providePasscode:providePasscode callback:callback];
        });
        return;
    }
    
    LDKSimpleLoginViewController *controller = self.loginViewController;
    
    if(!controller)
    {
        controller = [[LDKSimpleLoginViewController alloc] init];
        self.loginViewController = controller;
    }
    
    self.window.rootViewController = self.loginViewController;
    [self.loginViewController requestAuthenticationWithMessage:message userEditable:userEditable providePasscode:providePasscode callback:callback];
    controller.backgroundImage.image = [UIImage imageNamed:[self loginBackgroundImage]];
    controller.applicationLogo.image = [UIImage imageNamed:[self applicationLogoImage]];
    controller.applicationLogoStyle = LDKLoginLogoStyleDark;

}

- (NSString *)loginBackgroundImage
{
    return @"app_bg.jpg";
}

- (NSString *)applicationLogoImage
{
    return @"app_logo.png";
}


- (void) registeringWithMessage:(NSString *)message syncingData:(BOOL)syncingData syncProgress:(float)syncProgress
{
    if(![NSThread isMainThread])
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self registeringWithMessage:message syncingData:syncingData syncProgress:syncProgress];
        });
        return;
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        LDCLoginSyncViewController *controller = self.syncViewController;
        
        if(!controller)
        {
            controller = [[LDCLoginSyncViewController alloc] init];
            self.syncViewController = controller;
        }
        
        [self.syncViewController updateStatusText:message];
        
        if(syncProgress >= 1.0f || syncProgress <= 0.0f)
        {
            [self.syncViewController showProgressSpinner];
        }
        else
        {
            [self.syncViewController updateStatusBar:syncProgress andTotalItemCount:0];
        }
            
        self.window.rootViewController = self.syncViewController;
    });
}

- (void) selectCommunity
{
    dispatch_async(dispatch_get_main_queue(), ^{
        LDCLoginCommunitySelectionViewController *controller = self.communitySelectionViewController;
        
        if(!controller)
        {
            controller = [[LDCLoginCommunitySelectionViewController alloc] initWithNibName:@"LDCLoginCommunitySelectionViewController" bundle:[[LDMDataManager sharedInstance] LPKBundle]];
            self.communitySelectionViewController = controller;
        }
        self.window.rootViewController = self.communitySelectionViewController;
        
    });
}


- (void) registered
{
    dispatch_async(dispatch_get_main_queue(), ^{
        self.window.rootViewController = [self enterMainApplicationWindow];
    });
}

-(DisableInfoPopoverItem)disableInfoOptions
{
    return DisableNone;
}

-(void)selectLoginAsUser
{
    
    if(![NSThread isMainThread])
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self selectLoginAsUser];
        });
        return;
    }
    
    self.syncViewController = nil;

    dispatch_async(dispatch_get_main_queue(), ^{
        LDCSelectLoginAsUserViewController *controller = self.loginAsViewController;
        if(!controller)
        {
            controller = [[LDCSelectLoginAsUserViewController alloc] init];
            self.loginAsViewController = controller;
        }
        self.window.rootViewController = self.loginAsViewController;
    });
}

- (BOOL)shouldHideLoginAsDirectly
{
    return true;
}



@end
