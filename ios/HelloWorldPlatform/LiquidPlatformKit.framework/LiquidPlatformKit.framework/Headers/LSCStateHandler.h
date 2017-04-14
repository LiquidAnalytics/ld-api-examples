//
//  LSCStateHandler.h
//  seaside
//
//  Created by Bryan Nagle on 7/10/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LSCSyncController;

@interface LSCStateHandler : NSObject

@property int callNumber;

+ (void)executeOnThread:(NSThread *)thread;
+ (void)executeOnThread:(NSThread *)thread withParams:(NSDictionary *)params;
+ (void)execute;
+ (void)executeWithParams:(NSDictionary *)params;

- (void)didMoveToState;

@end


