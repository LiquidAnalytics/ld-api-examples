//
//  LDMDataSharingController.h
//  LiquidDataModel
//
//  Created by Carson Li on 2013-10-17.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

static NSString *kViewerURLScheme = @"com.liquidanalytics.decisions";

typedef void(^LDMDataSharingSendDataHandler)(NSURL *finalURL, BOOL sent, NSError *error);
typedef void(^LDMDataSharingHandler)(NSDictionary *paramDict, NSArray *items, NSError *error);

extern NSString *kReadPasteboardDataQuery;

typedef enum
{
    LDMDataSharingErrorTypeNoApplicationAvailableForScheme = 100,
    LDMDataSharingErrorTypeNoPasteboardForName = 200,
    LDMDataSharingErrorTypeNoDataFound = 300,
} LDMDataSharingErrorType;

@interface LDMDataSharingController : NSObject

+(void)sendDataToApplicationWithParamDict:(NSDictionary *)paramDict
                           data:(NSArray *)itemsToSend
                      appAxisId:(NSString *) appAxisId
                     completionHandler:(LDMDataSharingSendDataHandler)completionHandler;

+(void)receivePasteboardDataURL:(NSURL *)sendPasteboardDataURL
                 completionHandler:(LDMDataSharingHandler)completionHandler;

@end