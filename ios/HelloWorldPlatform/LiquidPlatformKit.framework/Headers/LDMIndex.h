//
//  LDMIndex.h
//  LiquidDataModel
//
//  Created by Mike Akers on 8/14/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDMIndex : NSObject
@property (strong) NSString *category;
@property (strong) NSString *type;
@property (strong) NSArray *fields;
@property (readonly) NSString *createSQLStatement;

- (id)initWithCategory:(NSString*)category type:(NSString*)type fields:(NSArray*)fields;
@end
