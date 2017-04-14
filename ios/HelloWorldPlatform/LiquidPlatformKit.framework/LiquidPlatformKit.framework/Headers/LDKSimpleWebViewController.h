//
//  LDKSimpleWebViewController.h
//  LDCore
//
//  Created by Carson Li on 2014-04-24.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MFMailComposeViewController.h>

@interface LDKSimpleWebViewController : UIViewController <UIWebViewDelegate>

@property (strong) NSURL *url;
@property (strong, nonatomic) NSString* htmlString;
@property (nonatomic) BOOL isPresentingModally;
@property NSInteger spinnerCount;
@property (strong) NSString *emailSubject;

-(void) refresh;

@end
