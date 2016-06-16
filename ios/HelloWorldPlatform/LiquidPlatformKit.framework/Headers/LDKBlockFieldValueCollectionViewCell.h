//
//  LDKBlockFieldValueCollectionViewCell.h
//  LDCore
//
//  Created by Bryan Nagle on 3/2/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKEditDetailCollectionViewCell.h"

@interface LDKBlockFieldValueCollectionViewCell : LDKEditDetailCollectionViewCell<LDKEditDetailCollectionViewCellDelegate, LDKCaptureViewControllerDelegate>

@property (nonatomic, assign) BOOL editDisabled;

- (void)sizeToFit;

@end
