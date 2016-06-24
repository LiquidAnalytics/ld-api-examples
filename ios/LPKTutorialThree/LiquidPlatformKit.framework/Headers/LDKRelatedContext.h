//
//  LDKRelatedContext.h
//  LDCore
//
//  Created by Marshall Hayden on 3/15/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import "LDMItem.h"

@interface LDKRelatedContext : LDMItem

@property NSString *itemType;
@property NSString *itemId;
@property NSString *relationshipPath;

@end
