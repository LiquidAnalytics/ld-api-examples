//
//  LDMDataManager+Seaside.h
//  LDCore
//
//  Created by Bryan Nagle on 2/6/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

typedef NS_ENUM(NSUInteger, LDMSeasideEventType) {
    LDMSeasideEventTypeSubmit,
    LDMSeasideEventTypeReceive,
    LDMSeasideEventTypeVerify
};

typedef NS_ENUM(NSUInteger, LDMSeasideEventStatus) {
    LDMSeasideEventStatusOpen,
    LDMSeasideEventStatusReopen,
    LDMSeasideEventStatusPending,
    LDMSeasideEventStatusComplete
};

@interface LDMDataManager (Seaside)

- (BOOL)saveItemsFromArray:(NSArray*)items;
- (BOOL)saveItemsFromArray:(NSArray*)items markAsUnverified:(BOOL)markUnverified updateWordLookup:(BOOL)runWordLookup;

- (BOOL)deleteItem:(LDMItem*)item;
- (BOOL)deleteItems:(NSArray *)items;

//the following delete methods are deprecated
- (BOOL)deleteItemOfType:(NSString*)type withId:(NSString*)itemId;

- (void) initSeasideEventsInDb:(FMDatabase *)db;
- (void) reopenStuckPendingEvents;

/**
 Returns dictionary of clientId -> LDMSeasideEvent objects containing all open and pending transactions.
 */
- (NSMutableDictionary *) incompleteEventsOfType:(LDMSeasideEventType)eventType;

- (int) countOfOpenEventsOfType:(LDMSeasideEventType)eventType;

/**
 Finds open events of this type; marks them pending; returns dictionary of clientId -> LDMSeasideEvents
 */
- (NSMutableDictionary *) attemptEventsOfType:(LDMSeasideEventType)eventType;

/**
 Returns actual LDMItems for submit.
 */
- (NSDictionary *) itemsByIdForSubmitEvents:(NSDictionary *)events;

/**
 Input is array of LDMSeasideEvent objects. Those events will be removed because they are now complete
 */
- (void) completeEvents:(NSArray *)events;

/**
 Input is array of LDMSeasideEvent objects. Those events which are assumed to be currently pending will be reopend unless another transaction for the same item has begun.
 */
- (void) reopenEvents:(NSArray *)events;

/**
 Creates a new seaside event for submitting a transaction. This will cause any other open or pending seaside events for the same item to be terminated.
 */
- (void) openSubmitEvent:(NSString *)clientId itemType:(NSString *)itemType submitAction:(NSString *)submitAction;
- (void) openSubmitEvent:(NSString *)clientId itemType:(NSString *)itemType submitAction:(NSString *)submitAction inDatabase:(FMDatabase *)db;


/**
 Creates a new seaside event for receiving an item. The event will not be created if there is already an open or pending Submit event for this clientId.
 */
- (void) openReceiveEvent:(NSString *)clientId transactionId:(NSString *)transactionId;

/**
 Input is array of LDMItem objects. Creates a new seaside event for verifing each item. The event will not be created if there is already an open or pending Submit event for that clientId.
 */
- (void) openVerifyEvents:(NSArray *)items;

@end
