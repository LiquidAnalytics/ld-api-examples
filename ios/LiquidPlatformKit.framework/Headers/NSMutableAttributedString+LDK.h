//
//  NSAttributedString+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 11/20/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSMutableAttributedString (LDK)

+ (NSMutableAttributedString *)attributedStringFromString:(NSString *)string;
- (void)setForegroundColor:(UIColor *)foregroundColor backgroundColor:(UIColor *)color forRange:(NSRange)range;
- (void)setFont:(UIFont *)font forTextAfterString:(NSString *)input;
- (void)setColor:(UIColor *)color forTextBeforeString:(NSString *)input;
- (void)setColor:(UIColor *)color forTextAfterString:(NSString *)input;
- (void)appendString:(NSString *)string font:(UIFont *)font color:(UIColor *)color;
- (void)appendFont:(UIFont *)font color:(UIColor *)color format:(NSString *)format, ...;

@end
