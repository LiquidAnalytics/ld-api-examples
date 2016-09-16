//
//  LDKPrinterManagerViewController.h
//  LDCore
//
//  Created by Yaw Agyepong on 6/17/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKPrinter.h"


@interface LDKPrinterManagerViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, LDKPrinterStatusUpdateDelegate>

@property (strong, nonatomic) IBOutlet UITableView *devicesTable;
@property (strong, nonatomic) IBOutlet UILabel *statusLabel;
@property (strong, nonatomic) IBOutlet UIButton *printButton;

@property (strong, nonatomic) LDMItem *cart;
@property (strong, nonatomic) NSString *printerProfile;

@end