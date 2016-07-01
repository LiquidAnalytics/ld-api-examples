//
//  LDCBatchOperator.h
//  LDCore
//
//  Created by Marshall Hayden on 4/1/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDCBatchOperator : NSObject

- (nonnull instancetype) initWithBatchCount:(int)batchCount batchWeight:(int)batchWeight queue:(dispatch_queue_t _Nonnull)queue callback:(void (^_Nonnull)(NSArray *_Nonnull batch))batchHandler;
- (void) addObject:(id _Nonnull)object;
- (void) addObject:(id _Nonnull)object withCount:(int)count withWeight:(int)weight;
- (void) handleCurrent;
- (int) totalCount;
- (int) totalWeight;
- (void) resetTotals;

@end
