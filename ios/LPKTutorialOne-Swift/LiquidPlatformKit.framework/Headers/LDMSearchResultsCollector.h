//
//  LDMSearchResultsCollector.h
//  LDCore
//
//  Created by Marshall Hayden on 10/3/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMSearchResultsPaginated.h"

@interface LDMSearchResultsCollector : NSObject

+ (LDMSearchResultsCollector * __nonnull)collect:(LDMSearchResultsPaginated  * __nonnull)results withCallback:(void (^ __nonnull)(LDMSearchResultsCollector * __nonnull collector, NSArray * __nonnull allValues))callback;

@end
