//
//  LDCSearchBarController.h
//  LDCore
//
//  Created by Bryan Nagle on 9/24/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDCSearchBarControllerDelegate;

@interface LDCSearchBarController : NSObject<UISearchBarDelegate>

@property (weak) id<LDCSearchBarControllerDelegate> delegate;

@end

@protocol LDCSearchBarControllerDelegate <NSObject>

- (void)searchBarController:(LDCSearchBarController *)controller performSearchWithText:(NSString *)searchText;

@optional

- (BOOL)searchBarController:(LDCSearchBarController *)controller searchBarShouldBeginEditing:(UISearchBar *)aSearchBar;
- (void)searchBarController:(LDCSearchBarController *)controller searchBarDidEndEditing:(UISearchBar *)aSearchBar;

@end