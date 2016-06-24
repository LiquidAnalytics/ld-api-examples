//
//  LDCLogging.h
//  LDCore
//
//  Created by David Ellis on 2013-05-16.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>
#import "LDCDBLogWriter.h"

@class DDFileLogger;

@interface LDCLogging : NSObject

@property (nonatomic, strong) DDFileLogger *fileLogger;


+ (LDCLogging *)sharedInstance;

- (void) setupLogging: (NSString *) welcome dbWriter: (id<LDCDBLogWriter>) dbLogger;
- (void) flushLogs;
- (NSMutableArray *) errorLogData;

@end
