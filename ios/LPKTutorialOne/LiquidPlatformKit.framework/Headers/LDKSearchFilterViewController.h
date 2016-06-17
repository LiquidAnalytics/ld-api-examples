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
@protocol LDKSearchFilterDelegate;

@interface LDKSearchFilterViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

- (LDKSearchFilterViewController *__nonnull)initWithCellDef:(NSDictionary *__nonnull)config identifier:(NSString *__nonnull)identifier;
- (void)setupFromQueryFilter:(LDMQueryFilter *__nonnull)queryFilter;
- (void)submit;

@property (weak) id<LDKSearchFilterDelegate> __nullable delegate;
@property (nonatomic, readonly) LDMSearch * __nullable searchItem;
@property (nonatomic, assign) BOOL performOnlineQueries;

@end

@protocol LDKSearchFilterDelegate

- (void)filterViewController:(LDKSearchFilterViewController *__nonnull)controller didSubmitSearchText:(NSString *__nullable)searchText searchItem:(LDMSearch *__nullable)searchItem queryFilter:(LDMQueryFilter *__nullable)queryFilter;

@end