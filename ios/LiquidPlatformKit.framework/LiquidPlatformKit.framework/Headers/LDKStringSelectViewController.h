//
//  LDKStringSelectViewController.h
//  LDCore
//
//  Created by CARSON LI on 2016-07-13.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDKStringSelectViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

@property (strong) NSArray *options;
@property (nonatomic, copy) void (^optionPressedBlock)(NSString *option);

-(instancetype) initWithOptions:(NSArray*)options;

@end
