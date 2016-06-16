//
//  LSCInfrastructureUtils.h
//  seaside
//
//  Created by David Ellis on 2013-09-26.
//
//

#import <Foundation/Foundation.h>

@interface LSCInfrastructureUtils : NSObject

+ (BOOL) isJailbroken;
+ (BOOL) addSkipBackupAttributeToFile: (NSString *) filePath;
+ (BOOL) iPad3orNewer;
+ (NSString *) serializeDeviceToken:(NSData*) deviceToken;
@end
