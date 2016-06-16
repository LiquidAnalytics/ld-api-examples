//
//  UIColor+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/2/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (LDK)

- (UIColor *)colorByChangingBrightness:(float)brightness saturation:(float)saturation;
- (UIColor *)colorByAdjustingBrightness:(float)brightness;
- (UIColor *)lighterColor;

@end
