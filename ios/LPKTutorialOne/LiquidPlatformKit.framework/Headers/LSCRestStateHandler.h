//
//  LSCRestStateHandler.h
//  seaside
//
//  Created by Bryan Nagle on 7/10/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import "LSCStateHandler.h"

@class ASIFormDataRequest;
@class LSCPayload;
@class LSCCommand;

@interface LSCRestStateHandler : LSCStateHandler

@property (readonly) NSString *requestMethod;

//Restful subclasses should override this method
- (void) createRequest:(ASIFormDataRequest *)request;

//CommandBean subclasses should override this method;
- (LSCCommand *)createRequest;

- (BOOL) useFileSystemCache;

- (void)requestFailedAsync:(ASIFormDataRequest *)request;

@end
