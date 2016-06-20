//
//  LDMSearchResults2.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 7/22/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMSearchResults.h"

#define SPECIAL_LETTER_SEGMENT @"SPECIAL_LETTER_SEGMENT"
#define DYNAMIC_LIMIT 25000
#define FETCH_PAGE_SIZE 100

@class LDMDataManager, LDMQueryFilter;

@interface LDMSearchResultsDynamic : LDMSearchResults <LDMSearchResultsProtocol, NSCacheDelegate>

@property NSString *selectCore;

- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)type faultBlocks:(BOOL)faultBlocks dataManager:(LDMDataManager *)manager withItemWhere: (NSString *) itemWhere withQueryFilter:(LDMQueryFilter *)queryFilter;

- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)type faultBlocks:(BOOL)faultBlocks dataManager:(LDMDataManager *)manager;
- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)type faultBlocks:(BOOL)faultBlocks dataManager:(LDMDataManager *)manager withItemWhere: (NSString *) itemWhere;
- (void)enumerateSection:(NSInteger)section usingBlock:(void (^)(int index, id sectionVal, LDMSchemaField *segmentKey))block;

@end
