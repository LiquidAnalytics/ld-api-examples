//
//  LDCLoginSyncViewController.h
//  LiquidDecisions
//
//  Created by Eric Johnson on 12/18/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface LDCLoginSyncViewController : UIViewController <UIScrollViewDelegate>

- (void)updateStatusText:(NSString*) status;
- (void)updateStatusBar:(float)progress andTotalItemCount:(int)itemCount;
- (void)showProgressSpinner;
- (NSString*)cacheDirectory;

@end

