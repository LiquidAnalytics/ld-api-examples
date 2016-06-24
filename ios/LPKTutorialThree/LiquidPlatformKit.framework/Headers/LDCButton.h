//
//  LDCForcedFontButton.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 6/20/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface LDCButton : UIButton

@property (strong) UIFont *forcedFont;
@property float touchMargin;
@property CGSize touchSize;

- (void) makeStretchableButton:(UIImage *)buttonImage withInsets:(UIEdgeInsets)insets forState:(UIControlState)state;
- (void)setup;
- (void)hideButton:(BOOL)hide;
- (void)enableButton:(BOOL)enable;
- (void)setLabelFontColor:(UIColor *)fontColor withSelectedColor:(UIColor *)selectedColor;

@end
