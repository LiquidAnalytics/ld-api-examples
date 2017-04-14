//
//  LDKEditableSlider.h
//  LDCore
//
//  Created by Bryan Nagle on 12/24/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKEditableSliderViewDelegate;

@interface LDKEditableSliderView : UIView

@property (assign) BOOL selected;
@property (assign) BOOL editable;
@property (nonatomic, assign) NSInteger minimumValue;
@property (nonatomic, assign) NSInteger maximumValue;
@property (nonatomic, assign) NSInteger stepValue;
@property (nonatomic, assign) float value;
@property (assign) UIEdgeInsets inset;
@property (weak) id<LDKEditableSliderViewDelegate> ldkDelegate;

@end

@protocol LDKEditableSliderViewDelegate <NSObject>

- (void)editableSliderView:(LDKEditableSliderView *)sliderView didSelectValue:(float)value;
- (void)editableSliderViewDidChangeOptions:(LDKEditableSliderView *)sliderView;

@end
