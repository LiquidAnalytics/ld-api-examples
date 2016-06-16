//
//  LDMSearchResultsAggregated.h
//  LDCore
//
//  Created by Bryan Nagle on 11/7/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMSearchResults.h"

@interface LDMSearchResultsAggregated : LDMSearchResults <LDMSearchResultsProtocol, LDMSearchResultsDelegate>

- (id)initWithSearchResults:(NSArray *)aSearchResults andSectionTitles:(NSArray *)aSectionTitles;
- (void)addSearchResult:(LDMSearchResults *)aSearchResult sectionTitle:(NSString *)aSectionTitle;
- (void)removeSearchResultsAtIndexes:(NSIndexSet *)indexes;

@end
