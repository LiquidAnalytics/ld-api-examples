//
//  LDCInfoViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 11/7/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import "LDCSplitPopoverViewController.h"
#import <MessageUI/MessageUI.h>

typedef enum : NSUInteger {
    InfoViewConfigureOptionEnabled = (0x1 << 0), // => 0x00000001
    InfoViewConfigureOptionTouchEnabled   = (0x1 << 1), // => 0x00000010
    InfoViewConfigureOptionDisclosureEnabled     = (0x1 << 2)  // => 0x00000100
} InfoViewConfigureOptions;

@protocol LDCInfoViewControllerDataSource;
@protocol LDCInfoViewControllerDelegate;

@interface LDCInfoViewController : LDCSplitPopoverViewController

@property (weak) id<LDCInfoViewControllerDataSource> datasource;
@property (weak) id<LDCInfoViewControllerDelegate> delegate;

+ (void)dismissAllAlertViews;
- (void)setContentSizeForViewInPopover;

@end

@protocol LDCInfoViewControllerDataSource <NSObject>

- (NSInteger)numberOfSectionsForInfoViewController:(LDCInfoViewController *)infoViewController;

- (NSInteger)numberOfOptionsInSection:(NSInteger)section forInfoViewController:(LDCInfoViewController *)infoViewController;

- (void)infoViewController:(LDCInfoViewController *)infoViewController forIndexPath:(NSIndexPath *)indexPath configureBlock:(void (^)(UIViewController *controller, NSString *text, float width, InfoViewConfigureOptions options))block;

- (void)infoViewController:(LDCInfoViewController *)infoViewController connectionInfo:(void (^)(NSString *delayString, NSString *qualityString))block;

@end

@protocol LDCInfoViewControllerDelegate <NSObject>

- (void)infoViewController:(LDCInfoViewController *)infoViewController didSelectOptionText:(NSString *)text atIndexPath:(NSIndexPath *)indexPath;

- (void)infoViewController:(LDCInfoViewController *)infoViewController logoutButtonPressed:(id)sender;

- (void)infoViewController:(LDCInfoViewController *)infoViewController resetButtonPressed:(id)sender;
- (void)infoViewController:(LDCInfoViewController *)infoViewController switchUserButtonPressed:(id)sender;

@end