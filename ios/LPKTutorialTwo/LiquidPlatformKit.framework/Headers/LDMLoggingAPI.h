//
//  LDMLoggingAPI.h
//  seaside
//
//  Created by David Ellis on 2013-05-29.
//
//

#import <Foundation/Foundation.h>
#import "LDMItem.h"

@class LDMLogDetail, LDMLogFile, ASIHTTPRequestDelegate;

@interface LDMLoggingAPI : NSObject

+ (LDMLoggingAPI *)sharedInstance;

- (LDMLogDetail *) createStandardLogItem: (NSString *) details withLogLevel:(NSString *) logLevel  withMethodName: (NSString *)methodName  withTimeStamp: (NSDate *)timeOfLog  withFileName:(NSString *)fileName  withLineNumber: (NSNumber *)lineNumber;
- (void) sendCrashReportToServer: (NSData *) crashReport withTimeStamp: (NSDate *) timeStamp withSummary: (NSString *) summary;
- (LDMLogFile *) createLogFileItem: (NSData *) data withTimeStamp: (NSDate *) timeStamp withSummary: (NSString *) summary;

- (void) sendLogItemsToServer: (NSArray *) sourceItems;
- (void) sendLogItemsToServer;
- (bool) lastLogTransmissionFailed;

@end
