//
//  MovieDetailViewController.h
//  LPKTutorialTwo
//
//  Created by CARSON LI on 2016-06-20.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LiquidPlatformKit/LDMItem.h>

@interface MovieDetailViewController : UIViewController

@property (strong) LDMItem *movie;
@property (strong) LDMItem *myRating;

@end
