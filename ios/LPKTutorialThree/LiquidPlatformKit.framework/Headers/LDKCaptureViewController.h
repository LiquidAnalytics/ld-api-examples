//
//  LDKCaptureViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 10/24/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class LDMItem;

@protocol LDKCaptureViewControllerDelegate;

typedef enum
{
    ScanModeSearch = 1,
    ScanModeCreate
} ScanMode;

@interface LDKCaptureViewController : UIViewController <AVCaptureMetadataOutputObjectsDelegate>

@property (weak, nonatomic) id<LDKCaptureViewControllerDelegate> delegate;
@property (copy, nonatomic) void (^didCaptureValueHandler)(NSString *type, NSString *value);
@property (copy, nonatomic) void (^didCancelHandler)();
@property (strong, nonatomic) NSArray *captureTypes;

+ (NSString *)capturableItemType:(NSString *)itemType;
+ (NSArray *)filtersForScanCode:(LDMItem *)scanCode forItemType:(NSString *)itemType;
- (BOOL)startReading;
- (void)stopReading;
- (void)pauseReading:(int)pauseDuration; //seconds

@end


@protocol LDKCaptureViewControllerDelegate <NSObject>

- (void)captureViewControllerDidCancel:(LDKCaptureViewController *)viewController;
- (void)captureViewController:(LDKCaptureViewController *)viewController didCaptureValue:(NSString *)value ofType:(NSString *)type;

@end
