//
//  LDKModalManager.h
//  LDCore
//
//  Created by Bryan Nagle on 11/19/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDKModalViewController;

@interface LDKModalManager : NSObject

@property (weak) LDKModalViewController *currentModalContainer;

+ (LDKModalManager *)sharedInstance;

@end
