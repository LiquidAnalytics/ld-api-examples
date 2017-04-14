//
//  LDCDBSeasideLogWriter.h
//  LiquidDecisions
//
//  Created by David Ellis on 2013-05-23.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDCDBLogWriter.h"

@interface LDCDBSeasideLogWriter : NSObject <LDCDBLogWriter>

+ (LDCDBSeasideLogWriter *)sharedInstance;

@end
