//
//  MovieDetailViewController.m
//  LPKTutorialOne
//
//  Created by CARSON LI on 2016-06-17.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "MovieDetailViewController.h"
#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMDataManager+Client.h>
#import <LiquidPlatformKit/LDMDataManager+UserExtensions.h>
#import <LiquidPlatformKit/LDMItem.h>
#import <LiquidPlatformKit/LDMEnumeration.h>
#import <BlocksKit/UIControl+BlocksKit.h>

@interface MovieDetailViewController ()

@property (weak) IBOutlet UILabel *categoryLabel;
@property (weak) IBOutlet UITextField *nameField;
@property (weak) IBOutlet UITextView *descriptionTextView;
@property (weak) IBOutlet UITextField *ratingTextField;
@property (weak) IBOutlet UIButton *changeButton;
@property (weak) IBOutlet UIStackView *horizontalViewStack;

@property (strong) LDMEnumeration *currentCategory;
@property (strong) NSArray *allCategories;

@end

@implementation MovieDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.currentCategory = [self.movie valueForKey:@"movieCategory"];
    
    //for the edit form we'll pull every movieCategory available and make buttons for each one
    
    [LDMEnumeration enumerationsNamed:@"movieCategory" withCompletionHandler:^(NSArray *categories) {
        self.allCategories = categories;
        
        for (LDMEnumeration *category in self.allCategories)
        {
            UIButton* button = [[UIButton alloc] init];
            [button setTitle:category.display forState:UIControlStateNormal];
            [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
            [button setBackgroundColor:[UIColor blueColor]];
            
            __block LDMEnumeration *thisCategory = category;
            [button bk_addEventHandler:^(id sender) {
                self.currentCategory = thisCategory;
                [self refreshUI];
                
            } forControlEvents:UIControlEventTouchUpInside];
            
            [self.horizontalViewStack addArrangedSubview:button];
        }
        [self refreshUI];
    }];
}

-(void) refreshUI
{

    self.nameField.text = [self.movie valueForKey:@"name"];
    self.descriptionTextView.text = [self.movie valueForKey:@"description"];
    
    self.categoryLabel.text = self.currentCategory ? [self.currentCategory display] : @"";
    
    if (self.myRating)
        self.ratingTextField.text = [NSString stringWithFormat:@"%@",[self.myRating valueForKey:@"value"]];
    

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

-(IBAction)changeCategory:(id)sender
{
    
}

-(IBAction)saveButtonPressed:(id)sender
{
    [self.movie setValue:self.nameField.text forKey:@"name"];
    [self.movie setValue:self.descriptionTextView.text forKey:@"description"];
    
    if (self.currentCategory)
        [self.movie setValue:self.currentCategory forKey:@"movieCategory"];
    
    if (self.ratingTextField.text.length != 0)
    {
        if (self.myRating)
        {
            [self.myRating setValue:self.ratingTextField.text forKey:@"value"];
            [[LDMDataManager sharedInstance] transactCreateOrUpdateWithItem:self.myRating withCompletionHandler:nil];
        }
        else
        {
            LDMItem *newRating = [[LDMDataManager sharedInstance] itemInstanceForTypeName:@"Rating"];
            LDMItem *user = [[LDMDataManager sharedInstance] getUser];
            [newRating setValue:[LDMItem generateId] forKey:@"ratingId"];
            [newRating setValue:[user valueForKey:@"userId"] forKey:@"userId"];
            [newRating setValue:[self.movie valueForKey:@"movieId"] forKey:@"movieId"];
            [newRating setValue:self.ratingTextField.text forKey:@"value"];
            [[LDMDataManager sharedInstance] transactCreateOrUpdateWithItem:newRating withCompletionHandler:nil];
        }
    }
    
    [[LDMDataManager sharedInstance] transactCreateOrUpdateWithItem:self.movie withCompletionHandler:^(BOOL success) {
        [self.navigationController popViewControllerAnimated:YES];
    }];
}

-(IBAction)deleteButtonPressed:(id)sender
{
    NSArray *items = self.myRating == nil ? @[self.movie] : @[self.movie, self.myRating];
    [[LDMDataManager sharedInstance] transactDeleteWithItems:items withCompletionHandler:^(BOOL success) {
        [self.navigationController popViewControllerAnimated:YES];
    }];
}

@end
