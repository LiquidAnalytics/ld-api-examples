//
//  LDKContext.h
//  LDCore
//
//  Created by Bryan Nagle on 3/11/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface LDKContext : NSObject

@property (nonatomic, readonly) NSArray *__nonnull contextEntries;
@property (nonatomic, readonly) NSArray *__nonnull allItems;

/*!
 * @discussion The single instance method for retrieving the context
               used in swift classes
 */
+ (LDKContext * __nonnull)swiftContext;

/*!
 * @discussion The single instance method for retrieving the context 
               used in all objective c classes
 */
+ (LDKContext * __nonnull)context;

/*!
 * @discussion Retrieve item from context based on ContextEntry
 * @param entryName The name of the entry defined in ContextEntry
 * @return The associated LDMItem if found, nil otherwise
 */
- (LDMItem * __nullable)itemForEntryNamed:(NSString *__nonnull)entryName;

/*!
 * @discussion Retrieve all items of a particular type in the context
 * @param itemType the name of the item type
 * @return An array of LDMItems found in the context
 */
- (NSArray *__nullable)itemsOfType:(NSString *__nonnull)itemType;

/*!
 * @discussion Removes an item in the context based on ContextEntry
 * @param entryName The name of the entry defined in ContextEntry
 */
- (void)removeItemForEntryNamed:(NSString *__nonnull)entryName;

/*!
 * @discussion Add an item to the contexxt
 * @param item The LDMItem to be added
 */
- (void)addItem:(LDMItem *__nonnull)item;

/*!
 * @discussion Removes all items in the context
 */
- (void)reset;

@end