//
//  LDKDataGridCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/12/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKEditDetailCollectionViewCell.h"
#import "LDKNewDataGridView.h"

@class LDMItem, LDMQueryFilter, LDMDataGridStyle;

@interface LDKDataGridCollectionViewCell : LDKEditDetailCollectionViewCell <LDKNewDataGridViewDelegate>

@property (nonatomic, strong) LDMItem *dataGridDef;
@property (nonatomic, strong) LDMDataGridStyle *dataGridStyle;
@property (nonatomic, strong) LDMQueryFilter *filter;
@property (nonatomic, strong) LDMQueryFilter *search;
@property (unsafe_unretained, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet LDKNewDataGridView *dataGridView;
@property (nonatomic, strong) NSString *functionId;

@end
