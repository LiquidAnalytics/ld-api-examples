//
//  LDMSearchResultsAbstractPaginated.h
//  LDCore
//
//  Created by Marshall Hayden on 6/9/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import "LDMSearchResults.h"
#import "LDMItemSchema.h"
#import "LDMFilter.h"

#define QUERY_PAGE_SIZE 250

@class LDMQueryFilter, LDMPageData;

@interface LDMSearchResultsPaginated : LDMSearchResults <LDMSearchResultsProtocol>

@property (strong, nonnull) NSString *selectCore;
@property int pageSize;
@property BOOL faultBlocks;
@property (strong, nonnull) NSMutableDictionary *results;
@property (strong, nullable) NSString *maxPageNameRequested;
@property (strong, nullable) NSString *itemType;
@property (strong, nullable) LDMItemSchema *schema;
@property (strong, nullable) NSString *orderCol;
@property (strong, nullable) NSString *alias;
@property BOOL ascending;
@property (readonly) BOOL didReceiveLastPage;

- (id __nonnull)initWithSelectCore:(NSString * __nullable)selectCore tableAlias:(NSString * __nullable)alias containsWhere:(BOOL)containsWhere orderedBy:(NSString * __nullable)orderCol ascending:(BOOL)ascending type:(NSString * __nullable)type withQueryFilter:(LDMQueryFilter * __nullable)queryFilter faultBlocks:(BOOL)faultBlocks withPageSize:(int)pageSize isStoredProcedure:(BOOL)storedProcedure dialect:(LDMFilterDialect)dialect idField:(NSString * __nullable)idField segmentQuery:(NSString * __nullable)segmentQueryOrNil;

- (BOOL)updateSelectCoreWithQueryFilter:(LDMQueryFilter * __nullable)queryFilter containsWhere:(BOOL)containsWhere tableAlias:(NSString * __nullable)alias;
- (void)page:(LDMPageData * __nullable)page returned:(NSArray * __nullable)data forward:(BOOL)forward;
- (NSString * __nullable)pageNameForSection:(int)section sectionPage:(int)sectionPage;
+ (NSString * __nullable)stringValueForValue:(id __nullable)value;
- (void)collectItems:(void (^__nonnull)(NSArray * __nonnull items))completion;

//Methods to override
- (NSArray * __nullable)dataToItems:(NSArray * __nullable)data;
- (void)executeQuery:(NSString * __nullable)query forPage:(LDMPageData * __nullable)page forward:(BOOL)forward;

@end