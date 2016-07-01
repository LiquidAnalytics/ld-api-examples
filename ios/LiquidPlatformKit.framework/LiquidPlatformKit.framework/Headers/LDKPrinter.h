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
/*!
 * @discussion Callback to update the current printer status
 * @param printerStatus An LDKPrinterStatus indicating current status of printer
 * @param message The string representing the printer status
 */
- (void)printerDidUpdateStatus:(LDKPrinterStatus)printerStatus withMessage:(NSString*) message;

@end

@interface LDKPrinter : NSObject

@property (weak) id<LDKPrinterStatusUpdateDelegate> delegate;
@property LDKPrinterStatus status;

#pragma mark Abstract methods for subclasses

/*!
 * @discussion Simple description of the current printer class
 */
- (NSString*) aboutDescription;

/*!
 * @discussion Determines whether printer supports printing images
 * @return TRUE if the printer supports printing images, FALSE otherwise
 */
- (BOOL) supportsImages;

/*!
 * @discussion Initialization method for external printer, requires serial number
 * @warning This method must be called before anything can be done to the printer object
 * @param serialNumber The serial number of the external device
 */
-(void) bindToPrinterWithSerialNumber:(NSString*) serialNumber;

/*!
 * @discussion Closes the connection the printer
 * @warning This method should be called after printing to prevent memory leaks
 */
-(void) unbind;

/*!
 * @discussion Standardized method for all implementing classes to update delegate
 * @param printerStatus An LDKPrinterStatus indicating current status of printer
 * @param message The string representing the printer status
 */
-(void) updatePrinterStatus:(LDKPrinterStatus) status withMessage:(NSString*) message;

/*!
 * @discussion Asynchronous method for printing an LDMItem
 * @param item The LDMItem to print (expected to be a Cart with line items)
 * @param config The PrintConfig item
 * @param completion Asychronous block that is called after receipt finishes printing
 */
-(void) printReceiptForItem:(LDMItem*) item withConfig:(LDKPrinterConfig*) config andCompletionHandler: (void (^)(BOOL success, NSString* message)) completion;


@end

