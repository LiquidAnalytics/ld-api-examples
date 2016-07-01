//
//  LSCGetItemsRESTHandler.h
//  LDCore
//
//  Created by Marshall Hayden on 3/27/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import "LSCRestStateHandler.h"
#import "LSCStreamingGetItemsDelegate.h"

@interface LSCGetItemsRESTHandler : LSCRestStateHandler <LSCStreamingGetItemsDelegate>

@property (strong, nullable) NSString *method;
@property (strong, nullable) NSNumber *track;
@property (strong, nullable) NSString *syncReason;
@property (strong, nullable) NSString *apiPath;
@property (strong, nullable) NSNumber *setPostParams;
@property (strong, nonnull) LSCStreamingGetItemsParser *parser;

- (void) processItems:(NSArray * __nonnull)batch;
- (void) processItemDeletes:(NSArray * __nonnull)batch;
- (void) finishProcessingCount:(int)totalCount weight:(int)totalWeight;

@end
