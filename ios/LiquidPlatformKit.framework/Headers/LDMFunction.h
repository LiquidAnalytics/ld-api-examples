//
//  LDMFunction.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 6/13/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"
#import "LDMFilter.h"
#import "LDMSearchResultsPaginated.h"

@class LDMQueryFilter, LDMDimension, LDMContext, LDMSearchResults, LDMDefinition;

@interface LDMFunction : LDMItem

@property (nonatomic, strong) NSString *__nonnull functionId;
@property (nonatomic, strong) LDMDimension *__nonnull functionType;
@property (nonatomic, strong) NSString *__nullable functionName;
@property (nonatomic, strong) NSString *__nonnull function;
@property (nonatomic, strong) NSArray *__nullable functionParams;
@property (nonatomic, strong) NSString *__nullable feed;
@property (nonatomic, strong) NSString *__nonnull itemType;
@property (nonatomic, strong) NSString *__nullable storedProcSummary;
@property (nonatomic, strong) NSDictionary *__nullable clientConfig;
@property (readonly) NSString *__nullable selectCore;
@property (readonly) BOOL containsWhere;
@property (readonly) NSString *__nullable tableAlias;
@property (readonly) NSString *__nullable segmentedBy;
@property (readonly) NSString *__nullable orderedBy;
@property (readonly) BOOL orderedDesc;

+ (NSArray *__nullable)resolveParameters:(NSArray *__nullable)parameters withDefaultItem:(LDMItem *__nullable)item withFunctionItem:(LDMFunction *__nullable)functionItem withContext:(LDMContext*__nullable)context;
- (NSString *__nullable)resolveParamsInStatement:(NSString *__nullable)statement withContext:(LDMContext *__nullable)context;

+ (NSArray *__nullable)functionsForFunctionIds:(NSArray *__nonnull)functionIds;
+ (void)functionsForFunctionIds:(NSArray *__nonnull)functionIds withBlock:(void (^__nullable)(LDMSearchResults *__nullable functions))block;

+ (void)allItemsFromFunctionItem:(LDMFunction * __nonnull)functionItem rowLimit:(int) limit withQueryFilter:(LDMQueryFilter * __nullable)queryFilter withBlock:(void (^__nonnull)(LDMSearchResults * __nullable))block withContext:(LDMContext * __nullable)context;

+ (void)allItemsfromFunctionId:(NSString * __nonnull)functionId queryFilter:(LDMQueryFilter * __nullable)queryFilter faultBlocks:(BOOL)faultBlocks context:(LDMContext * __nullable)context completion:(void (^ __nonnull)(LDMSearchResults * __nullable))completion;

+ (void)allItemsFromFunctionItem:(LDMFunction *__nullable)functionItem rowLimit:(int) limit withQueryFilter:(LDMQueryFilter *__nullable)queryFilter faultBlocks:(BOOL) faultBlockFlag withBlock:(void (^ __nullable)(LDMSearchResults *__nullable))block withContext:(LDMContext *__nullable)context;

+ (void)allItemsFromFunctionItem:(LDMFunction *__nullable)functionItem rowLimit:(int) limit withQueryFilter:(LDMQueryFilter *__nullable)queryFilter faultBlocks:(BOOL) faultBlockFlag withBlock:(void (^ __nullable)(LDMSearchResults *__nullable))block withItem:(LDMItem *__nullable)item;

+ (void)allItemsFromFunctionItem:(LDMFunction *__nullable)functionItem rowLimit:(int) limit withQueryFilter:(LDMQueryFilter *__nullable)queryFilter faultBlocks:(BOOL) faultBlockFlag withBlock:(void (^ __nullable)(LDMSearchResults *__nullable))block withItem:(LDMItem *__nullable)item sortBy:(NSString *__nullable)sortBy;

+ (LDMSearchResults * __nullable)allItemsFromFunctionItem:(LDMFunction * __nonnull)functionItem rowLimit:(int) limit withQueryFilter:(LDMQueryFilter * __nullable)queryFilter faultBlocks:(BOOL) faultBlockFlag withItem:(LDMItem * __nullable)item sortBy:(NSString * __nullable)sortBy withContext:(LDMContext * __nullable) context;



- (LDMDefinition *__nullable) clientConfigDefinition;

+ (NSString *__nullable) functionHash:(LDMFunction *__nullable)functionItem rowLimit:(int) limit withQueryFilter:(LDMQueryFilter *__nullable)queryFilter withContext:(LDMContext *__nullable)context;

+ (void)performDataFunction:(LDMFunction *__nullable)functionItem andQueryFilter:(LDMQueryFilter *__nullable)queryFilter completionBlock:(void (^__nullable)(NSError *__nullable error, NSArray *__nullable results))completionBlock;

+ (void)performPaginatedFunction:(LDMFunction *__nullable)functionItem orderBy:(NSString *__nullable)orderBy ascending:(BOOL)ascending andQueryFilter:(LDMQueryFilter *__nullable)queryFilter completionBlock:(void (^__nullable)(NSError *__nullable error, LDMSearchResultsPaginated *__nullable aResults))completionBlock;

+ (void)performPaginatedFunction:(LDMFunction *__nullable)functionItem orderBy:(NSString *__nullable)orderBy ascending:(BOOL)ascending andQueryFilter:(LDMQueryFilter *__nullable)queryFilter withContext:(LDMContext *__nullable)context completionBlock:(void (^__nullable)(NSError *__nullable error, LDMSearchResultsPaginated *__nullable aResults))completionBlock;

+ (void)performPaginatedFunction:(LDMFunction *__nullable)functionItem withPageSize:(int) pageSize orderBy:(NSString *__nullable)orderBy ascending:(BOOL)ascending andQueryFilter:(LDMQueryFilter *__nullable)queryFilter withContext:(LDMContext *__nullable)context completionBlock:(void (^__nullable)(NSError *__nullable error, LDMSearchResultsPaginated *__nullable aResults))completionBlock;

+ (LDMSearchResultsPaginated *__nonnull)performPaginatedFunction:(LDMFunction *__nullable)functionItem withPageSize:(int) pageSize orderBy:(NSString *__nullable)orderBy ascending:(BOOL)ascending andQueryFilter:(LDMQueryFilter *__nullable)queryFilter withContext:(LDMContext *__nullable)context;

+ (void)allItemsFromFunctionItem:(LDMFunction *__nullable)functionItem rowLimit:(int)limit orderBy:(NSString *__nullable)orderBy ascending:(BOOL)ascending withQueryFilter:(LDMQueryFilter *__nullable)queryFilter faultBlocks:(BOOL) faultBlockFlag withBlock:(void (^__nullable)(LDMSearchResults *__nullable))block withContext:(LDMContext *__nullable)context;

+ (void)setDialect:(LDMFilterDialect)dialect onQueryFilter:(LDMQueryFilter *__nullable)queryfilter;

- (BOOL) requiresOnlineData;
- (BOOL) isStoredProcedure;
- (NSString*__nullable) toSql;

@end
