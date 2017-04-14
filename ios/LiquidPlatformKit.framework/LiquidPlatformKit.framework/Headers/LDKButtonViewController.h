//
//  LDKButtonViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 3/21/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKButtonViewController : UIViewController

@property (strong) UIButton *button;
@property (strong) UILabel *label;

- (void)update;

@end
