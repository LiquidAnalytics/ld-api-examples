//
//  LDKPullToRefreshEventView.h
//  LDCore
//
//  Created by Bryan Nagle on 10/2/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKPullToRefreshEventViewDelegate;

@interface LDKPullToRefreshEventView : UIView 

@property (weak, nonatomic) id<LDKPullToRefreshEventViewDelegate> delegate;

@end

@protocol LDKPullToRefreshEventViewDelegate <NSObject>

- (void)refreshEventView:(UIView *)view didChangeState:(int)state;

@end