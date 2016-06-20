//
//  UILabel+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/16/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (LDK)

typedef enum {
    LDKUILabelEmailAction,
    LDKUILabelPhoneAction,
    LDKUILabelTwitterAction
} LDKUILabelActionType;

- (void)animatePulseColor:(UIColor *)color startColor:(UIColor*)startColor numberOfPulses:(NSInteger)numberOfPulses;
- (void)animateTextToColor:(UIColor *)color duration:(NSInteger)duration completion:(void (^)(BOOL finished))completion;
- (void)setText:(NSString *)text withIcon:(NSString*) image;
- (void)addActionOfType:(LDKUILabelActionType) actionType;
- (CGRect)boundingRectForCharacterRange:(NSRange)range;
@end
