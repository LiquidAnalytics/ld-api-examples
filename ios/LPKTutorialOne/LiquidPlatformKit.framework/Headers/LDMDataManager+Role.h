//
//  LDMDataManager+Role.h
//  LDCore
//
//  Created by Bryan Nagle on 2/20/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDMDataManager (Role)

/*!
 * @discussion Determines whether the item type is allowed to be edited by the user 
 * based on rules defined in the Liquid System (Role item)
 * @param itemType the item type expected in question
 * @return YES if the item type is allowed to be edited by the user, FALSE otherwise
 */
- (BOOL)isItemTypeIncluded:(NSString *)itemType;

@end
