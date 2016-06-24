//
//  LDMQueryFilter.h
//  LiquidDataModel
//
//  Created by Eric Johnson on 6/7/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDMQueryFilterClause;
@class LDMItemSchema;
@class LDMFilter;

@interface LDMQueryFilter : NSObject<NSCoding, NSCopying>

@property (nonatomic, strong) NSMutableArray *queryFilterClauses;
@property (readonly) NSArray *allFilters;

+ (LDMQueryFilter *)queryFilterAndFilters:(NSArray *)filters;
+ (LDMQueryFilter *)queryFilterOrFilters:(NSArray *)filters;
+ (LDMQueryFilter *)queryFilter;

/** This method is the preferred way of creating a LDMQueryFilter from a single nested LDMFilter.
 * This method is forwards compatible with upcoming filter consolidation.
 */
+ (LDMQueryFilter *)withFilter:(LDMFilter *)filter;

+ (LDMQueryFilter *)queryFilterWithClauseWithFilters:(NSArray *)filters;
+ (LDMQueryFilter *)queryFilterWithClausesForFilters:(NSArray *)filters;
+ (LDMQueryFilter *)queryFilterFromQueryFilters:(NSArray *)queryFilters;

- (id)initWithQueryFilterClauses:(NSArray *)clauses;
- (id)initWithArray:(NSArray *)newArray;
- (id)initWithJSONString:(NSString *)jsonString;
- (void)addClause:(LDMQueryFilterClause *)clause;
- (void)addClauseWithFilters:(NSArray *)filters;
- (void)addClauseWithFilters:(NSArray *)filters forTableName:(NSString *)tableName;
- (void)addClausesForFilters:(NSArray *)filters;
- (void)addClausesForFilters:(NSArray *)filters forTableName:(NSString *)tableName;
- (void)mergeWith:(LDMQueryFilter *)otherQueryFilter;
- (NSString *)toSql:(LDMItemSchema *)itemSchema;
- (NSArray *)allFilters;
- (BOOL)isEmpty;
- (NSArray *)JSONArray;
- (NSString *)JSONString;
- (void)setTableName:(NSString *)tableName;
- (BOOL)containsFilter:(LDMFilter *)aFilter;

@end
