//
//  LDKRangeViewController.h
//  LDCore
//
//  Created by glazers macbook on 12/18/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LDKRangeTextOptions)
{
    LDKRangeOptionNone = 0,
    LDKRangeOptionLabelAbove = 1 << 0,
    LDKRangeOptionBecomeFirstResponder = 1 << 1
};
@interface LDKRangeViewController :  UIViewController <UITextFieldDelegate, UIPopoverControllerDelegate>{
    
}
@property (strong) UILabel *startRangeLabelView;
@property (strong) UITextField *startRangeTextField;
@property (strong) UITextField *endRangeTextField;
@property (strong) UILabel *endRangeLabelView;
@property (assign) LDKRangeTextOptions options;
@property (assign) UIEdgeInsets edgeInsets;
@property (strong) NSString *startRangeLabel;
@property (nonatomic, strong) NSString *startRange;
@property (strong) NSString *endRangeLabel;
@property (nonatomic, strong) NSString *endRange;

@property (nonatomic, copy) void (^donePressedHandler)(LDKRangeViewController *controller);
- (void)close;

@end
