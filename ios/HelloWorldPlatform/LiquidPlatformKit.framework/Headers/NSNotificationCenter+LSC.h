//
//  NSNotificationCenter+LSC.h
//  seaside
//
//  Created by Bryan Nagle on 10/12/13.
//
//

#import <Foundation/Foundation.h>

#define SEASIDE_COMMAND_COMPLETED       @"LSCSeasideCommandCompleted"

@interface NSNotificationCenter (LSC)

- (void)postCommandVerb:(NSString *)verb success:(BOOL)success data:(NSDictionary *)data;
- (id)addCommandObserverForVerbs:(NSArray *)verbs block:(void (^)(NSString *verb, BOOL success, NSDictionary *data))block;
- (id)addCommandObserverForVerb:(NSString *)verb block:(void (^)(NSString *verb, BOOL success, NSDictionary *data))block;

@end
