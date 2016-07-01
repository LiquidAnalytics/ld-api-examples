//
//  LDMDataManager+LDMUserManager.h
//  LiquidDataModel
//
//  Created by David Ellis on 2013-05-30.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"

@interface LDMDataManager (LDMUserManager)

- (LDMItem *)getUser;
- (LDMItem *) getSystemUser;
- (NSString *) getSystemUserLanguage;
- (NSArray *)getUserItems;
- (LDMItem *)getUserPosition;
- (NSArray *)getUserPositions;
- (void)clearCachcedUser;

@end
