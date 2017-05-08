//
//  UserBioViewController.m
//  LPKTutorialOne
//
//  Created by LA Intern on 5/3/17.
//  Copyright © 2017 Liquid Analytics. All rights reserved.
//
#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMItem.h>
#import <LiquidPlatformKit/LDMSearchResults.h>
#import <LiquidPlatformKit/LSCSyncController.h>
#import "UserBioViewController.h"

@interface UserBioViewController ()
@property (weak) IBOutlet UILabel *UserBioLabel;
@property NSMutableString *result;
@end

@implementation UserBioViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    
    [[LDMDataManager sharedInstance] executeAsynch:^{
        NSArray *myBio = [[LDMDataManager sharedInstance] allItemsOfType:@"UserBio"];
        self.result = [NSMutableString string];
        if([myBio count] > 0)
            for(LDMItem *item in myBio){
                [self.result appendFormat:@"%@",item.dataDict];
            }
            
        else
            [self.result setString:@"NO BIO INFO"];
        
        
            self.UserBioLabel.text = [NSString stringWithFormat:@"info: %@ end", self.result];
        [self.UserBioLabel sizeToFit];
        }];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (void)buttonPressed{
    
    
    
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
