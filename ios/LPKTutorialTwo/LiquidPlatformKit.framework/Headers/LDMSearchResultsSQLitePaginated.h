//
//  LDMSearchResultsPaginated.h
//  LDCore
//
//  Created by Marshall Hayden on 2/11/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMSearchResultsPaginated.h"

@class LDMQueryFilter;

@interface LDMSearchResultsSQLitePaginated : LDMSearchResultsPaginated

- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere orderedBy:(NSString *)orderCol ascending:(BOOL)ascending type:(NSString *)type withQueryFilter:(LDMQueryFilter *)queryFilter isStoredProcedure:(BOOL)storedProcedure;

- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere orderedBy:(NSString *)orderCol ascending:(BOOL)ascending type:(NSString *)type withQueryFilter:(LDMQueryFilter *)queryFilter faultBlocks:(BOOL)faultBlocks isStoredProcedure:(BOOL)storedProcedure;

- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere orderedBy:(NSString *)orderCol ascending:(BOOL)ascending type:(NSString *)type withQueryFilter:(LDMQueryFilter *)queryFilter faultBlocks:(BOOL)faultBlocks withPageSize:(int)pageSize isStoredProcedure:(BOOL)storedProcedure;

- (id)initWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere orderedBy:(NSString *)orderCol ascending:(BOOL)ascending type:(NSString *)type withQueryFilter:(LDMQueryFilter *)queryFilter faultBlocks:(BOOL)faultBlocks withPageSize:(int)pageSize isStoredProcedure:(BOOL)storedProcedure segmentQuery:(NSString *)segmentQueryOrNil;

@end
