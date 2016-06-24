//
//  LDCSplitPopoverViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 11/7/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface LDCSplitPopoverViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UIView *contentView;
@property BOOL showContentViewBorder;
- (void)setup;
- (void)setText:(NSString *)text forKey:(NSString *)key forSection:(NSUInteger)section;
- (void)setViewController:(UIViewController *)viewController forKey:(NSString *)key;
- (void)setTouchHandler:(void (^)(id))touchHandler forKey:(NSString *)key;
- (void)setDisclosure:(BOOL)disclosure forKey:(NSString *)key;
- (void)setWidth:(float)width forKey:(NSString *)key;
- (void)setEnabled:(BOOL)enabled forKey:(NSString *)key;

- (void)showViewController:(UIViewController *)controller forKey:(NSString *)key;
- (void)hideViewController;
- (BOOL)splitIsViewDisplayingSecondView;
@end
