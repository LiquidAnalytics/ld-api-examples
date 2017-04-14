//
//  LDKFieldValueConfig.h
//  LDCore
//
//  Created by Bryan Nagle on 12/11/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LDKFieldValueType)
{
    LDKFieldValueTypeText,
    LDKFieldValueTypeButton,
    LDKFieldValueTypeBlank
};

@interface LDKFieldValueConfig : NSObject

@property (strong, nonatomic) NSString *field;
@property (strong, nonatomic) NSString *label;
@property (strong, nonatomic) NSString *value;
@property (strong, nonatomic) NSString *restrictDimensionLevel;
@property (strong, nonatomic) NSString *parentField;
@property (strong, nonatomic) UIColor *textColor;
@property (assign, nonatomic) LDKFieldValueType type;
@property (assign, nonatomic) BOOL editable;

+ (LDKFieldValueConfig *)fieldValueConfig;

@end
