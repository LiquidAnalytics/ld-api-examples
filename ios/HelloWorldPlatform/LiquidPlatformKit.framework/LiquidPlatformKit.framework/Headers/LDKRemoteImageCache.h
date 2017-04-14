//
//  LDKRemoteImageCache.h
//  LDCore
//
//  Created by Bryan Nagle on 2/26/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDKRemoteImageCache : NSObject

/*!
 * @discussion Singleton method, returns single instance of the class
 * @warning This should be the only way to use the class, do not create using alloc / init
 * @return The singleton instance of this class
 */
+ (LDKRemoteImageCache *)sharedInstance;

/*!
 * @discussion Convinence method to retrieve an image for an http url or a media abstract
 * @param nameOrUrlString the string of the url or mediaId starting with mediaAbstract://
 * @param completionHandler the asynchronous block called after the images have been retrieved
 */
- (void)imageForNameOrUrlString:(NSString *)nameOrUrlString completion:(void (^)(UIImage *image))completion;

/*!
 * @discussion Convinence method to retrieve an image for an http url
 * @param nameOrUrlString the string of the url
 * @param completionHandler the asynchronous block called after the images have been retrieved
 */
- (void)imageForUrlString:(NSString *)urlString completion:(void (^)(UIImage *image))completion;

@end
