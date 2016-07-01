//
//  NSMutableString+ModifySQLExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 6/7/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableString (ModifySQLExtensions)

- (void)insertStringBeforeFromClause:(NSString *)string;

@end
