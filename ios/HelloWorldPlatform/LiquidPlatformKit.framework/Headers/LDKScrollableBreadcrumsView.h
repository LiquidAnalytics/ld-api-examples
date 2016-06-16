//
//  LDKScrollableBreadcrumsView.h
//  LDCore
//
//  Created by Bryan Nagle on 1/9/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKBreadcrumsView.h"

@interface LDKScrollableBreadcrumsView : UIScrollView

@property (strong) LDKBreadcrumsView *breadcrumbsView;
@property (nonatomic, assign) BorderSides borderSides;

- (void)addBreadcrumbText:(NSString *)text forItemType:(NSString *)itemType;

@end
