//
//  LDMDataManager.h
//  LiquidDataModel
//
//  Created by Mike Akers on 4/19/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

#import "LDMItemSchema.h"
#import "LDMFilter.h"

@class Reachability;
@class FMDatabaseQueue;
@class LDMItemSchema;
@class LDMItem;
@class LDMDefinition;
@class LDMRelationshipSchema;
@class LDMSearchResults;
@class LDMFilter;
@class LDMSchemaField;
@class LDMQuery;
@class LDMQueryFilter;
@class FMDatabase;
@class LDMIndex;
@class FMResultSet;

#if !(SQL_DEFAULT_FETCH_LIMIT)

#define SQL_DEFAULT_FETCH_LIMIT     250

#endif

@interface LDMDataManager : NSObject<NSCacheDelegate>

@property (atomic, strong) NSMutableDictionary * __nonnull itemSchemas; //key is type, value is itemSchema instance
@property (atomic, strong) NSMutableDictionary *__nonnull relationshipSchemas; //key is relationship name, value is relationshipSchema instance
@property (atomic, strong) NSMutableDictionary *__nullable edgeRelationshipSchemas; //key is relationship name, value is relationshipSchema instance

@property (strong) NSString *__nonnull dbName;

@property (strong) Reachability *__nonnull reachabilityForInternetConnection;
@property (strong, nonatomic) dispatch_queue_t __nonnull asyncCallbackQueue;
@property (strong, nonatomic) dispatch_queue_t __nonnull asyncReadQueue;
@property (strong, nonatomic) dispatch_queue_t __nonnull asyncOnlineQueue;
@property (strong, nonatomic) dispatch_queue_t __nonnull asyncWriteQueue;

@property (strong, nonatomic) dispatch_queue_t __nonnull backgroundQueue DEPRECATED_ATTRIBUTE;
@property (readonly) FMDatabaseQueue *__nonnull writerQueue; //TODO: don't count on this property being public in the future
@property (readonly) FMDatabase *__nonnull readOnlyDB;
@property (atomic, readonly) NSArray *__nonnull allItemTypes;
@property (atomic, readonly) NSArray *__nonnull allBlockTypes;
@property (strong) NSDictionary *__nonnull userRolesDict;

/** Class name prefix for LDMItem subclasses */
@property (strong) NSString *__nonnull modelClassPrefix;

@property BOOL optimizationInProgress;
@property (strong) NSURL *__nonnull standardRDSEndpoint;
@property (strong) NSMutableDictionary *__nonnull ldmTransactions;

+ (LDMDataManager *__nonnull) sharedInstance;

+ (NSString *__nonnull)urlencodeString:(NSString *__nullable)input;

- (NSString*__nonnull) retrieveServerURL;
- (NSBundle*__nonnull) LPKBundle;
- (NSString*__nonnull) constructURLStringWithParams:(NSDictionary*__nullable) params;

- (void)logDBErrors:(FMDatabase*__nonnull)db;
- (void)logDBErrors:(FMDatabase*__nonnull)db withMessage:(NSString*__nonnull)message;

// This is the new standard method for async computation. Nobody should internally do separate threading logic for LDM-async related code - call this instead.
- (void)executeAsynchOnThreadWithCompletionHandler:(void (^__nullable)(id __nullable))completionHandler block:(id __nonnull (^ __nonnull)())block;
- (void)executeAsynchWithCompletionHandler:(void (^__nullable)(id __nullable))completionHandler block:(id __nonnull (^__nonnull)())block;
- (void)executeAsynch:(void (^__nonnull)())block;

- (BOOL)openDatabaseWithName:(NSString* __nonnull)dbName;
- (BOOL)openDatabaseWithName:(NSString* __nonnull)databaseName andDefinitions:(NSArray * __nullable)definitions;
- (void)closeDatabase;
- (FMResultSet *__nullable)executeSelect:(NSString *__nonnull)query;
- (FMResultSet *__nullable)executeSelectWithArgs:(NSString *__nonnull)query, ... NS_REQUIRES_NIL_TERMINATION;

