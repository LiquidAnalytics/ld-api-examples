//
//  LDMAnswer+Survey.h
//  LDCore
//
//  Created by Bryan Nagle on 11/27/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMAnswer.h"

@class LDMQuestion;

@interface LDMAnswer (Survey)

- (NSString *)stringValue;
- (BOOL)setDefaults:(LDMQuestion *)question;

@end
