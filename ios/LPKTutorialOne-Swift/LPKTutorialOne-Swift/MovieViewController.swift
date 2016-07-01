//
//  MovieViewController.swift
//  LPKTutorialOne-Swift
//
//  Created by CARSON LI on 2016-06-30.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

import Foundation
import LiquidPlatformKit

class MovieViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    @IBOutlet weak var movieTableView: UITableView!
    private var movies = Array<LDMItem>()
    private var ratings = Dictionary<String, LDMItem>()
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(animated: Bool) {
        self.fetchData();
    }
    
    func fetchData() {
        
        //grab all items of type Movie, and update the UI.  This method of retrieving data is only suggested if you're expecting a very
        //small dataset ( < 250 ).  In future tutorials, we go through more advanced ways of retrieving large data sets
        
        LDMDataManager.sharedInstance().executeAsynch {
            if let myRatings = LDMDataManager.sharedInstance().allItemsOfType("Rating") as? Array<LDMItem>{
                for rating in myRatings {
                    if let movieId = rating.valueForKey("movieId") as? String{
                        self.ratings[movieId] = rating
                    }
                }
            }
            
            if let myMovies = LDMDataManager.sharedInstance().allItemsOfType("Movie") as? Array<LDMItem>{
                self.movies = myMovies
            }
            
            dispatch_async(dispatch_get_main_queue()){
                self.movieTableView .reloadData()
            }
        };
        
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.movies.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = self.movieTableView.dequeueReusableCellWithIdentifier("MovieTableViewCell", forIndexPath: indexPath) as! MovieTableViewCell
        let movie = self.movies[indexPath.row]
    
        cell.nameLabel.text = movie.valueForKey("name") as? String
        cell.descriptionLabel.text = movie.valueForKey("description") as? String
        
        if let movieId = movie.valueForKey("movieId") as? String{
            if let rating = self.ratings[movieId]{
                if let ratingValue = rating.valueForKey("value") as? NSNumber{
                   cell.ratingLabel.text = "\(ratingValue)"
                }
            }
            else{
                cell.ratingLabel.text = String(format: "")
            }
        }
    
        return cell
        
    }

    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        dispatch_async(dispatch_get_main_queue()){
            self.performSegueWithIdentifier("showMovieDetailSegue", sender: self.movieTableView.cellForRowAtIndexPath(indexPath))
        }
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if (segue.identifier == "showMovieDetailSegue"){
            let destinationVC = segue.destinationViewController as? MovieDetailViewController
            if let cell = sender as? UITableViewCell{
                if let indexPath = self.movieTableView.indexPathForCell(cell){
                   let movie = self.movies[indexPath.row]
                    destinationVC?.movie = movie
                    
                    if let movieId = movie.valueForKey("movieId") as? String{
                        if let rating = self.ratings[movieId]{
                            destinationVC?.myRating = rating
                        }
                    }
                }
            }
        }
        else if (segue.identifier == "createMovieSegue")
        {
            let destinationVC = segue.destinationViewController as? MovieDetailViewController
            if let newMovie = LDMDataManager.sharedInstance().itemInstanceForTypeName("Movie"){
                newMovie.setValue(LDMItem.generateId(),forKey:"movieId");
                destinationVC?.movie = newMovie
            }
        }

    }
}
