//
//  LDKFilterView.h
//  LDCore
//
//  Created by Bryan Nagle on 1/20/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMQueryFilter;

@interface LDKFilterView : UIView

@property (nonatomic, strong) UIColor *labelColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIFont *labelFont;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) NSString *itemType;

- (void)loadQueryFilter:(LDMQueryFilter *)queryFilter itemType:(NSString *)itemType title:(NSString *)title keyValues:(NSArray *)keyValues;

@end
