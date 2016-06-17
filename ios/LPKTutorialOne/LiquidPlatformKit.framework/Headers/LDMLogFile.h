//
//  LDCLogFile.h
//  LiquidDecisions
//
//  Created by David Ellis on 2013-05-29.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMItem.h"

@interface LDMLogFile : LDMItem
@property (nonatomic, strong) NSString  *logId;
@property (nonatomic, strong) NSString  *userId;
@property (nonatomic, strong) NSString  *deviceId;
@property (nonatomic, strong) NSString  *fileType;
@property (nonatomic, strong) NSDate    *fileDate;
@property (nonatomic, strong) NSString  *summary;
@property (nonatomic, strong) NSString  *data;
@end
