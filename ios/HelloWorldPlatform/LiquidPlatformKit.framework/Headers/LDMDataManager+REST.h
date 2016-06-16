//
//  LDMDataManager+REST.h
//  LDCore
//
//  Created by CARSON LI on 2015-08-19.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@interface LDMDataManager (REST)

/*!
 * @discussion Request server for export of results for given query
 * @param itemType the item type expected for the sqlQuery
 * @param sqlQuery the actual sql string\
 * @param email the email address that will be informed upon export completion
 * @param format use constant "csv" or "json"
 * @param completionBlock Asynchronous callback handler after export request is sent to server
 */
- (void) requestExportAndEmailForItemType:(NSString * __nonnull)itemType withQuery:(NSString *__nonnull)sqlQuery forEmail:(NSString *__nonnull)email forFormat:(NSString *__nonnull)format withCompletionBlock:(void (^__nullable)(id __nullable results ,NSURL *__nonnull url, NSError *__nullable error))completionBlock;

- (void) createHTTPRequestForURL:(NSURL * __nonnull )url withRequestMethod:(NSString *__nonnull)requestMethod withPostParams:(NSDictionary *__nullable) postParams withTimeout:(NSUInteger)timeout withCompletionBlock:(void (^__nullable)(id __nullable results ,NSURL *__nonnull url, NSError *__nullable error))completionBlock;

@end
