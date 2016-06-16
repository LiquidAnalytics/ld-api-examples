//
//  LDCLoadingView.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 8/24/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>
#import "LDCLoadingViewManager.h"

@interface LDCLoadingView : UIView

@property (strong) UIActivityIndicatorView *activityIndicatorView;
@property (assign) float opacity;
@property (assign) UIActivityIndicatorViewStyle style;
@property (assign) BOOL animate;
@property (nonatomic, strong) NSArray *lines;
@property (strong) UIFont *defaultFont;

+ (id)loadingViewInView:(UIView *)aSuperview;
+ (id)loadingViewInView:(UIView *)aSuperview animate:(BOOL)animate;
+ (id)loadingViewInView:(UIView *)aSuperview withOpacity:(float)opacity;
+ (id)loadingViewInView:(UIView *)aSuperview withOpacity:(float)opacity andLockView:(UIView *)lockView;
+ (id)loadingViewInView:(UIView *)aSuperview withOpacity:(float)opacity andLockView:(UIView *)lockView animate:(BOOL)animate;
+ (id)loadingViewInView:(UIView *)aSuperview withOpacity:(float)opacity andLockView:(UIView *)lockView andTimeOut:(NSTimeInterval)timeOut andTimeOutBlock:(LDCLoadingViewTimeOutBlock)timeOutBlock;
+ (id)loadingViewInView:(UIView *)aSuperview withOpacity:(float)opacity andLockView:(UIView *)lockView andTimeOut:(NSTimeInterval)timeOut andTimeOutBlock:(LDCLoadingViewTimeOutBlock)timeOutBlock animate:(BOOL)animate;
+ (id)loadingViewInView:(UIView *)aSuperview withOpacity:(float)opacity andLockView:(UIView *)lockView lines:(NSArray *)lines style:(UIActivityIndicatorViewStyle)style animate:(BOOL)animate;
- (void)removeViewAnimated:(BOOL)animate;
- (void)removeView;

@end
