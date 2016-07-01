//
//  LDCInfoScreenController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 8/27/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDCInfoViewController.h"
#import "LDCSyncLogViewController.h"
#import "LDCDeviceManifestViewController.h"
#import "LDCConnectionInfoViewController.h"
#import "LDCReconcileManifestViewController.h"

@interface LDKInfoDelegateDatasource : NSObject<LDCInfoViewControllerDataSource, LDCInfoViewControllerDelegate, MFMailComposeViewControllerDelegate, LDCSyncLogViewControllerDataSource, LDCDeviceManifestViewControllerDataSource, LDCConnectionInfoViewControllerDataSource, LDCReconcileViewControllerDataSource, UIAlertViewDelegate, UINavigationControllerDelegate>

typedef enum : NSUInteger {
    DisableManageMyAccount =  1 << 0,
    DisableSendFeedback = 1 << 1,
    DisableConnectionInfo = 1 << 2,
    DisableSync = 1 << 3,
    DisableReconcileManifest = 1 << 4,
    DisableViewManifest = 1 << 5,
    DisableDefaultCalendar = 1 << 6,
    DisableNone = 1 << 7
} DisableInfoPopoverItem;

@property (nonatomic) DisableInfoPopoverItem disabledPopoverItemOptions;

@end
