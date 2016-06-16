//
//  LDMResultStub.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 7/28/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem, LDMSchemaField;

@interface LDMResultStub : NSObject

@property NSString *clientId;
@property NSMutableArray *sections;
@property BOOL backgroundFetched;

- (id)initWithDict:(NSDictionary *)rsDict withSectionFields:(NSArray *)fields;
- (BOOL)isStubForItem:(LDMItem *)item;

@end
