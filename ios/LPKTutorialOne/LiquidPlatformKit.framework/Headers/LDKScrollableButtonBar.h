//
//  LDKScrollableButtonBar.h
//  LDCore
//
//  Created by Bryan Nagle on 12/3/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKScrollableButtonBarDelegate;

@interface LDKScrollableButtonBar : UIView

@property (weak) id<LDKScrollableButtonBarDelegate> delegate;
@property (nonatomic) NSInteger selectedIndex;
@property (strong) UIFont *font;
@property (nonatomic, copy) void (^didSelectTitleHandler)(id sender, NSString *title, NSInteger index);
@property (readonly) NSString *selectedTitle;

- (void)addButton:(UIButton *)button;
- (void)addButtonOfClass:(Class)class withTitle:(NSString *)title;
- (void)addButtonOfClass:(Class)class withTitle:(NSString *)title andEventHandler:(void (^)(id sender))eventHandler;

- (void)addTitle:(NSString *)title;
- (UIButton *)addTitle:(NSString *)title handler:(void (^)(id sender))handler;
- (void)selectIndex:(NSInteger)index;
- (NSUInteger)indexOfTitle:(NSString *)title;

- (NSUInteger)buttonCount;
- (void)removeButtonWithIndex:(NSUInteger)index;

@end

@protocol LDKScrollableButtonBarDelegate <NSObject>

- (void)buttonBarView:(LDKScrollableButtonBar *)slideButtonView didSelectTitle:(NSString *)title atIndex:(NSInteger)index;

@end