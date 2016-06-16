//
//  LSCMediaUploadStateHandler.h
//  seaside
//
//  Created by Eric Johnson on 7/10/13.
//
//

#import <Foundation/Foundation.h>

@class LDCMediaAbstract;

@interface LDLMediaUploader : NSObject <NSURLConnectionDelegate>

+ (void)uploadImageData:(NSData *)imageData withFieldValues:(NSDictionary *)fieldValues withCompletionHandler:(void (^)(BOOL sucesss))completionHandler;

- (void)sendMedia:(NSData *)mediaData withFieldValues:(NSDictionary *)fieldValues andCompletionHandler:(void (^)(BOOL success))completionHandler;

@end
