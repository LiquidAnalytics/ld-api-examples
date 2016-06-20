//
//  LDMCalendarManager.h
//  LDCore
//
//  Created by Carson Li on 2014-07-09.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LDMItem;
@class EKEventStore;

@interface LDMCalendarManager : NSObject

+ (LDMCalendarManager *)sharedInstance;
- (void)findDefaultCalendarInEventStore:(EKEventStore*)eventStore;
- (void)addOrUpdateActivityInCalendar:(LDMItem*) item withCompletionHandler:(void (^)(BOOL success))completionHandler;

@end

