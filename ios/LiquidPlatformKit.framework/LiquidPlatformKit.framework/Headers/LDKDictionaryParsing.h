//
//  LDKDictionaryParsing.h
//  LDCore
//
//  Created by Bryan Nagle on 3/18/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDKDictionaryParsing : NSObject

+ (NSString *)dataGridDefIdForDataGridDefDict:(NSDictionary *)dict item:(LDMItem *)item;

@end
