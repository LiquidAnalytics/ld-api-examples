//
//  LDKNewDataGridView.h
//  LDCore
//
//  Created by Bryan Nagle on 9/17/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKTableViewEventCell.h"
#import "LDKPullToRefreshEventView.h"
#import "LDKColumnSort.h"

typedef NS_ENUM(int, LDKDataGridTableView)
{
    LDKDataGridTableViewMultiSelect,
    LDKDataGridTableViewDelete,
    LDKDataGridTableViewLocked,
    LDKDataGridTableViewMain,
    LDKDataGridTableViewCount
};

@class LDKDataGridColumnConfig;

@protocol LDKNewDataGridViewDelegate;

@interface LDKNewDataGridView : UIView <UITableViewDelegate, UITableViewDataSource, LDKTableViewEventCellDelegate, LDKPullToRefreshEventViewDelegate>

@property (nonatomic, weak) id <LDKNewDataGridViewDelegate> delegate;
@property (nonatomic, strong) NSMutableArray *tableViews;
@property (nonatomic, strong) NSMutableArray *headerViews;
@property (nonatomic, strong) NSMutableArray *footerViews;
@property (nonatomic, assign) UIEdgeInsets cellEdgeInsets;
@property (nonatomic, strong) UIColor *highlightTextColor;
@property (nonatomic, strong) UIColor *highlightBackgroundColor;
@property (nonatomic, assign) float rowHeight;
@property (nonatomic, strong) UIColor *labelFontColor;
@property (nonatomic, strong) UIColor *headerBackgroundColor;
@property (nonatomic, strong) UIColor *headerTextColor;
@property (nonatomic, strong) UIFont *headerFont;
@property (nonatomic, strong) UIColor *headerHighlightTextColor;
@property (nonatomic, strong) UIColor *footerBackgroundColor;
@property (nonatomic, strong) UIColor *footerTextColor;
@property (nonatomic, strong) UIFont *footerFont;
@property (nonatomic, assign) NSTextAlignment footerTextAlignment;
@property (nonatomic, assign) float headerViewHeight;
@property (nonatomic, assign) float footerViewHeight;
@property (nonatomic, assign) float cellBorderWidth;
@property (nonatomic, strong) UIColor *cellBorderColor;
@property (nonatomic, strong) UIColor *lockedSeparatorColor;
@property (nonatomic, assign) NSRange lockedColumns;
@property (nonatomic, strong) LDKColumnSort *columnSort;
@property (nonatomic, assign) BOOL scrollEnabled;
@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, assign) BOOL isMultiSelectVisible;
@property (nonatomic, assign) BOOL isMultiSelectEnabled;
@property (nonatomic, assign) BOOL sortingDisabled;
@property (nonatomic, assign) float multiSelectWidth;
@property (nonatomic, assign) BOOL showLastRowSpinner;
@property (nonatomic, strong) UIImage *multiSelectNotSelectedImage;
@property (nonatomic, strong) UIImage *multiSelectSelectedImage;
@property (nonatomic, assign) BOOL isDeleteEnabled;
@property (nonatomic, assign) BOOL isDeleteVisible;
@property (nonatomic, assign) float deleteWidth;
@property (nonatomic, strong) NSIndexPath *indexPathForSelectedRow;
@property (assign) BOOL hideHeader;

- (void)reloadData;
- (CGRect)rectForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)sizeToFit;
- (void)setScrollEnabled:(BOOL)scrollEnabled;

- (void)startLoading;
- (void)finishLoading;
- (void)reloadRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)selectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (void)reloadMultiSelectedRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)reloadMultiSelectedRowsWithRowAnimation:(UITableViewRowAnimation)animation;


@end

@protocol LDKNewDataGridViewDelegate <NSObject>

- (NSUInteger)numberOfSectionsForDataGridView:(LDKNewDataGridView *)view;
- (NSUInteger)dataGridView:(LDKNewDataGridView *)view numberOfRowsInSection:(NSInteger)section;
- (NSUInteger)numberOfColumnsForDataGridView:(LDKNewDataGridView *)view;
- (LDKDataGridColumnConfig *)dataGridView:(LDKNewDataGridView *)view configForColumn:(NSUInteger)column;

@optional

- (id)dataGridView:(LDKNewDataGridView *)view titleForHeaderInSection:(NSInteger)section;
- (id)dataGridView:(LDKNewDataGridView *)view valueForRowAtIndexPath:(NSIndexPath *)indexPath andColumn:(NSUInteger)column;
- (BOOL)dataGridView:(LDKNewDataGridView *)view shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath column:(NSUInteger)column touchPoint:(CGPoint)touchPoint;
- (NSIndexPath *)dataGridView:(LDKNewDataGridView *)view willSelectColumn:(NSInteger)column forRowAtIndexPath:(NSIndexPath *)indexPath touchPoint:(CGPoint)touchPoint;
- (void)dataGridView:(LDKNewDataGridView *)view didSelectColumn:(NSInteger)column forRowAtIndexPath:(NSIndexPath *)indexPath touchPoint:(CGPoint)touchPoint inCell:(UIView *)cell;
- (BOOL)dataGridView:(LDKNewDataGridView *)view headerWasTapped:(LDKDataGridColumnConfig *)config;
- (BOOL)dataGridViewShouldPullToRefresh:(LDKNewDataGridView *)view;
- (void)dataGridViewDidPullToRefresh:(LDKNewDataGridView *)view;
- (BOOL)dataGridView:(LDKNewDataGridView *)view showSpinnerForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)dataGridView:(LDKNewDataGridView *)view willChangeMultiSelectVisible:(BOOL)multiSelectVisible;
- (BOOL)dataGridView:(LDKNewDataGridView *)view shouldChangeMultiSelectVisible:(BOOL)multiSelectVisible;
- (void)dataGridView:(LDKNewDataGridView *)view didChangeMultiSelectVisible:(BOOL)multiSelectVisible;
- (UIButton *)multiSelectHeaderButtonFordataGridView:(LDKNewDataGridView *)view;
- (void)dataGridView:(LDKNewDataGridView *)view didMultiSelectForRowAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)dataGridView:(LDKNewDataGridView *)view isMultiSelectedForRowAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)dataGridView:(LDKNewDataGridView *)view showTapPrompt:(NSIndexPath *)indexPath;

- (BOOL)dataGridViewShouldShowFooter:(LDKNewDataGridView *)view;
- (NSString *)dataGridView:(LDKNewDataGridView *)view valueFooterColumn:(NSUInteger)column;
- (BOOL)dataGridView:(LDKNewDataGridView *)view didDeleteRowAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)dataGridViewShouldHighlightForNumeric:(LDKNewDataGridView *)view;
- (NSArray *)sectionIndexTitlesForDataGridView:(LDKNewDataGridView *)view;
- (NSInteger)dataGridView:(LDKNewDataGridView *)view sectionForSectionIndexTitle:(NSString *)title atIndex:(NSInteger)index;

@end
