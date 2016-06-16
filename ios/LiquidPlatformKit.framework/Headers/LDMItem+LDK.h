//
//  LDMItem+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 2/1/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LDMitem.h"

@interface LDMItem (LDK)

@property (nonatomic, readonly) BOOL hasReadPermission;
@property (nonatomic, readonly) BOOL hasWritePermission;
@property (nonatomic, readonly) BOOL isTransactable;

+ (BOOL)itemType:(NSString *)itemType hasPermission:(LDMSchemaRolePermissions)permission;
- (BOOL)hasPermission:(LDMSchemaRolePermissions)permission;
- (void)addBlocks:(NSArray *)blocks forBlockField:(NSString *)blockField;

@end
