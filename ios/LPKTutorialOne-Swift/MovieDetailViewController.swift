//
//  MovieDetailViewController.swift
//  LPKTutorialOne-Swift
//
//  Created by CARSON LI on 2016-07-01.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

import LiquidPlatformKit
import BlocksKit

class MovieDetailViewController: UIViewController{
    
    @IBOutlet weak var categoryLabel: UILabel!
    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var descriptionTextView: UITextView!
    @IBOutlet weak var ratingTextField: UITextField!
    @IBOutlet weak var changeButton: UIButton!
    @IBOutlet weak var horizontalViewStack: UIStackView!
 
    internal var movie : LDMItem!
    internal var myRating : LDMItem!
    internal var currentCategory : LDMEnumeration!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let theCategory = self.movie.valueForKey("movieCategory") as? LDMEnumeration{
            self.currentCategory = theCategory
        }
        
        LDMEnumeration.enumerationsNamed("movieCategory") { (results: [AnyObject]!) in
            if let enumResults = results as? Array<LDMEnumeration> {
                for category in enumResults{
                    let button = UIButton()
                    button.setTitle(category.display, forState: .Normal)
                    button.setTitleColor(UIColor.whiteColor(),  forState: .Normal)
                    button.backgroundColor = UIColor.blueColor()
                
                    button.bk_addEventHandler({ (sender: AnyObject! ) in
                        self.currentCategory = category
                        self.refreshUI()
                        
                    }, forControlEvents: .TouchUpInside)
                
                    self.horizontalViewStack.addArrangedSubview(button)
                }
            }
        }
        
        self.refreshUI()
    }
    
    func refreshUI(){
    
        self.nameField.text = self.movie.valueForKey("name") as? String
        self.descriptionTextView.text = self.movie.valueForKey("description") as? String
        
        if let category = self.currentCategory {
            self.categoryLabel.text = category.stringValue
        }
        else{
            self.categoryLabel.text = ""
        }
        
        if let rating = self.myRating{
            if let ratingValue = rating.valueForKey("value") as? NSNumber{
                self.ratingTextField.text = "\(ratingValue)"
            }
        }
    
    }
    
    @IBAction func saveButtonPressed(){
        
        self.movie.setValue(self.nameField.text, forKey: "name")
        self.movie.setValue(self.descriptionTextView.text, forKey: "description")
        
        if let category = self.currentCategory{
            self.movie.setValue(category, forKey: "movieCategory")
        }
        
        if let ratingText = self.ratingTextField.text{
            if let rating = self.myRating{
                rating.setValue(ratingText, forKey: "value")
                LDMDataManager.sharedInstance().transactCreateOrUpdateWithItem(rating, withCompletionHandler: nil)
            }
            else{
                if let newRating = LDMDataManager.sharedInstance().itemInstanceForTypeName("Rating"){
                    let user = LDMDataManager.sharedInstance().getUser()
                    newRating.setValue(LDMItem.generateId(), forKey: "ratingId")
                    newRating.setValue(user.valueForKey("userId"), forKey: "userId")
                    newRating.setValue(self.movie.valueForKey("movieId"), forKey: "movieId")
                    newRating.setValue(ratingText, forKey: "value")
                    LDMDataManager.sharedInstance().transactCreateOrUpdateWithItem(newRating, withCompletionHandler: nil)
                }
            }
        }
        
        LDMDataManager.sharedInstance().transactCreateOrUpdateWithItem(self.movie) { (success:Bool) in
             self.navigationController?.popViewControllerAnimated(true)
        }
        
    }
    
    @IBAction func deleteButtonPressed(){
        var items = Array<LDMItem>()
        if let rating = self.myRating{
            items.append(rating)
        }
        if let movie = self.movie{
            items.append(movie)
        }
        
        LDMDataManager.sharedInstance().transactDeleteWithItems(items) { (success:(Bool)) in
                self.navigationController?.popViewControllerAnimated(true)
        }
    }
    
}
