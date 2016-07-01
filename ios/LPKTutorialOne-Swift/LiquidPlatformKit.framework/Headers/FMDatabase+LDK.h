//
//  FMDatabase+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 1/27/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "FMDatabase.h"
#import <UIKit/UIKit.h>
#import "sqlite3.h"

@interface FMDatabase (LDK)

- (void)addCustomFunctions;

@end
