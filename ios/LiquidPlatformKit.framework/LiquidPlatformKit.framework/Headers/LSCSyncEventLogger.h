//
//  LSCSyncEventLogger.h
//  seaside
//
//  Created by Bryan Nagle on 8/15/13.
//
//

#import <Foundation/Foundation.h>

@protocol LSCSyncEventLoggerDelegate;

@interface LSCSyncEventLogger : NSObject

@property (weak) id<LSCSyncEventLoggerDelegate> delegate;

+ (LSCSyncEventLogger *)sharedInstance;
- (void)logMessage:(NSString *)message;

@end

@protocol LSCSyncEventLoggerDelegate <NSObject>

- (void)syncEventLogger:(LSCSyncEventLogger *)logger didLogMessage:(NSString *)message;

@end