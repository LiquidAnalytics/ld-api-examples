//
//  LDKButtonCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 12/16/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDCButton.h"

@interface LDKButtonCollectionViewCell : UICollectionViewCell

@property (strong) LDCButton *button;

- (void)setButtonClass:(Class)class;

@end
