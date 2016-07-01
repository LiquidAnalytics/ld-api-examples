//
//  LDKTextField.h
//  LDCore
//
//  Created by Bryan Nagle on 12/10/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKTextFieldDelegate;

@interface LDKTextField : UITextField

@property (weak) id<LDKTextFieldDelegate> ldkDelegate;

@end

@protocol LDKTextFieldDelegate <NSObject>

@optional

- (void)textFieldWillDelete:(LDKTextField *)textfield;
- (void)textFieldDidDelete:(LDKTextField *)textfield;

@end