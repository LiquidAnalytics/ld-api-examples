//
//  LDCBorderDrawer.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 5/18/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface LDKLayerEffects : NSObject

typedef enum 
{
    BorderTop = 1 << 0,
    BorderBottom = 1 << 1,
    BorderLeft = 1 << 2,
    BorderRight = 1 << 3,
    BorderAll = 1 << 4
} BorderSides;

typedef enum
{
    BorderStyleSolid = 0,
    BorderStyleDashed = 1
} BorderStyle;

+ (CGPathRef) newPathForRoundedRect:(CGRect)rect radius:(CGFloat)radius;
+ (void)borderOnLayer:(CALayer *)aLayer withColor:(UIColor *)color andLineWidth:(float)width andCornerRadius:(float)radius;
+ (void)borderOnLayer:(CALayer *)aLayer withColor:(UIColor *)color andLineWidth:(float)width andSides:(BorderSides)sides;
+ (void)innerShadowhadowOnLayer:(CALayer *)aLayer withHeight:(float)height andSides:(BorderSides)sides;
+ (void)innerShadowhadowOnLayer:(CALayer *)aLayer withColor:(UIColor *)color andHeight:(float)height andSides:(BorderSides)sides;
+ (void)lightInnerShadowhadowOnLayer:(CALayer *)aLayer withHeight:(float)height andSides:(BorderSides)sides;
+ (NSArray *)gradientColorsFromColor:(UIColor *)color forHeight:(float)height inverse:(BOOL)inverse;
+ (void)outerShadowhadowOnLayer:(CALayer *)aLayer andHeight:(float)height andSides:(BorderSides)sides;
+ (void)outerShadowhadowOnLayer:(CALayer *)aLayer withColor:(UIColor *)color andHeight:(float)height andSides:(BorderSides)sides;
+ (void)lightOuterShadowhadowOnLayer:(CALayer *)aLayer andHeight:(float)height andSides:(BorderSides)sides;
+ (void)roundedCornersOnLayer:(CALayer *)layer withRadius:(float)radius;

@end
