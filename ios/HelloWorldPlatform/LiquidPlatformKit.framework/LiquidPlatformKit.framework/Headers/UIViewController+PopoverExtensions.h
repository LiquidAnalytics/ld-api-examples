//
//  UIViewController+PopoverExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 10/2/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface UIViewController (PopoverExtensions)

- (void)setPopoverSizeFromTableView:(UITableView *)tableView;
- (void)setPopoverSizeFromTableView:(UITableView *)tableView andMaxHeight:(float)maxHeight;
- (void)setPopoverSizeFromTableView:(UITableView *)tableView withWidth:(float)width andMaxHeight:(float)maxHeight;

@end
