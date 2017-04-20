//
//  LDMItemSchema.h
//  LiquidDataModel
//
//  Created by Mike Akers on 4/22/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LDMSchemaRolePermissions)
{
    LDMSchemaFieldReadable = 0,
    LDMSchemaFieldWriteable = 1,
    LDMSchemaFieldHidden = 2
};

typedef NS_ENUM(NSUInteger, LDMSupportedOperations)
{
    LDMSupportedOperationNone = 0,
    LDMSupportedOperationCreate = 1 << 0,
    LDMSupportedOperationUpdate = 1 << 1,
    LDMSupportedOperationDelete = 1 << 2,
    LDMSupportedOperationSave = 1 << 3
};

@class LDMSchemaField;
@class LDMFilter;

@interface LDMItemSchema : NSObject <NSCopying>

@property (strong, nullable) NSString *viewOverrideType;
@property (strong, nonnull) NSString *type;
@property (strong, nonatomic, nullable) NSString *mainParentType;
@property (strong, nullable) NSArray *secondaryTypes;
@property (strong, nullable) NSString *name;
@property (strong, nullable) NSString *application;
@property (strong, nullable) NSString *aliasApplicationType;
@property (strong, nonnull) NSString *category;
@property (strong, nullable) NSString *permissionType;
@property (strong, nullable) NSString *priority;
@property (strong, nullable) NSString *schemaType;
@property (strong, nullable) NSString *viewSql;
@property (strong, nullable) NSString *clientViewStatement;
@property (strong, nullable) NSString *viewStatement;

@property (strong, nonnull) NSString *community;
@property (assign) BOOL writeable;
@property (assign) BOOL skipViewCreation;
@property (strong, nullable) NSString *viewName;

@property BOOL dimension;
@property BOOL geoLocatable;

@property (strong, nullable) NSString *applicationSource;
@property (strong, nullable) NSString *applicationSourceDelta;
@property (strong, nullable) NSString *crudBAPI;
@property (strong, nullable) NSString *loadType;
@property (strong, nullable) NSString *refreshSchedule;
@property (strong, nullable) NSString *rootType;
@property (strong, nullable) NSString * extendsType;
@property (readonly) BOOL isBlock;

/* referencing fields is discouraged. Instead use schemaFieldForField */
@property (strong, nonnull) NSMutableArray *fields; //Array of LDMSchemaField instances

/* referencing fieldsByName is discouraged. Instead use schemaFieldForField */
@property (readonly, nonnull) NSDictionary *fieldsByName;
@property (readonly) BOOL containsCoordinateField;

@property (readonly, nonnull) NSString *tableName;
@property (readonly, nullable) NSString *transactionTableName;
@property (readonly, nonnull) NSString *createTableSQLStatement;
@property (readonly, nullable) NSString *createBlockTableSQLStatement;
@property (readonly, nonnull) NSArray *dimensionSchemaFields;
@property (readonly, nonnull) NSArray *enumerationSchemaFields;
@property (readonly, nonnull) NSString *primaryFieldName;
@property (strong, nonatomic, nullable) NSArray *baseItemTypes;
@property (readonly, nullable) NSString *inhereitedType;


@property (readonly) LDMSupportedOperations supportedOperations;

- (nonnull id)initWithJSONString:(NSString *_Nonnull)schemaJSON;
- (nonnull id)initWithJSONData:(NSData *_Nonnull)schemaJSON;
- (void)setupWithDict:(NSDictionary*_Nullable)schemaDict;
- (NSArray *_Nonnull)dimensionSchemaFields;
-(BOOL)hasWordLookups;
- (NSString *_Nonnull)createTableSqlStatementForTableName:(NSString *_Nullable)tableName;
- (NSString *_Nonnull)createTableSQLStatementForTableName:(NSString *_Nullable)tableName withHeader:(NSString *_Nullable)headerSQLFragment andPksString:(NSString *_Nullable)pksString;
- (NSString *_Nonnull)tableNameWithSpecifier:(NSString *_Nullable)specifier forFieldName:(NSString *_Nullable)fieldName;
- (NSString *_Nullable)blockTableNameForFieldName:(NSString *_Nullable)fieldName;

- (BOOL)isClientComposite;

- (LDMSchemaField * _Nullable)schemaFieldForField:(NSString *_Nullable)field;
- (LDMSchemaField *_Nullable)blockField:(NSString *_Nullable)field;
- (LDMFilter *_Nullable)blockCondition:(NSString *_Nullable)field;

- (NSString *_Nonnull)primaryFieldName;
- (void) clearCachedFields;
- (NSString *_Nullable)addressFieldList:(BOOL)list;

/* Use of this method is discouraged. schemas should be defined in json and not modified.*/
- (void)addField:(LDMSchemaField *_Nonnull)field;
@end
