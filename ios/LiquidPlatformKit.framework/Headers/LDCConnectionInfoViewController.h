//
//  LDCConnectionInfoViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 11/9/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@protocol LDCConnectionInfoViewControllerDataSource;

@interface LDCConnectionInfoViewController : UIViewController

@property BOOL deviceIsRegistered;
@property (weak) id<LDCConnectionInfoViewControllerDataSource> datasource;

@end

@protocol LDCConnectionInfoViewControllerDataSource <NSObject>

- (NSURL *)urlForConnectionInfoViewController:(LDCConnectionInfoViewController *)connectionViewController;

@end