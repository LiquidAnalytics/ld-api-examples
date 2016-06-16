//
//  LDMDataManager+Wordlookup.h
//  LDCore
//
//  Created by Marshall Hayden on 4/22/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@interface LDMDataManager (Wordlookup)

- (void)generateWordLookupForAllTypesWithStatusBlock:(void(^)(NSString *statusMessage, float percentComplete))statusBlock;
- (void)generateWordLookupForItems:(NSArray *)items;
- (void)deleteWordLookupForItems:(NSArray *)items;
- (LDMQueryFilter *)wordLookupWithSearchText:(NSString *)searchText byType:(NSString *)type fields:(NSArray*)fields;

@end
