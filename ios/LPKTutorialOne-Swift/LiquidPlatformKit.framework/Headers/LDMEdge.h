//
//  LDMEdge.h
//  LDCore
//
//  Created by Bryan Nagle on 12/9/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"

@class LDMDimension;

@interface LDMEdge : LDMItem

@property (nonatomic, strong) LDMDimension *edgeType;
@property (nonatomic, strong) NSString *toType;
@property (nonatomic, strong) NSString *toId;
@property (nonatomic, strong) NSString *toClientId;
@property (nonatomic, strong) NSArray *properties;

@end
