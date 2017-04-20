//
//  LDKCalendarViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 8/8/16.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <UIKit/UIKit.h>

@protocol LDKCalendarViewControllerDelegate;

@interface LDKCalendarViewController : UIViewController

@property (nonatomic, assign) id<LDKCalendarViewControllerDelegate> delegate;
@property (nonatomic, retain) NSDate *date;

- (IBAction)prevMonth:(id)sender;
- (IBAction)nextMonth:(id)sender;
@end

@protocol LDKCalendarViewControllerDelegate <NSObject>

- (void)calendarViewConroller:(LDKCalendarViewController*)calendarViewController didSelectDate:(NSDate *)date initialLoad:(BOOL) initialFlag;

@end