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

- (id)addObserverForItemTypes:(NSArray *)itemTypes withResults:(LDMSearchResults *__nullable)results usingBlock:(void (^)())block;

- (id<NSObject> _Nonnull)addObserverForItemTypes:(NSArray<NSString*> * _Nonnull)itemTypes usingBlock:(void (^ _Nonnull)(NSDictionary<NSString *, NSDictionary<NSString*, __kindof LDMItem*>*> * _Nullable changeSubSet, NSDictionary<NSString*, id> * _Nullable deletesSubSet))block;
- (id<NSObject> _Nonnull)addObserverForItemType:(NSString * _Nonnull)itemType usingBlock:(void (^ _Nonnull)(NSDictionary<NSString *, __kindof LDMItem*>* _Nullable changesForTypeById, NSArray<NSString*> * _Nullable deletesForTypeById))block;
- (id)addObserverForItem:(LDMItem *)item usingBlock:(void (^)(LDMItem *__nullable aItem))block;

- (id)addObserverForItemType:(NSString *__nullable)itemType andClientId:(NSString *__nullable)clientId andHId:(NSString *__nullable) hId usingBlock:(void (^)(LDMItem *__nullable aItem))block;
- (id)addObserverForItemType:(NSString *__nullable)itemType andClientId:(NSString *__nullable)clientId usingBlock:(void (^)(LDMItem *__nullable aItem))block;
- (id)addObserverForClientId:(NSString *__nullable)clientId usingBlock:(void (^)(LDMItem *__nullable aItem))block;
- (id)addObserverOnField:(NSString *__nullable)field forValue:(NSString *__nullable)value usingBlock:(void (^)(LDMItem *__nullable aItem))block;
- (id)addObserverForItemType:(NSString *__nullable)itemType andClientIds:(NSArray *__nullable)clientIds usingBlock:(void (^)(NSArray *__nullable items))block;
- (id)addObserverForItems:(NSArray *__nullable)items ofType:(NSString *__nullable)itemType usingBlock:(void (^)(NSArray *__nullable items))block;

@end
