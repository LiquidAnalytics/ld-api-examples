//
//  LDKCameraController.h
//  LDCore
//
//  Created by Bryan Nagle on 1/17/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDKCameraConfig, LDCMediaAbstract;

@interface LDKImagePickerController : NSObject <UIImagePickerControllerDelegate, UINavigationControllerDelegate>

@property (nonatomic, copy) void (^didSelectImageHandler)(LDCMediaAbstract *mediaAbstract, NSData *imageData, UIImagePickerControllerSourceType);

+ (LDKCameraConfig *)cameraConfig;
+ (void)selectImageFromCameraWithCompletionHandler:(void (^)(LDCMediaAbstract *mediaAbstract, NSData *imageData))completionHandler forMediaType: (NSString *) mediaType;
+ (void)selectImageFromCameraWithCompletionHandler:(void (^)(LDCMediaAbstract *mediaAbstract, NSData *imageData))completionHandler;
+ (void)selectImageFromPhotoLibraryFromBarButtonItem:(UIBarButtonItem *)barButtonItem permittedArrowDirections:(UIPopoverArrowDirection)direction withCompletionHandler:(void (^)(LDCMediaAbstract *mediaAbstract, NSData *imageData))completionHandler forMediaType: (NSString *) mediaType;
+ (void)selectImageFromPhotoLibraryFromBarButtonItem:(UIBarButtonItem *)barButtonItem permittedArrowDirections:(UIPopoverArrowDirection)direction withCompletionHandler:(void (^)(LDCMediaAbstract *mediaAbstract, NSData *imageData))completionHandler;
+ (void)selectImageFromPhotoLibraryFromRect:(CGRect)rect inView:(UIView *)view permittedArrowDirections:(UIPopoverArrowDirection)direction withCompletionHandler:(void (^)(LDCMediaAbstract *mediaAbstract, NSData *imageData))completionHandler;
+ (void)selectImageFromPhotoLibraryFromRect:(CGRect)rect inView:(UIView *)view permittedArrowDirections:(UIPopoverArrowDirection)direction withCompletionHandler:(void (^)(LDCMediaAbstract *mediaAbstract, NSData *imageData))completionHandler forMediaType: (NSString *) mediaType;
@end
