//
//  LDKEditableLabel.h
//  LDCore
//
//  Created by Bryan Nagle on 12/12/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKTextView.h"

@protocol LDKEditableLabelDelegate;

@interface LDKEditableLabel : UIView<UITextViewDelegate, LDKTextViewDelegate>

@property (nonatomic, assign) id<LDKEditableLabelDelegate> ldkDelegate;
@property (assign) BOOL selected;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, weak) NSString *text;
@property (assign) NSTextAlignment textAlignment;
@property (assign) float minFontSize;
@property (strong) NSString *emptyText;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic) UIEdgeInsets textContainerInset;
@property (nonatomic) CGRect textFrame;
@property (nonatomic, assign) BOOL autoPositioningDisabled;

- (BOOL)becomeFirstResponder;
- (CGRect)rectForText;

@end

@protocol LDKEditableLabelDelegate <NSObject>

@optional

- (void)textFieldWillDelete:(LDKEditableLabel *)textfield;
- (void)textFieldDidDelete:(LDKEditableLabel *)textfield;

- (void)editableLabelDidEndEditing:(LDKEditableLabel *)editableLabel;
- (void)editableLabelDidChange:(LDKEditableLabel *)editableLabel;

- (void)setText:(NSString *)aText;
- (NSString *)text;

@end