//Optimization and index creation
- (void)addIndexToBeCreatedLater:(LDMIndex* __nonnull)index;
- (void)optimizeDataWithCompletedBlock:(void (^__nullable)())completed statusBlock:(void(^__nonnull)(NSString *__nonnull statusMessage, float percentComplete))statusBlock;

//Schema handling
- (BOOL)processItemSchema:(LDMItemSchema* __nonnull)itemSchema json:(NSString*__nullable)itemSchemaJson;
- (BOOL)processRelationshipSchema:(LDMRelationshipSchema*__nonnull)relationshipSchema json:(NSString*__nonnull)relationshipSchemaJson;

//definition handling
- (void)updateDefinitionItem:(LDMItem* __nonnull) definition;
- (LDMDefinition* __nullable)getDefinitionFromJsonString:(NSDictionary* __nullable)definitionJSON withDefinitionType:(NSString* __nullable)definitionType;
- (LDMDefinition*__nullable)getDefinitionFromDict:(NSDictionary*__nullable)dict andDefinitionType:(NSString*__nullable)definitionType;
- (BOOL)loadDefinitionsFromJsonString:(NSString*__nullable)definitionJSON withDefinitionType:(NSString*__nullable)definitionType;
- (BOOL)loadDefinitionsFromJsonData:(NSData*__nullable)definitionJSON withDefinitionType:(NSString*__nullable)definitionType;
- (BOOL)loadDefinitionsFromDictionary:(NSDictionary*__nullable)definitionDict withDefinitionType:(NSString*__nullable)definitionType;
- (NSDictionary *__nullable)definitionsByNameForDefinitionType:(NSString*__nullable)definitionType;
- (LDMItemSchema *__nullable)itemSchemaByNameForItemType:(NSString*__nullable)itemType;

// new item creation
- (LDMItem * __nullable)itemInstanceForTypeName:(NSString * __nonnull)typeName;
- (LDMItem * __nonnull)itemInstanceForItemSchema:(LDMItemSchema * __nonnull)itemSchema;
- (LDMItem * __nonnull)itemInstanceForItemSchema:(LDMItemSchema * __nonnull)itemSchema withDataFromDictionary:(NSDictionary * __nullable)dict;
- (LDMItem * __nonnull)itemInstanceForItemSchema:(LDMItemSchema *__nonnull)itemSchema withDataFromDictionary:(NSDictionary * __nullable)dict convertBlocks:(BOOL)convertBlocks performCaseCheck:(BOOL)performCaseCheck;


