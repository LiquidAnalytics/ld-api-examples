//
//  LDKFormCellController.h
//  LDCore
//
//  Created by Bryan Nagle on 1/22/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMItem;

@interface LDKFormCells : NSObject

+ (UITableViewCell *)tableView:(UITableView *)tableView cellForAdHoc:(NSString *)label;
+ (UITableViewCell *)tableView:(UITableView *)tableView cellForAddNew:(NSString *)label;
+ (UITableViewCell* )tableView:(UITableView *)tableView multiCloneRelationListCellForLabel:(NSString*) label;
+ (UITableViewCell *)tableView:(UITableView *)tableView listCellForItem:(LDMItem *)item field:(NSString *)field label:(NSString *)label row:(NSInteger)row forMultiCloneItems:(NSMutableOrderedSet*)multiCloneItems;

@end
