//
//  LDCDBLogWriter.h
//  LDCore
//
//  Created by David Ellis on 2013-05-23.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>

@class LDMItem;

@protocol LDCDBLogWriter <NSObject>

- (bool) lastLogTransmissionFailed;
- (void) sendLogItemsToServer;
- (void) sendLogItemsToServer: (NSArray *) arrayItems;
- (NSDictionary *) convertLogToItem: (DDLogMessage *) message;

@end
