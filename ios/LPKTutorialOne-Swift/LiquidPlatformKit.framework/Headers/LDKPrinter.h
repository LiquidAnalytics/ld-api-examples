//
//  LDKPrinter.h
//  LDCore
//
//  Created by CARSON LI on 2015-05-26.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    LDKPrinterStatusOffline = 0,
    LDKPrinterStatusConnecting,
    LDKPrinterStatusOnline,
    LDKPrinterStatusPrinting,
    LDKPrinterStatusJammed,
    LDKPrinterStatusEmpty,
    LDKPrinterStatusError
} LDKPrinterStatus;

@class LDMItem, LDKPrinterConfig;

@protocol LDKPrinterStatusUpdateDelegate <NSObject>

- (void)printerDidUpdateStatus:(LDKPrinterStatus)printerStatus withMessage:(NSString*) message;

@end


@interface LDKPrinter : NSObject

@property (weak) id<LDKPrinterStatusUpdateDelegate> delegate;
@property LDKPrinterStatus status;

#pragma mark Abstract methods for subclasses

- (NSString*) aboutDescription;
- (BOOL) supportsImages;

-(void) bindToPrinterWithSerialNumber:(NSString*) serialNumber;
-(void) unbind;
-(void) updatePrinterStatus:(LDKPrinterStatus) status withMessage:(NSString*) message;

-(void) printReceiptForItem:(LDMItem*) item withConfig:(LDKPrinterConfig*) config andCompletionHandler: (void (^)(BOOL success, NSString* message)) completion;
-(void) printData:(NSData*) data withCompletionHandler:(void (^)(BOOL success, NSString *message))completionHandler;

@end

