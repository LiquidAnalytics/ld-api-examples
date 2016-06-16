//
//  UIButton+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/9/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDCButton;

#define LDK_STANDARD_BUTTON_ALERT   100099

@interface UIButton (LDK)

+ (LDCButton *)systemItem:(UIBarButtonSystemItem)systemItem buttonWithFrame:(CGRect)frame andText:(NSString *)text;
+ (LDCButton *)stopButtonWithFrame:(CGRect)frame;
+ (LDCButton *)addButtonWithFrame:(CGRect)frame;
+ (LDCButton *)addButtonWithFrame:(CGRect)frame andText:(NSString *)text;
+ (LDCButton *)standardAlertButtonWithFrame:(CGRect)frame andTitle:(NSString *)title;
+ (LDCButton *)buttonWithSystemItem:(UIBarButtonSystemItem)systemItem frame:(CGRect)frame pressed:(void (^)(id sender))pressed;
+ (UIButton *)confirmButtonWithTitle:(NSString *)title confirmMessage:(NSString *)confirmMessage willConfirmBlock:(void (^)(UIButton *aButton))willConfirm didConfirmBlock:(void (^)(UIButton *aButton))didConfirmBlock;

- (void)setSpin:(BOOL)spin;

@end
