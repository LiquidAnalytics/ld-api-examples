//
//  NSAttributedString+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 5/13/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSAttributedString (LDK)

+ (NSAttributedString *)attributedStringWithText:(NSString *)text font:(UIFont *)font color:(UIColor *)color;
+ (NSAttributedString *)attributedStringWithText:(NSString *)text font:(UIFont *)font color:(UIColor *)color backgroundColor:(UIColor *)backgroundColor;

@end
