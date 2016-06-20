//
//  MovieViewController.m
//  LPKTutorialTwo
//
//  Created by CARSON LI on 2016-06-20.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//


#import "MovieViewController.h"
#import "MovieDetailViewController.h"
#import "MovieTableViewCell.h"

#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMItem.h>
#import <LiquidPlatformKit/LDMSearchResults.h>
#import <LiquidPlatformKit/LDMFunction.h>
#import <LiquidPlatformKit/LSCSyncController.h>
#import <LiquidPlatformKit/LDMQueryFilter.h>
#import <LiquidPlatformKit/LDMQueryFilterClause.h>
#import <LiquidPlatformKit/LDMFilter.h>

@interface MovieViewController ()

@property (weak) IBOutlet UITableView *movieTableView;
@property (weak) IBOutlet UITextField *passwordField;
@property (weak) IBOutlet UILabel *infoLabel;
@property (weak) IBOutlet UISearchBar *searchBar;
@property (strong) LDMSearchResults *movies;
@property (strong) LDMItem *selectedMovie;
@property (strong) LDMItem *selectedRating;
@property (strong) NSString *searchTerm;

@end

@implementation MovieViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void) viewWillAppear:(BOOL)animated
{
    //for the first tutorial we will fetch the data every time the view appears
    //for future tutorials we will utilize proper observers / notifications
    [self fetchData];
}

-(void) fetchData
{
    
    LDMQueryFilter *qf = [[LDMQueryFilter alloc] init];
    if (self.searchTerm.length != 0)
    {
        //we'll search by movie name and description
        LDMQueryFilterClause *clause = [[LDMQueryFilterClause alloc] init];
        [clause addFilter:[[LDMFilter alloc] initWithField:@"name" value:self.searchTerm comparison:LDMFilterComparisonLike]];
        [clause addFilter:[[LDMFilter alloc] initWithField:@"description" value:self.searchTerm comparison:LDMFilterComparisonLike]];
        [qf addClause:clause];
    }
    
    __weak MovieViewController *this = self;
    [LDMFunction allItemsfromFunctionId:@"AllMovieRatings" queryFilter:qf faultBlocks:NO context:nil completion:^(LDMSearchResults * _Nullable results) {
        this.movies = results;
        this.movies.delegate = this;
        dispatch_async(dispatch_get_main_queue(), ^{
            [this refreshUI];
        });
    }];
}

-(IBAction)syncButtonPressed:(id)sender
{
    NSLog(@"Sync requested");
    
    if(![LSCSyncController sharedInstance].serverReachable)
    {
        NSLog(@"Server was not reachable. Will not sync.");
        return;
    }
    
    [[LSCSyncController sharedInstance] requestSyncWithCompletionHandler:^(BOOL syncSucceeded) {
        NSLog(@"Sync was successful: %s", syncSucceeded ? "YES":"NO");
    }];
}

-(void) refreshUI
{
    [self.movieTableView reloadData];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.movies numberOfSections];
}

-(NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.movies numberOfRowsInSection:section];
}

-(UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    MovieTableViewCell* cell = [self.movieTableView dequeueReusableCellWithIdentifier:@"MovieTableViewCell" forIndexPath:indexPath];
    
    LDMItem *movieRatingComposite = [self.movies objectForRowAtIndexPath:indexPath];
   
    cell.nameLabel.text = [movieRatingComposite valueForKey:@"name"];
    cell.descriptionLabel.text = [movieRatingComposite valueForKey:@"description"];
    cell.ratingLabel.text = [movieRatingComposite valueForKey:@"value"] ? [NSString stringWithFormat:@"%@", [movieRatingComposite valueForKey:@"value"]] : @"";
    
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
   return [self.movies titleForHeaderInSection:section];
}

-(void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [[LDMDataManager sharedInstance] executeAsynch:^{
        
        LDMItem *movieRatingComposite = [self.movies objectForRowAtIndexPath:indexPath];
        self.selectedMovie = [[LDMDataManager sharedInstance] itemOfType:@"Movie" withId:[movieRatingComposite valueForKey:@"movieId"]];
        
        if ([[movieRatingComposite valueForKey:@"ratingId"] length] != 0)
            self.selectedRating = [[LDMDataManager sharedInstance] itemOfType:@"Rating" withId:[movieRatingComposite valueForKey:@"ratingId"]];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self performSegueWithIdentifier:@"showMovieDetailSegue" sender:[self.movieTableView cellForRowAtIndexPath:indexPath]];
        });
    }];
}

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    if (searchText.length == 0)
    {
        self.searchTerm = searchBar.text;
        [self fetchData];
    }
}

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar
{
    self.searchTerm = searchBar.text;
    [self fetchData];

}

-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"showMovieDetailSegue"])
    {
        MovieDetailViewController* destionationVC = [segue destinationViewController];
        destionationVC.myRating = self.selectedRating;
        destionationVC.movie = self.selectedMovie;
    }
    else if ([segue.identifier isEqualToString:@"createMovieSegue"])
    {
        MovieDetailViewController* destionationVC = [segue destinationViewController];
        LDMItem *newMovie = [[LDMDataManager sharedInstance] itemInstanceForTypeName:@"Movie"];
        [newMovie setValue:[LDMItem generateId] forKey:@"movieId"];
        destionationVC.movie = newMovie;
    }
}

- (void)searchResultsDidAddNewRows:(LDMSearchResults *)results
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.movieTableView reloadData];
    });
}

- (void) handleFetchError:(NSError *) error
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.movieTableView reloadData];
    });
}


@end
