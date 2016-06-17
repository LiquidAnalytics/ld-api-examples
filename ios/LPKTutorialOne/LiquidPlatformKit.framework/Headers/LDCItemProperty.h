//
//  LDCItemProperty.h
//  LiquidDecisions
//
//  Created by David Ellis on 2013-07-04.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMItem.h"

@interface LDCItemProperty : LDMItem

@property (strong, nonatomic) NSString *action;
@property (strong, nonatomic) NSString *itemType;
@property (strong, nonatomic) NSString *itemField;
@property (strong, nonatomic) NSString *itemId;
@property (strong, nonatomic) NSString *relationship;
@property (strong, nonatomic) NSString *label;
@property (strong, nonatomic) NSString *editDef;
@property (strong, nonatomic) NSArray *setFields;


@end
