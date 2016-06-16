//
//  TSStack.h
//  LDCore
//
//  Created by David Ellis on 2013-05-23.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TSStack : NSObject
{
    NSMutableArray *contents;
    NSLock         *threadLock;
}

- (void)push:(id)object;
- (id)pop;
@end

