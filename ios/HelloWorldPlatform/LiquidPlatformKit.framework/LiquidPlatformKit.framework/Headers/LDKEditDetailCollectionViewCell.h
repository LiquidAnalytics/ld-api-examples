//
//  LDKEditDetailCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/11/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKSwiftEnums.h"

@class LDMItem, LDKEditDetailViewController, LDMContext;
@protocol LDKEditDetailCollectionViewCellDelegate;

@interface LDKEditDetailCollectionViewCell : UICollectionViewCell

@property (strong, nonatomic) LDMItem *__nullable item;
@property (strong, nonatomic) LDMItem *__nullable section;
@property (readonly, nonatomic) NSDictionary *__nullable config;
@property (weak, nonatomic) UINavigationController *__nullable navigationController;
@property (weak, nonatomic) id<LDKEditDetailCollectionViewCellDelegate> __nullable delegate;
@property (strong, nonatomic) NSString *__nullable transactionId;
@property (strong, nonatomic) LDMContext *__nullable context;
@property (assign, nonatomic) BOOL performLocalQueries;
@property (assign, nonatomic) BOOL editing;
@property (assign, nonatomic) BOOL titleLabelDisabled;
@property (assign, nonatomic) BOOL disableCreateBlock;
@property (strong) NSNumber *__nullable maxNumOfBlocks;
@property (assign, nonatomic) LDKDrawerMode drawerMode;

- (void)refresh;
- (CGSize)sizeNeeded;

- (BOOL)editDetailViewController:(LDKEditDetailViewController *__nullable)viewController shouldSubmit:(NSString *__nullable)transactionId message:(NSMutableString *__nullable)message;

@end


@protocol LDKEditDetailCollectionViewCellDelegate <NSObject>

- (void)collectionViewCell:(LDKEditDetailCollectionViewCell *__nonnull)cell didChangeSizeNeeded:(CGSize)sizeNeeded scroll:(BOOL)scroll;

- (void)collectionViewCell:(LDKEditDetailCollectionViewCell *__nonnull)cell didModifyItem:(LDMItem *__nonnull)item fields:(NSArray *__nonnull)fields;

@optional

- (void)collectionViewCell:(LDKEditDetailCollectionViewCell *__nonnull)cell shouldSetSaveEnabled:(BOOL)saveEnabled;

- (void)collectionViewCell:(LDKEditDetailCollectionViewCell *__nonnull)cell didChangeFirstResponder:(UIView *__nullable)firstResponder;

@end