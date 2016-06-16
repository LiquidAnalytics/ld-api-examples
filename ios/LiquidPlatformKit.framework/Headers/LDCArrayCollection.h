//
//  LDCArrayCollection.h
//  LDCore
//
//  Created by Bryan Nagle on 8/13/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDCArrayCollection : NSObject

@property (assign) BOOL allowDuplicates;
@property (readonly) NSMutableDictionary *mutableDictionary;
@property (readonly) NSArray *keys;
@property (readonly) NSInteger count;

+ (LDCArrayCollection *)arrayCollection;
- (NSMutableArray *)arrayForKey:(NSString *)key;
- (void)addObjectsFromArray:(NSArray *)array forKey:(NSString *)key;
- (void)addObject:(id)object forKey:(NSString *)key;
- (void)removeObject:(id)object forKey:(NSString *)key;
- (void)removeAllObjectsForKey:(NSString *)key;
- (void)removeAllObjectsOfClass:(Class)class forKey:(NSString *)key;
- (NSArray *)keys;
- (NSInteger)countForKey:(NSString *)key;
- (void)setup;

@end
