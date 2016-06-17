//
//  LDKTableViewEventCell.h
//  LDCore
//
//  Created by Bryan Nagle on 9/19/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGSwipeTableCell.h"

@class MGSwipeTableCell;

@protocol LDKTableViewEventCellDelegate;

@interface LDKTableViewEventCell : MGSwipeTableCell

@property (nonatomic, weak) id<LDKTableViewEventCellDelegate> delegate;
@property (nonatomic, strong) UITouch *lastTouch;

- (void)setStateSelected:(BOOL)selected animated:(BOOL)animated;
- (void)setStateHighlighted:(BOOL)highlighted animated:(BOOL)animated;

@end

@protocol LDKTableViewEventCellDelegate <NSObject>

@optional

- (BOOL)cell:(LDKTableViewEventCell *)cell shouldChangeSelected:(BOOL)selected;
- (BOOL)cell:(LDKTableViewEventCell *)cell shouldChangeHighlighted:(BOOL)highlighted;
- (void)cell:(LDKTableViewEventCell *)cell didChangeSelected:(BOOL)selected;
- (void)cell:(LDKTableViewEventCell *)cell didChangeHighlighted:(BOOL)highlighted;

@end