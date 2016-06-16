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
    
    [self setDeviceIdIfNotSet];
    [self registerDefaultsFromSettingsBundle];
    [[LSCSyncController sharedInstance] loadServerURLs];
    
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

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return YES;
}

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
    
}

- (void)registerDefaultsFromSettingsBundle
{
    NSUserDefaults * defs = [NSUserDefaults standardUserDefaults];
    [defs synchronize];
    
    NSString *settingsBundle = [[NSBundle mainBundle] pathForResource:@"Settings" ofType:@"bundle"];
    
    if(!settingsBundle)
    {
        NSLog(@"Could not find Settings.bundle");
        return;
    }
    
    NSDictionary *settings = [NSDictionary dictionaryWithContentsOfFile:[settingsBundle stringByAppendingPathComponent:@"Root.plist"]];
    NSArray *preferences = [settings objectForKey:@"PreferenceSpecifiers"];
    
    for (NSDictionary *prefSpecification in preferences)
    {
        NSString *key = [prefSpecification objectForKey:@"Key"];
        if (key)
        {
            // check if value readable in userDefaults
            id currentObject = [defs objectForKey:key];
            if (currentObject == nil)
            {
                // not readable: set value from Settings.bundle
                id objectToSet = [prefSpecification objectForKey:@"DefaultValue"];
                [defs setObject:objectToSet forKey:key];
                NSLog(@"Setting object %@ for key %@", objectToSet, key);
            }
            else
            {
                // already readable: don't touch
                NSLog(@"Key %@ is readable (value: %@), nothing written to defaults.", key, currentObject);
            }
        }
    }
    
    [defs synchronize];
}

- (void)setDeviceIdIfNotSet
{
    NSString *deviceId = [[NSUserDefaults standardUserDefaults] objectForKey:@"seasideCustomDeviceId"];
    if(deviceId == nil || deviceId.length < 1)
    {
        [[NSUserDefaults standardUserDefaults] setObject:[LDMItem generateId] forKey:@"seasideCustomDeviceId"];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
}


@end
