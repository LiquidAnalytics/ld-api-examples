//
//  LDKSwipeButtonView.h
//  LDCore
//
//  Created by Bryan Nagle on 12/9/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKSwipeButtonViewDelegate;

@interface LDKSwipeButtonView : UIView

@property (nonatomic, weak) id<LDKSwipeButtonViewDelegate> delegate;
@property (nonatomic, strong) NSArray *buttons;
@property (nonatomic, assign) UIEdgeInsets buttonEdgeInsets;
@property (nonatomic, copy) void (^buttonPressed)(LDKSwipeButtonView *view, UIButton *sender);

- (void)expandAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;
- (void)collapseAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

@end

@protocol LDKSwipeButtonViewDelegate <NSObject>

- (void)swipeButtonView:(LDKSwipeButtonView *)view buttonPressed:(UIButton *)button;

@end