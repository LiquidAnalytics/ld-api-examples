//
//  MainViewController.m
//  LPKTutorialThree
//
//  Created by CARSON LI on 2016-06-23.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "MainViewController.h"
#import <LiquidPlatformKit/LDKDimensionSelectManager.h>
#import <LiquidPlatformKit/LDMDimension.h>
#import <LiquidPlatformKit/LDCInfoViewController.h>
#import <LiquidPlatformKit/LDKInfoDelegateDatasource.h>
#import <LiquidPlatformKit/LRPopoverManager.h>
#import <LiquidPlatformKit/LDMFunction.h>
#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMDataManager+UserExtensions.h>
#import <LiquidPlatformKit/LDMDataManager+REST.h>
#import <LiquidPlatformKit/LDMDataManager+SearchAsync.h>
#import <LiquidPlatformKit/LDKSignatureCaptureViewController.h>
#import <LiquidPlatformKit/LDKSimpleWebViewController.h>
#import <LiquidPlatformKit/LDKItemSelectViewController.h>
#import <LiquidPlatformKit/LDCLoadingViewManager.h>
#import <LiquidPlatformKit/LDKCaptureViewController.h>
#import <LiquidPlatformKit/LiquidPlatformKit-Swift.h>
#import <LiquidPlatformKit/LiquidPlatformKit.h>

#import "UIAlertView+Blockskit.h"
#import "FunctionViewController.h"

@interface MainViewController ()

@property (weak) IBOutlet UIButton *enumSelectDemoButton;
@property (weak) IBOutlet UIButton *itemSelectDemoButton;
@property (weak) IBOutlet UIButton *sigDemoButton;
@property (weak) IBOutlet UIButton *emailDemoButton;
@property (weak) IBOutlet UIButton *webPreviewButton;
@property (weak) IBOutlet UIButton *functionResultsDemoButton;
@property (weak) IBOutlet UIButton *scanDemoButton;

@property (weak) IBOutlet UIButton *menuButton;
@property (weak) IBOutlet UISwitch *itemMultiSelectSwitch;

@property (weak) IBOutlet UITextField *emailTextField;

@property (strong) LDCInfoViewController *infoViewController;
@property (strong) LDKInfoDelegateDatasource *infoViewDelegateDatasource;
@property (strong) LDKSignatureCaptureViewController *sigCapViewController;
@property (strong) LDKCaptureViewController *captureViewController;
@property (strong) UINavigationController *simpleWebViewWrapper;
@property (strong) UINavigationController *itemSelectWrapper;
@property (strong) LDKSimpleWebViewController *simpleWebView;
@property (strong) LDKItemSelectViewController *itemSelectViewController;

@property (strong) LDMSearchResults *searchResults;
@property (strong) LDMFunction *functionItem;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.itemMultiSelectSwitch.on = NO;
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)enumSelectDemoButtonPressed:(id)sender
{
    [LDKDimensionSelectManager presentDimensionSelectWithLevel:@"movieCategory" fromRect:self.enumSelectDemoButton.frame inView:self.view permittedArrowDirections:UIPopoverArrowDirectionAny andCompletedBlock:^(LDMDimension *dimension) {
        NSLog(@"Selected: %@", [dimension stringValue]);
    }];
}

-(IBAction)itemSelectDemoButtonPressed:(id)sender{
    
    if (self.itemSelectWrapper == nil){
        self.itemSelectViewController = [[LDKItemSelectViewController alloc] initWithItemsOfType:@"Movie" withQueryFilter:nil online:NO];
        self.itemSelectWrapper = [[UINavigationController alloc]
                                     initWithRootViewController:self.itemSelectViewController];
        [self.itemSelectWrapper setModalPresentationStyle:UIModalPresentationPageSheet];
    }
    
    __weak MainViewController *this = self;
    self.itemSelectViewController.multiSelectEnabled = self.itemMultiSelectSwitch.isOn;

    [self.itemSelectViewController setDidSelectItem:^(LDKItemSelectViewController * _Nonnull vc, LDMItem * _Nullable result) {
        [this.itemSelectWrapper dismissViewControllerAnimated:YES completion:nil];
        NSLog(@"Item selected: %@", result);
    }];
    
    [self.itemSelectViewController setDidSelectItems:^(LDKItemSelectViewController * _Nonnull vc, NSArray * _Nonnull items) {
        [this.itemSelectWrapper dismissViewControllerAnimated:YES completion:nil];
        NSLog(@"Items selected: %@", items);
    }];
    
    [self presentViewController:self.itemSelectWrapper animated:YES completion:nil];
}


-(IBAction)sigDemoButtonPressed:(id)sender
{
    if (self.sigCapViewController == nil)
    {
        self.sigCapViewController = [[LDKSignatureCaptureViewController alloc] initWithNibName:@"LDKSignatureCaptureViewController" bundle:[[LDMDataManager sharedInstance] LPKBundle]];
        self.sigCapViewController.view.alpha = 0.975;
        [self.sigCapViewController setModalPresentationStyle:UIModalPresentationOverCurrentContext];
        [self.sigCapViewController setDoneBlock:^(id sender, NSString *base64EncodedImage, NSString *signatureName){
            //Now I can do something with this image data. Remember if you want to sync with the server
            //the dataType on that field has to be  "dataType": "base64".
        }];
    }

    //if you have an existing signature you want to pass in for edit, you can do the following
    //self.sigCapViewController.base64EncodedImage = <fill this in>
    
    //remember you have two helpers in function manager encodeToBase64String / decodeBase64ToImage
    
    [self presentViewController:self.sigCapViewController animated:YES completion:nil];

}

