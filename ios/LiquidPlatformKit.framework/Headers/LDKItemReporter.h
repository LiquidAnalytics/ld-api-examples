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

@end