- (LDMSearchResults* __nonnull)itemsWithRelationNamed:(NSString * __nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter;
- (LDMSearchResults* __nonnull)itemsWithRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter faultBlocks:(BOOL)faultBlocks;
- (void)itemsWithRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter andCompletionHandler:(void (^__nullable)(LDMSearchResults *__nonnull aResults))block;
- (void)itemsWithRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter faultBlocks:(BOOL)faultBlocks andCompletionHandler:(void (^__nullable)(LDMSearchResults *__nonnull aResults))block;

- (LDMSearchResults *__nonnull)searchWithText:(NSString*__nonnull)searchText andQueryFilter:(LDMQueryFilter *__nullable)queryFilter;
- (void)searchWithText:(NSString *__nonnull)searchText queryFilter:(LDMQueryFilter *__nullable)queryFilter andCompletionHandler:(void (^__nullable)(LDMSearchResults *__nonnull aResults))block;

- (BOOL)cacheItemsFromArray:(NSArray *__nullable)items usingFieldValues:(NSDictionary *__nullable)filterValues;
- (void)populateRelatedItem:(LDMItem *__nonnull)itemA fromItem:(LDMItem *__nonnull)itemB usingRelationship:(NSString *__nonnull)relationship;

//Dimensions
- (NSDictionary*__nonnull)dimensionValuesForCategory:(NSString*__nonnull) category andType:(NSString*__nonnull)type;

- (NSString*__nullable)dimensionValueForCategory:(NSString*__nonnull)category type:(NSString*__nonnull)type andValue:(NSString*__nonnull)value;

- (BOOL)isValidItemType:(NSString *__nonnull)string;

// Synchronous Direct SQL Methods
- (NSArray*__nonnull)fetchItemsOfType:(NSString *__nonnull)type fromSqlQuery:(NSString*__nonnull)sql;
- (NSArray*__nonnull)fetchItemsFromSqlQuery:(NSString*__nonnull)sql usingItemSchema:(LDMItemSchema*__nonnull)itemSchema inDatabase:(FMDatabase*__nullable)db faultBlocks:(BOOL)faultBlocks;

// Asynchronous Direct SQL Methods
- (void)fetchItemsOfType:(NSString *__nonnull)type fromSqlQuery:(NSString*__nonnull)sql andCompletionHandler:(void (^__nullable)(LDMSearchResults *__nonnull))completionHandler;
- (void)fetchItemsFromSqlQuery:(NSString*__nonnull)sql withItemSchema:(LDMItemSchema*__nonnull)itemSchema faultBlocks:(BOOL)faultBlocks andCompletionHandler:(void (^__nullable)(LDMSearchResults *__nonnull))completionHandler;

// Data Point Methods
- (void)dataPointsFromSqlStatement:(NSString *__nonnull)sqlStatement withCompletionHandler:(void (^__nullable)(NSArray *__nonnull))completionHandler;

// Syncronous Block Methods
- (LDMItem *__nullable)blockForField:(NSString *__nonnull)fieldName onItem:(LDMItem *__nonnull)item;
- (NSArray *__nonnull)blocksForField:(NSString *__nonnull)fieldName onItem:(LDMItem *__nonnull)item;

// Syncronous Block / List Access Methods
- (LDMItemSchema *__nullable)schemaFromCategoryType:(NSString *__nullable)itemPath;

// Synchronous Item Access Methods
- (LDMItem* __nullable)itemOfType:(NSString* __nonnull)typeName withId:(NSString* __nonnull)objectId;
- (LDMItem* __nullable)itemOfType:(NSString* __nonnull)typeName withId:(NSString* __nonnull)objectId faultBlocks:(BOOL)faultBlocks;

- (NSArray * __nonnull)allItemsOfType:(NSString * __nonnull)typeName;
- (NSArray * __nonnull)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter;
- (NSArray * __nonnull)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter faultBlocks:(BOOL)faultBlocks;
- (NSArray * __nonnull)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter sortBy:(NSArray * __nullable)sortBy;
- (NSArray * __nonnull)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter sortBy:(NSArray * __nullable)sortBy faultBlocks:(BOOL)faultBlocks;
- (NSArray * __nonnull)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter sortBy:(NSArray * __nullable)sortBy inDatabase:(FMDatabase* __nullable)db faultBlocks:(BOOL)faultBlocks distinct:(BOOL)distinct;

- (NSString * __nonnull)queryForAllItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter sortBy:(NSArray * __nullable)sortBy distinct:(BOOL)distinct;

// Asynchronous Item Access Methods
- (void)itemOfType:(NSString* __nonnull)typeName withId:(NSString* __nonnull)objectId completionHandler:(void (^ __nonnull)(LDMItem * __nullable))block;
- (void)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter completionHandler:(void (^ __nonnull)(LDMSearchResults * __nullable results))block;
- (void)allItemsOfType:(NSString * __nonnull)typeName withQueryFilter:(LDMQueryFilter * __nullable)queryFilter faultBlocks:(BOOL)faultBlocks completionHandler:(void (^ __nonnull)(LDMSearchResults * __nullable results))block;
- (void)allItemsOfType:(NSString *__nullable)typeName withQueryFilter:(LDMQueryFilter *__nullable)queryFilter sortBy:(NSArray*__nullable)sortBy faultBlocks:(BOOL)faultBlocks completionHandler:(void (^)(LDMSearchResults * __nullable results))block;

// Relationship methods
- (LDMSearchResults*__nullable)itemsWithRelationNamed:(NSString *__nonnull)relationshipName toItem:(LDMItem *__nonnull)item;
- (void)itemsWithRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withQueryFilter:(LDMQueryFilter *__nullable)queryFilter andCompletionHandler:(void (^__nullable)(LDMSearchResults *__nonnull results))block;
- (LDMSearchResults*__nullable)itemsWithRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withQueryFilter:(LDMQueryFilter *__nullable)queryFilter;
- (LDMItem *__nullable)itemFromRelationship:(NSString *__nonnull)relationship andParentItem:(LDMItem *__nonnull)parent;
- (void)itemWithRelationNamed:(NSString *__nonnull)relationshipName toItem:(LDMItem *__nonnull)item withCompletionHandler:(void (^__nullable)(LDMItem *__nullable))completionHandler;
- (LDMSearchResults*__nullable)itemsWithRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter sectionBy:(NSString *__nullable)sectionBy sectionDesc:(BOOL)sectionDesc groupBy:(NSString *__nullable)groupBy orderBy:(NSString *__nullable)orderBy orderDesc:(BOOL)orderDesc faultBlocks:(BOOL)faultBlocks;
- (NSArray *__nullable)itemsAndMapsWithRelationNamed:(NSString *__nonnull)relationshipName toItem:(LDMItem *__nonnull)item;

// LDMQuery Methods
- (LDMSearchResults *__nonnull)executeQuery:(LDMQuery *__nonnull)query;
- (LDMSearchResults *__nonnull)executeQuery:(LDMQuery *__nonnull)query withItem:(LDMItem * __nullable)item;
- (LDMSearchResults *__nonnull)executeQuery:(LDMQuery *__nonnull)query withItem:(LDMItem * __nullable)item faultBlocks:(BOOL) faultBlocks;

// LDMQueryFilter Methods
- (LDMQueryFilter *__nullable)queryFilterForKey:(NSString *__nonnull)key;
- (BOOL)setQueryFilter:(LDMQueryFilter *__nonnull)queryFilter forKey:(NSString *__nonnull)key;
- (BOOL)removeQueryFilterForKey:(NSString *__nonnull)key;

// Access to all definitions for the localization
- (NSDictionary *__nullable)allDefinitions;
- (LDMDefinition *__nullable)definitionOfType:(NSString *__nonnull)defType forKey:(NSString *__nonnull)key;

// org.Role functionality
- (NSString *__nullable)userRoleTypesString;
- (NSDictionary *__nullable)permissionsDictionaryForType:(NSString *__nonnull)itemType;
- (LDMSchemaRolePermissions)permissionsForType:(NSString *__nonnull)itemType;
- (NSArray *__nullable)typesForPermission:(LDMSchemaRolePermissions)permission;

// Misc
- (NSString *_Nonnull)populateCommunityNameForSQLStatement:(NSString *_Nonnull)statement;

/**
 * Be very careful using this method. Inside the block callback operations are still happening inside the DB transaction. Accessing the DB again inside the block will cause a deadlock.
 */
- (void)executeQuery:(NSString*__nonnull)query enumerateResultsUsingBlock:(void (^__nonnull)(NSDictionary*__nullable))block;
- (BOOL)executeUpdateQuery:(NSString *__nonnull)query;
- (BOOL)executeUpdateQuery:(NSString*__nonnull)query numRetries:(int)retries withDelay:(NSTimeInterval)delay;
- (void)faultBlocksForItems:(NSArray *__nonnull)items ofType:(NSString *__nonnull)type inDatabase:(FMDatabase*__nullable)db;
- (void)addItemSchema:(LDMItemSchema *__nonnull)itemSchema forType:(NSString *__nonnull)type;
- (void)updateTableForItemSchema:(LDMItemSchema *__nonnull)itemSchema withColumnDictionary:(NSDictionary *__nonnull)columnDict;

- (NSArray*__nullable)itemsOfType:(NSString *__nonnull)typeName withIds:(NSArray *__nonnull)objectIds faultBlocks:(BOOL)faultBlocks;

- (NSString *__nullable)queryForItemsWithSingleRelationNamed:(NSString *__nonnull)complexRelationshipName toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter sectionBy:(NSString *__nullable)sectionBy sectionDesc:(BOOL)sectionDesc groupBy:(NSString *__nullable)groupBy orderBy:(NSString *__nullable)orderBy orderDesc:(BOOL)orderDesc resultType:(NSString *__nullable*__nullable)resultType;
- (NSString *__nonnull)queryForItemsWithSingleRelationNamed:(NSString *__nonnull)relationshipPath toItem:(LDMItem *__nonnull)item withSupportingItems:(NSDictionary *__nullable)items withQueryFilter:(LDMQueryFilter *__nullable)queryFilter sectionBy:(NSString *__nullable)sectionBy sectionDesc:(BOOL)sectionDesc groupBy:(NSString *__nullable)groupBy orderBy:(NSString *__nullable)orderBy orderDesc:(BOOL)orderDesc resultType:(NSString *__nullable*__nullable)resultType resultTable:(NSString *__nullable*__nullable)resultTable dialect:(LDMFilterDialect)dialect dynamic:(BOOL)dynamic;

- (NSString *__nonnull)itemTypeFromBlockType:(NSString *__nonnull)blockType sourceItem:(LDMItem *__nullable)source inDatabase:(FMDatabase*__nullable)db;
- (BOOL)expandBlockSchemaField:(LDMSchemaField *__nonnull)schemaField onItem:(LDMItem*__nonnull)item inDatabase:(FMDatabase*__nullable)db;
- (BOOL)expandListForSchemaField:(LDMSchemaField *__nonnull)schemaField onItem:(LDMItem*__nonnull)item inDatabase:(FMDatabase*__nullable)db;

- (BOOL)executeSaveUpdateForItem:(LDMItem*__nonnull)item inDatabase:(FMDatabase*__nonnull)db;
- (BOOL)executeSaveUpdateForItems:(NSArray *__nonnull)items inDatabase:(FMDatabase *__nonnull)db;

- (BOOL)executeSaveUpdateForItem:(LDMItem*__nonnull)item intoTableNamed:(NSString *__nonnull)tableName inDatabase:(FMDatabase*__nonnull)db;

- (BOOL)_saveItemsFromArray:(NSArray*__nonnull)items markAsUnverified:(BOOL)markAsUnverified;

- (void)dropDatabase;

- (NSMutableArray*__nonnull)itemInstancesForBlockDictionaries:(NSArray *__nullable)itemDicts parentItem:(LDMItem *__nullable)parentItem parentFieldName:(NSString *__nullable)parentFieldName;
- (NSArray*__nonnull)itemInstancesForItemDictionaries:(NSArray *__nullable)itemDicts;

- (BOOL)executeDeleteForItems:(NSArray *__nonnull)items inDatabase:(FMDatabase *__nonnull)db;

- (BOOL)executeTransactionUpdateForItems:(NSArray*__nonnull)items inDatabase:(FMDatabase*__nonnull)db;
- (BOOL)hasPermissionForGadgetId:(NSString *__nonnull)gadgetid;
- (NSArray *__nonnull)listsForField:(NSString *__nonnull)fieldName onItem:(LDMItem *__nonnull)item;
- (void)generateListViewsForAllSchemas;

- (void)prepareType:(NSString *_Nonnull)itemType;
- (void)truncateType:(NSString *_Nonnull)itemType;

@end


