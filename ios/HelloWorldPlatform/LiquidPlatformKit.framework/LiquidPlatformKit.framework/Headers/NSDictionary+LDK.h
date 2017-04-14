//
//  NSDictionary+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 9/30/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (LDK)

+ (NSDictionary *)dictionaryFromJsonFile:(NSString *)fileName;
+ (NSDictionary *)dictionaryFromJson:(NSString *)json;
- (id)keyForObject:(id)object;

@end
