//
//  NSThread+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 2/18/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSThread (LDK)

+ (void)backgroundAsyncWithBlock:(void (^)())block;
+ (void)performConcurrentAsyncTasks:(NSArray *)tasks completion:(void (^)())completion;

@end
