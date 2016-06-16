//
//  ObjectTable.h
//  LDCore
//
//  Created by Bryan Nagle on 9/14/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDCArrayCollection.h"

@interface LDCObjectTable : LDCArrayCollection

- (NSInteger)numberOfSections;
- (NSInteger)numberOfRowsForSection:(NSInteger)section;
- (NSString *)sectionKeyForSection:(NSInteger)section;
- (NSInteger)sectionForSectionKey:(NSString *)sectionKey;
- (void)addSectionKey:(NSString *)key;
- (void)addSectionKeys:(NSArray *)keys;
- (void)dataForIndexPath:(NSIndexPath *)indexPath block:(void (^)(NSString *sectionKey, id object))block;
- (void)removeDataForIndexPath:(NSIndexPath *)indexPath;

@end
