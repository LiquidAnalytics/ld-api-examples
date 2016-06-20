//
//  LDCReconcileManifestViewController.h
//  LDCore
//
//  Created by David Ellis on 10/29/2013.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LSCReconcileManifestEventLogger.h"

@protocol LDCReconcileViewControllerDataSource;

@interface LDCReconcileManifestViewController : UIViewController <LSCReconcileManifestEventLoggerDelegate>

@property (weak) id<LDCReconcileViewControllerDataSource> datasource;

@end

@protocol LDCReconcileViewControllerDataSource <NSObject>

- (void)syncReconcileViewController:(LDCReconcileManifestViewController *)reconcileViewController timesForLastReconcile:(void (^)(NSDate *startDate, NSDate *endDate))block;

- (NSString *)syncLabelTextForReconcileViewController:(LDCReconcileManifestViewController *)syncLogViewController;

- (void)syncReconcileViewController:(LDCReconcileManifestViewController *)syncLogViewController didPressSyncButton:(id)sender;

@end