//
//  LDKEditableButton.h
//  LDCore
//
//  Created by Bryan Nagle on 12/17/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDCButton.h"
#import "LDKEditableLabel.h"

#define LDKEDITABLE_BUTTON_DELETE_BUTTON_INSET_LEFT                                        10.0f
#define LDKEDITABLE_BUTTON_DELETE_BUTTON_WIDTH                                             22.0f

@protocol LDKEditableButtonDelegate;

@interface LDKEditableButton : LDCButton<LDKEditableLabelDelegate>

@property (nonatomic, assign) BOOL editable;
@property (assign) BOOL deleteHidden;
@property (weak) id<LDKEditableButtonDelegate> ldkDelegate;

@end

@protocol LDKEditableButtonDelegate <NSObject>

@optional

- (void)editableButtonDidEndEditing:(LDCButton *)editableButton;
- (void)editableButtonDidChange:(LDCButton *)editableButton;
- (void)editableButtonDeletePressed:(LDCButton *)editableButton;

@end