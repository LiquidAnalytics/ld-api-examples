//
//  LDKBreadcrumsView.h
//  LDCore
//
//  Created by Bryan Nagle on 1/9/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+LDK.h"

@protocol LDKBreadcrumsViewDelegate;

@interface LDKBreadcrumsView : UIView

@property (strong) NSMutableArray *breadcrums;
@property (strong) UIFont *font;
@property (strong) UIColor *textColor;
@property (strong) UIColor *selectedTextColor;
@property (strong) UIColor *borderColor;
@property (assign) CGSize contentSize;
@property (assign) BorderSides borderSides;
@property (assign) BOOL borderFullWidth;
@property (weak) id<LDKBreadcrumsViewDelegate> ldkDelegate;

- (void)addBreadcrumbText:(NSString *)text withImageName:(NSString *)imageName;
- (void)addBreadcrumbText:(NSString *)text forItemType:(NSString *)itemType;

@end

@protocol LDKBreadcrumsViewDelegate <NSObject>

- (void)breadCrumbsView:(LDKBreadcrumsView *)view didTapButtonAtIndex:(NSInteger)index;

@end
