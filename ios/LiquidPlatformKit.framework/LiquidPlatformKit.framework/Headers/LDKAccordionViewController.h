//
//  LDKAccordionViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 3/14/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LDKAccordionOption)
{
    LDKAccordionOptionNone = 0,
    LDKAccordionOptionAutoCollapseOnExpand = 1 << 0,
    LDKAccordionOptionPreventFullCollapse = 1 << 1
};

@protocol LDKAccordionViewControllerDataSource, LDKAccordionViewControllerDelegate;

@interface LDKAccordionViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

@property (weak, nonatomic) id<LDKAccordionViewControllerDataSource> dataSource;
@property (weak, nonatomic) id<LDKAccordionViewControllerDelegate> delegate;
@property (assign, nonatomic) BOOL scrollEnabled;
@property (assign) LDKAccordionOption options;
@property (strong) NSMutableIndexSet *expandedRows;

- (float)heightNeeded;
- (void)collapseAllRows;
- (void)reloadData;
- (BOOL)isRowExpanded:(NSInteger)row;
- (void)scrollToRow:(NSInteger)row;
- (void)expandRow:(NSInteger)row;
- (void)collapseRow:(NSInteger)row;
- (void)reloadRow:(NSInteger)row;
- (NSInteger)indexPathForCell:(UITableViewCell *)cell;
- (CGRect)rectForRow:(NSUInteger)row;

@end

@protocol LDKAccordionViewControllerDataSource <NSObject>

- (NSInteger)numberOfRowsInAccordion:(LDKAccordionViewController *)accordion;
- (UIView *)accordionViewController:(LDKAccordionViewController *)accordion titleViewForRow:(NSInteger)row;
- (UIView *)accordionViewController:(LDKAccordionViewController *)accordion expandedViewForRow:(NSInteger)row;
- (float)accordionViewController:(LDKAccordionViewController *)accordion collapsedHeightForViewForRow:(NSInteger)row;
- (float)accordionViewController:(LDKAccordionViewController *)accordion expandedHeightForViewForRow:(NSInteger)row;


@end

@protocol LDKAccordionViewControllerDelegate <NSObject>

@optional

- (BOOL)accordionViewController:(LDKAccordionViewController *)accordion shouldExpandRow:(NSInteger)row;
- (BOOL)accordionViewController:(LDKAccordionViewController *)accordion shouldShowChevron:(NSInteger)row;

- (void)accordionViewController:(LDKAccordionViewController *)accordion willExpandRow:(NSInteger)row;
- (void)accordionViewController:(LDKAccordionViewController *)accordion willCollapseRow:(NSInteger)row;

- (void)accordionViewController:(LDKAccordionViewController *)accordion willChangeHeightNeeded:(float)heightNeeded;

- (void)accordionViewController:(LDKAccordionViewController *)accordion didChangeHeightNeeded:(float)heightNeeded;
- (void)accordionViewController:(LDKAccordionViewController *)accordion didExpandRow:(NSInteger)row;
- (void)accordionViewController:(LDKAccordionViewController *)accordion didCollapseRow:(NSInteger)row;
- (void)accordionViewController:(LDKAccordionViewController *)accordion didSelectRow:(NSInteger)row;

- (void)accordionViewControllerDidFinishAnimating:(LDKAccordionViewController *)accordion;

@end