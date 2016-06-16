//
//  NSArray+LDMItemExtensions.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 5/14/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface NSArray (LDMItemExtensions)

- (NSData *)toItemsJson;
- (NSData *)toItemsJsonString;
- (NSArray *)toItemsArray;
- (void)splitInHalfWithBlock:(void (^)(NSArray *array1, NSArray *array2))block;

@end
