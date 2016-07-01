//
//  LDMFilter+functionSupport.h
//  LiquidDecisions
//
//  Created by Mike Akers on 10/2/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import "LDMFilter.h"

@class LDMItemPath;

@interface LDMFilter (LanguageParsingExtensions)
- (void)resolveFiltersWithPath:(LDMItemPath*)path;
@end
