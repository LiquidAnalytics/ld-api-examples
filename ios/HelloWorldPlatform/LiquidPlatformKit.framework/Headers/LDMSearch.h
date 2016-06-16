//
//  LDMSearch.h
//  LDCore
//
//  Created by Bryan Nagle on 2/5/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//


@interface LDMSearch : LDMItem

@property (nonatomic, strong) NSString *queryId;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *itemType;
@property (nonatomic, strong) NSArray *queryFilter;
@property (nonatomic, strong) NSString *image;
@property (nonatomic, strong) NSNumber *sort;
@property (nonatomic, strong) NSString *createdBy;
@property (nonatomic, strong) LDMDimension *orgPath;
@property (nonatomic, strong) NSString *accountId;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *searchText;
@property (strong) NSString *scope;
@property (strong) NSString *useIdentifier;
@property (strong) NSArray *groupIds;

@end
