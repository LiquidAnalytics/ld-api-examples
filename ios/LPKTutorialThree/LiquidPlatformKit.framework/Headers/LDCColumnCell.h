//
//  LDCColumnCell.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 8/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDCColumnCellDataSource;

@interface LDCColumnCell : UITableViewCell

@property (weak) id<LDCColumnCellDataSource> datasource;
@property (strong) NSIndexPath *indexPath;
@property (assign) NSInteger cellpadding;
@property (strong) UIColor *borderColor;
@property (nonatomic, assign) BOOL loading;

- (void)configureForIndexPath:(NSIndexPath *)indexPath;

@end

@protocol LDCColumnCellDataSource <NSObject>

- (NSInteger)columnCell:(LDCColumnCell *)cell numberOfColumnsForIndexPath:(NSIndexPath *)indexPath;
- (float)columnCell:(LDCColumnCell *)cell widthForColumn:(NSInteger)column;

- (void)columnCell:(LDCColumnCell *)cell indexPath:(NSIndexPath *)indexPath column:(NSInteger)column configureCell:(void (^)( NSString *text, UIFont *font, NSLineBreakMode lineBreakMode, NSTextAlignment textAlignment, UIColor *textColor))configureBlock;

@end