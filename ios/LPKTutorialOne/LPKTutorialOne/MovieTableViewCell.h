//
//  MovieTableViewCell.h
//  LPKTutorialOne
//
//  Created by CARSON LI on 2016-06-17.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MovieTableViewCell : UITableViewCell

@property (weak) IBOutlet UILabel* nameLabel;
@property (weak) IBOutlet UILabel* descriptionLabel;
@property (weak) IBOutlet UILabel* ratingLabel;

@end
