//
//  LDMDataManager+EdgeExtensions.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 7/1/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@class LDMItem;

@interface LDMDataManager (EdgeExtensions)

- (NSArray *)itemsOfType:(NSString *)type fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType orderBy:(NSString*)order;
- (NSArray *)itemsOfType:(NSString *)type toItem:(LDMItem *)toItem usingEdgeItemType:(NSString *)edgeItemType;
- (NSArray *)itemsOfType:(NSString *)type toItem:(LDMItem *)toItem usingEdgeItemType:(NSString *)edgeItemType orderBy: (NSString *)order;

- (void)itemsOfType:(NSString *)type fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
- (void)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
- (void)itemsOfType:(NSString *)type toItem:(LDMItem *)toItem usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
- (NSArray *)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType sortBy:(NSArray *)sortBy;
- (NSArray *)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType dimensionField:(NSString *)dimensionField idField:(NSString *)idFieldName andQueryFilter:(LDMQueryFilter *)qf sortBy:(NSArray *)sortBy;
- (void)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType dimensionField:(NSString *)dimensionField idField:(NSString *)idField andQueryFilter:(LDMQueryFilter *)qf sortBy:(NSArray *)sortBy withCompletionBlock:(void (^)(NSArray *aItems))block;
@end
