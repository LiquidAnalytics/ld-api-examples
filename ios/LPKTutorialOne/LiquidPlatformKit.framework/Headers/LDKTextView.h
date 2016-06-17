//
//  LDKTextView.h
//  LDCore
//
//  Created by Bryan Nagle on 12/13/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKTextViewDelegate;

@interface LDKTextView : UITextView

@property (weak) id<LDKTextViewDelegate> ldkDelegate;
@property (nonatomic, retain) NSString *placeholder;
@property (nonatomic, retain) UIColor *placeholderColor;

-(void)textChanged:(NSNotification*)notification;

@end

@protocol LDKTextViewDelegate <NSObject>

@optional

- (void)textFieldWillDelete:(LDKTextView *)textfield;
- (void)textFieldDidDelete:(LDKTextView *)textfield;

@end