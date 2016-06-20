//
//  LDKBorderedImageCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/31/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+LDK.h"

@interface LDKBorderedCell : UITableViewCell

@property (assign) LDKViewSide borderSides;
@property (strong) UIColor *borderColor;
@property (assign) float borderWidth;

- (void)setup;

@end
