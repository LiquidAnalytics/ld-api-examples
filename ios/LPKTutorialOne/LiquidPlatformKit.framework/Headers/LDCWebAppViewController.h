//
//  LDCWebAppViewController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 4/5/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMItem, LDCAccount, LDMDefinition;

@interface LDCWebAppViewController : UIViewController <UIWebViewDelegate>

@property (weak, nonatomic) IBOutlet UIWebView *webView;
@property (strong) LDMItem *item;
@property (strong) id endPoint;
@property (assign) BOOL modal;
@property (strong) NSString *param;
@property (assign) BOOL reloadEndpoint;
@property (assign) BOOL workflowURL;
@property (strong) NSString* label;

@end
