//
//  LDKEnumerationSelectViewController.h
//  LDCore
//
//  Created by Bryan Nagle on 2/5/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LDKItemSelectViewController.h"

@class LDMEnumeration;

@interface LDKEnumerationSelectViewController : LDKItemSelectViewController

@property (nonatomic, strong) NSString *enumerationName;
@property (nonatomic, strong) LDMEnumeration *enumerationParent;
@property (nonatomic, strong) NSString *enumerationChildName;
@property (nonatomic, strong) NSString *fromType;
@property (nonatomic, strong) NSString *fromField;
@property (nonatomic, strong) LDMQueryFilter *typeQueryFilter;

+ (LDKEnumerationSelectViewController *)enumerationSelector;
+ (LDKEnumerationSelectViewController *)enumerationSelectorWithName:(NSString *)name parent:(LDMEnumeration *)parent andChildName:(NSString *)aChildName;

@end
