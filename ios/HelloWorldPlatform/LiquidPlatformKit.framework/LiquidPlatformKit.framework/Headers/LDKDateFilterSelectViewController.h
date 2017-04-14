//
//  LDKDateFilterSelectViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/19/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMQueryFilter;

typedef NS_ENUM(NSUInteger, DateFilterOption)
{
    DateFilterOptionNone,
    DateFilterOptionBefore,
    DateFilterOptionAfter
};

@interface LDKDateFilterSelectViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, copy) void (^selected)(NSDate *date, DateFilterOption option);
@property (nonatomic, assign) BOOL showDateOnly;
@property (nonatomic, assign) BOOL showBeforeAfter;
@property (nonatomic, assign) BOOL dynamicHeight;
@property (nonatomic, assign) BOOL returnOnDone;
@property (nonatomic, assign) BOOL showClearButton;
@property (strong) NSDate *currentDate;
@property (strong) NSNumber *minuteInterval;

-(void) loadOptions:(NSDictionary*)options;

@end
