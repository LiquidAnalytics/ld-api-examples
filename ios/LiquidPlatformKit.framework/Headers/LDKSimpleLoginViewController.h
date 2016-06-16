//
//  LDKSimpleLoginViewController.h
//  LiquidDecisions
//
//  Created by Marshall Hayden on 5/27/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, LDKLoginLogoStyle)
{
    LDKLoginLogoStyleDark,
    LDKLoginLogoStyleLight
};

@interface LDKSimpleLoginViewController : UIViewController<UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *backgroundImage;
@property (weak, nonatomic) IBOutlet UIImageView *applicationLogo;
@property (assign, nonatomic) LDKLoginLogoStyle applicationLogoStyle;

- (void)requestAuthenticationWithMessage:(NSString *)message userEditable:(BOOL)userEditable providePasscode:(BOOL)providePasscode callback:(void (^)(NSString *username, NSString *password))callback;
- (void)updateStatusLabel:(NSString *)statusText enable:(BOOL)enable;

@end
