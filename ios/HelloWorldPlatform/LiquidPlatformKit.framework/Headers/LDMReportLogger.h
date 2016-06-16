//
//  ReportLogger.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 6/18/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface LDMReportLogger : NSObject

+ (void)logValue:(NSString *)value forKey:(NSString *)key forReport:(NSString *)reportName;
+ (void)logValue:(NSString *)value forKey:(NSString *)key forReport:(NSString *)reportName shouldFlush:(BOOL)flush;
+ (void)flushReport:(NSString *)reportName;

@end
