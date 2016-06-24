//
//  LDKItemReporter.h
//  LDCore
//
//  Created by CARSON LI on 2015-03-17.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDMItem;

@interface LDKItemReporter : NSObject

+ (LDKItemReporter *)sharedInstance;

/*!
 * @discussion Asynchronous call to create a reporting item. Works in conjunction with item type "ItemReporting"
 * @param items An LDMitem to be reported
 */
- (void) reportItem:(LDMItem*) item;

/*!
 * @discussion Same as reportItem, but for multiple items
 * @param items An array of LDMItems to be reported
 */
- (void) reportItems:(NSArray*) items;



@end
