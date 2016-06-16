//
//  NSNumber+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 11/20/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDKKeyPadViewController.h"

@interface NSNumber (LDK)

@property (readonly) NSString *percentString;
@property (readonly) NSString *decimalString;
@property (readonly) NSString *currencyString;
@property (readonly) NSString *intString;
@property (readonly) NSString *wordString;
@property (readonly) NSString *boolString;
- (NSString *)stringForKeypadFormat:(LDKKeyPadFormat)format;

@end
