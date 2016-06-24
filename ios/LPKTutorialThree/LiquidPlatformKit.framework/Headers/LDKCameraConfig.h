//
//  LDKCameraConfig.h
//  LDCore
//
//  Created by Bryan Nagle on 1/15/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKCameraConfig : NSObject

@property (nonatomic, assign) BOOL supportCamera;
@property (nonatomic, assign) BOOL supportImageLibrary;
@property (nonatomic, assign) CGSize targetResolution;
@property (nonatomic, assign) float compression;

+ (LDKCameraConfig *)cameraConfigFromDict:(NSDictionary *)dict;
- (id)initWithDict:(NSDictionary *)dict;
- (void)loadDict:(NSDictionary *)dict;
- (CGSize)targetResolutionForImageOrientation:(UIImageOrientation)imageOrientation;

@end
