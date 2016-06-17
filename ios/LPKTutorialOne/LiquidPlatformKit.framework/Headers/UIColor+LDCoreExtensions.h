//
//  UIColor+LDCoreExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 9/23/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (LDCoreExtensions)

+ (UIColor *)colorForHexString:(NSString *)hexstr;
+ (UIColor *)colorForHexValue:(NSInteger)rgbValue;
+ (UIColor *)colorForRGBArray:(NSArray *)array;
+ (UIColor *)colorWithStandardRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue;

@end
