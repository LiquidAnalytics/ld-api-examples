//
//  NSMutableString+LDCoreExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 1/25/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface NSMutableString (LDCoreExtensions)

- (void)appendString:(NSString *)string withDelimiter:(NSString *)delimiter;

@end
