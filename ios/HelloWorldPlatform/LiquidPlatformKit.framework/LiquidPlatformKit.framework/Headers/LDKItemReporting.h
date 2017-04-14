//
//  LDKItemReporting.h
//  LDCore
//
//  Created by CARSON LI on 2015-03-17.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"

@interface LDKItemReporting : LDMItem

@property NSString *itemType;
@property NSString *action;
@property NSString *reportType;
@property NSArray *reportFields;
@property NSArray *criteriaFields;
@property NSNumber *sendDuplicates;
@property NSNumber *geoLocate;

@end
