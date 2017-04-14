//
//  LDCHelpManager.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 2/25/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class LDCHelpViewController;

@interface LDCHelpManager : NSObject

+ (LDCHelpManager *)sharedInstance;

@property (strong) LDCHelpViewController *viewController;
@property (nonatomic, strong) NSString *currentLayout;
@property (strong) NSMutableDictionary *globalReferenceViewsByTag;
@property (strong) NSMutableDictionary *referenceViewsByTag;

- (void)showAnimate:(BOOL)animate;
- (void)closeAnimate:(BOOL)animate;
- (UIView *)findViewForTag:(NSInteger)tag;
- (CGRect)findRectForTag:(NSInteger)tag;

@end
