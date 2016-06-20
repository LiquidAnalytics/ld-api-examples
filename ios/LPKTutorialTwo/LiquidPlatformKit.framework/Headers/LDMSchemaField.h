//
//  LDMSchemaField.h
//  LiquidDataModel
//
//  Created by Mike Akers on 4/22/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013 2014 All rights reserved
//

#import <Foundation/Foundation.h>

static NSString * const DATATYPE_BOOLEAN        = @"boolean";
static NSString * const DATATYPE_DATE           = @"date";
static NSString * const DATATYPE_DECIMAL        = @"decimal";
static NSString * const DATATYPE_DIMENSION      = @"dimension";
static NSString * const DATATYPE_INT            = @"int";
static NSString * const DATATYPE_LIST           = @"list";
static NSString * const DATATYPE_REFNUM         = @"refnum";
static NSString * const DATATYPE_STRING         = @"string";
static NSString * const DATATYPE_JSONELEMENT    = @"jsonElement";
static NSString * const DATATYPE_EMAIL          = @"email";
static NSString * const DATATYPE_PHONE          = @"phone";
static NSString * const DATATYPE_BINARY         = @"binary";
static NSString * const DATATYPE_ENUM           = @"enumeration";
static NSString * const DATATYPE_HTML           = @"HTML";
static NSString * const DATATYPE_URL            = @"url";
static NSString * const DATATYPE_BLOCK          = @"block";

typedef NS_ENUM(NSUInteger, LDMFieldType) {
    LDMFieldTypeBoolean,
    LDMFieldTypeDate,
    LDMFieldTypeDecimal,
    LDMFieldTypeDimension,
    LDMFieldTypeInteger,
    LDMFieldTypeList,
    LDMFieldTypeRefnum,
    LDMFieldTypeString,
    LDMFieldTypeBinaryData,
    LDMFieldTypeURL,
    LDMFieldTypeJsonElement,
    LDMFieldTypeEmail,
    LDMFieldTypeEnumeration,
    LDMFieldTypeHTML,
    LDMFieldTypePhone,
    LDMFieldTypeBlock
};

@class LDMItemSchema;

@interface LDMSchemaField : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *application;
@property (nonatomic, strong) NSString *aliasApplicationRead;
@property (nonatomic) BOOL includeInChecksum;
@property (nonatomic, strong) NSString *dataType;
@property (nonatomic, strong) NSString *dimensionType;
@property (nonatomic, strong) NSString *dimensionLevel;
@property (readonly) LDMFieldType fieldType;
@property (readonly) LDMFieldType listElementFieldType;
@property (nonatomic, readonly) NSString *SQLType;
@property (nonatomic, strong) NSString *label;
@property (nonatomic) BOOL primary;
@property (nonatomic) BOOL dimensionDisplay;
@property (nonatomic) BOOL dimensionParentValue;
@property (nonatomic) BOOL dimensionValue;
@property (nonatomic, strong) NSString *aliasDevice;
@property (nonatomic, strong) NSString *comment;
@property (nonatomic, strong) NSString *format;
@property (nonatomic) NSInteger orderDetailView;
@property (nonatomic) NSInteger orderListView;
@property (nonatomic, strong) NSDictionary *primaryFieldTableAlias;
@property (nonatomic) BOOL required;
@property (nonatomic) BOOL requiredCreate;
@property (nonatomic) BOOL requiredDelete;
@property (nonatomic) BOOL requiredRead; 
@property (nonatomic) BOOL requiredUpdate;
@property (nonatomic, strong) NSString *rule;
@property (nonatomic, strong) NSString *source;
@property (nonatomic, strong) NSString *geocodeType;
@property (nonatomic, strong) NSString *listOfMaps;
@property (nonatomic, strong) NSString *tableSource;
@property (nonatomic, strong) NSString *tableField;
@property (nonatomic, strong) NSString *filterCondition;
@property (nonatomic, strong) NSString *searchIndexType;
@property (nonatomic, strong) NSString *searchIndexName;
@property (nonatomic, strong) NSString *cloneAction;
@property (nonatomic, strong) NSString *defaultValue;
@property (nonatomic, strong) NSString *listElementType;
@property (nonatomic, strong) NSString *itemType;
@property (nonatomic, strong) NSString *blockType;
@property (nonatomic) BOOL doNotTransact;
@property (strong) NSString *deviceStorageType;
@property (strong) NSString *serverStorageType;
@property (nonatomic, weak) LDMItemSchema *parent;
@property (nonatomic, strong) NSString *enumerationName;

- (id)initWithDict:(NSDictionary *)schemaDict;
- (BOOL)isSearchField;
- (NSString*)searchIndex;
- (BOOL)isDimensionList;
- (BOOL)isDimension;
- (BOOL)isEnumeration;
- (BOOL)belongsToListOfMaps;
- (BOOL)isList;
- (BOOL)isListOfRefNum;
- (BOOL)isListOfDimensions;
- (BOOL)isBlock;
- (BOOL)isListOfBlocks;
- (NSComparator)comparatorForType;
+ (NSComparator)comparatorForType:(NSString*)dataType;
- (id)fieldValueFromValue:(id)value;
- (id)serializeableFieldValueFromValue:(id)value;
- (BOOL)isDate;
- (BOOL)isNumeric;
- (BOOL)isDimensionType;

@end
