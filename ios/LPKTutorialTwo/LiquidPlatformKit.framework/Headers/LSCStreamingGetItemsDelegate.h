//
//  LSCStreamingGetItemsDelegate
//  LDCore
//
//  Created by Marshall Hayden on 3/24/14.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LSCStreamingGetItemsParser;
@class LDMItem;

@protocol LSCStreamingGetItemsDelegate <NSObject>

- (void) parserDidBegin:(LSCStreamingGetItemsParser *)parser;
- (void) parserDidEnd:(LSCStreamingGetItemsParser *)parser;

- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveSchema:(NSDictionary *)schemaDict;
- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveRelationship:(NSDictionary *)relationshipDict;
- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveDefinitions:(NSDictionary *)definitions;

- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveDeleteItemDictionary:(NSDictionary *)dict;

- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveItemDictionary:(NSDictionary *)dict weight:(int)weight;
- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveBlock:(LDMItem *)block forField:(NSString *)fieldName onItem:(LDMItem *)item;

- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveTruncateMessage:(id)truncateMessage;
- (void) parser:(LSCStreamingGetItemsParser *)parser didReceivePrepareMessage:(id)prepareMessage;

- (void) parser:(LSCStreamingGetItemsParser *)parser didReceiveUnhandledElement:(id)element;

@end
