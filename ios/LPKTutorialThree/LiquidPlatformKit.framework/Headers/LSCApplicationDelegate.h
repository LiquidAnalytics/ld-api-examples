//
//  LSCApplicationDelegate.h
//  seaside
//
//  Created by Eric Johnson on 2/13/13.
//
//

#import <Foundation/Foundation.h>

@protocol LSCApplicationDelegate <NSObject>
@required
- (void)loginTokenHasExpired;
- (void)loginTokenInvalid;
- (void)passwordResetSent;
- (void)passwordChanged;
- (void)passwordChangeFailedWithMessage:(NSString *)message;
@end
