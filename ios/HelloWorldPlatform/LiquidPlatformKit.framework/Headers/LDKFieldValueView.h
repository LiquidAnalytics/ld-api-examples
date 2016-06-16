//
//  LDKFieldValueView.h
//  LDCore
//
//  Created by Bryan Nagle on 12/11/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKSwiftEnums.h"

@class LDKFieldValueConfig;
@protocol LDKFieldValueViewDelegate;

@interface LDKFieldValueView : UIView <UITextViewDelegate>

@property (nonatomic, strong) UIColor *keyColor;
@property (nonatomic, strong) UIColor *valueColor;
@property (nonatomic, strong) UIFont *keyFont;
@property (nonatomic, strong) UIFont *valueFont;
@property (nonatomic, strong) UIColor *keyEditableColor;
@property (nonatomic, strong) UIColor *valueEditableColor;
@property (nonatomic, strong) UIFont *keyEditableFont;
@property (nonatomic, strong) UIFont *valueEditableFont;
@property (nonatomic, assign) UIEdgeInsets labelInsets;
@property (nonatomic, assign) UIEdgeInsets pairInsets;
@property (nonatomic, assign) UIEdgeInsets contentInsets;
@property (nonatomic, weak) id<LDKFieldValueViewDelegate> delegate;
@property (nonatomic, strong) UIColor *valueUnderlineColor;
@property (nonatomic, assign) float valueUnderlineWidth;
@property (strong, nonatomic) NSMutableArray *labels;
@property (strong, nonatomic) NSMutableDictionary *valueViewsByIndex;
@property (nonatomic, assign) BOOL editDisabled;
@property (nonatomic, assign) BOOL editing;
@property (assign, nonatomic) LDKDrawerMode drawerMode;
@property (assign, nonatomic) float heightNeeded;

- (void)endEditing;
- (void)underlineView:(UIView *)view withColor:(UIColor *)color;
- (void)reloadFieldValueAtIndex:(NSInteger)index;

@end

@protocol LDKFieldValueViewDelegate <NSObject>

- (NSInteger)numberOfFieldsForFieldValueView:(LDKFieldValueView *)view;
- (LDKFieldValueConfig *)configForFieldAtIndex:(NSInteger)index;
- (void)fieldView:(LDKFieldValueView *)view didChangeValue:(id)value atIndex:(NSInteger)index;
- (void)pushControlForConfig:(LDKFieldValueConfig *)config sender:(UIButton *)sender index:(NSInteger)index;

@optional
- (void)fieldView:(LDKFieldValueView *)view didChangeFirstResponder:(UIView *)firstResponder;
- (void)fieldView:(LDKFieldValueView *)view fieldValueWasTapped:(UIView *)sender config:(LDKFieldValueConfig *)config index:(int)index;

@end