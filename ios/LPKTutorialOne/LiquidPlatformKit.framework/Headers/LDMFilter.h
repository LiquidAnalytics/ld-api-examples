//
//  LDMFilter.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 5/14/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LDMFilterComparison) {
    LDMFilterComparisonGreaterThan,
    LDMFilterComparisonGreaterThanOrEqualTo,
    LDMFilterComparisonLessThan,
    LDMFilterComparisonLessThanOrEqualTo,
    LDMFilterComparisonLike,
    LDMFilterComparisonLikeMatchStart,
    LDMFilterComparisonLikeMatchEnd,
    LDMFilterComparisonLikeMatchValuePrefix,
    LDMFilterComparisonEquals,
    LDMFilterComparisonNotEquals,
    LDMFilterComparisonIn DEPRECATED_ATTRIBUTE = LDMFilterComparisonEquals,
    LDMFilterComparisonNotIn DEPRECATED_ATTRIBUTE = LDMFilterComparisonNotEquals,
    LDMFilterComparisonIsNull,
    LDMFilterComparisonIsNotNull
};

typedef NS_ENUM(NSUInteger, LDMFilterDialect)
{
    LDMFilterDialectSQLite,
    LDMFilterDialectPostgreSQL
};

typedef NS_ENUM(NSUInteger, LDMFilterConjunction) {
    LDMFilterConjunctionOr,
    LDMFilterConjunctionAnd
};

@class LDMItemSchema, LDMSchemaField;

@interface LDMFilter : NSObject<NSCopying>

#define wildCardSequence @"~_MATCH_WILDCARD_~"

@property (strong, nullable) LDMSchemaField *fieldSchema;
@property (strong, nullable) NSString *field;
@property (strong, nullable) NSString *blockField;
@property (strong, nullable) id value;
@property (strong, nullable) NSString *type;
@property LDMFilterComparison comparison;
@property BOOL andOnly;
@property (strong, nullable) NSString *friendlyValue; // The text string associated with that value (dimension name, for instance)
@property (strong, nullable) NSString *displayLabel;
@property BOOL dimensionHasBeenResolved;
@property BOOL isSearchFilter;
@property BOOL noIndex;
@property BOOL trim;
@property BOOL preQuoted;
@property BOOL disableTableName;
@property LDMFilterDialect dialect;
@property LDMFilterConjunction conjunction;
@property (strong, nullable) NSMutableArray *subFilters;
@property (strong, nullable) NSString *tableName;

+ (nonnull instancetype)andFilter;
+ (nonnull instancetype)andFilter:(NSArray<LDMFilter*>*__nonnull)filters;
+ (nonnull instancetype)orFilter;
+ (nonnull instancetype)orFilter:(NSArray<LDMFilter*>*__nonnull)filters;
+ (nonnull instancetype)andFilterWithField:(NSString *__nonnull)aField value:(id __nullable)aValue comparison:(LDMFilterComparison) aComparison;
+ (nonnull instancetype)orFilterWithField:(NSString *__nonnull)aField value:(id __nullable)aValue comparison:(LDMFilterComparison) aComparison;
+ (nonnull instancetype)filterWithField:(NSString *__nonnull)aField value:(id __nullable)aValue comparison:(LDMFilterComparison) aComparison;
- (void) add:(LDMFilter *__nonnull)subFilter;
- (NSString *__nonnull)toSql:(LDMItemSchema *__nullable)itemSchema tableName:(NSString *__nullable)tableName;
+ (nonnull instancetype)betweenFilterWithField:(NSString *__nonnull)aField lowValue:(id __nonnull)lowValue highValue:(id __nonnull)highValue;

- (nonnull id)initWithField:(NSString *__nonnull)aField value:(id __nullable)aValue comparison:(LDMFilterComparison) aComparison resolvedDimension:(BOOL)aDimensionHasBeenResolved preQuoted:(BOOL)aPreQuoted;
- (nonnull id)initWithField:(NSString *__nonnull)aField value:(id __nullable)aValue comparison:(LDMFilterComparison) aComparison resolvedDimension:(BOOL)aDimensionHasBeenResolved;
- (nonnull id)initWithField:(NSString *__nonnull)aField value:(id __nullable)aValue comparison:(LDMFilterComparison) aComparison;
- (nonnull id)initWithDict:(NSDictionary *__nonnull)dict;
- (NSDictionary *__nonnull)dictionaryFromFilter;
- (NSString *__nullable)tableAlias;
- (NSDictionary *__nullable)kvPairFromFilter;
- (BOOL)isEqualToFilter:(LDMFilter *__nullable)filter;

+ (NSString *__nonnull)sqlCompareStringForComparison:(LDMFilterComparison) comparison;
+ (LDMFilterComparison)comparisonforName:(NSString *__nonnull)name;
+ (NSString *__nullable)stringValueFor:(id __nullable)value;

- (BOOL)matchesItem:(LDMItem *__nonnull)item;

@end
