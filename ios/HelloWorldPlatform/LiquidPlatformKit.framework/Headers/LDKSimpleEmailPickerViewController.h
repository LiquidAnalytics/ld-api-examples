//
//  LDKSimpleEmailPickerViewController.h
//  LDCore
//
//  Created by CARSON LI on 2015-08-26.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^LDKSimpleEmailPickerDoneBlock)(NSString *email);

@interface LDKSimpleEmailPickerViewController : UIViewController

@property BOOL isPresentingModally;
@property (nonatomic, copy) LDKSimpleEmailPickerDoneBlock doneBlock;
@property (strong) NSString* defaultEmail;

@end
