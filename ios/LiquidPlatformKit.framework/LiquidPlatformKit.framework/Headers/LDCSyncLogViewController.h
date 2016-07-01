//
//  LDCSyncLogViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 11/9/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>
#import "LSCSyncEventLogger.h"

@protocol LDCSyncLogViewControllerDataSource, LDCSyncLogDelegate;

@interface LDCSyncLogViewController : UIViewController

@property (weak) id<LDCSyncLogViewControllerDataSource> datasource;

@end


@protocol LDCSyncLogViewControllerDataSource <NSObject>

- (void)syncLogViewController:(LDCSyncLogViewController *)syncLogViewController timesForLastSync:(void (^)(NSDate *startDate, NSDate *endDate))block;

- (NSString *)syncLabelTextForSyncLogViewController:(LDCSyncLogViewController *)syncLogViewController;

- (void)syncLogViewController:(LDCSyncLogViewController *)syncLogViewController didPressSyncButton:(id)sender;

@end