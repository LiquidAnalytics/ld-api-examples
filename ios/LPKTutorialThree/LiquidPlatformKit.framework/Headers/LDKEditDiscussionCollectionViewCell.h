//
//  LDKEditDiscussionCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/14/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKEditDetailCollectionViewCell.h"

@interface LDKEditDiscussionCollectionViewCell : LDKEditDetailCollectionViewCell <UITextViewDelegate>

@property (unsafe_unretained, nonatomic) IBOutlet UILabel *titleLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UITextView *textView;

@end
