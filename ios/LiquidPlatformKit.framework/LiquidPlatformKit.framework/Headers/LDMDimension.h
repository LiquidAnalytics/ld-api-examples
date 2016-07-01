//
//  LDMDimension.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 6/5/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"

@class FMDatabase, LDMQueryFilter;

@interface LDMDimension : LDMItem

@property (nonatomic, readonly, strong) NSString *path;
@property (nonatomic, strong) NSNumber *sortOrder;
@property (nonatomic, strong) NSString *display;
@property (nonatomic, strong) NSString *description;

@property (nonatomic, strong) NSNumber *depth;
@property (nonatomic, strong) NSString *level;
@property (nonatomic, strong) NSString *parent;

@property (readonly) NSString *stringValue;
@property (readonly) NSString *lastMemberValue;
@property (readonly) NSString *parentPath;
@property (nonatomic, strong) NSNumber *childCount;

+ (void)initializeDimensions;
+ (LDMDimension *)dimensionForPath:(NSString *)path;
+ (void)dimensionForPath:(NSString *)path withCompletionHandler:(void (^)(LDMDimension *))completionHandler;
+ (NSArray *)dimensionsForLevel:(NSString *)level;
+ (void)dimensionsForLevel:(NSString *)level withCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSArray *)dimensionsForLevel:(NSString *)level withParent:(LDMDimension *)parent;
+ (void)dimensionsForLevel:(NSString *)level withParent:(LDMDimension *)parent withCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (void)dimensionsForLevel:(NSString *)level withQueryFilter:(LDMQueryFilter *)queryFilter andCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSArray *)dimensionsForLevel:(NSString *)level withParent:(LDMDimension *)parent andQueryFilter:(LDMQueryFilter *)aQueryFilter;
+ (NSArray *)decoratedDimensionsForLevel:(NSString *)level withParent:(LDMDimension *)parent andQueryFilter:(LDMQueryFilter *)aQueryFilter;
+ (LDMDimension *)dimensionForLevel:(NSString *)level withChild:(LDMDimension *)child;
+ (void)dimensionForLevel:(NSString *)level withChild:(LDMDimension *)child withCompletionHandler:(void (^)(LDMDimension *))completionHandler;
+ (NSArray*)childLevelsForParentDimension:(LDMDimension*)parent;
+ (void)childLevelsForParentDimension:(LDMDimension*)parent withCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSArray *)dimensionsForLevels:(NSArray *)levels;

+ (LDMDimension *)dimensionFromCacheForPath:(NSString *)path;

+ (NSArray *)dimensionsForPaths:(NSArray *)paths;
+ (void)dimensionsForPaths:(NSArray *)paths withCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSMutableDictionary *)dimensionByDepthForLevel:(NSString *)level;
+ (NSString *)parentPathForDimension:(LDMDimension *)dimension;

- (id)initManualDimensionWithPath:(NSString *)aPath andDisplay:(NSString *)aDisplay andSortOrder:(NSInteger)aSortOrder;

- (NSArray *)dimensionsFromParentForLevel:(NSString *)level;
- (void)dimensionsFromParentForLevel:(NSString *)level withCompletionHandler:(void (^)(NSArray *))completionHandler;
- (LDMDimension *)dimensionFromChildForLevel:(NSString *)level;

- (BOOL)isEqualToString:(NSString *)string;
- (BOOL)isEqual:(id)other;
- (BOOL)isEqualToDimension:(LDMDimension *)dimension;
- (BOOL)hasLastMemberValue:(NSString *)memberVal;
- (LDMDimension *)parentDimension;

+ (void) dimensionReceived:(LDMDimension *)aDimension inDb:(FMDatabase*)db;
+ (NSString*)levelForComponents:(NSArray*)components;

+ (NSArray *)dimensionsForPaths:(NSArray *)paths queryFilter:(LDMQueryFilter *)queryFilter;
- (BOOL)hasChildren;
- (NSComparisonResult)compare:(LDMDimension *)object;

@end
