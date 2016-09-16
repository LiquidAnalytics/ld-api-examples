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

@property (strong) NSString *printerConfigId;
@property (strong) NSString *embeddedLogo;
@property (strong) NSString *disclaimer;
@property (strong) NSString *receiptTitle;
@property (strong) NSString *barcodeData;
@property (strong) LDMEnumeration *barcodeType;
@property (strong) NSString *footerOne;
@property (strong) NSString *footerTwo;
@property (strong) NSString *footerThree;
@property (strong) NSString *footerFour;
@property (strong) NSString *lineItemField;
@property (strong) NSString *lineItemTitle;
@property (strong) NSString *lineItemSubtitle;
@property (strong) NSString *summaryLabel;
@property (strong) NSString *summaryStatement;
@property (strong) NSString *lineItemValueOne;
@property (strong) NSString *lineItemValueTwo;
@property (strong) NSString *lineItemDiscountDescription;
@property (strong) NSString *lineItemValueThree;
@property (strong) NSString *lineItemComment;
@property (strong) NSString *signedByStatement;
@property (strong) NSArray *salesInfoFields;
@property (strong) NSArray *customerInfoFields;
@property (strong) NSArray *summaryFields;
@property (strong) NSArray *extraInfoFields;

@end
