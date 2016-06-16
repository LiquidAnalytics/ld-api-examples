//
//  LDKKeyValueView.h
//  LDCore
//
//  Created by Bryan Nagle on 9/25/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKKeyValueView : UIView

@property (nonatomic, strong) NSArray *keyValuePairs;
@property (nonatomic, assign) UIEdgeInsets labelInsets;
@property (nonatomic, assign) UIEdgeInsets pairInsets;
@property (nonatomic, assign) UIEdgeInsets contentInsets;
@property (nonatomic, strong) UIColor *valueUnderlineColor;
@property (nonatomic, assign) float valueUnderlineWidth;
@property (nonatomic, assign) NSUInteger numberOfColumns;
@property (nonatomic, strong) UIFont *keyFont;
@property (nonatomic, strong) UIFont *valueFont;
@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic, copy) void (^labelWasTapped)(UILabel *label, NSDictionary *pair);

- (void)sizeToFit;

@end

