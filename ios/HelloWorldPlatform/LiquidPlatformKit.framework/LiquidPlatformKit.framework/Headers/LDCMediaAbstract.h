//
//  LDCMediaAbstract.h
//  LiquidDecisions
//
//  Created by LDMItemGenerator on 7/11/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import "LDMItem.h"
#import "LDMDimension.h"

@interface LDCMediaAbstract : LDMItem

@property (nonatomic, strong) NSString *mediaId;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *accountId;
@property (nonatomic, strong) NSString *orgPath;
@property (nonatomic, strong) LDMDimension *mediaType;
@property (nonatomic, strong) NSString *link;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *description;
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, strong) NSString *createdBy;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) NSString *updatedBy;
@property (nonatomic, strong) NSDate *updatedAt;
@property (nonatomic, strong) NSString *fileName;
@property (nonatomic, strong) NSString *contentType;
@property (nonatomic, strong) NSNumber *filesize;
@property (nonatomic, strong) LDMDimension *productHierarchy;

@end
