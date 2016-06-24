//
//  LDKPersistedFilterRootViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 1/20/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKFilterRootViewController.h"

@class LDMQueryFilter;

@interface LDKPersistedFilterRootViewController : LDKFilterRootViewController

@property (strong) NSString *key;
@property (assign) BOOL loadSaved;

- (LDMQueryFilter *)savedFilters;
- (void)loadQueryFilter:(LDMQueryFilter *)queryFilter;
- (void)saveQueryFilter:(LDMQueryFilter *)queryFilter;

@end
