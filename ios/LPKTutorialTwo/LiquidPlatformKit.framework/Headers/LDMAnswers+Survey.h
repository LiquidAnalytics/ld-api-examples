//
//  LDMAnswers+Survey.h
//  LDCore
//
//  Created by Bryan Nagle on 11/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMAnswers.h"

@class LDMAnswer;

@interface LDMAnswers (Survey)

- (LDMAnswer *)answerForQuestionId:(NSString *)questionId;
- (void)populateAnswersForQuestions:(NSArray *)questions;

@end
