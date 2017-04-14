//
//  LDCSystemInfo.h
//  LDCore
//
//  Created by Bryan Nagle on 8/29/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface LDCSystemInfo : NSObject

+ (double)currentMemoryUsageBytes;
+ (double)currentMemoryUsageMb;
+ (NSString *)memoryUsage;
+ (void)logMemoryUsage;

@end
