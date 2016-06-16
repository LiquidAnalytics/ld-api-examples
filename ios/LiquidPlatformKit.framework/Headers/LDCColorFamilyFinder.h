//
//  LDCColorFamilyFinder.h
//  LiquidDecisions
//
//  Created by CARSON LI on 2014-11-26.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDCColorFamilyFinder : NSObject

+(void) colorForFamilyName:(NSString*)familyName forValue:(NSString*) value withCompletionHandler:(void (^)(UIColor *result))completionHandler;
+(UIColor*) colorForString:(NSString*)input;
+(NSArray*) gradientColorsForString:(NSString*)input;
+(NSArray*) gradientColorsForColor:(UIColor*)baseColor;
@end
