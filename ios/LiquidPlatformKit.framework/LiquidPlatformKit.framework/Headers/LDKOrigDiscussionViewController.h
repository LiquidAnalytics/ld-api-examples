//
//  LDKOrigDiscussionViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 12/10/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PHFComposeBarView.h"
#import "LDMSearchResults.h"

@class LDMQueryFilter, LDMItem;

@interface LDKOrigDiscussionViewController : UIViewController

@property (strong, nonatomic) LDMQueryFilter *queryFilter;
@property (strong, nonatomic) LDMItem *parentItem;
@property (strong, nonatomic) LDMItem *detailFormAction;

@end
