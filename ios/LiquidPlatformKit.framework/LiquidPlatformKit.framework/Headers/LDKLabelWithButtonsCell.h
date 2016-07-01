//
//  LDKLabelWithButtonsCell.h
//  LDCore
//
//  Created by Bryan Nagle on 2/12/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKLabelWithButtonsCellDelegate;

@interface LDKLabelWithButtonsCell : UITableViewCell

@property (assign) float buttonSpacing;
@property (strong) NSMutableArray *buttons;
@property (nonatomic, copy) void (^cellDidLoadBlock)(LDKLabelWithButtonsCell *cell);
@property (weak) id<LDKLabelWithButtonsCellDelegate> ldkDelegate;
@property (assign) BOOL hideButtonsWhenNotSelected;

- (void)addButtonWithTitle:(NSString *)title;
- (void)addButtonWithTitle:(NSString *)title andEventHandler:(void (^)(LDKLabelWithButtonsCell *cell, UIButton *button, NSInteger index))handler;
- (void)removeButtonAtIndex:(NSInteger)index;
- (void)setButtonsHidden:(BOOL)hidden;

@end

@protocol LDKLabelWithButtonsCellDelegate <NSObject>

@optional

- (void)labelWithButtonsCellDidLoad:(LDKLabelWithButtonsCell *)cell;
- (void)labelWithButtonsCell:(LDKLabelWithButtonsCell *)cell buttonTapped:(UIButton *)button atIndex:(NSInteger)index;

@end