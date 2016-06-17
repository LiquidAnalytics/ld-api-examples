//
//  LDCTouchView.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 10/1/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface LDKTouchView : UIView

@property (assign) BOOL animationDisabled;
@property (nonatomic, copy) void (^touchBeganBlock)(id);
@property (nonatomic, copy) void (^touchEndedBlock)(id);

- (void)remove;

@end
