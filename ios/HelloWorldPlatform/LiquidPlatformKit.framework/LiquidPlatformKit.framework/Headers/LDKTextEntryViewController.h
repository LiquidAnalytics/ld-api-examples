//
//  LDKTextEntryViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 1/21/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LDKTextEntryOptions)
{
    LDKTextEntryOptionNone = 0,
    LDKTextEntryOptionLabelAbove = 1 << 0,
    LDKTextEntryOptionBecomeFirstResponder = 1 << 1
};

@interface LDKTextEntryViewController : UIViewController <UITextFieldDelegate, UIPopoverControllerDelegate>

@property (strong) UILabel *labelView;
@property (strong) UITextField *textField;
@property (assign) LDKTextEntryOptions options;
@property (assign) UIEdgeInsets edgeInsets;
@property (strong) NSString *label;
@property (nonatomic, strong) NSString *text;
@property (assign) BOOL disableDoneOnDismiss;
@property (nonatomic, copy) void (^didEnterTextHandler)(NSString *text);
@property (nonatomic, copy) void (^donePressedHandler)(LDKTextEntryViewController *controller);

+ (LDKTextEntryViewController *)presentNavTextEntryWithLabel:(NSString *)label text:(NSString *)text fromRect:(CGRect)rect inView:(UIView *)view permittedArrowDirections:(UIPopoverArrowDirection)direction completionHandler:(void (^)(NSString *text))completionHandler;

+ (LDKTextEntryViewController *)presentTextEntryWithLabel:(NSString *)label text:(NSString *)text fromRect:(CGRect)rect inView:(UIView *)view permittedArrowDirections:(UIPopoverArrowDirection)direction completionHandler:(void (^)(NSString *text))completionHandler;

+ (LDKTextEntryViewController *)presentTextEntryWithLabel:(NSString *)label text:(NSString *)text fromBarButtonItem:(UIBarButtonItem *)barButtonItem permittedArrowDirections:(UIPopoverArrowDirection)direction completionHandler:(void (^)(NSString *text))completionHandler;

+ (instancetype)textEntryViewController;

- (void)close;

@end
