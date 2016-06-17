//
//  LDKCSubDataGridViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 11/5/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKNewDataGridView.h"
#import "LDMSearchResults.h"

@class LDMItem, LDMFunction, LDMQueryFilter, LDKAccordionViewController;

@interface LDKSubDataGridViewController : UIViewController <LDKNewDataGridViewDelegate, LDMSearchResultsDelegate>

@property (weak, nonatomic) IBOutlet UIView *gridPlaceholderView;
@property (strong, nonatomic) LDKNewDataGridView *dataGridView;

@property (nonatomic, strong) NSString *dataGridDefId;
@property (nonatomic, strong) LDMItem *section;
@property (nonatomic, strong) LDMItem *dataGridDef;
@property (strong, nonatomic) NSString *functionId;
@property (strong, nonatomic) LDMDimension *functionType;
@property (nonatomic, strong) LDMItem *item;
@property (strong, nonatomic) LDMQueryFilter *filter;
@property (strong, nonatomic) LDMQueryFilter *search;
@property (weak, nonatomic) LDKAccordionViewController *accordionViewController;
@property NSString *parentGridRelation;
@property NSString *parentGridFunctionId;
@property (assign, nonatomic) BOOL performLocalQueries;
@property (nonatomic, copy) UIViewController *(^legacyEditViewController)(NSString *editDefName, LDMItem *aItem);
@property (nonatomic, copy) void (^didChangeHeightNeeded)();

- (void)load:(void (^)(BOOL finished))completionHandler;
- (void)fetchData:(void (^)(BOOL finished))completionHandler;
- (void)sizeToFit;

@end
