//
//  LDMAnswers.h
//  LDCore
//
//  Created by Bryan Nagle on 11/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"
#import "LDMDimension.h"

@interface LDMAnswers : LDMItem

@property (nonatomic, strong) NSString *answersId;
@property (nonatomic, strong) NSString *accountId;
@property (nonatomic, strong) NSString *surveyId;
@property (nonatomic, strong) NSArray *answers;
@property (nonatomic, strong) NSString *processStatus;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSDate *submittedAt;

@end
