//
//  LDMDataManager+Save.h
//  LDCore
//
//  Created by Bryan Nagle on 2/6/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@class LDMItem, FMDatabase;

@interface LDMDataManager (Client)

/*!
 * @discussion Synchronous call to send one item to the server with action = Save
 * @param item The LDMItem to be sent to the server
 * @return TRUE if item is successfully written to the database, FALSE otherwise
 */
- (BOOL)persistItem:(LDMItem *)item;

/*!
 * @discussion Synchronous call to send many items to the server with action = Save
 * @param items An array of LDMItems to be sent to the server
 * @return TRUE if the items are successfully written to the database, FALSE otherwise
 */
- (BOOL)persistItemsFromArray:(NSArray *)items;

/*!
 * @discussion Asynchronous call to send item to the server with action = Save
               callback occurs after item is written to local database
 * @param item The LDMItem to be sent to the server
 * @param completionHandler Asynchronous callback block after save is completed
 */
- (void)persistItem:(LDMItem *)item withCompletionHandler:(void (^)(BOOL success))completionHandler;

/*!
 * @discussion Asynchronous call to send many items to the server with action = Save
               callback occurs after items are written to local database
 * @param items An array of LDMItems to be sent to the server
 * @param completionHandler Asynchronous callback block after save is completed
 */
- (void)persistItemsFromArray:(NSArray *)items withCompletionHandler:(void (^)(BOOL success))completionHandler;

/*!
 * @discussion Send an item to the server with action = Save as part of a transaction.
 * @warning Transactions are not sent to the server until commitTransaction is called
 * @param item The LDMItem to be sent to the server
 * @param transactionName The transaction ID this action is added to
 */
- (void)persistItem:(LDMItem *)item inTransaction:(NSString *)transactionName;

/*!
 * @discussion Send items to the server with action = Save as part of a transaction.
 * @warning Transactions are not sent to the server until commitTransaction is called
 * @param items An array of LDMItems to be sent to the server
 * @param transactionName The transaction ID this action is added to
 */
- (void)persistItemsFromArray:(NSArray *)items inTransaction:(NSString *)transactionName;

/*!
 * @discussion Synchronous call to send one item to the server 
               with action = Create if new, Update otherwise
 * @param item The LDMItem to be sent to the server
 * @return TRUE if item is successfully written to the database, FALSE otherwise
 */
- (BOOL)transactCreateOrUpdateWithItem:(LDMItem *)item;

/*!
 * @discussion Synchronous call to send items to the server 
               with action = Create if new, Update otherwise
 * @param items An array of LDMItems to be sent to the server
 * @return TRUE if item is successfully written to the database, FALSE otherwise
 */
- (BOOL)transactCreateOrUpdateWithItems:(NSArray *)items;

/*!
 * @discussion Asynchronous call to send one item to the server
               with action = Create if new, Update otherwise
 * @param item The LDMItem to be sent to the server
 * @param completionHandler Asynchronous callback block after save is completed
 */
- (void)transactCreateOrUpdateWithItem:(LDMItem *)item withCompletionHandler:(void (^)(BOOL success))completionHandler;

/*!
 * @discussion Asynchronous call to send items to the server
               with action = Create if new, Update otherwise
 * @param items Array of LDMItems to be sent to the server
 * @param completionHandler Asynchronous callback block after save is completed
 */
- (void)transactCreateOrUpdateWithItems:(NSArray *)items withCompletionHandler:(void (^)(BOOL success))completionHandler;

/*!
 * @discussion Send one item to the server with action = Create if new,
               Update otherwise as part of a transaction
 * @warning Transactions are not sent to the server until commitTransaction is called
 * @param item The LDMItem to be sent to the server
 * @param transactionName The transaction ID this action is added to
 */
- (void)transactCreateOrUpdateWithItem:(LDMItem *)item inTransaction:(NSString *)transactionName;

/*!
 * @discussion Send items to the server with action = Create if new,
               Update otherwise as part of a transaction
 * @warning Transactions are not sent to the server until commitTransaction is called
 * @param items Array of LDMItems to be sent to the server
 * @param transactionName The transaction ID this action is added to
 */
- (void)transactCreateOrUpdateWithItems:(NSArray *)items inTransaction:(NSString *)transactionName;


/*!
 * @discussion Synchronous call to delete one item
 * @param item The LDMItem to be deleted
 * @return TRUE if item is successfully deleted from local database, FALSE otherwise
 */
- (BOOL)transactDeleteWithItem:(LDMItem *)item;

/*!
 * @discussion Synchronous call to delete an array of items
 * @param items Array of LDMItems to be deleted
 * @return TRUE if item is successfully deleted from local database, FALSE otherwise
 */
- (BOOL)transactDeleteWithItems:(NSArray *)items;

/*!
 * @discussion Asynchronous call to delete one item
 * @param item The LDMItem to be deleted
 * @param completionHandler Asynchronous callback block after delete is executed
 */
- (void)transactDeleteWithItem:(LDMItem *)item withCompletionHandler:(void (^)(BOOL success))completionHandler;

/*!
 * @discussion Asynchronous call to delete many items
 * @param items Array of LDMItems to be deleted
 * @param completionHandler Asynchronous callback block after delete is executed
 */
- (void)transactDeleteWithItems:(NSArray *)items withCompletionHandler:(void (^)(BOOL success))completionHandler;

/*!
 * @discussion Delete an item as part of a transaction
 * @warning Transactions are not sent to the server until commitTransaction is called
 * @param item The LDMItem to be sent to the deleted
 * @param transactionName The transaction ID this action is added to
 */
- (void)transactDeleteWithItem:(LDMItem *)item inTransaction:(NSString *)transactionName;

/*!
 * @discussion Delete items as part of a transaction
 * @warning Transactions are not sent to the server until commitTransaction is called
 * @param items An array of LDMItems to be sent to the deleted
 * @param transactionName The transaction ID this action is added to
 */
- (void)transactDeleteWithItems:(NSArray *)items inTransaction:(NSString *)transactionName;

/*!
 * @discussion Initialization of a new transaction
 * @param transactionName The unique key to define the newly created transaction
 */
- (void)beginTransaction:(NSString *)transactionName;

/*!
 * @discussion Revert all actions that were part of a transaction
 * @param transactionName The unique key to locate the transaction
 */
- (void)rollbackTransaction:(NSString *)transactionName;

/*!
 * @discussion Execute all pending actions in the transaction
 * @param transactionName The unique key to locate the transaction
 */
- (void)commitTransaction:(NSString *)transactionName;


- (void)transactCreateOrUpdateWithCompositeBlockItem:(LDMItem*)compositeBlockItem onlineParent:(BOOL)onlineParent withCompletionHandler:(void (^)(BOOL success))completionHandler;

- (void) updateBlockIndexPathsForBlockItem:(LDMItem*)blockItem fromIndexPath:(NSIndexPath*)fromIndexPath toIndexPath:(NSIndexPath*)toIndexPath withCompletionHandler:(void (^)(BOOL success, LDMItem *item))completionHandler;


@end
