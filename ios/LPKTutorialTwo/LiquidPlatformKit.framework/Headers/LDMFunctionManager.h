//
//  LDMFunctionManager.h
//  LDCore
//
//  Created by CARSON LI on 2014-12-02.
//  Copyright (c) 2014 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@class LDMItem, LDMItemPath, LDMDimension, LDMSchemaField, ISO8601DateFormatter;

@interface LDMFunctionManager : NSObject

@property (strong) NSDateFormatter *shortDateFormatter;
@property (strong) NSDateFormatter *dateFormatter;
@property (strong) NSNumberFormatter *numberFormatter;
@property (strong) NSNumberFormatter *nonZeroNumberFormatter;
@property (strong) CLLocationManager *locationManager;
@property (strong) LDMItemPath *path;
@property (strong) NSDictionary *varDict;
@property (strong) NSMutableDictionary *cachedItemsByClientId;
@property (strong) NSTimer *cacheTimer;

+ (LDMFunctionManager *)sharedInstance;

- (id)executeMethodNamed:(NSString *)methodName withArgument:(id)argument;
- (id)executeMethodNamed:(NSString *)methodName onTarget:(id)target withArgument:(id)argument;
- (id)executeMethodNamed:(NSString *)methodName onTarget:(id)target;
- (id)executeMethodNamed:(NSString *)methodName;

/*!
 * @brief A simple way to create a new unique ID
 * @return A string that can be used as the primary key for any field
 */
- (NSString *)uuid;

/* Number Rounding / Formatting */

/*!
 * @brief A number parsing helper, removes decimals
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, rounded down with no decimal places
 */
- (NSString *)floatWithoutZero:(id)input;

/*!
 * @brief A number parsing helper, keeps decimals
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, rounded up to 2 decimal places
 */
- (NSString *)floatWithZero:(id)input;

/*!
 * @brief A number parsing helper, removes decimals, formatted with $
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, rounded down with no decimal places, starts with $
 */
- (NSString *)toCurrencyWithoutZero:(id)input;

/*!
 * @brief A number parsing helper, keeps decimals, formatted with $
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, rounded up to 2 decimal places, starts with $
 */
- (NSString *)toCurrencyWithZero:(id)input;

/*!
 * @brief A number parsing helper for formatting percentages
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, multiplied by 100, no decimal places
 */
- (NSString *)toPercent:(NSNumber *)input;

/*!
 * @brief A number parsing helper for formatting percentages
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, multiplied by 100, keeps 1 decimal place
 */
- (NSString *)toPercentWith1Decimal:(id)input;

/*!
 * @brief A number parsing helper for formatting percentages
 * @param input The number to be parsed, can be a NSString or NSNumber
 * @return String representation of number, multiplied by 100, keeps 2 decimal places
 */
- (NSString *)toPercentWith2Decimal:(id)input;

/* _Number Rounding / Formatting_ */

/* String Parsing */

/*!
 * @brief Returns yes / no instead of true / false
 * @param input The value to be evaluated, can be a NSSTring or NSNumber
 * @return The string YES or NO, instead of true or false
 */
- (NSString *)yesOrNo:(id)input;

/*!
 * @brief Returns yes / empty string instead of true / false
 * @param input The value to be evaluated, can be a NSSTring or NSNumber
 * @return The string YES or Empty String, instead of true or false
 */
- (NSString *)yesOrBlank:(id)value;

/*!
 * @brief Returns upper case version of input string
 * @param input The string to be transformed
 * @return The upper case version of the input string
 */
- (NSString *)toUpper:(NSString *)input;

/*!
 * @brief Returns lower case version of input string
 * @param input The string to be transformed
 * @return The lower case version of the input string
 */
- (NSString *)toLower:(NSString *)input;

/*!
 * @brief Returns empty string or just the input parameter
 * @param input The string to be evaluated
 * @return The input string if it exists, otherwise an empty string
 */
- (NSString *)noneIfEmpty:(id)input;

/*!
 * @brief Returns input parameter or the string N/A
 * @param input The string to be evaluated
 * @return The input string if it exists, otherwise the string N/A
 */
- (NSString *)notAvailable:(id)input;

/*!
 * @brief Substring for first six characters
 * @param input The string to be evaluated
 * @return The first six characters of the input string
 */
