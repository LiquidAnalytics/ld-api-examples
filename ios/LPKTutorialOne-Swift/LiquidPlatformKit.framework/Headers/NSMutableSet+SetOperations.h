//
//  NSMutableSet+SetOperations.h
//  LDCore
//
//  Created by Eric Johnson on 2/19/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface NSMutableSet (SetOperations)
- (NSMutableSet *) newSetWithSymmetricDifference:(NSMutableSet *)setB;
- (NSMutableSet *) newSetMinusSet:(NSMutableSet *)setB;
- (NSMutableSet *) newSetUnionSet:(NSMutableSet *)setB;
- (NSMutableSet *) newSetIntersectionSet:(NSMutableSet *)setB;
- (void) symmetricDifference:(NSMutableSet *)setB;
@end
