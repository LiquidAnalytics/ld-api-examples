//
//  LDMSurvey+CircularProgress.h
//  LDCore
//
//  Created by Bryan Nagle on 1/23/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LDMSurvey.h"

@class LDMQuestion;

@interface LDMSurvey (Progress)

- (void)calculateSurveyPercentComplete:(void (^)(float percentComplete))handler forAccount: (NSString *)accountId;
- (BOOL)isQuestion:(LDMQuestion *)question answered:(NSArray *)answers;
@end
