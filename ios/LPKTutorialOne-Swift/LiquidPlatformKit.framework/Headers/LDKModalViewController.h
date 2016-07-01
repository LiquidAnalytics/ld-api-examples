//
//  LDKModalViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 11/19/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKModalViewController : UIViewController

@property (assign) CGSize frameSize;
@property (strong) UIViewController *contentViewController;

- (void)dismissWithCompletion:(void (^)(BOOL finished))completion;

@end
