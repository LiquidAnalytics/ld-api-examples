//
//  LDKProgressTableViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 8/1/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKProgressTableViewCell : UITableViewCell

@property (strong) UIProgressView *progressBar;
@property (strong) UILabel *titleLabel;

@end