-(IBAction)emailDemoButtonPressed:(id)sender
{
    if (_emailTextField.text.length == 0)
    {
        [UIAlertView bk_showAlertViewWithTitle:@"Hey!" message:@"Email field cannot be left empty" cancelButtonTitle:@"OK" otherButtonTitles:nil handler:nil];
        return;
    }
    
    NSString *functionId = @"AllMovieRatingsOnline"; //this is the online version of the funciton used in LPKTutorialTwo, check it out in MC
    [[LDMDataManager sharedInstance] executeAsynch:^{
        self.functionItem = (LDMFunction*)[[LDMDataManager sharedInstance] itemOfType:@"Function" withId:functionId];
        [LDMFunction allItemsFromFunctionItem:self.functionItem rowLimit:5000 orderBy:nil ascending:YES withQueryFilter:nil faultBlocks:YES withBlock:^(LDMSearchResults * _Nullable results) {
            self.searchResults = results;
            dispatch_async(dispatch_get_main_queue(), ^{
                [self showEmailPopup];
            });

        } withContext:nil];
    }];
}


-(IBAction)functionResultsDemoPressed:(id)sender
{
    FunctionViewController *functionViewController = [[FunctionViewController alloc] init];
    [self presentViewController:functionViewController animated:YES completion:nil];
    
}

-(IBAction)webPreviewDemoPressed:(id)sender
{
    if (self.simpleWebViewWrapper == nil){
        self.simpleWebView = [[LDKSimpleWebViewController alloc] initWithNibName:@"LDKSimpleWebViewController" bundle:[[LDMDataManager sharedInstance] LPKBundle]];
        self.simpleWebView.isPresentingModally = YES;
        self.simpleWebViewWrapper = [[UINavigationController alloc]
                                     initWithRootViewController:self.simpleWebView];
        [self.simpleWebViewWrapper setModalPresentationStyle:UIModalPresentationPageSheet];
    }
    self.simpleWebView.url = [[NSURL alloc] initWithString:@"https://www.google.com"];
    
    [self presentViewController:self.simpleWebViewWrapper animated:YES completion:nil];
}


-(void)showEmailPopup
{
    
    [UIAlertView bk_showAlertViewWithTitle:@"Info" message:[NSString stringWithFormat:@"You have requested a CSV export of this function, to be emailed to: %@. (Only the first 5000 rows will be exported) Would you like to proceed?",self.emailTextField.text] cancelButtonTitle:@"No" otherButtonTitles:@[@"Yes"] handler:^(UIAlertView *alertView, NSInteger buttonIndex) {
        
        if (buttonIndex == 0) return;
        [[LDMDataManager sharedInstance] requestExportAndEmailForItemType:[self.functionItem itemType] withQuery:[self.searchResults toSql] forEmail:self.emailTextField.text forFormat:@"CSV" withCompletionBlock:^(id results, NSURL *url, NSError *error) {
            NSString *msg = error == nil ? @"Your request has been placed in queue. You will receive the email when the job is complete." : [NSString stringWithFormat:@"Unable to process (%@)", error];
            
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Info" message:msg delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }];
        
    }];
    
}


-(IBAction)menuPressed:(id)sender
{
    LRPopoverManager *popoverManager = [LRPopoverManager sharedManager];
    
    if (popoverManager.currentPopoverController.popoverVisible)
    {
        [popoverManager.currentPopoverController dismissPopoverAnimated:YES];
        return;
    }
    
    if (!self.infoViewController)
    {
        self.infoViewController = [[LDCInfoViewController alloc] initWithNibName:@"LDCInfoViewController" bundle:[[LDMDataManager sharedInstance] LPKBundle]];
        self.infoViewDelegateDatasource = [[LDKInfoDelegateDatasource alloc] init];
        self.infoViewController.datasource = self.infoViewDelegateDatasource;
        self.infoViewController.delegate = self.infoViewDelegateDatasource;
        self.infoViewDelegateDatasource.disabledPopoverItemOptions = DisableNone;
    }
    
    UIPopoverController *popoverController = [[UIPopoverController alloc] initWithContentViewController:self.infoViewController];
    [popoverController presentPopoverFromRect:self.menuButton.frame inView:self.view permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    [popoverManager setCurrentPopoverController:popoverController];

}

-(IBAction)scanDemoButtonPressed:(id)sender
{
    if (self.captureViewController == nil)
    {
        self.captureViewController = [[LDKCaptureViewController alloc] initWithNibName:nil bundle:[[LDMDataManager sharedInstance] LPKBundle]];
        self.captureViewController.delegate = self;
        self.captureViewController.modalPresentationStyle = UIModalPresentationFormSheet;
    }
    [self presentViewController:self.captureViewController animated:YES completion:nil];
}

- (void)captureViewControllerDidCancel:(LDKCaptureViewController *)viewController
{
    [viewController stopReading];
    [viewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)captureViewController:(LDKCaptureViewController *)viewController didCaptureValue:(NSString *)value ofType:(NSString *)type
{
    if(value.length < 1) return;
    
    AudioServicesPlaySystemSound(1108);     //Camera shutter sound.
    
    [viewController stopReading];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        NSLog(@"scanned value: %@", value);
    });
    
    [viewController dismissViewControllerAnimated:YES completion:nil];
}

@end
