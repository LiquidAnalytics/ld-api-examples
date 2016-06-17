//
//  Command.h
//  seaside
//
//  Created by Mike Akers on 9/27/11.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>
#import "JSONRepresentation.h"

#define COMMAND_EMPTY_PAYLOAD_SIZE                                  2

@class LSCPayload;

@interface LSCCommand : NSObject <JSONRepresentation>
//@property (nonatomic, retain) NSString *version;                     //Version of Payload
@property (nonatomic, retain) NSString *guid;           //Unique Identifier for this Command, Auto Increments with each command
@property (nonatomic, retain) NSString *loginToken;     //Login Token Applicable to the command. This is not the ADFS token, this is the LD Token
@property (nonatomic, retain) NSString *verb;           //Three Character Command Code
@property (nonatomic, getter = isResponse) BOOL response;                  //TRUE  - CommandBean is the Response
//FALSE - CommandBean is the Initator of the command
@property (nonatomic, retain) NSArray *payloads;        //Payload of the command
@property (nonatomic, retain) NSString *application;

@property (nonatomic, retain) NSString *connectionType;

//@property (nonatomic, retain) NSNumber *instance;
@property (nonatomic, retain) NSNumber *itemCount;
@property (nonatomic, strong) NSString *commandGroupId;
@property (nonatomic, strong) NSString *clientBuild;
@property (nonatomic, strong) NSDate *timestamp;
@property (nonatomic, strong) NSString *shortDesc;
@property (nonatomic, strong) NSString *requestGuid;
@property (nonatomic, strong) NSString *community;
@property (nonatomic, strong) NSNumber *registered;


@property NSInteger  requestTimeout;
+ (NSString *)generateId;
+ (NSString *)generateClientBuild;
- (LSCPayload *)payloadWithName:(NSString *)payloadName;
@end