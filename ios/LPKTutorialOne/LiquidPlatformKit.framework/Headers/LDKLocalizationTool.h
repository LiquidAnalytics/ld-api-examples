//
//  LDKLocalizationTool.h
//  LiquidDecisions
//
//  Created by Eric Johnson on 11/30/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface LDKLocalizationTool : NSObject
+ (void)logDefinition:(NSString *)string;
+ (LDKLocalizationTool *)sharedInstance;
+(NSString *)currentLanguage;
+(NSBundle *)currentBundle;

- (void)parseLocalizedStringFile;
@end
