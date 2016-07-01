//
//  LDKKeyValueCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/11/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKEditDetailCollectionViewCell.h"
#import "LDKFieldValueView.h"

@class LDKFieldValueView, LDMItem;

@interface LDKFieldValueCollectionViewCell : LDKEditDetailCollectionViewCell <LDKFieldValueViewDelegate>

@property (weak, nonatomic) LDKFieldValueView *fieldValueView;
@property (assign, nonatomic) BOOL editDisabled;

- (void)refresh;

@end
