//
//  LDKSignatureCaptureViewController.h
//  LDCore
//
//  Created by CARSON LI on 2015-05-15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^LDKSignatureCaptureDoneBlock)(id sender, NSString *base64EncodedImage, NSString *signatureName);

@interface LDKSignatureCaptureViewController : UIViewController <UITextFieldDelegate>

@property (nonatomic, copy) LDKSignatureCaptureDoneBlock doneBlock;
@property (nonatomic, copy) NSString* base64EncodedImage;
@property (nonatomic, copy) NSDate* captureDate;
@property (strong) NSString* signatureName;

@end
