//
//  LLSDataGridView.h
//  Liquid Sales
//
//  Created by Nick Rimer on 11/2/11.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@class LDKDataGridView;

@protocol LDKDataGridViewDataSource
- (NSInteger)numberOfRowsInDataGrid:(LDKDataGridView *)dataGrid;
- (NSInteger)numberOfColumnsInDataGrid:(LDKDataGridView *)dataGrid forRowWithIndex:(NSInteger)index customFlag:(BOOL) customFlag;
- (CGFloat)dataGrid:(LDKDataGridView *)dataGrid heightForRow:(NSInteger)rowIndex;
- (CGFloat)dataGrid:(LDKDataGridView *)dataGrid widthForCellAtRow:(NSInteger)rowIndex column:(NSInteger)columnIndex;
- (NSString *)dataGrid:(LDKDataGridView *)dataGrid stringForRow:(NSInteger)rowIndex column:(NSInteger)columnIndex customFlag:(BOOL)customFlag;
- (UIColor *)dataGrid:(LDKDataGridView *)dataGrid colorForRow:(NSInteger)rowIndex column:(NSInteger)columnIndex;
- (NSTextAlignment)dataGrid:(LDKDataGridView *)dataGrid textAlignmentForCellAtRow:(NSInteger)rowIndex column:(NSInteger)columnIndex;

- (NSString *)dataGrid:(LDKDataGridView *)dataGrid stringForHeaderCellAtColumn:(NSInteger)columnIndex customFlag:(BOOL)customFlag;
- (NSInteger)numberOfColumnsInHeaderOfDataGrid:(LDKDataGridView *)dataGrid;
- (CGFloat)dataGrid:(LDKDataGridView *)dataGrid widthForHeaderCellAtColumn:(NSInteger)columnIndex;

- (NSInteger)numberOfColumnsInFirstPageOfDataGrid:(LDKDataGridView *)dataGrid;

@optional

- (void)dataGrid:(LDKDataGridView *)dataGrid headerWasDoubleTappedAtIndex:(NSUInteger)index;
- (NSInteger)numberOfStaticColumns;
- (NSInteger)numberOfColumnsInSecondPageOfDataGrid;
- (NSInteger)numberOfColumnsInThirdPageOfDataGrid;
//subheaders
- (NSInteger)numberOfSubHeaders;
- (CGFloat)widthForSubHeaderCellAtColumn:(NSInteger)columnIndex;
- (CGFloat)placementForSubHeader:(NSInteger)columnIndex;
- (NSString *)stringForSubHeaderCellAtColumn:(NSInteger)columnIndex;
- (NSInteger)tableForSubHeader:(NSInteger)columnIndex;
- (void)showPopoverFrom:(LDKDataGridView *)sender atIndex:(NSIndexPath *)index forTable:(int)tableNumber;
@end

@interface LDKDataGridView : UIViewController <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, retain) UITableView *tableView;
@property (strong, nonatomic) UIView *headerView;
@property (strong, nonatomic) UIView *secondHeaderView;
@property (strong, nonatomic) UITableView *secondTableView;
@property (strong, nonatomic) UIView *thirdHeaderView;
@property (strong, nonatomic) UITableView *thirdTableView;
@property (strong, nonatomic) UIView *fourthHeaderView;
@property (strong, nonatomic) UITableView *fourthTableView;
@property (strong, nonatomic) UIView *staticHeaderView;
@property (strong, nonatomic) UITableView *staticTableView;
@property (strong, nonatomic) UIView *staticBack;
@property (strong, nonatomic) UIView *image;
@property (strong, nonatomic) UILabel *leftHeaderLabel;
@property (strong, nonatomic) UILabel *rightHeaderLabel;

@property (nonatomic, assign) id <LDKDataGridViewDataSource> delegate;

- (void)reloadData;
- (void)resetScrollPosition;

@end
