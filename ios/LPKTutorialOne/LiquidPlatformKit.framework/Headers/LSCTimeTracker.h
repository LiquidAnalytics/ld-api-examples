//
//  LSCTimeTracker.h
//  seaside
//
//  Created by Bryan Nagle on 2/10/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@protocol LSCTimeTrackerDelegate <NSObject>
- (void)trackEndedForKey:(NSString *)key atTime:(NSDate *)end withDuration:(NSNumber *)duration;
@end

@interface LSCTimeTracker : NSObject
+ (LSCTimeTracker *)sharedInstance;
+ (NSNumber *)getTimeStamp;
- (void)start:(NSString *)key;
- (double)end:(NSString *)key;
- (void)registerDelegate:(id)delegate forKey:(NSString *)key;
- (void)unregisterDelegateForKey:(NSString *)key;
- (double)peek:(NSString *)key;
@end
