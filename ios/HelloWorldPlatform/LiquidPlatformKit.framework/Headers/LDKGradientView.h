//
//  LDKGradientView.h
//  LDCore
//
//  Created by Bryan Nagle on 12/2/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKCoreGraphicsEffects.h"

@interface LDKGradientView : UIView

@property (strong) NSArray *colors;
@property (assign) LDKCoreGraphicsOption direction;

@end
