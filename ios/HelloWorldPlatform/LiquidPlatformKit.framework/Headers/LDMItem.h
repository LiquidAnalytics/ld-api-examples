//
//  LDMItem.h
//  LiquidDataModel
//
//  Created by Mike Akers on 4/19/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import "JSONKitRepresentation.h"

typedef NS_ENUM(NSUInteger, LDMItemSource)
{
    LDMItemSourceLocal,
    LDMItemSourceOnline
};

@class LDMItemSchema, LDMItemHeader;

@interface LDMItem : NSObject<MKAnnotation, JSONKitRepresentation>

@property (strong, nonnull) LDMItemSchema *itemSchema;
@property (readonly) BOOL hasBaseItem;
@property (readonly, nonnull) LDMItem *baseItem;
@property (readonly, nonnull) NSString *primaryString;
@property (readonly, nonnull) NSString *primaryKey;
@property (strong, nullable) UIImage *mapIcon;
@property (strong, nonnull) LDMItemHeader *header;
@property (strong, nonnull) NSMutableDictionary *dataDict;
@property (readonly, nonnull) NSArray *primaryFields;
@property (readonly, nonnull) NSString *primaryField;
@property (assign) LDMItemSource itemSource;

- (nonnull instancetype)initWithDict:(NSDictionary *__nullable)dict;
+ (NSString * __nonnull)generateId;
- (nonnull id)initWithItemSchema:(LDMItemSchema*__nonnull)itemSchema;
- (nonnull id)initWithItemSchema:(LDMItemSchema*__nonnull)anItemSchema addDynamicMethods:(BOOL)addDynamic;
- (nonnull id)initWithType:(NSString*__nonnull)itemType withDataDict:(NSDictionary*__nullable)dataDictionary withHeaderDict:(NSDictionary*__nullable)headerDictionary;

- (void)setDataFromDictionary:(NSDictionary*__nullable)dataDict;
- (void)setDataFromDictionary:(NSDictionary*__nullable)aDict convertBlocks:(BOOL)convertBlocks performCaseCheck:(BOOL)performCaseCheck;

- (void)copyDataFromDictionary:(NSDictionary*__nullable)aDict;

- (void)newRevision;
- (void)setup;
- (BOOL)hasBaseItem;
- (void)blocksToBaseItems;
- (LDMItem *__nonnull)baseItem;
- (BOOL)wasSynced;
- (void) autoSetPrimaryKeys;
- (NSString *__nonnull)primaryKeyWithNoDefault;
- (NSString *__nonnull)primaryKey;
- (NSString *__nonnull)primaryString;
- (NSString *__nonnull)primaryStringWithDelimiter:(NSString *__nonnull)delimiter;
- (NSString *__nonnull)primaryStringWithDelimiter:(NSString *__nonnull)delimiter includeHeaderFields:(BOOL)includeHeader;
- (LDMItem *__nonnull)convertToType:(NSString *__nonnull)type;
- (id __nullable)valueForComplexKey:(NSString *__nonnull)complexKey;
- (void) setValue:(id __nullable)value forComplexKey:(NSString *__nonnull)complexKey;
- (void)addDynamicSelectors;
- (id __nullable)rawValueForKey:(NSString *__nonnull)key;
- (void)setValuesForMatchingFieldsFromItem:(LDMItem *__nullable)aItem;
- (void)overwriteValuesFromItem:(LDMItem *__nullable)aItem;
- (void)replaceValuesFromItem:(LDMItem *__nullable)aItem;
- (void)copyHeaderAndDataFromItem:(LDMItem *__nullable)aItem;
- (unsigned long)crc32: (NSDictionary *__nullable)sourceDict;

- (NSArray *__nonnull)primaryFields;
- (void)faultBlocks:(void (^__nullable)(BOOL success, LDMItem * __nullable item))completionHandler;
- (void)addValueChangeObserver:(NSObject *__nonnull)observer options:(NSKeyValueObservingOptions)options;
- (void)addValueChangeObserver:(NSObject *__nonnull)observer forFieldNames:(NSArray *__nullable)fieldNames options:(NSKeyValueObservingOptions)options;
- (void)addValueChangeObserver:(NSObject *__nonnull)observer;
- (void)removeValueChangeObserver:(NSObject *__nonnull)observer;

- (BOOL)updateLocation:(CLLocation *__nullable)location;

@end
