//
//  LDMItemSet.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 5/26/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface LDMItemSet : NSObject

@property (readonly) NSInteger count;

- (LDMItem *)itemAtIndex:(NSInteger)index;
- (LDMItem *)itemForId:(NSString *)itemId;
- (void)addItem:(LDMItem *)item;
- (void)replaceItemAtIndex:(NSInteger)index withItem:(LDMItem *)item;
- (void)removeItemAtIndex:(NSInteger)index;

@end
