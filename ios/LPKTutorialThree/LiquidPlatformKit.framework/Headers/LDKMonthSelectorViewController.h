//
//  LDKMonthSelectorViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 7/17/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKMonthSelectorViewController : UIViewController

@property (strong) NSDate *currentDate;
@property (nonatomic, copy) void (^didSelectDate)(NSDate *date);

- (void)loadDate:(NSDate *)date;

@end
