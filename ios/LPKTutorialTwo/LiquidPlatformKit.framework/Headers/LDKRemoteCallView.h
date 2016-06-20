//
//  LDKRemoteCallView.h
//  LDCore
//
//  Created by Bryan Nagle on 5/13/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMSearchResultsOnline.h"

@class LDMContext, LDMFunction, LDMSearchResults;

@protocol LDKRemoteCallViewDelegate;

@interface LDKRemoteCallView : UIView <LDMSearchResultsDelegate>

@property (nonatomic, strong) NSArray *lines;
@property (nonatomic, strong) NSString *buttonTitle;
@property (strong) UIFont *defaultFont;
@property (assign) NSTextAlignment textAlignment;
@property (nonatomic, strong) LDMFunction *systemFunction;
@property (nonatomic, strong) LDMContext *context;
@property (weak) id<LDKRemoteCallViewDelegate> delegate;
@property (nonatomic, copy) NSArray *(^getLinesBlock)(NSDictionary *response, LDMSearchResults *results, LDMFunction *function);

- (void)performOnlineCall;
- (void)update;

@end


@protocol LDKRemoteCallViewDelegate <NSObject>

- (NSArray *)remoteCallView:(LDKRemoteCallView *)view linesForResponse:(NSDictionary *)response andSearchResults:(LDMSearchResults *)results function:(LDMFunction *)function;

@end