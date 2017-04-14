//
//  NSDate+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 1/8/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

typedef enum {
    LDKCalendarStartDaySunday = 0,
    LDKCalendarStartDayMonday = 1,
} LDKCalendarStartDay;

@interface NSDate (LDK)

@property (readonly) NSString *monthName;
@property (readonly) NSString *yearString;
@property (readonly) NSDate *dateWithZeroTime;
@property (readonly) NSDate *dateWithEndOfDayTime;
@property (readonly) NSDate *dateWithStartOfDayTime;
@property (readonly) NSDateFormatter *dateFormatter;
@property (readonly) NSString *shortDateString;
@property (readonly) NSString *longDateString;
@property (readonly) NSString *longDateWithTimeString;

+ (NSDate *)dateFromKeyword:(NSString *)keyword;
+ (NSDate *)today;
+ (NSDate *)tomorrow;
+ (NSDate *)yesterday;
+ (NSDate *)weekStartDate;
+ (NSDate *)weekEndDate;
+ (LDKCalendarStartDay) getWeekStartDay;
+ (void) setWeekStartDay:(LDKCalendarStartDay)startDay;
+ (NSDate *)firstDayOfCurrentMonth;
+ (NSDate *)firstDayOfPreviousMonth;
+ (NSDate *)firstDayOfNextMonth;
+ (NSDate *)firstDayOfPreviousWeek;
+ (NSDate *)firstDayOfCurrentWeek;
+ (NSDate *)oneMonthAgoFromToday;
+ (NSDate *)firstDayOfCurrentQuarter;
+ (NSDate *)firstDayOfPreviousQuarter;
+ (NSDate *)firstDayOfNextQuarter;
+ (NSDate *)firstDayOfQuarterFromDate:(NSDate *)date;
+ (NSDate *)oneQuarterAgoFromToday;

- (NSString *)javaTime;
- (NSString *)monthName;
- (NSString *)yearString;
- (NSInteger)year;
- (NSInteger)month;

- (NSDate*) minimumDateForSameYear;
- (NSDate*) maximumDateForSameYear;
- (NSDate*) minimumDateForSameMonth;
- (NSDate*) maximumDateForSameMonth;
- (NSDate *)dateBySubtractingMonths:(NSUInteger)months;
- (NSDate *)dateByAddingMonths:(NSUInteger)months;
- (NSDate *)dateBySubtractingDays:(NSUInteger)Days;
- (NSDate *)dateByAddingDays:(NSUInteger)days;
- (NSDate *)dateByAddingHours:(NSUInteger)hours;
- (NSDate *)dateBySubtractingHours:(NSUInteger)hours;
- (NSDate *)dateByAddingMinutes:(NSUInteger)minutes;
- (NSDate *)dateBySubtractingMinutes:(NSUInteger)minutes;
- (NSDate *)dateByAddingSeconds:(NSUInteger)seconds;
- (NSDate *)dateBySubtractingSeconds:(NSUInteger)seconds;
- (NSDate *)dateBySubtractingYears:(NSUInteger)years;
- (NSDate *)dateBySettingMonth:(NSInteger)month;
- (NSDate *)dateBySettingDay:(NSInteger)day;

+ (NSInteger)daysWithinEraFromDate:(NSDate *)startDate toDate:(NSDate *)endDate;
- (NSInteger)daysWithinEraToDate:(NSDate *)toDate;

- (NSString *)shortDateString;
- (NSString *)longDateString;
- (NSDate *)dateBySettingDay:(NSInteger)day withTimeZone:(NSString *)timezone;
- (NSDate *)dateByTimeEndOfDay;
- (NSDate*)lastDayOfMonth;
- (NSInteger)numberOfDaysInMonthCount;
- (NSDate *)endOfDay;

@end
