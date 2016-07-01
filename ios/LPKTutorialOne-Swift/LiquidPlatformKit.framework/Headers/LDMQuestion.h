//
//  LDMQuestion.h
//  LDCore
//
//  Created by Bryan Nagle on 11/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"
#import "LDMDimension.h"

@interface LDMQuestion : LDMItem

@property (nonatomic, strong) NSString *questionId;
@property (nonatomic, strong) LDMDimension *orgPath;
@property (nonatomic, strong) NSString *question;
@property (nonatomic, strong) NSString *answerType;
@property (nonatomic, strong) LDMDimension *dimensionLevel;
@property (nonatomic, strong) NSArray *adhoc;
@property (nonatomic, strong) NSNumber *min;
@property (nonatomic, strong) NSNumber *max;
@property (nonatomic, strong) NSNumber *step;
@property (nonatomic, strong) NSString *mediaId;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *dimensionFilter;
@property (nonatomic, strong) NSString *itemType;
@property (nonatomic, strong) NSString *itemField;
@property (nonatomic, strong) NSString *edgeType;
@property (nonatomic, strong) id choices;
@property (nonatomic, strong) NSNumber *sortOrder;
@property (nonatomic, strong) NSNumber *required;
@property (nonatomic, strong) NSString *defaultValue;

@end
