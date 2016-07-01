//
//  UICollectionView+LDK.h
//  LDCore
//
//  Created by Bryan Nagle on 2/5/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UICollectionView (LDK)

- (void)reloadDataPreserveSelection;
- (void)scrollToBottom:(BOOL)animated;

@end
