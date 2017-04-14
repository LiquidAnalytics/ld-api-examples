//
//  LDMSearchResults.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 5/14/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SearchResultsUpdateOption)
{
    SearchResultsUpdateHeaderCrcOption = (0x1 << 0),
    SearchResultsUpdateDataCrcOption = (0x1 << 1)
};

@class LDMSearchResults;
@class LDMSchemaField;
@class LDMDataManager;
@class LDMItem;

@protocol LDMSearchResultsDelegate <NSObject>

- (void)searchResultsDidAddNewRows:(LDMSearchResults * __nullable)results;
@optional
- (void)searchResultsDidChangeState:(NSInteger)state data:(NSDictionary * __nullable)data retry:(NSInteger)retry;
- (void)handleFetchError:(NSError * __nullable)error;

@end

@protocol LDMSearchResultsProtocol

@required
@property (readonly) NSInteger numberOfSections;
@property (readonly) NSInteger count;
@property (weak, nullable) id<LDMSearchResultsDelegate> delegate;

@optional
@property (nonatomic, copy, nullable) void (^searchResultsDidAddNewRows)(LDMSearchResults * __nullable results);
@property (readonly, nullable) NSArray *sectionIndexTitles;
@property (readonly, nullable) NSArray *allItems;
@property (readonly) BOOL isEmpty;
@property (readonly, nullable) LDMSchemaField *firstSegmentKey;
@property (readonly, nullable) NSMutableArray *sectionKeys;

- (id __nonnull)initWithResults:(NSArray * __nullable)results segmentedBy:(LDMSchemaField * __nullable) segmentKey dataManager:(LDMDataManager * __nullable) manager;
- (id __nonnull)initWithSingleSectionStaticResults:(NSArray * __nullable)results;
- (void)mergeWith:(LDMSearchResults * __nullable)searchResults usingDataManager:(LDMDataManager * __nullable)manager;
- (void)mergeResults:(NSArray * __nullable)results segmentedBy:(LDMSchemaField * __nullable)segmentKey dataManager:(LDMDataManager * __nullable)manager;
- (void)removeObjectAtIndexPath:(NSIndexPath * __nullable)indexPath;
- (NSInteger)numberOfRowsInSection:(NSInteger)section;
- (id __nullable)objectForRowAtIndexPath:(NSIndexPath * __nonnull)indexPath;
- (NSString * __nullable)titleForHeaderInSection:(NSInteger)section;
- (NSArray * __nullable)itemsInSection:(NSInteger)section;
- (void)mergeResultSegmentedByType:(NSArray * __nullable)results;
- (NSIndexPath * __nullable)indexForItem:(LDMItem * __nullable)mItem;
- (NSIndexPath * __nullable)indexForItem:(LDMItem * __nullable)mItem fromField:(NSString * __nullable)field toField:(NSString* __nullable)matchingField;
- (BOOL)updateResultsWithItems:(NSArray * __nullable)updatedItems;
- (NSArray * __nullable)distinctValuesForField:(NSString * __nullable)field;
- (NSInteger)sectionForSectionIndexTitle:(NSString * __nullable)title atIndex:(NSInteger)index;
- (NSString* __nullable)toSql;

- (void)updateItem:(LDMItem * __nullable)aItem withOptions:(SearchResultsUpdateOption)options andBlock:(void (^ __nullable)(LDMItem * __nullable item, NSIndexPath * __nullable indexPath, BOOL fetch))block;
- (void)updateItems:(NSArray * __nullable)aItems withOptions:(SearchResultsUpdateOption)options andBlock:(void (^ __nullable)(NSArray * __nullable indexPaths))block;
- (void)removeItemByClientId:(NSString * __nullable)clientId withBlock:(void (^ __nullable)(NSIndexPath * __nullable indexPath))block;

- (BOOL)containsExactItem:(LDMItem * __nullable)aItem;
- (BOOL)onlineData;

@end

@interface LDMSearchResults : NSObject <LDMSearchResultsProtocol>

@property (weak, nullable) id<LDMSearchResultsDelegate> delegate;

- (void)updateItems:(NSArray * __nullable)aItems withBlock:(void (^ __nullable)(NSArray * __nullable indexPaths))block;
- (void)removeItemsByClientIds:(NSArray * __nullable)clientIds withBlock:(void (^ __nullable)(NSArray * __nullable indexPaths))block;

@end
