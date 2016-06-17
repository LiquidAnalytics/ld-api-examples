//
//  LDCReusableViewCache.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 5/14/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDCReusableViewCache : NSObject

- (void)registerViewClass:(Class)viewClass forReuseIdentifier:(NSString *)reuseIdentifier;
- (void)registerViewNib:(UINib *)nib forReuseIdentifier:(NSString *)reuseIdentifier;
- (UIView *)reusableViewForIdentifier:(NSString *)reuseIdentifier;

@end
