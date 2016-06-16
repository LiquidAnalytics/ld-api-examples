//
//  UIActionSheet+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/5/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMDimension, LDCMediaAbstract;

@interface UIActionSheet (LDK)

+ (UIActionSheet *)actionSheetForDimensions:(NSArray *)dimensions withTitle:(NSString *)title select:(void (^)(LDMDimension *dimension))selected;
+ (UIActionSheet *)actionSheetForMediaAbstracts:(NSArray *)mediaAbstracts withTitle:(NSString *)title select:(void (^)(LDCMediaAbstract *mediaAbstract))selected;
+ (void)showSeparatorOnLastButtonForIPadForActionSheet:(UIActionSheet *)actionSheet;

@end
