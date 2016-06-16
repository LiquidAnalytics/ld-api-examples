//
//  LDKCollectionView.h
//  LDCore
//
//  Created by Bryan Nagle on 12/24/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TPKeyboardAvoidingCollectionView.h"

@interface LDKCollectionView : TPKeyboardAvoidingCollectionView

@property (readonly, nonatomic) NSArray *allCells;

- (UICollectionViewCell *)nonReusableCellWithIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;
- (NSString *)keyForNonReusableCell:(UICollectionViewCell *)cell;

@end
