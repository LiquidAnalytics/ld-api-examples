//
//  UIView+LDCoreExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 12/14/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>
#import "LDKLayerEffects.h"

typedef NS_ENUM(NSUInteger, LDKViewSide)
{
    LDKSideBorderNone = 0,
    LDKViewSideTop = 1 << 0,
    LDKViewSideBottom = 1 << 1,
    LDKViewSideRight = 1 << 2,
    LDKViewSideLeft = 1 << 3,
    LDKViewSideAll = 1 << 4
};

@interface UIView (LDK)

@property (readonly) UIButton *button;
@property (readonly) UITableViewCell *cell;
@property (readonly) UICollectionViewCell *collectionViewCell;
@property (readonly) UICollectionView *collectionView;

+ (UIView *)viewFromNib:(UINib *)nib;
+ (UIView *)subviewOfClass:(Class)class nib:(UINib *)nib;
+ (UIView *)subviewOfClass:(Class)class nibName:(NSString *)nibName;

- (BOOL)isVisible;
- (UIView *)findChildViewOfClass:(__unsafe_unretained Class)class;
- (UIView *)findParentViewOfClass:(__unsafe_unretained Class)class;
- (UIButton *)button;
- (UITableViewCell *)cell;
//- (void)setBorderWithColor:(UIColor *)color andLineWidth:(float)width andSides:(BorderSides)sides;

- (void)setLightBlurredTransparentBackground;
- (void)setLightBlurredTransparentBackgroundWithTintColor:(UIColor *)tintColor;
- (void)setDarkBlurredTransparentBackground;
- (void)setDarkBlurredTransparentBackgroundWithTintColor:(UIColor *)tintColor;
- (void)setInnerShadowWithHeight:(float)height andSides:(BorderSides)sides;
- (void)setInnerShadowWithColor:(UIColor *)color andHeight:(float)height andSides:(BorderSides)sides;
- (void)setGradientBackgroundWithColors:(NSArray *)colors;
- (void)removeBorders;
- (void)setBorderWidth:(float)lineWidth color:(UIColor *)color sides:(LDKViewSide)sides;
- (void)setBorderWidth:(float)lineWidth color:(UIColor *)color sides:(LDKViewSide)sides offset:(float)offset widthOffset:(float)widthOffset;
- (UIImage *)renderToImageSize:(CGSize)size;

- (void)animateGlitterWithDuration:(float)duration scale:(NSInteger)scale strength:(NSInteger)strength separation:(float)separation color:(UIColor *)color completion:(void (^)(BOOL finished))completion;

- (void)setFrameOrigin:(CGPoint)origin;
- (void)setFrameSize:(CGSize)size;
- (UIViewController *) firstAvailableUIViewController;

@end
