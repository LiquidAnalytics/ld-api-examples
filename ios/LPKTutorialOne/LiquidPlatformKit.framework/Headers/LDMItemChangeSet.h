//
//  LDMItemSet.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 5/22/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>
@class LDMItem;

@interface LDMItemChangeSet : NSObject

@property (strong) NSString *uniqueField;
@property (readonly) NSArray *allItems;
@property (readonly) NSArray *originalItems;
@property (readonly) NSArray *addedItems;
@property (readonly) NSArray *modifiedItems;
@property (readonly) NSArray *removedItems;
@property (readonly) NSInteger count;
@property (readonly) NSString *description;

- (id)initWithItems:(NSArray *)items;
- (id)initWithItems:(NSArray *)items andUniqueField:(NSString*)newUniqueField;
- (void)setupWithItems:(NSArray *)items;
- (void)addItem:(LDMItem *)item;
- (void)replaceItemAtIndex:(NSInteger)index withItem:(LDMItem *)item;
- (LDMItem *)itemAtIndex:(NSInteger)index;
- (void)removeItemAtIndex:(NSInteger)index;

@end
