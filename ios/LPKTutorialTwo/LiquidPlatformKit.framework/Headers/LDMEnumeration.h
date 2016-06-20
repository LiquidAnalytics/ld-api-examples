//
//  LDMEnumeration.h
//  LDCore
//
//  Created by Marshall Hayden on 8/28/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMItem.h"

@class LDMDimension, LDMQueryFilter, FMDatabase;

@interface LDMEnumeration : LDMItem

@property (strong) NSString *name;
@property (strong) NSString *element;
@property (strong) NSString *parent;
@property (strong) NSString *parentElement;
@property (strong) NSString *display;
@property (strong) NSNumber *sortOrder;

@property (readonly) NSString *stringValue;
@property (readonly) LDMEnumeration *parentEnumeration;

#pragma mark Deprecated methods for LDMDimension compatibility - remove these once they are not called
@property (readonly) NSString *path;
@property (readonly) NSString *description;
@property (readonly) NSNumber *depth;
@property (readonly) NSString *level;
@property (readonly) NSString *lastMemberValue;
@property (readonly) NSString *parentPath;
@property (readonly) NSNumber *childCount;

+ (LDMEnumeration *)enumerationNamed:(NSString *)name element:(NSString *)element;
+ (void)enumerationNamed:(NSString *)name element:(NSString *)element withCompletionHandler:(void (^)(LDMEnumeration *))completionHandler;

+ (NSArray *)enumerationsNamed:(NSString *)name;
+ (void)enumerationsNamed:(NSString *)name withCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSArray *)enumerationsNamed:(NSString *)name withQueryFilter:(LDMQueryFilter *)aQueryFilter;

+ (NSArray *)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent;
+ (void)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent withCompletionHandler:(void (^)(NSArray *))completionHandler;

+ (NSArray *)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent withChildrenNamed:(NSString *)childName;
+ (void)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent withChildrenNamed:(NSString *)childName withCompletionHandler:(void (^)(NSArray *))completionHandler;

+ (NSArray *)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent withChildrenNamed:(NSString *)childName andQueryFilter:(LDMQueryFilter *)aQueryFilter;
+ (void)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent withChildrenNamed:(NSString *)childName andQueryFilter:(LDMQueryFilter *)aQueryFilter withCompletionHandler:(void (^)(NSArray *))completionHandler;

+ (void)enumerationsNamed:(NSString *)name withQueryFilter:(LDMQueryFilter *)queryFilter andCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSArray *)enumerationsNamed:(NSString *)name withParent:(LDMEnumeration *)parent andQueryFilter:(LDMQueryFilter *)aQueryFilter;

+ (NSArray *)enumerationsNamed:(NSString *)name withQueryFilter:(LDMQueryFilter *)aQueryFilter fromType:(NSString *)itemType fromField:(NSString *)fieldName withTypeQueryFilter:(LDMQueryFilter *)typeQueryFilter;
+ (void)enumerationsNamed:(NSString *)name withQueryFilter:(LDMQueryFilter *)aQueryFilter fromType:(NSString *)itemType fromField:(NSString *)fieldName withTypeQueryFilter:(LDMQueryFilter *)typeQueryFilter withCompletionHandler:(void (^)(NSArray *))completionHandler;

+ (NSArray*)childNamesForParentEnumeration:(LDMEnumeration *)parent;
+ (void)childNamesForParentEnumeration:(LDMEnumeration *)parent withCompletionHandler:(void (^)(NSArray *))completionHandler;

+ (NSArray *)enumerationsNamed:(NSString *)name withElements:(NSArray *)elements;
+ (void)enumerationsNamed:(NSString *)name withElements:(NSArray *)elements withCompletionHandler:(void (^)(NSArray *))completionHandler;

- (NSArray *)enumerationsFromParentNamed:(NSString *)name;
- (void)enumerationsFromParentNamed:(NSString *)name withCompletionHandler:(void (^)(NSArray *))completionHandler;
- (NSArray *)dimensionsFromParentForLevel:(NSString *)level;
- (void)dimensionsFromParentForLevel:(NSString *)level withCompletionHandler:(void (^)(NSArray *))completionHandler;

- (LDMEnumeration *)enumerationFromChildNamed:(NSString *)name;
- (void)enumerationFromChildNamed:(NSString *)name withCompletionHandler:(void (^)(LDMEnumeration *))completionHandler;
- (LDMEnumeration *)dimensionFromChildForLevel:(NSString *)level;
- (void)dimensionFromChildForLevel:(NSString *)level withCompletionHandler:(void (^)(LDMEnumeration *))completionHandler;

- (BOOL)isEqualToString:(NSString *)string;
- (BOOL)isEqual:(id)other;
- (BOOL)isEqualToDimension:(LDMDimension *)dimension;
- (BOOL)isEqualToEnumeration:(LDMEnumeration *)enumeration;
- (BOOL)hasLastMemberValue:(NSString *)memberVal;
- (LDMEnumeration *)parentDimension;

+ (void) enumerationReceived:(LDMEnumeration *)enumeration;
+ (void) enumerationReceived:(LDMEnumeration *)enumeration inDb:(FMDatabase*)db;

- (BOOL)hasChildren;

+ (NSString *)elementFor:(id)enumeration;

@end
