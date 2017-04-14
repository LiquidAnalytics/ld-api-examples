//
//  LDCHorizontalButtonBarView.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 11/15/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@interface LDCHorizontalButtonBarView : UIView

@property (strong) NSString *highlightedKey;

- (void)addButtonWithImage:(UIImage *)image andTouchHandler:(void (^)(id))handler forKey:(NSString *)key;
- (void)addButtonWithTitle:(NSString *)title andTouchHandler:(void (^)(id))handler forKey:(NSString *)key;
- (void)addButtonWithImage:(NSString *)imageName title:(NSString *)title andTouchHandler:(void (^)(id))handler forKey:(NSString *)key;
@end
