//
//  LDKFieldSelectViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/19/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKTextSelectViewControllerDelegate;

@interface LDKTextSelectViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (strong) NSArray *strings;
@property (nonatomic, copy) void (^selected)(NSString *string);
@property (copy, nonatomic) void (^didCalculateHeightNeeded)(float heightNeeded);
@property (assign) int maxHeight;
@property (nonatomic, weak) id<LDKTextSelectViewControllerDelegate> delegate;
@property (strong, nonatomic) NSAttributedString *prefix;
@property (readonly, nonatomic) NSArray *allStrings;

+ (LDKTextSelectViewController *)selectViewControllerWithStrings:(NSArray *)strings andSelectedBlock:(void (^)(NSString *string))selectedBlock;

- (void)reloadData;
- (NSArray *)allStrings;

@end

@protocol LDKTextSelectViewControllerDelegate <NSObject>

@optional
- (void)textSelectViewController:(LDKTextSelectViewController *)viewController didCalculateHeightNeeded:(float)heightNeeded;
- (void)textSelectViewController:(LDKTextSelectViewController *)viewController didSelectValue:(NSString *)value;

@end