//
//  LDKSetField.h
//  LDCore
//
//  Created by CARSON LI on 2015-03-17.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"

@interface LDKSetField : LDMItem

@property (strong) NSString *field;
@property (strong) NSString *statement;
@property (strong)  NSNumber *isPrimary;

@end
