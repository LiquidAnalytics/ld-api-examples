//
//  LDKCoreGraphicsEffects.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 2/15/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LDKCoreGraphicsOption)
{
    LDKCoreGraphicsVertical,
    LDKCoreGraphicsHorizontal
};

@interface LDKCoreGraphicsEffects : NSObject


+ (void)linearGradientOnContext:(CGContextRef)context inRect:(CGRect)rect withStartColor:(UIColor *)startColor andEndColor:(UIColor *)endColor;

+ (void)fillGradientOnContext:(CGContextRef)context inRect:(CGRect)rect withColors:(NSArray *)colors andDirection:(LDKCoreGraphicsOption)direction;

+ (void)fillRect:(CGRect)rect onContext:(CGContextRef)context withColor:(UIColor *)color;

+ (void)drawLineOnContext:(CGContextRef)context fromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint withColor:(UIColor *)color andWidth:(float)width;

+ (void)drawText:(NSString *)text onContext:(CGContextRef)context inRect:(CGRect)rect font:(UIFont *)font lLineBreakMode:(NSLineBreakMode)lineBreakMode alignment:(NSTextAlignment)alignment color:(UIColor *)color;

@end
