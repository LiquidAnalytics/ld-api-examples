//
//  UIImage+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/2/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (LDK)

typedef NS_ENUM(NSUInteger, LDKAccessoryImageType)
{
    LDKAccessoryImageTypeLeftArrow,
    LDKAccessoryImageTypeRightArrow,
    LDKAccessoryImageTypeUpArrow,
    LDKAccessoryImageTypeDownArrow
};

+ (UIImage *)griadientImageWithSize:(CGSize)size locations:(CGPoint)locations magnitude:(float)magnitude start:(CGPoint)start end:(CGPoint)end colors:(NSArray *)colors;
+ (UIImage *)imageWithColor:(UIColor *)color;
+ (UIImage *)imageScaledToSize:(UIImage *)srcImage newSize:(CGSize)size;
+ (UIImage *)imageScaledToFitSize:(UIImage *)image newSize:(CGSize)size;
+ (UIImage *)arrowAccessoryImageOfType:(LDKAccessoryImageType)type ofSize:(CGSize)size withColor:(UIColor *)color;
- (UIImage *)imageScaledToSize:(CGSize)size;
- (UIImage *)imageScaledToFitSize:(CGSize)size;
- (UIImage *)imageScaledToFitSize:(CGSize)size scale:(float)scale;
+ (UIImage *)imageScaledToFitSize:(UIImage *)image newSize:(CGSize)size scale:(float)scale;
+ (UIImage *)imageScaledToSize:(UIImage *)srcImage newSize:(CGSize)size scale:(float)scale;

- (UIImage *)addTintColor:(UIColor *)color withOpacity:(CGFloat)opacity;

@end
