//
//  UIViewController+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 11/9/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

#define LDKMODAL_VIEWCONTROLLER_DID_DISMISS                                                 @"LDKModalViewControllerDidDismiss"

typedef NS_ENUM(NSUInteger, LDKModalStyle)
{
    LDKModalStyleNone,
    LDKModalStyleTallFormBottom,
    LDKModalStyleTallFormCentered
};

@interface UIViewController (LDK)

+ (UIViewController *)viewControllerFromClassName:(NSString *)className nibName:(NSString *)nibName;
+ (CGSize)rotatedScreenSize;
+ (CGRect)boundingRectForLDKModalStyle:(LDKModalStyle)style;

+ (id)addObserverForLDKModalDidDismissUsingBlock:(void (^)(NSNotification *))block;
+ (void)presentViewControllerDefaultStyle:(UIViewController *)controller animated:(BOOL)flag completion:(void (^)(void))completion;
+ (void)presentViewController:(UIViewController *)controller withLDKModalStyle:(LDKModalStyle)modalStyle animated:(BOOL)flag completion:(void (^)(void))completion;
+ (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion;
+ (void)presentViewController:(UIViewController *)controller withLDKModalStyle:(LDKModalStyle)modalStyle withLeftButtonTitle:(NSString *)leftButtonTitle andLeftButtonHandler:(void (^)(id))leftButtonHandler andRightButtonTitle:(NSString *)rightButtonTitle andRightButtonHandler:(void (^)(id))rightButtonHandler animated:(BOOL)flag completion:(void (^)(void))completion;
+ (void)presentFullScreenViewController:(UIViewController *)fullScreenViewController andRootViewController:(UIViewController*)rvc withSlideInTransition:(BOOL)transitionFlag;
+ (void)dismissFullScreenViewController:(UIViewController*)fullScreenViewController animated:(BOOL)animated completion:(void (^)(void))completion;

- (void)presentViewControllerDefaultStyle:(UIViewController *)controller animated:(BOOL)flag completion:(void (^)(void))completion;
- (void)presentViewController:(UIViewController *)controller withLDKModalStyle:(LDKModalStyle)modalStyle animated:(BOOL)flag completion:(void (^)(void))completion;
- (void)presentViewController:(UIViewController *)controller withLDKModalStyle:(LDKModalStyle)modalStyle withLeftButtonTitle:(NSString *)leftButtonTitle andLeftButtonHandler:(void (^)(id))leftButtonHandler andRightButtonTitle:(NSString *)rightButtonTitle andRightButtonHandler:(void (^)(id))rightButtonHandler animated:(BOOL)flag completion:(void (^)(void))completion;
- (UIImage *)renderToImageSize:(CGSize)size;
- (BOOL)isInPopOverController;

@end
