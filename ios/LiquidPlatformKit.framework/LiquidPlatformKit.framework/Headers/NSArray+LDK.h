//
//  NSArray+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 9/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface NSArray (LDK)

- (NSArray *)objectsOfClass:(Class)class;
- (BOOL)containsAnyObjectInArray:(NSArray *)array;
- (void)paginateWithPageSize:(NSInteger)pageSize pageBlock:(void (^)(NSArray *objectPage))block;
- (NSUInteger)indexOfItemWithField:(NSString *)field andValue:(id)value;
- (LDMItem *)itemWithField:(NSString *)field andValue:(id)value;
- (NSArray *)itemsWithField:(NSString *)field andValue:(id)value;
- (LDMRelationshipSchema *)relationshipWithName:(NSString *)name;
- (NSArray *)sortedArrayUsingField:(NSString *)field andValues:(NSArray *)values;
- (NSString*) stringWithQuotationsAndCommasForArray:(NSString*) field;
+ (NSArray *)arrayOfClassNames:(NSArray *)classes;
- (NSArray *)valuesForField:(NSString *)field;
- (NSArray *)arrayByFlatteningArrayofArrays;
- (id)lastObjectByMatchingPredicate:(NSPredicate *)predicate;
- (NSDictionary *)collateItemsByField:(NSString *)field;
- (BOOL)containsDimension:(LDMDimension *)aDimension;

@end
