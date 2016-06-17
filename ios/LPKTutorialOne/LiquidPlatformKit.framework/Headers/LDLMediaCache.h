//
//  LDLMediaCache.h
//  LiquidDecisions
//
//  Created by Mike Akers on 9/19/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDCMediaAbstract;

@interface LDLMediaCache : NSObject
+ (LDLMediaCache *)sharedInstance;
+ (BOOL)deleteAllThumnails;

- (void)retrieveMediaForMediaAbstract:(LDCMediaAbstract*)mediaAbstract completionHandler:(void (^)(NSString* path))block failureBlock:(void (^)(NSError* error))failureBlock;
- (void)retrieveSearchResultsForItemType:(NSString *)itemType query:(NSString *)query userId:(NSString *)userId filters:(NSDictionary *)references completionHandler:(void (^)(NSArray *mediaIds))completionHandler;

- (void)retrieveMediaForMediaAbstractId:(NSString *)mediaId completionHandler:(void (^)(UIImage* image))block failureBlock:(void (^)(NSError* error))failureBlock;

- (void)retrieveMediaThumbnailForMediaAbstractId:(NSString *)mediaId completionHandler:(void (^)(UIImage* image))block failureBlock:(void (^)(NSError* error))failureBlock;

- (BOOL)isMediaThumbnailCached:(NSString*)mediaId;
- (BOOL)isMediaCached:(LDCMediaAbstract*)mediaAbstract;

- (NSString*)dataFileNameForMediaAbstract:(LDCMediaAbstract*)mediaAbstract;
- (NSString*)requestURLStringForMediaAbstract:(NSString *)mediaId thumbnail:(BOOL)thumbnail;
- (void)start;
- (void)clear;




@end
