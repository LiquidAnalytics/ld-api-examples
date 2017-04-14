//
//  LDKTextViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/6/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKTextViewCellDelegate;

@interface LDKTextViewCell : UITableViewCell <UITextViewDelegate>

@property (strong) UITextView *textView;
@property (strong) UIButton *disclosureButton;
@property (assign) BOOL showsDiclosureButton;
@property (assign) BOOL isExpanded;
@property (weak) id<LDKTextViewCellDelegate> delegate;

@end

@protocol LDKTextViewCellDelegate <NSObject>

- (void)textViewCell:(LDKTextViewCell *)cell didPressDisclosureButton:(UIButton *)button;

@end