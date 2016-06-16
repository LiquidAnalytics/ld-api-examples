//
//  LDKMultiLineTextCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 1/5/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKEditDetailCollectionViewCell.h"

@class LDMItem;

@interface LDKMultiLineTextCollectionViewCell : LDKEditDetailCollectionViewCell <UITextViewDelegate>

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (assign, nonatomic) BOOL editable;
@property (assign, nonatomic) BOOL hideTitleLabel;

- (void)sizeToFit;

@end
