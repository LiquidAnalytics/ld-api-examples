//
//  LDMQueryFilterClause.h
//  LiquidDataModel
//
//  Created by Eric Johnson on 6/7/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDMFilter;
@class LDMItemSchema;

@interface LDMQueryFilterClause : NSObject<NSCoding, NSCopying>

@property (strong, nonatomic) NSMutableArray *filterArray;
@property (strong) NSString *table;
@property BOOL noTable;

+ (id)clauseWithFilter:(LDMFilter *)filter;
- (id)initWithFilterArray:(NSArray *)filters;
- (id)initWithArray:(NSArray *)newArray;
- (void)addFilter:(LDMFilter *)filter;
- (NSString *)toSql:(LDMItemSchema *)itemSchema;
- (NSArray *)filterDicts;
@end
