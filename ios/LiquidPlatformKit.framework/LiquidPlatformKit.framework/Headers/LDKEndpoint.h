//
//  LDKEndpoint.h
//  LDCore
//
//  Created by Bryan Nagle on 3/27/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDKEndpoint : NSObject

+ (id)endPointForName:(NSString *)endPointName;
+ (id)feedBackEmailConfig;

@end
