//
//  LDMItem+Edge.h
//  LDCore
//
//  Created by Bryan Nagle on 12/9/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMitem.h"

@class LDMEdge, LDMDimension;

@interface LDMItem (Edge)

+ (NSArray *)edgesForItems:(NSArray *)items edgeType:(id)edgeType fromParent:(LDMItem *)parent;
- (NSArray *)edgesForItems:(NSArray *)items edgeType:(id)edgeType;
- (void)setEdgesForField:(NSString *)field items:(NSArray *)items edgeType:(id)edgeType;
- (void)deleteEdgesForLevel:(NSString *)level withCompletionBlock:(void (^)(BOOL success))completionBlock;
//- (void)addEdgeToItem:(LDMItem *)item;

@end
