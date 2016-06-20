//
//  LDKFullScreenDataGridViewController.h
//  LDCore
//
//  Created by Carson Li on 2014-07-31.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKDataGridView.h"
#import "LDKSearchBar.h"
#import "LDKFilterViewController.h"
#import "LDMSearchResults.h"

@class LDMQueryFilter;

@interface LDKFullScreenDataGridViewController : UIViewController <LDKDataGridViewDataSource,UISearchBarDelegate, LDKSearchBarButtonDelegate, LDKFilterDelegate, LDMSearchResultsDelegate>

@property (strong) LDMQueryFilter *queryFilter;
@property (strong) LDMQueryFilter *searchBarFilterQueryFilter;

-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil withConfig: config;

-(void) refresh;

@end
