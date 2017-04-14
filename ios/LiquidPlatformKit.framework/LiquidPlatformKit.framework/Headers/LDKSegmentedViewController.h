//
//  LDKSegmentedViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 2/5/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKSegmentedViewControllerDelegate;

@interface LDKSegmentedViewController : UIViewController

@property (nonatomic, weak) UIViewController *currentViewController;
@property (weak) id<LDKSegmentedViewControllerDelegate> ldkDelegate;

@end

@protocol LDKSegmentedViewControllerDelegate <NSObject>

- (NSInteger)numberOfSegmentsInSegmentedViewController:(LDKSegmentedViewController *)controller;
- (NSString *)segmentedViewController:(LDKSegmentedViewController *)controller titleForSegmentAtIndex:(NSInteger)index;
- (UIViewController *)segmentedViewController:(LDKSegmentedViewController *)controller viewControllerForSegmentAtIndex:(NSInteger)index;

@end