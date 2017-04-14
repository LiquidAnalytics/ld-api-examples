//
//  LDKBorderedImageCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/31/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKBorderedCell.h"

@interface LDKBorderedImageCell : LDKBorderedCell

@property (strong) UIImageView *ldkImageView;
@property (assign) LDKViewSide imageBorderSides;
@property (strong) UIColor *imageBorderColor;
@property (assign) float imageBorderWidth;

@end
