//
//  LDCLogFormatter.h
//  LDCore
//
//  Created by David Ellis on 2013-05-16.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>

@interface LDCLogFormatter : NSObject <DDLogFormatter>
{
    int atomicLoggerCount;
    NSDateFormatter *threadUnsafeDateFormatter;
}

- (NSString *)stringFromDate:(NSDate *)date;
@end
