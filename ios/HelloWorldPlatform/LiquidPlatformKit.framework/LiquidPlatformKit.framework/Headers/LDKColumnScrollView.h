//
//  LDKColumnScrollView.h
//  LDCore
//
//  Created by Bryan Nagle on 11/21/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKColumnScrollViewDelegate;

@interface LDKColumnScrollView : UIScrollView

@property (nonatomic, weak) id<LDKColumnScrollViewDelegate> ldkDelegate;
@property (nonatomic, assign) UIEdgeInsets contentInsets;
@property (nonatomic, assign) CGSize cellSize;

@end

@protocol LDKColumnScrollViewDelegate <NSObject>

- (NSInteger)numberOfViewsForColumnScrollView:(LDKColumnScrollView *)view;
- (UIView *)columnScrollView:(LDKColumnScrollView *)view viewForItemAtIndexPath:(NSIndexPath *)indexPath;

@end