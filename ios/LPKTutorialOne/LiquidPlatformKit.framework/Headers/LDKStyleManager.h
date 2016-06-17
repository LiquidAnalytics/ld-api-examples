//
//  LDKStyleManager.h
//  LiquidDecisions
//
//  Created by Eric Johnson on 5/21/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

//Standard Color enum
typedef NS_ENUM(NSUInteger, LDKStandardColor) {
    LDKStandardColorRed,
    LDKStandardColorOrange,
    LDKStandardColorBlack,
    LDKStandardColorWhite,
    LDKStandardColorDarkGrey,
    LDKStandardColorLightGrey,
    LDKStandardColorGreen,
    LDKStandardColorLightGreen,
    LDKStandardColorBlue,
    LDKStandardColorLightBlue
};
//Standard Font enum
typedef NS_ENUM(NSUInteger, LDKStandardFont) {
    LDKStandardFontLight,
    LDKStandardFontHeavy,
    LDKStandardFontCondensedBold,
    LDKStandardHeaderFontLight,
    LDKStandardHeaderFontLightSmall,
    LDKStandardKeypadFont,
    LDKStandardSubHeaderFontLight
};

@interface LDKStyleManager : NSObject

//Class Methods
+ (UIFont *__nullable)fontFromName:(NSString *__nullable)fontString andSize:(float)fontSize;
+ (UIFont *__nullable)fontForKey:(NSString *__nullable)key;
+ (UIColor *__nullable)colorForKey:(NSString *__nullable)key;
+ (UIColor *__nullable)colorForKey:(NSString *__nullable)key defaultColor:(UIColor *__nullable)defaultColor;
+ (NSArray*__nullable)colorsForKey:(NSString *__nullable)key;
+ (NSString *__nullable)hexStringForKey:(NSString *__nullable)key;
+ (void)fontAndColorForKey:(NSString *__nullable)key withBlock:(void (^__nonnull)(UIFont * __nullable font, UIColor * __nullable color))block;
+ (UIColor *__nullable)standardColorForKey:(LDKStandardColor)standarColorKey;
+ (UIColor *__nullable)standardColorForKey:(LDKStandardColor)standarColorKey defaultColor:(UIColor *__nullable)defaultColor;
+ (UIFont *__nullable)standardFontForKey:(LDKStandardFont)standardFontKey;
+ (void)setStandardLabelUXForLabel:(UILabel *__nullable)aLabel;
+ (void)setStandardTextUXForLabel:(UILabel *__nullable)aLabel;
+ (NSString*__nullable)deCamelCase:(NSString *__nullable) string;
+ (NSArray*__nullable)rgbColorValuesForKey:(NSString*__nullable)key;
+ (NSTextAlignment)textAlignmentFromString:(NSString *__nullable)string defaultAlignment:(NSTextAlignment)defaultAlignment;
+ (UIColor * __nullable)colorFromString:(NSString *__nullable)string;
+ (UIColor *__nullable)colorFromString:(NSString *__nullable)string defaultColor:(UIColor *__nullable)defaultColor;

@end
