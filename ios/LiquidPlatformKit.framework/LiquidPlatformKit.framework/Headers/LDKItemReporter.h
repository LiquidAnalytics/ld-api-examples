//
//  LDKItemReporter.h
//  LDCore
//
//  Created by CARSON LI on 2015-03-17.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface LDKItemReporter : NSObject

+ (LDKItemReporter *)sharedInstance;

- (void) reportItems:(NSArray*) items;
- (void) reportItem:(LDMItem*) item;
- (void) reportItems:(NSArray*) items withAction:(NSString*) action;
- (void) reportItem:(LDMItem*) item withAction:(NSString*) action;
- (void) reportUXMetrics:(NSArray*) metricDicts;


@end
