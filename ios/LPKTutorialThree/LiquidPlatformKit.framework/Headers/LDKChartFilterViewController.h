//
//  LDKChartFilterViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 7/17/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKItemSelectViewController.h"

@class LDMItem;

@protocol LDKChartFilterViewControllerDelegate;

@interface LDKChartFilterViewController : UIViewController <LDKItemSelectViewControllerDelegate>

@property (unsafe_unretained, nonatomic) IBOutlet UITableView *tableView;
@property (strong, nonatomic) NSMutableDictionary *varDict;
@property (weak) id<LDKChartFilterViewControllerDelegate> delegate;

+ (NSMutableDictionary *)defaultsFromConfig:(NSDictionary *)config valueForStatement:(id (^)(NSString *statement))valueForStatement;
+ (NSData *)configToJSONData:(NSDictionary *)config;
+ (NSDictionary *)configFromJSONData:(NSData *)data;

- (instancetype)initWithConfig:(NSDictionary *)config identifier:(NSString *)identifier;

@end

@protocol LDKChartFilterViewControllerDelegate <NSObject>

- (id)valueForStatement:(NSString *)statement;
- (void)chartFilterViewController:(LDKChartFilterViewController *)controller didSelectFilterValues:(NSDictionary *)values;

@end