- (NSString *)firstSixCharacters:(NSString*)input;

/*!
 * @brief Substring for last six characters
 * @param input The string to be evaluated
 * @return The last six characters of the input string
 */
- (NSString *)lastSixCharacters:(NSString*)input;

/*!
 * @brief Transform array of strings into a comma separated value string
 * @param input The string to be evaluated, should be NSArray
 * @return A csv string composed of the values in the array
 */
-(NSString*) toCSVString:(id)input;

/*!
 * @brief Format the address block into one formatted string
 * @param address The LDMItem to format, should be of itemType Address
 * @return A string with new lines to describe the addres block
 */
- (NSString*)fullAddressOnMutipleLines:(LDMItem*) address;

/* _String Parsing_ */

/* Image Helpers */

/*!
 * @discussion Simple transformation from UIImage to Base64 encoded string, 
               schema should be type base64
 * @param image The image to be converted
 * @return A base64 encoded string that respresents the input image
 */
- (NSString *)encodeToBase64String:(UIImage *)image;

/*!
 * @brief Simple transformation from a base64 encoded string, to an UIImage
 * @param strEncodeData The base64 encoded string that represents the image data
 * @return An UIImage that is decoded from the input string variable
 */
- (UIImage *)decodeBase64ToImage:(NSString *)strEncodeData;
/* _Image Helpers_ */


/* Validation */

/*!
 * @brief A simple check to ensure a valid phone number
 * @param phoneNumber the input string to be evaluated
 * @return True or False in an NSNumber format depending on whether the phone number format is valid
 */
- (NSNumber*)isValidPhoneNumber:(NSString*)phoneNumber;

/*!
 * @brief A simple check to ensure a valid email
 * @param emailAddress the input string to be evaluated
 * @return True or False in an NSNumber format depending on whether the email format is valid
 */
- (NSNumber*)isValidEmail:(NSString*)emailAddress;
/* _Validation_ */

/* Date and Time manipulation */

/*!
 * @brief Formats input date into MM/dd/yyyy format, for local time zone
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toShortDate:(id)dateObj;

/*!
 * @brief Formats input date into MM/dd/yy hh:mm a format, for local time zone
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toShortDateWithTime:(id)dateObj;

/*!
 * @brief Formats input date into MMMM/dd/yyyy format, for local time zone
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toLongDate:(NSDate *)date;

/*!
 * @brief Formats input date into MMMM/dd/yyyy hh:mm a format, for local time zone
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toLongDateWithTime:(NSDate *)date;

/*!
 * @discussion Formats input date into MM/dd/yyyy format, 
               for GMT (UTC) time zone
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toShortDateAsGMT:(id)dateObj;

/*!
 * @discussion Formats input date into MM/dd/yyyy format,
               for local time zone and defaults with N/A
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format, N/A is date is empty
 */
- (NSString *)toShortDateWithDefaultString:(id)dateObj;

/*!
 * @discussion Formats input date into MM/dd/yyyy format,
               for GMT (UTC) time zone and defaults with N/A
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format, N/A is date is empty
 */
- (NSString *)toShortDateAsGMTWithDefaultString:(id)dateObj;

/*!
 * @brief Formats input date into EEE MM/dd/yyyy format, local time zone
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)fullDate:(id) dateObj;

/*!
 * @brief Simple helper to return the current date in MM/dd/yyyy format
 * @return The current date in a string format
 */
- (NSString *)currentShortDate;

/*!
 * @discussion Determines if the input parameter is for 
               "today" (same year, month and day)
 * @param input The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return true if the input date is for date, false otherwise
 */
- (BOOL) isDateForToday:(id)input;

/*!
 * @discussion Simple way to retrieve the number of seconds from
               "now" to beginning of 1970
 * @return A string for the number of seconds since 1970, no decimal places
 */
- (NSString *)now;

/*!
 * @discussion Simple way to retrieve the number of seconds from "now" 
               to beginning of 1970, plus 1 hour
 * @param input The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 */
- (NSString*) oneHourFromNow;

/*!
 * @discussion Simple way to retrieve the number of seconds from "now"
               to beginning of 1970, plus 3 months
 * @return A string for the number of seconds since 1970 plus 3 months, no decimal places
 */
- (NSString*) threeMonthsFromNow;

