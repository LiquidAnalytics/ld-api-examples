//
//  UINavigationBar+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 10/22/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationBar (LDK)

+ (UIBarButtonItem *)fixedSpaceBarItemWithWidth:(float)width;
+ (NSArray *)barItemsArray:(NSArray *)array withFixedSpacing:(float)spacing;
- (void)setTitleColor:(UIColor *)color;
- (void)setNoShadow;

@end
