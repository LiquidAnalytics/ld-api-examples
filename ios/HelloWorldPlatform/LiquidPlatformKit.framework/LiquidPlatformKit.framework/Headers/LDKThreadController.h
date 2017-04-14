//
//  LDKThreadController.h
//  LDCore
//
//  Created by Bryan Nagle on 1/15/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDKThreadController : NSObject

@property (strong, nonatomic) dispatch_queue_t queue;

+ (dispatch_queue_t)queue;

@end
