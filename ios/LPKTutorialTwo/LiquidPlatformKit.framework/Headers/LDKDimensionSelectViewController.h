//
//  LDKDimensionSelectViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/16/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDCSearchBarController.h"
#import "LDKLabelWithButtonsCell.h"

#define DIMENSION_POPOVER_HEIGHT                        1000.0f

@class LDMDimension, LDMQueryFilter;

@protocol LDKDimensionSelectViewControllerDelegate;

@interface LDKDimensionSelectViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, LDCSearchBarControllerDelegate, LDKLabelWithButtonsCellDelegate>

@property (nonatomic, copy) LDMQueryFilter *queryFilter;
@property (nonatomic, strong) NSString *pathText;
@property (assign) NSNumber *depth;
@property (strong) NSString *dimensionLevel;
@property (strong) NSArray *dimensions;
@property (strong, nonatomic) NSArray *levels;
@property (strong) id<LDKDimensionSelectViewControllerDelegate> delegate;
@property (strong) LDMDimension *parentDimension;
@property (assign) BOOL multiSelectDisabled;
@property (assign) BOOL shouldDrillDownToChildLevel;            //Property to flag drill down behaviour; its irrespective of dimension drill down level.
@property (strong, nonatomic) NSString *dimensionSelectLevel;   //Property to indicate dimension level to drill down to.

- (void)loadMembersForLevel:(NSString *)level;
- (void)loadMembersForLevel:(NSString *)level withParentDimension:(LDMDimension *)dimension;

@end

@protocol LDKDimensionSelectViewControllerDelegate <NSObject>

- (void) selectAllDimensionsForLevel:(NSString*) level andDimensions:(NSArray*) dimensions;
- (void) removeAllDimensionsForLevel:(NSString*) level;

- (void)dimensionSelectViewController:(LDKDimensionSelectViewController *)dimensionSelectViewController didSelectLevel:(NSString *)level andDimension:(LDMDimension *)dimension;

- (void)dimensionSelectViewController:(LDKDimensionSelectViewController *)dimensionSelectViewController doneButtonPressedWithSender:(id)sender andParentDimension:(LDMDimension *)parentDimension;

- (NSString *)dimensionSelectViewController:(LDKDimensionSelectViewController *)dimensionSelectViewController labelForDimensionLevel:(NSString *)dimensionLevel;

@optional

- (BOOL)dimensionSelectViewController:(LDKDimensionSelectViewController *)dimensionSelectViewController isDimensionSelected:(LDMDimension *)dimension;

@end