//
//  LDCLoadingViewManager.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 8/24/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

typedef void (^LDCLoadingViewTimeOutBlock)(id __nonnull loadingView);

@class LDCLoadingView;

@interface LDCLoadingViewManager : NSObject

+ (LDCLoadingViewManager *__nonnull)sharedInstance;
- (LDCLoadingView *__nullable)loadingViewInView:(UIView *__nonnull)aSuperView;
- (LDCLoadingView *__nullable)loadingViewInView:(UIView *__nonnull)aSuperview withOpacity:(float)opacity;
- (LDCLoadingView *__nullable)loadingViewInView:(UIView *__nonnull)aSuperView withOpacity:(float)opacity andLockView:(UIView *__nullable)lockView;
- (LDCLoadingView *__nullable)loadingViewInView:(UIView *__nonnull)aSuperView withOpacity:(float)opacity andLockView:(UIView *__nullable)lockView andTimeOut:(NSTimeInterval)timeOut andTimeOutBlock:(LDCLoadingViewTimeOutBlock __nullable)timeOutBlock;
- (LDCLoadingView *__nullable)loadingViewInView:(UIView *__nonnull)aSuperview withOpacity:(float)opacity andLockView:(UIView *__nullable)lockView lines:(NSArray *__nullable)lines style:(UIActivityIndicatorViewStyle)style animate:(BOOL)animate;
- (void)removeLoadingViewInView:(UIView *__nonnull)aSuperView;
- (void)redrawLoadingViews;

@end
