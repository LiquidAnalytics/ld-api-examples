//
//  LDCDBLogger.h
//  LDCore
//
//  Created by David Ellis on 2013-05-23.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TSStack.h"
#import <CocoaLumberjack/DDAbstractDatabaseLogger.h>
#import "LDCDBLogWriter.h"

@interface LDCDBLogger : DDAbstractDatabaseLogger {
    TSStack *messageBuffer;
}

@property (weak) id <LDCDBLogWriter> dbLogger;

@end
