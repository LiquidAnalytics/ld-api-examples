//
//  NSString+LDPathExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 6/5/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (LDPathExtensions)

@property (readonly) NSArray *pathComponents;
@property (readonly) NSInteger depth;
@property (readonly) NSString *value;
@property (readonly) NSString *family;

- (NSString *)valueForMember:(NSString *)member;
- (NSString *)family;
- (NSString *)lastLevel;
- (NSString *)displayForLevel;

@end
