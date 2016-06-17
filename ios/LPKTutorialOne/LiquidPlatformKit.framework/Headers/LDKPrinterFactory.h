//
//  LDKPrinterFactory.h
//  LDCore
//
//  Created by CARSON LI on 2015-05-26.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LDKPrinter;

@interface LDKPrinterFactory : NSObject

+(LDKPrinter*) printerForProfile: (NSString*) profile;


@end
