//
//  LDMItemPath.h
//  LDCore
//
//  Created by David Ellis on 2014-04-29.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMItem.h"
#import "LDMItemHeader.h"

#define ItemNotFound              -1

typedef enum {
    PathChangeNoneType,
    PathChangeAddType,
    PathChangeReplaceType,
    PathChangedRemoveType
} PathChangeType;

@interface LDMItemPath : NSObject<NSCoding, NSCopying>

@property (readonly) LDMItem *currentItem;
@property (readonly) NSString *url;
@property (readonly) NSUInteger count;
@property (nonatomic, copy) void (^pathChanged)(PathChangeType);

+ (id)path;
+ (id)pathWithArray:(NSArray *)array;
+ (id)pathWithItem:(LDMItem *)item;

- (id)initWithItem:(LDMItem *)item;
- (id)initWithArray:(NSArray *)newArray;
- (LDMItemPath *)stackItem:(LDMItem *)item;
- (void)insertItemBeforeFirstItem:(LDMItem *)item;
- (void)addItem:(LDMItem *)item;
- (LDMItem *)currentItem;
- (NSInteger)indexOfLastItemOfType:(NSString *)typeName;
- (LDMItem *)itemForIndex:(NSInteger)index;
- (LDMItem *)lastItemOfType:(NSString *)typeName;
- (void)removeLastOccuranceOfType:(NSString *)type;
- (void)addOrReplaceItemById:(LDMItem *)aItem;
- (void)addOrReplaceNearestOccuranceOfItem:(LDMItem *)item;
- (void)replaceItemAtIndex:(NSInteger)index withItem:(LDMItem *)item;
- (NSDictionary *)relationshipsDict;
- (BOOL)isEmpty;
- (NSString *)url;
- (NSString *)description;
- (void)addOrMoveItemToEndOfPathById:(LDMItem*)aItem;
- (void)pop;

@end
