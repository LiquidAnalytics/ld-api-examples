//
//  LDMDataManager+SearchAsync.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 8/7/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@class LDMSearchResults;
@class LDMSearchResultsOnline;
@class LDMContext;
@class LDMFunction;
@class LDMSearchResultsSQLitePaginated;
@class LDMQueryFilter;
@class LDMSchemaField;

#define MAX_RETRIES 10
#define MIN_RETRY_TIME 500
#define MAX_RETRY_TIME 10000

#define POST_PARAM_ITEM_JSON_KEY    @"cartJson"

typedef NS_ENUM(NSUInteger, LDMOnlineQuerySearchHint)
{
    LDMOnlineQuerySearchNext,
    LDMOnlineQuerySearchPrev
};


@interface LDMDataManager (SearchAsync)

- (void)searchItemsOfType:(NSString *)typeName withQueryFilter:(LDMQueryFilter *)queryFilter segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol faultBlocks:(BOOL)faultBlocks withCompletionHandler:(void (^)(LDMSearchResults *results))completionHandler;

- (void)searchItemsWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)typeName faultBlocks:(BOOL)faultBlocks withCompletionHandler:(void (^)(LDMSearchResults *results))completionHandler;

- (void)searchItemsWithSelectCore:(NSString *)selectCore tableAlias:(NSString *)alias containsWhere:(BOOL)containsWhere segmentedBy:(NSArray *)segmentKeys orderedBy:(NSString *)orderCol type:(NSString *)typeName faultBlocks:(BOOL)faultBlocks withItemWhere: (NSString *) itemWhere withCompletionHandler:(void (^)(LDMSearchResults *results))completionHandler;

- (void)onlineRequestForCartShare:(LDMItem*)cart withCompletionBlock:(void (^)(id results ,NSURL* url))completionBlock;

-(void) onlineRequestForCartPreview:(LDMItem*)cart withCompletionBlock:(void (^)(id results ,NSURL* url))completionBlock;

- (void)onlineRequestForDeviceItemPreview:(LDMItem*)deviceItem withCompletionBlock:(void (^)(id results ,NSURL* url))completionBlock;

- (void) onlineRequestForDeltaHistoryForItem:(LDMItem*)item forFields:(NSArray*)fields withQueryFilter:queryFilter withCompletionBlock:(void (^)(id results ,NSURL* url))completionBlock;

- (LDMSearchResultsOnline *)onlineQueryFromFunctionItem:(LDMFunction *)functionItem queryFilter:(LDMQueryFilter *)queryFilter context:(LDMContext *)context;

- (LDMSearchResultsOnline *)onlineQueryForRTFunctionItem:(LDMFunction *)functionItem orderBy:(NSString *)orderBy ascending:(BOOL)ascending faultBlocks:(BOOL)faultBlocks context:(LDMContext *)context;

- (void) onlinePostRedirectGetForFunctionItem:(LDMFunction*) functionItem withContext:(LDMContext*) context withCompletionBlock:(void (^)(NSString*  error ,NSURL *redirectUrl, BOOL useExternalBrowser))completionBlock;

- (LDMSearchResultsOnline *)onlineQueryFromFunctionItem:(LDMFunction *)functionItem queryFilter:(LDMQueryFilter *)queryFilter orderBy:(NSString *)orderBy ascending:(BOOL)ascending context:(LDMContext *)context;

- (void) onlineRequestForExternalService:(NSString*) baseURL withCredentials:(NSDictionary*)credentials withPostParams: params shouldParseResponse: (BOOL) parseResponse withCompletionBlock:(void (^)(id results ,NSURL* url))completionBlock;

#pragma mark --SQLitePaginated API--

- (LDMSearchResultsSQLitePaginated *)searchItemsFromSQLiteOfType:(NSString *)typeName withQueryFilter:(LDMQueryFilter *)queryFilter orderedBy:(NSString *)orderCol faultBlocks:(BOOL)faultBlocks;
- (LDMSearchResultsSQLitePaginated *)itemsFromSQLiteWithRelationNamed:(NSString *)relationshipPaths toItem:item withQueryFilter:(LDMQueryFilter *)queryFilter orderBy:(NSString *)orderCol orderDesc:(BOOL)orderDesc faultBlocks:(BOOL)faultBlocks;

@end
