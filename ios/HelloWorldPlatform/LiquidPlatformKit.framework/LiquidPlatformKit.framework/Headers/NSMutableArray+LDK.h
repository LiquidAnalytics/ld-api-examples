//
//  NSMutableArray+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 9/26/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMDimension;

@interface NSMutableArray (LDK)

- (void)removeItem:(LDMItem *)item;
- (void)removeItemsInArray:(NSArray *)items;
- (BOOL)containsItem:(LDMItem *)item;
- (BOOL)containsItem:(LDMItem *)item matchField:(NSString *)matchField;
- (LDMItem *)findItem:(LDMItem *)item matchField:(NSString *)matchField;
- (void)removeObjectsOfClass:(Class)class;
- (void)removeDimensionWithPath:(NSString *)path;
- (LDMDimension *)dimensionForPath:(NSString *)path;
- (NSInteger)indexOfDimensionPath:(NSString *)path;
- (void)removeViews;
- (void)removeViewControllers;
- (void)addObjectIfNotPresentInArray:(id)anObject;
//- (void)addObjectsFromArrayIfNotPresentInArray:(NSArray *)otherArray; //TODO:

@end
