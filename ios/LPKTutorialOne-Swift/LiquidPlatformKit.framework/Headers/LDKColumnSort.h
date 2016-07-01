//
//  LDKColumnSort.h
//  LDCore
//
//  Created by Bryan Nagle on 10/7/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDKColumnSort : NSObject

@property (strong, nonatomic) NSString *label;
@property (assign, nonatomic) BOOL ascending;

+ (LDKColumnSort *)columnSortLabel:(NSString *)aLabel ascending:(BOOL)aAscending;

@end
