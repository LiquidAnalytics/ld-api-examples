//
//  LSCStreamingItemParser.h
//  LDCore
//
//  Created by Marshall Hayden on 3/24/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSCStreamingGetItemsDelegate.h"

@interface LSCStreamingGetItemsParser : NSObject

@property (weak) id<LSCStreamingGetItemsDelegate> delegate;

- (instancetype)init;
-(void)parse:(NSData *)data;
-(void)print;
- (BOOL)handleElement:(NSDictionary *)element weight:(NSNumber *)weight;

@end
