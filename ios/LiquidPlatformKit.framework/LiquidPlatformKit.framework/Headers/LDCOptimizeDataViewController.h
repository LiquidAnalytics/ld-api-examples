//
//  LDCOptimizeDataViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/21/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDCOptimizeDataViewController : UIViewController

+ (LDCOptimizeDataViewController *)optimizeDataControllerWithIndexes:(NSArray *)aIndexes;
+ (void)createIndexes:(NSArray *)indexes;
+ (BOOL)hasIndexesChanged:(NSArray *)appIndexes;

@property (nonatomic, copy) void (^completed)(NSInteger indexCount);

@end
