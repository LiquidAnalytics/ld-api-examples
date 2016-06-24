//
//  NSInvocation+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 3/31/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSInvocation (LDK)

+ (id)performSelector:(SEL)sel target:(id)target arguments:(NSArray *)arguments;

@end
