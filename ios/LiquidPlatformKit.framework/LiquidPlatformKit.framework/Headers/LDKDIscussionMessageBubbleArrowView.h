//
//  LDKDIscussionMessageBubbleArrowView.h
//  LDCore
//
//  Created by Mike Akers on 3/16/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, LDKDiscussionMessageBubbleArrowDirection) {
    LDKDiscussionMessageBubbleArrowDirectionLeft,
    LDKDiscussionMessageBubbleArrowDirectionRight
};

@interface LDKDiscussionMessageBubbleArrowView : UIView

@property (nonatomic) LDKDiscussionMessageBubbleArrowDirection arrowDirection;
@property (nonatomic, strong) UIColor *fillColor;

@end
