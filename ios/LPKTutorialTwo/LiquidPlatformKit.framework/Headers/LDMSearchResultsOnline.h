//
//  LDMSearchResultsOnline.h
//  LDCore
//
//  Created by Carson Li on 2014-03-10.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDMSearchResults.h"

@class LDMDataManager, LDMQueryFilter;

@interface LDMSearchResultsOnline : LDMSearchResults <LDMSearchResultsProtocol>

@property BOOL didViewLastPage;
@property (nonatomic, strong) NSDate *timeStamp;
@property (nonatomic, copy) void (^didFetchInitialData)(LDMSearchResultsOnline *results);
@property (nonatomic, copy) void (^searchResultsDidAddNewRowsHandler)(LDMSearchResultsOnline *results);
@property (nonatomic, copy) void (^fetchErrorHandler)(NSString *errorMessage);

- (id)initWithWithParams:(NSDictionary*)aParams functionId:(NSString *)functionId queryFilter:(LDMQueryFilter *)queryFilter itemType:(NSString*)itemType orderedBy:(NSString *)orderCol ascending:(BOOL)ascending maxResults:(NSInteger)maxResults faultBlocks:(BOOL)faultBlocks dataManager:(LDMDataManager *)manager;

- (void)initResults:(NSDictionary*)initialData;
- (void)addResultsToDataSet:(NSArray*)results forPage:(int)page;

@end
