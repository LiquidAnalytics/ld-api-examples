//
//  LDKSearchBar.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 5/24/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@protocol LDKSearchBarButtonDelegate;
@class LDMQueryFilter;

@interface LDKSearchBar : UISearchBar

@property (weak) id<LDKSearchBarButtonDelegate> searchButtonDelegate;
@property BOOL enabled;
@property BOOL filterButtonsEnabled;
@property float rightInset;
@property (nonatomic, strong) NSArray *filtersForCurrentIndex;
@property (strong, nonatomic) UIColor *buttonTextColor;
@property (strong, nonatomic) UIColor *buttonTextHighlightColor;

- (void)addButtonWithActiveFilterImage:(UIImage *)activeImage inactiveFilterImage:(UIImage*)inactiveImage andName:(NSString *)name;
- (void)removeAllButtonsAnimate:(BOOL)animate;
- (void)removeButtonWithName:(NSString*) name andAnimate:(BOOL) animate;
- (void)buttonNamed:(NSString *)name isActive:(BOOL)active;
- (void)setSearchIndex:(NSInteger)newIndex;
- (void)clearSearchTextForIndex:(NSInteger)newIndex;
- (void)clearSearchText;
- (void)setEnabled:(BOOL)enabled;
- (void)removeSearchAccessoryAtIndex:(NSUInteger) index;
- (void)addButtonWithActiveFilterImage:(UIImage *)activeImage inactiveFilterImage:(UIImage *)inactiveImage buttonText:(NSString *)buttonText andName:(NSString *)name;
- (void)addButtonOfStyle:(NSString *)style withText:(NSString *)text withMinSize:(CGSize)minSize withPadding:(float)padding forName:(NSString *)name;
- (void)addButtonOfClass:(Class)class withText:(NSString *)text withMinSize:(CGSize)minSize withPadding:(float)padding forName:(NSString *)name;
- (NSArray *)filtersForIndex:(NSInteger)newIndex;
- (NSArray *)filtersForCurrentIndex;
- (void)setFilters:(NSArray *)filters ForIndex:(NSInteger)newIndex;
- (void)setFiltersForCurrentIndex:(NSArray *)filters;
- (void)updateRightInset:(float)aRightInset;
- (void)clearFiltersForIndex:(NSInteger)newIndex;
- (void)clearFiltersForCurrentIndex;
- (LDMQueryFilter*)searchQueryFilterForItemType:(NSString *)itemType;
- (void)hideSearchTextField;

@end

@protocol LDKSearchBarButtonDelegate <NSObject>

- (void)searchBar:(LDKSearchBar *)searchBar buttonPressed:(UIButton*)button withName:(NSString *)name;

@end