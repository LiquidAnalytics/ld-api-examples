//
//  LDJsonSerialization.h
//  LDCore
//
//  Created by David Ellis on 11/4/2013.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDMJsonSerialization : NSObject

+ (id __nullable) parseJsonData : (NSData * __nonnull) source;
+ (id __nullable) parseJsonString : (NSString * __nonnull) source;

+ (NSData * __nullable) serializeJsonObjectToData : (id __nonnull) source;
+ (NSString * __nullable) serializeJsonObjectToString : (id __nonnull) source;
+ (NSString * __nullable) serializeJsonObjectToPrettyString : (id __nonnull) source;

@end
