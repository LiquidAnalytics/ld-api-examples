//
//  LDMDefinition.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 4/27/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDMItemPath;

@interface LDMDefinition : NSObject <NSCopying>

@property (strong) NSMutableDictionary *dict;
@property (nonatomic, strong) LDMItemPath *path;

- (id)initWithDict:(NSDictionary *)aDict;

- (id)initWithDefinition:(LDMDefinition *)definition;

- (void)setDataFromDictionary:(NSDictionary*)aDict;

- (NSString*) JSONString;

- (BOOL)isEmpty;

- (BOOL) booleanValueForKey:(NSString *)key withDefault:(BOOL)defaultVal;

@end
