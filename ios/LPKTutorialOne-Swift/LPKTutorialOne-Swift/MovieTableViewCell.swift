//
//  MovieTableViewCell.swift
//  LPKTutorialOne-Swift
//
//  Created by CARSON LI on 2016-07-01.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

import UIKit

public class MovieTableViewCell: UITableViewCell
{
    @IBOutlet public weak var nameLabel: UILabel!
    @IBOutlet public weak var descriptionLabel: UILabel!
    @IBOutlet public weak var ratingLabel: UILabel!
    
    override public func awakeFromNib()
    {
        super.awakeFromNib()
        // Initialization code
    }
    
    override public func setSelected(selected: Bool, animated: Bool)
    {
        super.setSelected(selected, animated: animated)
        // Configure the view for the selected state
    }
    
}