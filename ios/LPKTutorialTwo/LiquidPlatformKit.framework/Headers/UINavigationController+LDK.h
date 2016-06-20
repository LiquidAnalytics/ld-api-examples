//
//  UINavigationController+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 10/23/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationController (LDK)

+ (void)setPreferredStatusBarStyle:(UIStatusBarStyle)aStatusBarStyle;


- (void)setLightContentStyleColor:(UIColor *)color;
- (void)setLightContentStyleColor:(UIColor *)color translucent:(BOOL)translucent;
- (void)setDarkContentStyleColor:(UIColor *)color;
- (void)setDarkContentStyleColor:(UIColor *)color translucent:(BOOL)translucent;

@end
