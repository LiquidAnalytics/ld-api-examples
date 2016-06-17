//
//  UITableView+LDCoreExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 12/2/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface UITableView (LDCoreExtensions)

- (void)reloadDataStatefully;
- (void)deselect;
- (float)calculateHeightWithDataSource:(id)dataSource;
- (float)calculateHeightWithDataSource:(id)dataSource andLimit:(NSInteger)limit;
- (void)redrawData;
- (void)scrollToTopWithAnimation:(BOOL)animated;
- (void)reloadRowsInSection:(NSInteger)section withRowAnimation:(UITableViewRowAnimation)rowAnimation;
- (void)stopScroll;

@end
