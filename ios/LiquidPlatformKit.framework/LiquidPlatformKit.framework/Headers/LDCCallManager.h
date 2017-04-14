//
//  LDCCallManager.h
//  LDCore
//
//  Created by Bryan Nagle on 8/31/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>
//#import <Foundation/Foundation.h>

@interface LDCCallManager : NSObject

+ (LDCCallManager *) sharedInstance;
- (void) directCallWithNumber:(NSString*)number;

@end
