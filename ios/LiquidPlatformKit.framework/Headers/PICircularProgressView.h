//
//  PICircularProgressView.h
//  PICircularProgressView
//
//  Created by Dominik Alexander on 11.06.13.
//  Copyright (c) 2013 Dominik Alexander. All rights reserved.
//  Hosted on GITHUB - MIT License

#import <UIKit/UIKit.h>

@interface PICircularProgressView : UIView

@property (nonatomic) double progress;
@property (atomic, strong) NSString *text;

// Should be BOOLs, but iOS doesn't allow BOOL as UI_APPEARANCE_SELECTOR
@property (nonatomic) NSInteger showText UI_APPEARANCE_SELECTOR;
@property (nonatomic) NSInteger roundedHead UI_APPEARANCE_SELECTOR;
@property (nonatomic) NSInteger showShadow UI_APPEARANCE_SELECTOR;

@property (nonatomic) CGFloat thicknessRatio UI_APPEARANCE_SELECTOR;
@property (nonatomic) CGRect preferredRect UI_APPEARANCE_SELECTOR;
@property (assign) BOOL usePreferredRect;

@property (nonatomic, strong) UIColor *innerBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *outerBackgroundColor UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIColor *textColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *font UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIColor *progressFillColor UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) UIColor *progressTopGradientColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *progressBottomGradientColor UI_APPEARANCE_SELECTOR;

@end
