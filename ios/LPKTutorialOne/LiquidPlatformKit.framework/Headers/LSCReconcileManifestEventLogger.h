//
//  LSCReconcileManifestEventLogger.h
//  LDCore
//
//  Created by David Ellis on 11/8/2013.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LSCReconcileManifestEventLoggerDelegate;

@interface LSCReconcileManifestEventLogger : NSObject
    @property (weak) id<LSCReconcileManifestEventLoggerDelegate> delegate;


    + (LSCReconcileManifestEventLogger *)sharedInstance;
    - (void)logMessage:(NSString *)message;
@end


@protocol LSCReconcileManifestEventLoggerDelegate <NSObject>

- (void)reconcileManifestEventLogger:(LSCReconcileManifestEventLogger *)logger didLogMessage:(NSString *)message;

@end