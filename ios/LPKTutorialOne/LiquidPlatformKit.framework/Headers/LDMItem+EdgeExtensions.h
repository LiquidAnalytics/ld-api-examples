//
//  LDMItem+EdgeExtensions.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 6/25/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"

typedef enum {
    LDMEdgeModeTo,
    LDMEdgeModeFrom
} LDMEdgeMode;

@class LDMDimension;
@class LDMQueryFilter;

@interface LDMItem (EdgeExtensions)


+ (LDMItem *)blockEdgeforItem:(LDMItem *)item onParentItem:(LDMItem *)parentItem withEdgeType:(NSString *)edgeType;

+ (NSArray *)itemsOfType:(NSString *)type usingEdgeField:(NSString *)edgeField onItem:(LDMItem *)item;
- (NSArray *)itemsOfType:(NSString *)type usingEdgeField:(NSString *)edgeField;


+ (NSArray *)itemsOfType:(NSString *)type toItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType orderBy: (NSString *)order;

+ (NSArray *)itemsOfCompositeType:(NSString *)type usingBaseType:(NSString *)baseItemType andBaseItemPrimaryField:(NSString *)field fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType;

+ (void)itemsOfCompositeType:(NSString *)type usingBaseType:(NSString *)baseItemType andBaseItemPrimaryField:(NSString *)field fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType withCompletionHandler:(void (^)(NSArray *aItems))completionHandler;

+ (NSArray *)itemsOfType:(NSString *)type fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType orderBy:(NSString*) order;

+ (void)itemsOfType:(NSString *)type fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
+ (void)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
//+ (NSArray *)itemsOfType:(NSString *)type toItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType;
+ (void)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType dimensionField:(NSString *)dimensionField idField:(NSString *)idField queryFilter:(LDMQueryFilter *)qf sortBy:(NSArray *)sortBy withCompletionBlock:(void (^)(NSArray *aItems))block;

+ (NSArray *)itemsOfType:(NSString *)type fromEdges:(NSArray *)edges withMode:(LDMEdgeMode)mode;
+ (NSArray *)edgeItemsOfType:(NSString *)edgeItemType fromItem:(LDMItem *)fromItem toType:(NSString *)toType;
+ (NSArray *)edgeItemsOfType:(NSString *)edgeItemType toItem:(LDMItem *)toItem fromType:(NSString *)fromType;

+ (NSArray *)edgeItemsOfType:(NSString *)edgeItemType fromItem:(LDMItem *)fromItem;
+ (LDMItem *)mapItemForEdgeFromItem:(LDMItem *)fromItem toItem:(LDMItem *)toItem usingMapItemType:(NSString *)mapItemType withEdgeType:(NSString *)edgeType;
+ (LDMItem *)mapItemForDimensionEdgeFromItem:(LDMItem *)fromItem toDimension:(LDMDimension *)dimension usingMapItemType:(NSString *)mapItemType withEdgeType:(NSString *)edgeType;

+ (void)dimensionsFromEdgesForItem:(LDMItem *)item withCompletionHandler:(void (^)(NSArray *))completionHandler;

+ (NSArray *)itemsOfType:(NSString *)type fromType:(NSString *)fromType fromItem:(LDMItem *)fromItem usingEdgeItemType:(NSString *)edgeItemType dimensionField:(NSString *)dimensionField idField:(NSString *)idField queryFilter:(LDMQueryFilter *)qf sortBy:(NSArray *)sortBy;

+ (NSArray *)dimensionPathsFromEdgesOfItemType:(NSString *)edgeItemType fromItem:(LDMItem *)fromItem withEdgeType:(id)edgeType;
+ (void)dimensionsFromEdgesForItem:(LDMItem *)item andEdgeType:(id)edgeType withCompletionHandler:(void (^)(NSArray *))completionHandler;
+ (NSArray *)dimensionEdgesFromItem:(LDMItem *)fromItem;

- (void)itemsOfType:(NSString *)type usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
- (void)itemsOfType:(NSString *)type fromType:(NSString *)fromType usingEdgeItemType:(NSString *)edgeItemType withCompletionBlock:(void (^)(NSArray *aItems))block;
- (void)itemsOfType:(NSString *)type fromType:(NSString *)fromType usingEdgeItemType:(NSString *)edgeItemType dimensionField:(NSString *)dimensionField idField:(NSString *)idField queryFilter:(LDMQueryFilter *)qf sortBy:(NSArray *)sortBy withCompletionBlock:(void (^)(NSArray *aItems))block;

- (NSArray *)edgeItemsOfType:(NSString *)edgeItemType;
- (NSArray *)edgeItemsOfType:(NSString *)edgeItemType toType:(NSString *)toType;
- (NSArray *)edgeItemsOfType:(NSString *)edgeItemType fromType:(NSString *)fromType;

- (LDMItem *)mapItemForEdgeToItem:(LDMItem *)item usingMapItemType:(NSString *)mapItemType withEdgeType:(NSString *)edgeType;
- (LDMItem *)mapItemForEdgeFromItem:(LDMItem *)item usingMapItemType:(NSString *)mapItemType withEdgeType:(NSString *)edgeType;
- (LDMItem *)mapItemForDimensionEdgeToDimension:(LDMDimension *)dimension usingMapItemType:(NSString *)mapItemType withEdgeType:(NSString *)edgeType;

- (void)dimensionsFromEdgesWithCompletionHandler:(void (^)(NSArray *))completionHandler;

- (NSArray *)itemsOfType:(NSString *)type fromType:(NSString *)fromType usingEdgeItemType:(NSString *)edgeItemType dimensionField:(NSString *)dimensionField idField:(NSString *)idField queryFilter:(LDMQueryFilter *)qf sortBy:(NSArray *)sortBy;

+ (NSArray *)itemsOfType:(NSString *)itemType forDimensions:(NSArray *)dimensions onField:(NSString *)field;

+ (NSArray *)dimensionPathsFromEdgesOfItemType:(NSString *)edgeItemType fromItem:(LDMItem *)fromItem;

+ (NSArray *)edgeItemsOfType:(NSString *)edgeItemType withEdgeType:(NSString *)edgeType forItemIds:(NSArray *)itemIds;
+ (void)dimensionsFromEdgesForItem:(LDMItem *)item andEdgeType:(id)edgeType queryFilter:(LDMQueryFilter *)queryFilter withCompletionHandler:(void (^)(NSArray *))completionHandler;

@end
