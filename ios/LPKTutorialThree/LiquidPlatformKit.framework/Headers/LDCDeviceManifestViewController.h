//
//  LDCDeviceManifestViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 2/6/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>
#import "LDCColumnCell.h"

@protocol LDCDeviceManifestViewControllerDataSource;

@interface LDCDeviceManifestViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, LDCColumnCellDataSource>

//@property (weak) id<LSCSyncControllerDataModelDelegate> dataManager;

@property (weak) id<LDCDeviceManifestViewControllerDataSource> datasource;
@property NSTimeInterval lastRefreshTime;
@property (assign) BOOL isLoading;

- (void)refresh;

@end

@protocol LDCDeviceManifestViewControllerDataSource <NSObject>

- (NSArray *)itemTypesForDeviceManifestViewController:(LDCDeviceManifestViewController *)manifestViewController;

- (NSArray *)blockTypesForDeviceManifestViewController:(LDCDeviceManifestViewController *)manifestViewController;

- (void)deviceManifestViewController:(LDCDeviceManifestViewController *)manifestViewController infoDictForItemType:(NSString *)itemType withBlock:(void (^)(NSDictionary *aResultDict))block;

@optional

- (void)deviceManifestViewController:(LDCDeviceManifestViewController *)manifestViewController viewWillAppear:(BOOL)animated;

- (void)deviceManifestViewController:(LDCDeviceManifestViewController *)manifestViewController viewWillDisappear:(BOOL)animated;

@end