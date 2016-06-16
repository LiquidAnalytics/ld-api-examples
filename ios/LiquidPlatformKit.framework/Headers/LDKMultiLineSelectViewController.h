//
//  LDKItemStatementViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 3/11/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMSearchResults, LDKMultiLineSelectConfig;
@protocol LDKItemStatementViewControllerDelegate;

@interface LDKMultiLineSelectViewController : UIViewController

@property (nonatomic, strong, nullable) LDMSearchResults *results;
@property (nonatomic, weak, nullable) id<LDKItemStatementViewControllerDelegate> delegate;
@property (nonatomic, copy) NSInteger (^__nullable numberOfLinesForItem)(LDMItem * __nullable item);
@property (nonatomic, copy, nullable) LDKMultiLineSelectConfig *__nullable (^configForItem)(LDMItem * __nullable item);
@property (nonatomic, copy, nullable) BOOL (^shouldDeleteItem)(LDMItem * __nullable item);
@property (nonatomic, copy, nullable) void (^didSelectItem)(LDMItem * __nullable item);

+ (LDKMultiLineSelectViewController * __nonnull )multiLineViewController;
+ (LDKMultiLineSelectViewController * __nonnull )multiLineViewControllerWithItems:(NSArray * __nullable )items;

@end

@interface LDKMultiLineSelectConfig : NSObject

@property (nonatomic, strong, nullable) NSArray *lines;
@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic, assign) BOOL disableDelete;

+ (LDKMultiLineSelectConfig * __nullable )config;
+ (LDKMultiLineSelectConfig * __nullable )configWithLines:(NSArray *__nonnull)lines image:(UIImage *__nullable)image disableDelete:(BOOL)disableDelete;

@end

@protocol LDKItemStatementViewControllerDelegate <NSObject>

- (NSInteger)multiLineViewController:(LDKMultiLineSelectViewController * __nullable )viewController numberOfLinesForItem:(LDMItem * __nullable )item;
- (LDKMultiLineSelectConfig * __nullable )multiLineViewController:(LDKMultiLineSelectViewController * __nullable )viewController configForItem:(LDMItem * __nullable )item;
- (BOOL)multiLineViewController:(LDKMultiLineSelectViewController * __nullable )viewController shouldDeleteItem:(LDMItem * __nullable )item;
- (void)multiLineViewController:(LDKMultiLineSelectViewController * __nullable )viewController didSelectItem:(LDMItem * __nullable )item;

@end