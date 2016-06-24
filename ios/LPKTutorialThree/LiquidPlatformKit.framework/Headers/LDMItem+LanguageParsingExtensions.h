//
//  LDMItem+LanguageParsingExtensions.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 9/8/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import "LDMItem.h"

@class LDMItemPath, LDMContext;

@interface LDMItem (LanguageParsingExtensions)

- (id __nullable)valueForStatement:(NSString * __nonnull)statement;
- (id __nullable)valueForStatement:(NSString * __nonnull)statement usingPath:(LDMItemPath * __nullable)path;
- (id __nullable)valueForStatement:(NSString * __nonnull)statement usingContext:(LDMContext * __nullable)context andPath:(LDMItemPath * __nullable)path;
- (NSArray * __nullable)evaluateParameters:(NSArray * __nullable)arrayIn;
- (void)clearKeyValuesFromSet:(NSArray * __nullable)keyValuesSet;
- (NSArray *__nullable)setKeyValuesFromSet:(NSArray * __nullable)keyValuesSet usingRelatedItem:(LDMItem * __nullable)relatedItem withContext:(LDMContext* __nullable)context withPath:(LDMItemPath* __nullable)path;
- (NSArray *__nullable)setKeyValuesFromSet:(NSArray * __nullable)keyValuesSet usingRelatedItem:(LDMItem * __nullable)relatedItem withPath:(LDMItemPath * __nullable)path;
- (NSArray *__nullable)setKeyValuesFromSet:(NSArray * __nullable)keyValuesSet;
- (id __nullable)valueForStatement:(NSString * __nullable)statement usingContext:(LDMContext * __nullable)context andPath:(LDMItemPath * __nullable)path withVariableDict:(NSDictionary * __nullable)varDict;
- (BOOL)isFieldValueValid:(NSString * __nullable)fieldName validateRules:(NSArray * __nullable)validateRules;
- (BOOL)matchesCriteriaForMatchFields:(NSArray* __nullable)matchFields;

@end
