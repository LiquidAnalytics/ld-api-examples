//
//  LDMSurvey.h
//  LDCore
//
//  Created by Bryan Nagle on 11/25/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"
#import "LDMDimension.h"

@interface LDMSurvey : LDMItem

@property (nonatomic, strong) NSString *surveyId;
@property (nonatomic, strong) NSString *externalSurveyReference;
@property (nonatomic, strong) NSString *surveyType;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *description;
@property (nonatomic, strong) NSDate *surveyDate;
@property (nonatomic, strong) NSDate *lastUpdated;
@property (nonatomic, strong) NSArray *questions;
@property (nonatomic, strong) NSString *itemType;
@property (nonatomic, strong) NSString *itemId;
@property (nonatomic, strong) NSArray *edges;
@property (nonatomic, strong) NSNumber *mandatorySurvey;
@property (nonatomic, strong) NSDate *validFrom;
@property (nonatomic, strong) NSDate *validTo;
@property (nonatomic, strong) LDMDimension *orgPath;
@property (nonatomic, strong) NSArray *distributionPoints;
@property (nonatomic, strong) NSArray *chains;
@property (nonatomic, strong) NSArray *fmas;
@property (nonatomic, strong) NSArray *divisions;
@property (nonatomic, strong) NSArray *channels;
@end

