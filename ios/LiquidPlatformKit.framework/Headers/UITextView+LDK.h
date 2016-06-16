//
//  UITextView+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 12/3/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextView (LDK)

- (void)addTextFieldBackgroundOnParentView:(UIView *)parentView;
- (CGRect)boundingRectForCharacterRange:(NSRange)range;

@end
