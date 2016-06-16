//
//  NSArray+LDMValuationExtensions.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 7/8/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface NSArray (LDMValuationExtensions)

- (BOOL)evaluateWithItem:(LDMItem *)item;

@end
