//
//  LDMAnswer.h
//  LDCore
//
//  Created by Bryan Nagle on 11/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"
#import "LDMDimension.h"

@interface LDMAnswer : LDMItem

@property (nonatomic, strong) NSString *answerId;
@property (nonatomic, strong) NSString *questionId;
@property (nonatomic, strong) NSString *answerSelection;
@property (nonatomic, strong) LDMDimension *answerDimension;
@property (nonatomic, strong) NSNumber *answerInt;
@property (nonatomic, strong) NSNumber *answerDecimal;
@property (nonatomic, strong) NSString *answerType;
@property (nonatomic, strong) NSDate *answeredAt;
@property (nonatomic, strong) NSString *processStatus;
@property (nonatomic, strong) NSMutableArray *answerMultiSelection;
@end
