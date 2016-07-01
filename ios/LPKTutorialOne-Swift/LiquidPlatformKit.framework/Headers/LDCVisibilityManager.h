//
//  LDCVisibilityManager.h
//  LiquidDecisions
//
//  Created by Carson Li on 11/21/2013.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem, LDMContext, LDMItemPath, LDMDefinition;

@interface LDCVisibilityManager : NSObject

+(BOOL) shouldLoadItemBasedOnHint:(LDMItem*) item withDict:(NSDictionary*) dict;

+(BOOL) shouldLoadItemBasedOnUser:(NSDictionary*) dict;
+(BOOL) shouldLoadItem:(LDMItem*) item  forFieldItem:(LDMItem*) fieldItem;
+(BOOL) shouldLoadItem:(LDMItem*) item  forDict:(NSDictionary*) dict;
+(BOOL) shouldLoadItem:(LDMItem*) item  forDict:(NSDictionary*) dict forContext:(LDMContext*) context forPath:(LDMItemPath*) path;
+ (BOOL)doesContainRoleTypeForDict:(NSDictionary*) dict;
+ (BOOL)doesRoleAllowForItem:(LDMItem*) item;
+ (LDMDefinition *)templateDefForItem:(LDMItem *)item;
+ (BOOL)evaluateRules:(NSArray *)visibilityDicts item:(LDMItem *)item context:(LDMContext *)context path:(LDMItemPath *)path invert:(BOOL)invertResult;
+ (BOOL)evaluateRules:(NSArray *)visibilityDicts item:(LDMItem *)item;

+ (BOOL)evaluateVisibility:(id)visibility item:(LDMItem *)item;
+ (BOOL)evaluateVisibility:(id)visibility item:(LDMItem *)item context:(LDMContext *)context path:(LDMItemPath *)path invert:(BOOL)invertResult;

@end
