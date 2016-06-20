//
//  LDKEvent.h
//  LDCore
//
//  Created by Bryan Nagle on 1/17/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDKEvent : NSObject

+ (LDKEvent *)sharedInstance;

- (id)addListener:(id (^)(id arguments))listener forEventName:(NSString *)eventName;
- (NSArray *)postEventName:(NSString *)eventName withArguments:(id)arguments;
- (void)removeListener:(id)listener forEventName:(NSString *)eventName;
- (void)removeAllEventsForKey:(NSString *)key;

@end