/*!
 * @discussion Simple way to retrieve the number of seconds from "now" 
               to beginning of 1970, plus 6 months
 * @return A string for the number of seconds since 1970 plus 6 months, no decimal places
 */
- (NSString*) sixMonthsFromNow;

/*!
 * @discussion Simple way to retrieve the number of seconds from "now" 
               to beginning of 1970, plus 1 year
 * @return A string for the number of seconds since 1970 plus 1 year, no decimal places
 */
- (NSString*) oneYearFromNow;

/*!
 * @discussion Formats input date into yyyy-MM-dd HH:mm:ss format
               in local time zone, appropriate for online queries
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toRDSDate:(NSDate *)date;

/*!
 * @discussion Formats input date into yyyy-MM-dd HH:mm:ss format
               in GMT (UTC) time zone, appropriate for online queries
 * @param dateObj The date to be parsed, NSDate or NSString, which can also be in java milliseconds
 * @return The date in string format
 */
- (NSString *)toRDSGMTDate:(NSDate *)date;

/*!
 * @brief Simple way to retrieve the current datetime in yyyy-MM-dd HH:mm:ss format
 * @return The date in string format
 */
- (NSString *)rdsNow;

/*!
 * @brief Simple way to retrieve the 12:00:00 a.m today in yyyy-MM-dd HH:mm:ss format
 * @return The date in string format
 */
- (NSString*)beginningOfTodayRDS;

/*!
 * @brief Simple way to retrieve the 11:59:59 a.m today in yyyy-MM-dd HH:mm:ss format
 * @return The date in string format
 */
- (NSString*)endOfTodayRDS;

/* _Date and Time manipulation_ */

/* Enumeration Helper Functions */

/*!
 * @brief Retrieve the element component of the enumeration
 * @param input The Enumeration object to extract from
 * @return A string, the element value in the enumeration object
 */
- (NSString *)enumerationElement:(LDMEnumeration*) input;

/*!
 * @brief Retrieve the display component of the enumeration
 * @param input The Enumeration object to extract from
 * @return A string, the display value in the enumeration object
 */
- (NSString *)enumerationDisplay:(LDMEnumeration*) input;

/* _Enumeration Helper Functions_ */

/* Dimension Helper Functions */
/*!
 * @brief Retrieve the path component of the dimension
 * @param dimension The Dimension object to extract from
 * @return A string, the path value in the dimension object
 */
- (NSString *)dimensionPath:(LDMDimension*) dimension;

/*!
 * @brief Retrieve the alias component of the dimension
 * @param dimension The Dimension object to extract from
 * @return A string, the alias value in the dimension object
 */
- (NSString *)dimensionAlias:(LDMDimension*) dimension;

/*!
 * @brief Retrieve the last child value of the dimension (last value in brackets)
 * @param dimension The Dimension object to extract from
 * @return A string, the alias value in the dimension object
 */
- (NSString *)dimensionLastChildMemberValue:(LDMDimension *)dimension;

/* Dimension Helper Functions_ */

/* Misc / Legacy (Do not Delete)*/

- (id)parse:(id)argument;
- (LDMDimension *)parentDimension:(LDMDimension *)dimension;
- (NSNumber *)numberFromId:(id)numberObj;
- (NSString *)asJson: (id) value;
- (NSString *)toCurrency:(id)input;
- (NSString *)toIntFromString:(NSString *)string;
- (NSString *)toGroupedDecimal:(id)numberObj;
- (NSString *)dateInGMTWithTime:(id) dateObj;
- (NSString *) stringFromDate:(NSDate *)date;
- (NSDate *) dateFromShortDateStringWithTime:(NSString *)dateStr;
- (NSString *)shortDayOfWeekForGMT:(id)dateObj;
- (NSTimeZone *)userTimeZone;
- (NSString*) nowAsUserTime;
- (NSDate *)dateFromString:(NSString *)string;
- (LDMSchemaField*)schemaFieldForField:(NSString*)field onItem:(LDMItem*)item;
- (BOOL)performComparision:(NSString*)comparison withItemValue:(id)itemValue andComparisonValue:(id)comparisonValue withItemSchema:(LDMSchemaField *)fieldSchema withTypeOverride:(NSString*)type;

/* _Misc / Legacy_ */

@end
