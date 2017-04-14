//
//  LDCKeyPadViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 8/21/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

typedef void (^LDKKeyPadValueChangedBlock)(id keypadViewController, NSString *value);
typedef void (^LDKKeyPadDoneBlock)(id sender, NSString *value);

typedef NS_ENUM(NSUInteger, LDKKeyPadFormat)
{
    LDKKeyPadFormatInt,
    LDKKeyPadFormatDecimal,
    LDKKeyPadFormatCurrency,
    LDKKeyPadFormatPercent
};

@class LDKScrollableButtonBar, LDMDimension;

@protocol LDCKeyPadViewDelegate;

@interface LDKKeyPadViewController : UIViewController

@property (weak) id<LDCKeyPadViewDelegate> delegate;
@property (nonatomic, copy) LDKKeyPadValueChangedBlock valueChangedblock;
@property (nonatomic, copy) LDKKeyPadValueChangedBlock didDisappearBlock;
@property (nonatomic, copy) LDKKeyPadDoneBlock doneblock;
@property (strong) NSString *defaultValue;
@property (strong) NSString *orignalValue;
@property (assign) LDKKeyPadFormat format;
@property BOOL extraButtonHidden;
@property BOOL doneCallbackOnDismiss;
@property BOOL clearOnFirstTouch;
@property (nonatomic, readonly) NSString *valueString;
@property (strong) NSMutableDictionary *data;
@property (assign) BOOL doneButtonHidden;
@property (assign) BOOL donePressed;
@property (assign) float maximumValue;
@property (nonatomic, assign) BOOL isInPopover;

@property (weak, nonatomic) IBOutlet UIView *keyView;
@property (nonatomic, strong) NSMutableString *_value;
@property (unsafe_unretained, nonatomic) IBOutlet LDKScrollableButtonBar *buttonBar;
@property (nonatomic, strong) NSString *accessibilityLabelPrefix;

+ (LDKKeyPadFormat)formatForString:(NSString *)string defaultFormat:(LDKKeyPadFormat)defaultFormat;
- (void)setValue:(id)aValue;
- (void)reset;

@end

@protocol LDCKeyPadViewDelegate <NSObject>

@optional

- (void)uomChanged:(LDMDimension*)uom;
- (void)keypadDidLoad:(LDKKeyPadViewController *)keypad;
- (void)keypad:(LDKKeyPadViewController *)keypad maxValueExceeded:(NSString *)maxValue;
- (void)keypad:(LDKKeyPadViewController *)keypad valueChanged:(NSString *)value;
- (void)donePressedForKeypad:(LDKKeyPadViewController *)keypad value:(NSString *)value;

@end