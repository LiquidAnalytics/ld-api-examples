//
//  LDKFilterViewController.h
//  LDCore
//
//  Created by Marshall Hayden on 6/20/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMSearch;
@class LDMQueryFilter;
@protocol LDKFilterDelegate;

@interface LDKFilterViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

- (instancetype)initWithCellDef:(NSDictionary *)config identifier:(NSString *)identifier;
- (void)setupFromQueryFilter:(LDMQueryFilter *)queryFilter;

@property (weak) id<LDKFilterDelegate> delegate;
@property (nonatomic, readonly) LDMSearch *searchItem;
@property (nonatomic, assign) BOOL performOnlineQueries;

@end

@protocol LDKFilterDelegate

/** the query filter is a pre-compiled query filter that will match the search. */
- (void)filterViewController:(LDKFilterViewController *)controller searchSelected:(LDMSearch *)search queryFilter:(LDMQueryFilter *)queryFilter;

@end