//
//  LDKIndexedMapArrays.h
//  LDCore
//
//  Created by Marshall Hayden on 6/25/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A map from String to Array. Each element in each array has an index. new elements are added to the end of the array for their key, which will shift down in index the elements in later keys.
 */
@interface LDKIndexedMapArrays : NSObject

@property (readonly) NSInteger count;

+ (LDKIndexedMapArrays *)indexedMapArrays;

/** returns the absolute index of the new value. Returns NSNotFound if the value is already in the array. */
- (NSInteger)addValue:(id)value forKey:(NSString *)key;

/** returns the absolute index of the first occurrence of this value if distinct = NO. Else same behavior as the method not specifying distinct param. */
- (NSInteger)addValue:(id)value forKey:(NSString *)key distinct:(BOOL)distinct;

/** returns the index of the first element of the new values */
- (NSInteger)setValues:(NSArray *)values forKey:(NSString *)key;

/** returns the values for the specified key. Modifying this array will put the datastructure in an inconsistent state! copy first. */
- (NSMutableArray *)valuesForKey:(NSString *)key;

/** Returns @[value, key] */
- (NSArray *)valueAndKeyAtIndex:(NSInteger)index;

- (void)removeValuesForKey:(NSString *)key;
- (void)removeValueAtIndex:(NSInteger)index;
- (NSInteger)removeValue:(id)value forKey:(NSString*) key;

- (void)clear;

- (NSArray *)allKeys;

@end
