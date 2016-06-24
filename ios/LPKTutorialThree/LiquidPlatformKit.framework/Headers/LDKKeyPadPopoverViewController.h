//
//  LDKKeyPadPopoverViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 3/17/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKKeyPadViewController.h"

@interface LDKKeyPadPopoverViewController : LDKKeyPadViewController

+ (LDKKeyPadPopoverViewController *)presentKeypadFromRect:(CGRect)rect inView:(UIView *)view;
+ (LDKKeyPadPopoverViewController *)presentKeypadFromRect:(CGRect)rect inView:(UIView *)view decimal:(BOOL)decimal;

@end
