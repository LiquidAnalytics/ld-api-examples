//
//  LDMItemHeader.h
//  LiquidDataModel
//
//  Created by Mike Akers on 4/25/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

#define LDCItemHeaderMainTableString @"mainTableString"
#define LDCItemHeaderBlockTableString @"blockTableString"
#define LDCItemHeaderFieldCount @"fieldCount"

typedef enum  {
    LDMItemHeaderBatchFragmentModeSelect = 0,
    LDMItemHeaderBatchFragmentModeUnion
} LDCItemHeaderBatchFragmentMode;

typedef enum  {
    LDMSyncStatusPending = 0,
    LDMSyncStatusInTransit,
    LDMSyncStatusDelivered,
    LDMSyncStatusReceived
} LDMSyncStatus;

@interface LDMItemHeader : NSObject<NSCoding, NSCopying>
@property (strong) NSString *id;
@property (strong) NSString *clientId;
@property (strong) NSString *action;
@property (strong) NSString *state;
@property (strong) NSString *checksum;
@property (strong) NSString *type;
@property (strong) NSString *revisionId;
@property (strong) NSDate *createdAt;
@property (strong) NSString *createdBy;
@property (strong) NSDate *updatedAt;
@property (strong) NSDate *processedAt;
@property (strong) NSString *category;
@property (strong) NSString *applicationId;
@property (strong) NSString *client;
@property (strong) NSString *syncStatus;
@property (strong) NSString *name;
@property (strong) NSString *community;
@property (strong) NSString *receiptMessage;
@property (strong) NSString *receiptOccuredAt;
@property (strong) NSString *receiptType;

@property (strong) NSString *parent_id;
@property (strong) NSString *parent_type;
@property (strong) NSString *parent_fieldName;
@property (strong) NSNumber *parent_sequence;
@property (strong) NSString *expiresAt;
@property (strong) NSString *updatedByUserId;
@property (strong) NSString *receiptRelatedItems;

//@property (strong) NSString *itemSetId;
//@property (string) BOOL *active;

+ (NSDictionary*)propsDict;
+ (NSDictionary*)propsDictNoBlock;
+ (NSDictionary*)sqlCreateFragments;
- (NSString*)sqlBatchInsertFragmentWithMode:(LDCItemHeaderBatchFragmentMode)mode;
- (void) setDataFromDictionary:(NSDictionary*)dict;
- (void)setDataFromDictionary:(NSDictionary*)aDict performCaseCheck:(BOOL)caseCheck;

//- (NSDate *)updatedAtDate;
@end
