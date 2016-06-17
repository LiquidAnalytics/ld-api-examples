//
//  LDKDataGridConfig.h
//  LDCore
//
//  Created by Bryan Nagle on 9/17/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMItem.h"

@interface LDKDataGridColumnConfig : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) NSString *label;
@property (nonatomic, strong) NSString *superColumnLabel;
@property (nonatomic, assign) float width;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, assign) NSTextAlignment textAlignment;
@property (nonatomic, assign) BOOL sortDisabled;
@property (nonatomic, assign) BOOL numericHighlighting;
@property (nonatomic, strong) NSString *type;

+ (LDKDataGridColumnConfig *)config;
+ (LDKDataGridColumnConfig *)configFromItem:(LDMItem *)item;

@end
