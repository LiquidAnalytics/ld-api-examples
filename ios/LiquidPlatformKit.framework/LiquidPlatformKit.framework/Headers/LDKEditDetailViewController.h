//
//  LDKEditDetailViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 12/11/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKEditDetailCollectionViewCell.h"

#define LDKEDITDETAIL_SHOULD_CLOSE_LISTENER                 @"ldkEditDetailShouldClose"

@class LDMItem, LDMContext;

@interface LDKEditDetailViewController : UIViewController <LDKEditDetailCollectionViewCellDelegate>

@property (strong, nonatomic) LDMItem *item;
@property (strong, nonatomic) LDMContext *context;
@property (strong, nonatomic) LDMItem *config;
@property (strong, nonatomic) NSMutableDictionary *options;
@property (strong, nonatomic) NSString *transactionId;
@property (assign, nonatomic) BOOL transactDisabled;
@property (assign, nonatomic) BOOL dismissDisabled;
@property (assign, nonatomic) BOOL performLocalQueries;
@property (assign, nonatomic) BOOL hasUserModified;
@property (assign, nonatomic) BOOL deleteEnabled;
@property (assign, nonatomic) BOOL disableCreateBlock;
@property (strong) NSNumber *maxNumOfBlocks;
@property (copy, nonatomic) void (^didComplete)(BOOL success, LDMItem *aItem);
@property (copy, nonatomic) void (^didDelete)(BOOL success, LDMItem *aItem);
@property (copy, nonatomic) void (^performOnSave)(LDMItem *aItem, NSString *statement);

+ (LDKEditDetailViewController *)editDetailViewController;

@end
