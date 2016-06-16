//
//  LDMClientEdgeHelper.h
//  LiquidDataModel
//
//  Created by Eric Johnson on 9/9/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface LDMClientEdgeHelper : NSObject
+ (LDMClientEdgeHelper *)sharedInstance;

- (void)createEdgeOfType:(NSString *)edgeType fromItem:(LDMItem *)fromItem toItem:(LDMItem *)toItem usingMapItemType:(NSString *)mapType;
- (void)createPendingEdgesForChangeSet:(NSDictionary *)changeSet;
@end
