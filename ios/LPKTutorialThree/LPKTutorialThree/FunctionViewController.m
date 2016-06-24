//
//  FunctionViewController.m
//  LPKTutorialThree
//
//  Created by CARSON LI on 2016-06-24.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "FunctionViewController.h"
#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMItem.h>
#import <LiquidPlatformKit/LDMSearchResults.h>
#import <LiquidPlatformKit/LDMFunction.h>
#import <LiquidPlatformKit/LDMQueryFilter.h>
#import <LiquidPlatformKit/LDMQueryFilterClause.h>
#import <LiquidPlatformKit/LDMFilter.h>
#import <LiquidPlatformKit/LDMDefinition.h>
#import <LiquidPlatformKit/LDMItem+LanguageParsingExtensions.h>

#import "GenericTableViewCell.h"

@interface FunctionViewController ()

@property (weak) IBOutlet UITableView *tableView;
@property (weak) IBOutlet UITextField *functionIdTextField;
@property (strong) LDMSearchResults *searchResults;
@property (strong) NSString *itemType;
@end

@implementation FunctionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.itemType = @"MovieRatingComposite";
    self.functionIdTextField.text = @"AllMovieRatings";
    [self.tableView registerNib:[UINib nibWithNibName:@"GenericTableViewCell" bundle:nil] forCellReuseIdentifier:@"GenericTableViewCell"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void) viewWillAppear:(BOOL)animated
{
    //for the first tutorial we will fetch the data every time the view appears
    //for future tutorials we will utilize proper observers / notifications
    [self fetchData];
}

-(void) fetchData
{
    __weak FunctionViewController *this = self;
    
    //replace this with any function available in the system. you can easily change cellForRow to see what you'd like,
    //but for something generic you can just add a Definition item where defType = cellDef and type = <itemType>
    
    [LDMFunction allItemsfromFunctionId:self.functionIdTextField.text queryFilter:nil faultBlocks:NO context:nil completion:^(LDMSearchResults * _Nullable results) {
        this.searchResults = results;
        this.searchResults.delegate = this;
        dispatch_async(dispatch_get_main_queue(), ^{
            [this refreshUI];
        });
    }];
}

-(void) refreshUI
{
    [self.tableView reloadData];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.searchResults numberOfSections];
}

-(NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.searchResults numberOfRowsInSection:section];
}

-(UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    GenericTableViewCell* cell = [self.tableView dequeueReusableCellWithIdentifier:@"GenericTableViewCell" forIndexPath:indexPath];
    
    LDMItem *item = [self.searchResults objectForRowAtIndexPath:indexPath];
    
    LDMDefinition *def = [[LDMDataManager sharedInstance] definitionOfType:@"cellDef" forKey:self.itemType];
    if (def)
    {
        //when using value for statement, you can use anything from function manager, or even add your own category
        //go here: https://liquidanalytics.gitbooks.io/liquid-platform-implementation-guide/content/ldmfunctionmanager.html
        
        cell.row1label.text = [item valueForStatement:def.dict[@"row1"]];
        cell.row3label.text = [item valueForStatement:def.dict[@"row2"]];
        cell.row2label.text = [item valueForStatement:def.dict[@"row3"]];
    }
    else{
        //you have to create a Definition item first
        cell.row1label.text = @"";
        cell.row2label.text = @"";
        cell.row3label.text = @"";
    }
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [self.searchResults titleForHeaderInSection:section];
}

- (void)searchResultsDidAddNewRows:(LDMSearchResults *)results
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.tableView reloadData];
    });
}

- (void) handleFetchError:(NSError *) error
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.tableView reloadData];
    });
}

-(IBAction)doneButtonPressed:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

-(IBAction)refreshButtonPressed:(id)sender
{
    [self refreshUI];
}


@end
