//
//  LDMContext.h
//  LDCore
//
//  Created by David Ellis on 2014-04-29.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMSearchResults.h"

#define LDMContextDidChangeNotification         @"LDMContextDidChangeNotification"

@class LDMItem, LDMItemPath, LDMQueryFilter;

@interface LDMContext : NSObject


@property (nonatomic, strong) LDMItem *coreItem;
@property (nonatomic, strong) NSString *coreItemType;
@property (nonatomic, strong) LDMItem *user;
@property (nonatomic, strong) LDMItem *cart;
@property (nonatomic, strong) LDMItem *accountForOrg;

@property (readonly) LDMItemPath *path;

+ (LDMContext *)contextWithItems:(NSArray *)items;
+ (LDMContext *)contextWithItem:(LDMItem *)item;
- (NSArray *)allItems;
- (id)initWithContext:(LDMContext *)context;
- (LDMItem *)itemOfType:(NSString *)type;
- (void)setItems:(NSArray *)items;
- (void)setItem:(LDMItem *)item;
- (void)setItem:(LDMItem *)item forType:(NSString *)type;
- (LDMContext *)contextForStore:(NSString *)storeName;
- (LDMItem *)itemOfType:(NSString *)type fromStore:(NSString *)storeName;
- (void)setItem:(LDMItem *)item forType:(NSString *)type forStore:(NSString *)storeName;

- (LDMQueryFilter*)queryFilterForKey:(NSString*)key;
- (void)setQueryFilter:(LDMQueryFilter *)qf forKey:(NSString*)key;
- (void)removeQueryFilterForKey:(NSString *)key;

- (void)setCachedSearchResults:(LDMSearchResults *)searchResults  forKey:(NSString *)keyName;
- (LDMSearchResults *)getCachedSearchResults:(NSString *)keyName;

- (LDMItem *)lastAdded;
- (LDMItemPath *)pathForStore:(NSString *)storeName;
- (NSUInteger)resetContextToItem:(LDMItem *)newItem;
- (NSUInteger)resetContextToBeforeItem:(LDMItem *)newItem;
- (void)removeAllObjects;


@end
