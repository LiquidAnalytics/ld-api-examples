//
//  LDCThreadLocal.h
//  LDCore
//
//  Created by Marshall Hayden on 8/19/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDCThreadLocal : NSObject

@property (readonly) id get;

+ (id)threadLocalWithInitialValueBlock:(id (^)())initialValue;

@end
