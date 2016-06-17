//
//  LDMCacheManager.h
//  LiquidDataModel
//
//  Created by Bryan Nagle on 8/20/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface LDMCacheManager : NSObject

@property (atomic, strong) NSCache *dimensionCache;
@property (atomic, strong) NSCache *itemCache;

@end
