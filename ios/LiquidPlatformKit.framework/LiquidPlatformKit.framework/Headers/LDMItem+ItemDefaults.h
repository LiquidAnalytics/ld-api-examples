//
//  LDMItem+ItemDefaults.h
//  LiquidDecisions
//
//  Created by Eric Johnson on 2/18/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import "LDMItem.h"

@interface LDMItem (ItemDefaults)
+ (LDMItem *)newItemOfType:(NSString *)type;
- (LDMItem *)clone;
- (LDMItem *)cloneAndReplacePrimarykeys;
@end
