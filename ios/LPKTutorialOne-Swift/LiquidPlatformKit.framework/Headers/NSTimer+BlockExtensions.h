//
//  NSTimer+BlockExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 8/24/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

typedef void (^NSTimerIntervalBlock)(NSTimer *timer);

@interface NSTimer (BlockExtensions)

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)theSeconds repeats:(BOOL)repeats block:(NSTimerIntervalBlock)block;

@end
