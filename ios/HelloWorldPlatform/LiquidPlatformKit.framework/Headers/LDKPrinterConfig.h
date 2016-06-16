//
//  LDKPrinterConfig.h
//  LDCore
//
//  Created by CARSON LI on 2015-05-27.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMItem.h"

@class LDMEnumeration;

@interface LDKPrinterConfig : LDMItem

@property NSString *printerConfigId;
@property NSString *embeddedLogo;
@property NSString *disclaimer;
@property NSString *receiptTitle;
@property NSString *barcodeData;
@property LDMEnumeration *barcodeType;
@property NSString *footerOne;
@property NSString *footerTwo;
@property NSString *footerThree;
@property NSString *footerFour;
@property NSString *lineItemField;
@property NSString *lineItemTitle;
@property NSString *lineItemSubtitle;
@property NSString *summaryLabel;
@property NSString *summaryStatement;
@property NSString *lineItemValueOne;
@property NSString *lineItemValueTwo;
@property NSString *lineItemDiscountDescription;
@property NSString *lineItemValueThree;
@property NSString *lineItemComment;
@property NSString *signedByStatement;
@property NSArray *salesInfoFields;
@property NSArray *customerInfoFields;
@property NSArray *summaryFields;
@property NSArray *extraInfoFields;

@end
