//
//  LDCMacros.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 5/21/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#ifndef LiquidDecisions_LDCMacros_h
#define LiquidDecisions_LDCMacros_h

#define LOG_FLAG_UXMETRIC  (1 << 5)  // 0...1000
#define LOG_FLAG_APPMETRIC (1 << 6)
#define LOG_FLAG_CRASHLOG  (1 << 7)
#define LOG_LEVEL_UXMETRIC (DDLogFlagError | DDLogFlagWarning | DDLogFlagInfo | DDLogFlagVerbose | LOG_FLAG_UXMETRIC | LOG_FLAG_APPMETRIC)

#define OBJC_LOG @"OBJC_LOG"

extern const int ddLogLevel;
extern const int dbLogLevel;

//New From David - Lumber jack implementation
#undef DLog             //DEBUG LOG
#undef VLog             //VERBOSE LOG

#undef ALog             //ORIGINAL ALOG is replaced with VLog
#undef UXLog

#ifdef DEBUG
#   define DLog(fmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagWarning, 0, OBJC_LOG, __PRETTY_FUNCTION__, fmt, ##__VA_ARGS__)
#else
#   define DLog(...)
#endif

//IF YOU WANT TO REDUCE LOGGING TO THE SERVER DO NOT DO IT HERE
//CHANGE LDCDBSEASIDELOGWRITER.M WHICH HANDLES THE ACTUAL LOGGING TO THE SERVER
//CHANGING TO NSLOG WILL JUST SLOW DOWN YOUR APP

#define NullLog(...) if (true) { }

#if APPIUM == 1

#define VLog(fmt, ...) NullLog(fmt, ##__VA_ARGS__);
#define ALog(fmt, ...) NullLog(fmt, ##__VA_ARGS__);

#else

#define VLog(fmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, DDLogFlagVerbose, 0, OBJC_LOG, __PRETTY_FUNCTION__, fmt, ##__VA_ARGS__)
#define ALog(fmt, ...) VLog(fmt, ##__VA_ARGS__);

#endif

#define UXLog(logType, identifier, argumentType, argumentId, argumentRevision, relationship) LOG_MAYBE(LOG_ASYNC_ENABLED, ddLogLevel, LOG_FLAG_UXMETRIC, 0, nil, __PRETTY_FUNCTION__, @"{\"LogType\":\"%@\",\"Identifier\":\"%@\",\"ArgumentType\":\"%@\",\"ArgumentId\":\"%@\",\"ArgumentRevision\":\"%@\",\"Relationship\":\"%@\",\"DateStamp\":\"%@\"}", logType, identifier, argumentType, argumentId, argumentRevision, relationship, [[LDMFunctionManager sharedInstance] dateInGMTWithTime:[NSDate date]])

#define SUPPRESS_PERFORM_SELECTOR_LEAK_WARNING(code)                        \
_Pragma("clang diagnostic push")                                        \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")     \
code;                                                                   \
_Pragma("clang diagnostic pop")                                         \

#endif

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
