//
//  LDCDimensionSelectManager.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/18/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDKDimensionSelectViewController.h"

@class LDMQueryFilter;

@interface LDKDimensionSelectManager : NSObject<LDKDimensionSelectViewControllerDelegate>

@property (weak) UIViewController *rootViewController;
@property (strong) NSDictionary *labelsByLevel;
@property (assign) BOOL multiSelectDisabled;
@property (assign) BOOL disableDrillDown;
@property (nonatomic, copy) LDMQueryFilter *queryFilter;
@property (weak) UINavigationController *navigationController;
@property (strong) NSMutableArray *selectedDimensions;

+ (LDKDimensionSelectManager *)presentDimensionSelectWithLevel:(NSString *)level fromRect:(CGRect)rect inView:(UIView *)view permittedArrowDirections:(UIPopoverArrowDirection)direction andCompletedBlock:(void (^)(LDMDimension *dimension))completionBlock;

- (id)initWithNavigationController:(UINavigationController *)aNavigationController;

- (UIViewController *)selectDimensionForLevel:(NSString *)level withParentDimension:(LDMDimension*)parent withSelectedBlock:(void (^)(LDMDimension *dimension))selected andCompletedBlock:(void (^)(LDMDimension *dimension))completed;
- (UIViewController *)selectDimensionsForLevels:(NSArray *)levels withParentDimension:(LDMDimension*)parentDimension withSelectedBlock:(void (^)(NSArray *dimensions))selected andCompletedBlock:(void (^)(NSArray *dimensions))completed;
- (UIViewController *)selectDimensionForLevel:(NSString *)level withSelectedBlock:(void (^)(LDMDimension *dimension))selected andCompletedBlock:(void (^)(LDMDimension *dimension))completed;

- (UIViewController *)selectDimensionsForLevels:(NSArray *)levels withLabels:(NSArray *)labels  withSelectedBlock:(void (^)(NSArray *dimensions))selected andCompletedBlock:(void (^)(NSArray *dimensions))completed;

- (void)loadSelected:(NSArray *)array;
- (void)loadSelectedDimensions:(NSArray *)dimensions;
- (BOOL)isLevelSelected:(NSString *)level;
- (void)removeSelectedDimension:(LDMDimension *)dimension;
- (void)removeAllSelectedDimensions;

@end
