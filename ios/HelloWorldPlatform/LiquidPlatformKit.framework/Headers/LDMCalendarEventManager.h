//
//  LDMCalendarEventManager.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 10/7/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

#define CALENDAR_EVENT_CURRENT_APPOINTMENT_CHANGED                              @"CalendarEventCurrentAppointmentChanged"

@interface LDMCalendarEventManager : NSObject

+ (LDMCalendarEventManager *)sharedInstance;
- (void)start;
- (void)stop;

@end
