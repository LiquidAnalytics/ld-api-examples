//
//  LDKEmailComposer.h
//  LDCore
//
//  Created by Bryan Nagle on 6/19/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MFMailComposeViewController.h>

@class LDCMediaAbstract;

@interface LDKEmailComposer : NSObject <MFMailComposeViewControllerDelegate>

@property (strong) NSString *subject;
@property (strong) NSString *body;
@property (strong) NSArray *toRecipients;
@property (strong) NSData *attachmentData;
@property (strong) NSString *attachmentFileName;
@property (strong) NSString *attachmentMimeType;
@property BOOL enableHTML;

@property (nonatomic, copy) void (^emailFinishHandler)();
@property (strong) MFMailComposeViewController *composeMailViewController;
@property (weak) UIViewController *parentViewController;

+ (NSString *)descriptionFromMediaAbstract:(LDCMediaAbstract *)mediaAbstract;
+ (NSString *)mimeTypeFromMediaAbstract:(LDCMediaAbstract *)mediaAbstract;
+ (LDKEmailComposer *)composer;
- (void)presentFromViewController:(UIViewController *)viewController;

@end
