//
//  NSString+LDCoreExtensions.h
//  LDCore
//
//  Created by Bryan Nagle on 9/10/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@interface NSString (LDCoreExtensions)

@property (readonly) NSString *stringByRemovingOuterQuotes;
@property (readonly) NSString *stringByRemovingOuterSingleQuotes;
@property (readonly) NSString *stringByTrimmingWhiteSpace;
@property (readonly) NSDate *javaTimeToDate;
/** returns the string with camel cased words converted to individual capitalized words */
@property (readonly) NSString *wordsFromCamelCase;

@property (readonly) BOOL containsRelation;
@property (readonly) BOOL containsFunction;
@property (readonly) BOOL isLiteral;

- (BOOL)containsRelation;
- (BOOL)containsFunction;
- (BOOL)containsQueryFilter;
- (BOOL)isLiteral;
- (BOOL)containsBlockWithValueSpecifier;
- (BOOL)containsString:(NSString *)match;
- (BOOL)containsAnyString:(NSArray *)matches;
- (BOOL)containsStrings:(NSArray *)matches;
- (BOOL)beginsWithString:(NSString *)match;
- (BOOL)isCaseInsensitiveEqualToAnyStringInArray:(NSArray *)strings;
- (NSString*)stringBetweenString:(NSString *)start andString:(NSString *)end;
- (NSString *)stringBetweenString:(NSString *)start andLastOccuranceOfString:(NSString *)end;
- (NSString *)stringBetweenLastOccuranceOfString:(NSString *)start andString:(NSString *)end;
- (NSString *)stringBeforeLastOccuranceOfString:(NSString *)string;
- (NSString *)stringAfterLastOccuranceOfString:(NSString *)string;
- (NSString *)stringUntilString:(NSString *)end;
- (NSString *)stringAfterString:(NSString *)start;
- (BOOL)isCaseInsensitiveEqualToString:(NSString *)string;
- (BOOL)isEqualToAnyString:(NSString *)firstArg, ... NS_REQUIRES_NIL_TERMINATION;
- (BOOL)isCaseInsensitiveEqualToAnyString:(NSString *)firstArg, ... NS_REQUIRES_NIL_TERMINATION;
- (void)blockSwitch:(NSString *)firstArg, ... NS_REQUIRES_NIL_TERMINATION;
- (void)blockSwitchWithDefault:(void (^)())defaultBlock cases:(NSString *)firstArg, ... NS_REQUIRES_NIL_TERMINATION;
- (NSUInteger)countOfCharacter:(UniChar)character;
- (BOOL)containsBlock;
- (NSString *)stringWithNegativeFormatByStrippingParenthesis;
- (NSString *)stringAfterRemovingComments;
- (NSUInteger)numberOfLines;
- (BOOL)isISO8601Timestamp;
- (BOOL)isLongString;
- (BOOL)isDateString;
- (NSString *) camelCaseFromNaturalLanguage;
- (NSString *) camelCaseFromNaturalLanguage:(BOOL)upperFirstChar;


@end
