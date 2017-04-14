//
//  LDMDataManager+Search.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 8/4/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@class LDMSearchResults;
@class LDMSearchResultsOnline;
@class LDMContext;


@interface LDMDataManager (Search)

- (LDMSearchResults *)searchItemsWithSelectCore:(NSString *)selectCore queryFilter:(LDMQueryFilter *)queryFilter tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)typeName faultBlocks:(BOOL)faultBlocks;

- (LDMSearchResults *)searchItemsOfType:(NSString *)typeName withQueryFilter:(LDMQueryFilter *)queryFilter segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol faultBlocks:(BOOL)faultBlocks;

- (LDMSearchResults *)searchItemsWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)typeName faultBlocks:(BOOL)faultBlocks;
- (LDMSearchResults *)searchItemsWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)typeName faultBlocks:(BOOL)faultBlocks withItemWhere: (NSString* ) itemWhere;

- (void)executeItemSearchSynchronous:(NSString*)sql usingItemSchema:(LDMItemSchema*)itemSchema enumerateResultsUsingBlock:(void (^)(LDMItem*))block;

- (void)executeSearchSynchronous:(NSString*)query enumerateResultsUsingBlock:(void (^)(NSDictionary*))block;

- (NSInteger)executeCountForItemsOfType:(NSString *)type;
- (NSInteger)executeCountForItemsOfType:(NSString *)type withQueryFilter:(LDMQueryFilter *)queryFilter;

- (NSString *)executeLastUpdateForItemsOfType:(NSString *)type;

/** Exposed for test cases only. Do not call directly. */
- (NSString *)selectCoreForItemsOfType:(NSString *)typeName withQueryFilter:(LDMQueryFilter *)queryFilter containsWhere:(NSNumber **)containsWhere;



@end
