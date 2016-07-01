//
//  UITableViewCell+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 10/24/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableViewCell (LDK)

- (void)setSelectedBackgroundColor:(UIColor *)color;
- (void)setSelectedBackgroundColor;
- (UITableView *)tableView;

@end
