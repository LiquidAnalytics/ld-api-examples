//
//  LDKItemSelectViewController.h
//  LDCore
//
//  Created by David Ellis on 2014-04-07.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMSearchResults.h"
#import "LDKSearchBar.h"
#import "LDMDefinition.h"
#import "LDKFilterViewController.h"

@class LDMItem, LDMQueryFilter, LDKFilterView;

@protocol LDKItemSelectViewControllerDelegate;

@interface LDKItemSelectViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UISearchBarDelegate, LDMSearchResultsDelegate, LDKSearchBarButtonDelegate, LDKFilterDelegate, LDKCaptureViewControllerDelegate>

@property (strong, nonatomic, nullable) LDMSearchResults  *results; //Results that are shown in the list
@property (assign, nonatomic) BOOL showAlphaJump;          //Side Alpha Rolodex Shown
@property (assign, nonatomic) BOOL showSectionHeader;      //Show Section Headers at top of each section
@property (assign, nonatomic) BOOL multiSelectEnabled;
@property (assign, nonatomic) float cellHeight;             //Height of a cell
@property (strong, nonatomic, nullable) NSString *itemType;              //Passed to delegate to represent type
@property (strong, nonatomic, nullable) LDMItem *function;
@property (weak, nullable) id<LDKItemSelectViewControllerDelegate> delegate;
@property (weak, nullable) id configurationData;
@property (strong, nonatomic, nullable) NSMutableArray *selectedItems;
@property (strong, nonatomic, nullable) NSMutableArray *selectedItemIds;
@property (strong, nonatomic, nullable) LDMQueryFilter *queryFilter;
@property (strong, nonatomic, nullable) LDMQueryFilter *searchQueryFilter;


@property (weak, nonatomic, nullable) IBOutlet LDKSearchBar *_searchBar;
@property (weak, nonatomic, nullable) IBOutlet UITableView *_tableView;
@property (strong, nonatomic, nullable) NSMutableDictionary *sectionHeaderCache;
@property (strong, nonatomic, nullable) LDMDefinition *cellDefinition;
@property BOOL online;
@property BOOL irn;
@property BOOL disableFiltering;
@property (strong, nullable) LDMItem *relatedItem;
@property (strong, nullable) NSString *relationshipPath;
@property (strong, nullable) LDMQueryFilter *selectionQueryFilter;
@property (strong, nonatomic, nullable) NSString *headerButtonLabel;
@property (strong, nonatomic, nullable) LDKFilterView *filterView;
@property (assign, nonatomic) BOOL disableSearch;

@property (copy, nonatomic) void (^ __nonnull didCancel)(LDKItemSelectViewController * __nonnull controller);
@property (copy, nonatomic) void (^ __nonnull didSelectItem)(LDKItemSelectViewController * __nonnull controller, LDMItem * __nullable item);
@property (copy, nonatomic) void (^ __nonnull didSelectItems)(LDKItemSelectViewController * __nonnull controller, NSArray *__nonnull items);
@property (copy, nonatomic) void (^ __nonnull headerButtonPressed)(LDKItemSelectViewController * __nonnull controller, UIButton * __nonnull sender);

- (nonnull instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil;
- (nonnull instancetype)initWithItemsWithRelationNamed:(NSString * __nullable)relationshipPath toItem:(LDMItem * __nullable)item online:(BOOL)online;
- (nonnull instancetype)initWithItemsOfType:(NSString * __nullable)type withQueryFilter:(LDMQueryFilter* __nullable)qf online:(BOOL)online;
- (nonnull instancetype)initWithStaticResults:(LDMSearchResults * __nullable)results ofType:(NSString * __nullable)itemType;
- (nonnull instancetype)initWithFunction:(LDMItem * __nullable)aFunction;
- (void)filterViewHidden:(BOOL)hidden;
- (void)reloadData;

@end

@protocol LDKItemSelectViewControllerDelegate <NSObject>

@optional
- (void)LDKItemSelectViewController:(LDKItemSelectViewController * __nullable)controller selectedItem:(LDMItem * __nullable)item;
- (void)LDKItemSelectViewController:(LDKItemSelectViewController * __nullable)controller selectedItems:(NSArray * __nullable)items;
- (void)LDKItemSelectViewControllerDidCancel:(LDKItemSelectViewController * __nullable)controller;

@end
