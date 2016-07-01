//
//  LSCReconcileManifestController.h
//  LDCore
//
//  Created by David Ellis on 11/7/2013.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASIHTTPRequestDelegate.h"

enum {
    activeReconcileNone,
    activeReconcileSummary,
    activeReconcileDetail
};

typedef NSInteger RECONCILE_STATES;

@interface LSCReconcileManifestController : NSObject <ASIHTTPRequestDelegate>
@property (strong) NSString *reconcileSessionId;
@property RECONCILE_STATES currentReconcileState;

+ (LSCReconcileManifestController *)sharedInstance;

- (void) reconcileWithSummaryManifest;
- (void) reconcileWithDetailManifest : (NSArray *) types;
- (void) reconcileComplete;
@end
