//
//  LDCAbstractAppDelegate.h
//  LiquidDecisions
//
//  Created by Marshall Hayden on 5/22/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LSCSyncController.h"
#import "LDKSimpleLoginViewController.h"
#import "LDKInfoDelegateDatasource.h"

@class LDMFunctionManager;

@interface LDCAbstractAppDelegate : UIResponder <UIApplicationDelegate, UIAlertViewDelegate, LSCSeasideApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

#pragma mark Abstract methods for subclasses

- (UIViewController *)enterMainApplicationWindow;
- (NSArray *)applicationIndexes;
- (NSString *)loginBackgroundImage;
- (NSString *)applicationLogoImage;
- (DisableInfoPopoverItem)disableInfoOptions;
- (LDKLoginLogoStyle)applicationLogoStyle;
- (BOOL)requiresOldstyleWordlookup;
- (BOOL) validateDevicePasscode:(NSString *)message;
/** return the LDMFunctionManager sharedInstance. This will be the first the function manager is used, giving the client application the opportunity to initialize the instance with the correct categories / extensions included */
- (LDMFunctionManager *)functionManagerSharedInstance;
- (BOOL)shouldHideLoginAsDirectly;


@end
