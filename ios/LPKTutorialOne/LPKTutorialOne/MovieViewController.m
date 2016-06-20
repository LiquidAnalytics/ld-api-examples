//
//  MovieViewController.m
//  LPKTutorialOne
//
//  Created by CARSON LI on 2016-06-17.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import "MovieViewController.h"
#import "MovieDetailViewController.h"
#import "MovieTableViewCell.h"

#import <LiquidPlatformKit/LDMDataManager.h>
#import <LiquidPlatformKit/LDMItem.h>
#import <LiquidPlatformKit/LDMSearchResults.h>
#import <LiquidPlatformKit/LSCSyncController.h>

@interface MovieViewController ()

@property (weak) IBOutlet UITableView *movieTableView;
@property (weak) IBOutlet UITextField *passwordField;
@property (weak) IBOutlet UILabel *infoLabel;
@property (strong) NSArray *movies;
@property (strong) NSDictionary *ratings;

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
 
    //grab all items of type Movie, and update the UI.  This method of retrieving data is only suggested if you're expecting a very
    //small dataset ( < 250 ).  In future tutorials, we go through more advanced ways of retrieving large data sets
    
    __weak MovieViewController *this = self;
    
    [[LDMDataManager sharedInstance] executeAsynch:^{
       
        NSArray *myRatings = [[LDMDataManager sharedInstance] allItemsOfType:@"Rating"];
        NSMutableDictionary *ratingDict = [NSMutableDictionary dictionary];
        
        for (LDMItem *rating in myRatings)
        {
            ratingDict[[rating valueForKey:@"movieId"]] = rating;
        }
        this.ratings = [NSDictionary dictionaryWithDictionary:ratingDict];
        
        this.movies = [[LDMDataManager sharedInstance] allItemsOfType:@"Movie"];
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

-(NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.movies.count;
}

-(UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    MovieTableViewCell* cell = [self.movieTableView dequeueReusableCellWithIdentifier:@"MovieTableViewCell" forIndexPath:indexPath];
    
    LDMItem *movie = self.movies[indexPath.row];
    LDMItem *rating = self.ratings[[movie valueForKey:@"movieId"]];
    
    cell.nameLabel.text = [movie valueForKey:@"name"];
    cell.descriptionLabel.text = [movie valueForKey:@"description"];
    cell.ratingLabel.text = rating ? [NSString stringWithFormat:@"%@ star(s)",[rating valueForKey:@"value"]] : @"N/A";
    
    return cell;
}

-(void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self performSegueWithIdentifier:@"showMovieDetailSegue" sender:[self.movieTableView cellForRowAtIndexPath:indexPath]];
    });
}


-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"showMovieDetailSegue"])
    {
        
        MovieDetailViewController* destionationVC = [segue destinationViewController];
        UITableViewCell* cell = (UITableViewCell*) sender;
        NSIndexPath *indexPath = [self.movieTableView indexPathForCell:cell];
        LDMItem *movie = self.movies[indexPath.row];
        LDMItem *rating = self.ratings[[movie valueForKey:@"movieId"]];
        
        if (rating)
            destionationVC.myRating = rating;
        
        destionationVC.movie = movie;
    }
    else if ([segue.identifier isEqualToString:@"createMovieSegue"])
    {
        MovieDetailViewController* destionationVC = [segue destinationViewController];
        LDMItem *newMovie = [[LDMDataManager sharedInstance] itemInstanceForTypeName:@"Movie"];
        [newMovie setValue:[LDMItem generateId] forKey:@"movieId"];
        destionationVC.movie = newMovie;
    }
}



@end
