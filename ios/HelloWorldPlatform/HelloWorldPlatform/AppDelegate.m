//
//  AppDelegate.m
//  HelloWorldPlatform
//
//  Created by CARSON LI on 2016-05-03.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "AppDelegate.h"
#import <LiquidPlatformKit/LSCSyncController.h>
#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDCLogging.h>
#import <LiquidPlatformKit/LDCDBSeasideLogWriter.h>
#import <LiquidPlatformKit/LDMItem.h>
#import <LiquidPlatformKit/LSCInfrastructureUtils.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[LDCLogging sharedInstance] setupLogging:@"Starting LDCLogging" dbWriter:[LDCDBSeasideLogWriter sharedInstance]];

    //initialize application, must call this method before anything else is done
    //this does not have to be done in the delegate, and typically done in conjunction
    //with a loading screen of some sort in the background
    
    if (![[LDMDataManager sharedInstance] openDatabaseWithName:@"HelloWorldLiquid"]) {
        NSLog(@"CRITICAL! Database could not be opened!");
        return NO;
    }
    

    
    return YES;
}


- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
}

-(void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{

}

- (void) application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    
}

- (void)applicationWillResignActive:(UIApplication *)application
{
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    
}


- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
    
}

@end
