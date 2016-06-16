//
//  UIFont+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/13/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (LDK)

- (UIFont *)fontToFitText:(NSString *)text inSize:(CGSize)size;
- (void)fitText:(NSString *)text inSize:(CGSize)size handler:(void (^)(UIFont *font, CGSize sizeNeeded))handler;

@end
