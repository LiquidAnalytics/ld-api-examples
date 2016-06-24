//
//  LDKFilterRootViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/14/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKItemSelectViewController.h"

@protocol LDKFilterRootViewControllerDelegate;
@protocol LDKItemSelectViewControllerDelegate;

@interface LDKFilterRootViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, LDKItemSelectViewControllerDelegate>

@property (strong) NSString *itemType;
@property (strong) NSDictionary *config;
@property (assign) BOOL hideNameEntry;
@property (weak) id<LDKFilterRootViewControllerDelegate> delegate;

- (void)update;
- (void)loadSelectionsFromFilters:(NSArray *)filters;

@end

@protocol LDKFilterRootViewControllerDelegate <NSObject>

- (void)filterRootViewController:(LDKFilterRootViewController *)filterViewController didSelectDimensions:(NSArray *)dimensions andFilters:(NSArray *)filters;

@end