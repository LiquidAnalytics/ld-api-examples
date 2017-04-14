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

/*!
* @discussion The singleton instance for the class. Only use this when working with LDLMediaCache
* @return The global instance of LDLMediaCache
*/
+ (LDLMediaCache *)sharedInstance;

/*!
 * @discussion Uploads media abstract item and associated media binary
 * @param imageData the media binary data
 * @param fieldValues a dictionary of values used to create the media item
 * @param completionHandler callback code block when the upload is complete
 */

- (void)uploadImageData:(NSData *)imageData withFieldValues:(NSDictionary *)fieldValues withCompletionHandler:(void (^)(BOOL sucesss))completionHandler;

/*!
 * @discussion Downloads the media given an media abstract item and returns the result in an async block
 * @param mediaAbstract The media abstract item in question
 * @param block success code block with a string of the local image location
 * @param failutreBlock failure code block that is called with error as parameter
 */
+ (BOOL)deleteAllThumnails;

- (void)retrieveMediaForMediaAbstract:(LDCMediaAbstract*)mediaAbstract completionHandler:(void (^)(NSString* path))block failureBlock:(void (^)(NSError* error))failureBlock;
- (void)retrieveSearchResultsForItemType:(NSString *)itemType query:(NSString *)query userId:(NSString *)userId filters:(NSDictionary *)references completionHandler:(void (^)(NSArray *mediaIds))completionHandler;

/*!
 * @discussion Downloads the media for a given media ID and returns the result in an async block
 * @param mediaId The media id PK used to find the media abstract item
 * @param block success code block with a string of the local image location
 * @param failutreBlock failure code block that is called with error as parameter
 */
- (void)retrieveMediaThumbnailForMediaAbstract:(LDCMediaAbstract *)mediaAbstract completionHandler:(void (^)(UIImage* image))block failureBlock:(void (^)(NSError* error))failureBlock;
- (void)retrieveMediaForMediaAbstractId:(NSString *)mediaId completionHandler:(void (^)(UIImage* image))block failureBlock:(void (^)(NSError* error))failureBlock;

/*!
 * @discussion Downloads a thumbnail for the media item and returns the result in an async block
 * @param mediaId The media id PK used to find the media abstract item
 * @param completionHandler success code block with a UIImage of the thumbnail
 * @param failutreBlock failure code block that is called with error as parameter
 */
- (void)retrieveMediaThumbnailForMediaAbstractId:(NSString *)mediaId completionHandler:(void (^)(UIImage* image))block failureBlock:(void (^)(NSError* error))failureBlock;

/*!
 * @discussion Simple check to see if the thumbnail for a mediaId is already cached
 * @param mediaId The media id PK used to find the media abstract item
 * @return TRUE if the thumbnail is cached, FALSE otherwise
 */
- (BOOL)isMediaThumbnailCached:(NSString*)mediaId;
- (BOOL)isMediaCachedForMediaAbstract:(LDCMediaAbstract*)mediaAbstract;

/*!
 * @discussion Simple check to see if the media for a mediaId is already cached
 * @param mediaId The media id PK used to find the media abstract item
 * @return TRUE if the media is cached, FALSE otherwise
 */
- (BOOL)isMediaCachedForMediaId:(NSString*)mediaId;

/*!
 * @discussion Given a media abstract item, returns the local path of the downloaded file
 * @param mediaAbstract The media abstract item in question
 * @return A string that represents the local path of the downloaded file
 */
- (NSString*)fullPathForDbFileName:(NSString*)dbFileName;
- (NSString*)dataFileNameForMediaAbstract:(LDCMediaAbstract*)mediaAbstract;
- (NSString*)requestURLStringForMediaAbstract:(NSString *)mediaId thumbnail:(BOOL)thumbnail withLink:(NSString*)link;
- (void) removeWithFileName:(NSString*)fileName deleteRelated:(BOOL)related;
- (void) removeMediaAbstract:(LDCMediaAbstract*)mediaAbstract;
- (void)start;
- (void)clear;

/*!
 * @discussion Gives the URL of the media abstract item hosted on the Liquid Server (sharing purposes)
 * @param mediaId The media id PK used to find the media abstract item
 * @param thumbail Detemriens whether you want the thumbnail version of the URL or not
 * @return A string that represents the URL of the hosted media on the server
 */
- (NSString*)requestURLStringForMediaAbstract:(NSString *)mediaId thumbnail:(BOOL)thumbnail;

/*!
 * @discussion Clears out the cached database entirely
 */
- (void)clear;

/*!
 * @discussion Clears out all of the thumbnails that have been previously downloaded
 * @return TRUE if the thummbnails delete successfully, FALSE otherwise
 */
- (BOOL)deleteAllThumnails;


@end
