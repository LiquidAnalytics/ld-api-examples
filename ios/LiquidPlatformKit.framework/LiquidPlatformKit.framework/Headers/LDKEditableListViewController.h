//
//  LDKEditableListViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 12/23/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKTextField.h"

@protocol LDKEditableListDelegate;

@interface LDKEditableListViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, UITextFieldDelegate, LDKTextFieldDelegate>

@property (strong) UITableView *tableView;
@property (nonatomic, strong) NSMutableArray *lines;
@property (strong) NSIndexPath *selectedIndexPath;
@property (weak) id<LDKEditableListDelegate> ldkDelegate;
@property (assign) BOOL editable;
@property (assign) BOOL selected;
@property (nonatomic, assign) BOOL scrollEnabled;

- (void)reloadData;
- (void)clearSelection;

@end


@protocol LDKEditableListDelegate <NSObject>

@optional

- (void)editableList:(LDKEditableListViewController *)controller didChangeValue:(NSString *)value forIndexPath:(NSIndexPath *)indexPath;
- (void)editableList:(LDKEditableListViewController *)controller didMoveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;
- (void)editableList:(LDKEditableListViewController *)controller didRemoveRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)editableList:(LDKEditableListViewController *)controller didInsertValue:(NSString *)value atIndexPath:(NSIndexPath *)indexPath;
- (void)editableList:(LDKEditableListViewController *)controller valuesDidChange:(NSArray *)values;
- (void)editableList:(LDKEditableListViewController *)controller didSelectValue:(NSString *)value forIndexPath:(NSIndexPath *)indexPath;

- (void)editableListDidEndEditing:(LDKEditableListViewController *)controller;

@end