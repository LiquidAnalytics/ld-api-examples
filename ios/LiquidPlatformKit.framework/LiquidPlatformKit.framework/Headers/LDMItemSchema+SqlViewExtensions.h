//
//  LDMItemSchema+SqlViewExtensions.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 9/18/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMItemSchema.h"

@interface LDMItemSchema (SqlViewExtensions)

- (NSString *)headerSelectSqlWithTableAlias:(NSString *)tableAlias;
- (NSString *)fieldSelectSqlWithTableAlias:(NSString *)tableAlias;

@end
