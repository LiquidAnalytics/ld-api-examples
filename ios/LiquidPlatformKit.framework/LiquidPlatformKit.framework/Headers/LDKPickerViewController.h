//
//  LDKPickerViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 1/16/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDKPickerViewControllerDelegate;

@interface LDKPickerViewController : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate>

@property (assign) float width;
@property (assign) float rowHeight;
@property (strong) NSArray *options;
@property (weak) id<LDKPickerViewControllerDelegate> ldkDelegate;
@property (nonatomic, copy) void (^didSelectOptionHandler)(LDKPickerViewController *controller, id option, NSInteger row);
@property (strong) id selectedOption;

+ (LDKPickerViewController *)presentPickerFromRect:(CGRect)rect inView:(UIView *)view permittedArrowDirections:(UIPopoverArrowDirection)direction options:(NSArray *)options selectedOption:(id)selectedOption handler:(void (^)(LDKPickerViewController *controller, id option, NSInteger row))handler;

@end

@protocol LDKPickerViewControllerDelegate <NSObject>

- (void)pickerViewController:(LDKPickerViewController *)controller didSelectOption:(id)option atRow:(NSInteger)row;

@end