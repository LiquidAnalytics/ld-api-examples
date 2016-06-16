//
//  NSString+ModifySQLExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 6/7/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (SQLExtensions)

- (NSRange)rangeOfFromStatement;
- (NSString *)aliasForTable:(NSString *)table;

@end
