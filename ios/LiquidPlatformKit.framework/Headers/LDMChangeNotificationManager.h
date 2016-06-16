//
//  LDMChangeNotificationManager.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 8/11/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

#define ITEMS_CHANGE_NOTIFICATION @"LDMItemsChangeNotification"
//#define ITEMS_MODIFIED_CHANGE_NOTIFICATION @"LDMItemsModifedChangeNotification"

@class LDMItem;

@interface LDMChangeNotificationManager : NSObject

+ (LDMChangeNotificationManager *)sharedInstance;
- (void)itemChanged:(LDMItem *)item;
- (void)itemsChanged:(NSArray *)items;
- (void)broadcast;
- (void)broadcastFromSource:(NSString *)source;
- (void)broadcastFromSource:(NSString *)source synchronous:(BOOL)synchronous;
- (void)deletedItem:(LDMItem *)item;
- (void)deletedItemOfType:(NSString*)type andClientId:(NSString *)clientId;
- (void)deletedItems:(NSArray *)items;
- (void)deletedItemsOfType:(NSString*)type andClientIds:(NSArray *)ids;

@end
