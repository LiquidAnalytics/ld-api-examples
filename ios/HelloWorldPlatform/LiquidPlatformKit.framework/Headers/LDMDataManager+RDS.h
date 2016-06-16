//
//  LDMDataManager+RDS.h
//  LDCore
//
//  Created by Marshall Hayden on 10/29/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"
#import "LDMSearchResultsRDSPaginated.h"

@interface LDMDataManager (RDS)

- (NSURL * __nullable)lsSqlUrl;

- (void)executeRDSQuery:(NSString * __nonnull)query callback:(void (^ __nonnull)(NSArray *  __nullable results, BOOL success, NSError * __nullable error))callback;
- (void)executeRDSQuery:(NSString * __nullable)query itemType:(NSString * __nullable)itemType faultBlocks:(BOOL)faultBlocks callback:(void (^ __nullable)(NSArray * __nullable results, BOOL success, NSError * __nullable error))callback;
- (void)itemFromRDSofType:(NSString * __nullable)itemType withId:(NSString * __nullable)itemId faultBlocks:(BOOL)faultBlocks callback:(void (^ __nullable)(LDMItem * __nullable result, BOOL success, NSError * __nullable error))callback;
- (void)itemFromRDSofType:(NSString * __nullable)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter sortBy:(NSArray * __nullable)sortBy faultBlocks:(BOOL)faultBlocks callback:(void (^ __nullable )(LDMItem * __nullable result, BOOL success, NSError * __nullable error))callback;
- (void)allItemsFromRDSofType:(NSString * __nullable)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter sortBy:(NSArray * __nullable)sortBy faultBlocks:(BOOL)faultBlocks callback:(void (^ __nullable )(NSArray * __nullable results, BOOL success, NSError * __nullable error))callback;
- (LDMSearchResultsRDSPaginated * __nullable)searchItemsFromRDSOfType:(NSString * __nullable)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter orderedBy:(NSString * __nullable)orderCol faultBlocks:(BOOL)faultBlocks;
- (LDMSearchResultsRDSPaginated * __nullable)itemsFromRDSWithRelationNamed:(NSString * __nullable)relationshipPaths toItem:item withQueryFilter:(LDMQueryFilter * __nullable)queryFilter orderBy:(NSString * __nullable)orderCol orderDesc:(BOOL)orderDesc faultBlocks:(BOOL)faultBlocks;

@end
