//
//  LDKDicussionMessageTokenizer.h
//  LDCore
//
//  Created by Mike Akers on 3/26/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, DiscussionTokenType)
{
    DiscussionTokenTypeHashTag,
    DiscussionTokenTypeCallout,
    DiscussionTokenTypeItemReference
};

@interface LDKDicussionMessageToken : NSObject

@property (strong, nonatomic) NSString *text;
@property NSRange range;
@property DiscussionTokenType type;

- (instancetype)initWithText:(NSString*)text range:(NSRange)range;
@end

@interface LDKDicussionMessageTokenizer : NSObject

- (NSArray*)tokensForString:(NSString*)string;

@end
