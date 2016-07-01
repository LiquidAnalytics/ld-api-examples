//
//  UIToolbar+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 10/22/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIToolbar (LDK)

- (void)setTransparentBackground;
- (void)removeTopBorder;

- (UIBarButtonItem *)addTitle:(NSString *)title font:(UIFont *)font handler:(void (^)(id sender))handler;
- (UIBarButtonItem *)addTitle:(NSString *)title handler:(void (^)(id sender))handler;
- (UIBarButtonItem *)addSystemItem:(UIBarButtonSystemItem)systemItem handler:(void (^)(id sender))handler;
- (void)setItemTintColor:(UIColor *)color;
- (void)removeTitle:(NSString *)title;
- (void)sizeToFitItems;
- (void)removeItem:(UIBarButtonItem *)item animated:(BOOL)animated;

@end
