//
//  NSNotificationCenter+LDMExtensions.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 9/5/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDMItem, LDMSearchResults;

@interface NSNotificationCenter (LDMExtensions)

/*!
 * @discussion Receive callback on block whenever the item is updated through the server or transacted on the client
 * @param item The LDMItem to be observed on 
 * @param block The callback code when the item is modified. aItem is nil if the item is deleted.
 * @return The observer attached to the item parameter
 */
- (id<NSObject> __nonnull)addObserverForItem:(LDMItem *__nonnull)item usingBlock:(void (^__nonnull)(LDMItem *__nullable aItem))block;

/*!
 * @discussion Receive callback on block whenever one of more of the items is updated through the server or transacted on the client
 * @param items An array of LDMitems to be observed on
 * @param block The callback code when the item is modified
 * @return The observer attached to the list of items
 */
- (id<NSObject> __nonnull)addObserverForItems:(NSArray *__nullable)items ofType:(NSString *__nullable)itemType usingBlock:(void (^__nullable)(NSArray *__nullable items))block;

/*!
 * @discussion Receive callback on block whenever any item of a particular type is updated by the server or transacted on the client
 * @param itemType The item type to be observed on
 * @param block The callback code when the item type is modified.  changesForTypeById and deltesForTypeById both give the clientId
 * @return The observer attached to the item parameter
 */
- (id<NSObject> _Nonnull)addObserverForItemType:(NSString * _Nonnull)itemType usingBlock:(void (^ _Nonnull)(NSDictionary<NSString *, __kindof LDMItem*>* _Nullable changesForTypeById, NSArray<NSString*> * _Nullable deletesForTypeById))block;

/*!
 * @discussion Receive callback on block whenever any item of an array of types is updated by the server or transacted on the client
 * @param itemTypes An array of item types to observe on
 * @param block The callback code when the item type is modified.
 * @return The observer attached to the item parameter
 */
- (id<NSObject> _Nonnull)addObserverForItemTypes:(NSArray<NSString*> * _Nonnull)itemTypes usingBlock:(void (^ _Nonnull)(NSDictionary<NSString *, NSDictionary<NSString*, __kindof LDMItem*>*> * _Nullable changeSubSet, NSDictionary<NSString*, id> * _Nullable deletesSubSet))block;


@end
