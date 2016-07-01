//
//  LDMRelationshipSchema.h
//  LiquidDataModel
//
//  Created by Marshall Hayden on 4/30/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LDMRelationshipSide) {
    LDMRelationshipSideFrom,
    LDMRelationshipSideTo
};

typedef NS_ENUM(NSInteger, LDMRelationshipDirection) {
    LDMRelationshipDirectionForward,
    LDMRelationshipDirectionReverse
};

typedef NS_ENUM(NSUInteger, LDMRelationshipFieldCategory) {
    LDMRelationshipFieldCategoryLiteral,
    LDMRelationshipFieldCategoryField,
    LDMRelationshipFieldCategoryBlockAndField,
    LDMRelationshipFieldCategoryNegatedLiteral
};

@class LDMItem;

@interface LDMRelationshipSchema : NSObject
@property (strong) NSString *name;
@property (strong) NSString *fromType;
@property (strong) NSArray *fromField;
@property (strong) NSString *toType;
@property (strong) NSArray *toField;
@property (strong) NSArray *moreFrom;
@property (strong) NSString *cloneAction;
@property BOOL exactDimensionMatch;
@property BOOL likeRelationType;
@property (readonly) BOOL isCompositeToExtendsRelation;

+ (NSArray *)relationshipSchemasForRelationPath:(NSString *)relationPath;

- (id)initWithJSONData:(NSData *)schemaJSON;
- (id)initWithJSONString:(NSString *)schemaJSON;
- (void)setupWithDict:(NSDictionary*)schemaDict;

- (NSString*)otherType:(NSString *)type;
- (NSString *)otherField:(NSString *)field;
- (NSArray *)fieldsForType:(NSString *)type;
- (NSString*)fieldAtIndex:(NSUInteger)index fromType:(NSString *)type usingItem:(LDMItem *) item;
- (id)fieldValueAtIndex:(NSUInteger)index fromItem:(LDMItem *)item;
- (NSUInteger)countOfFields;
- (NSUInteger)countOfFromFields;
- (BOOL)isCompositeToExtendsRelation;
+ (BOOL) isUnderlyingFromForside:(LDMRelationshipSide)side andDirection:(LDMRelationshipDirection)direction;
+ (LDMRelationshipFieldCategory) fieldCategory:(NSString *)value;
@end
