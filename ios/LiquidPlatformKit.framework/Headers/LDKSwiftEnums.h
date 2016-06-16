//
//  LDKSwiftEnums.h
//  LDCore
//
//  Created by Bryan Nagle on 9/8/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#ifndef LDCore_LDKSwiftEnums_h
#define LDCore_LDKSwiftEnums_h

typedef NS_ENUM(NSUInteger, LDKDrawerMode)
{
    LDKDrawerModeOneThird,
    LDKDrawerModeTwoThirds,
    LDKDrawerModeThreeThirds
};


typedef NS_ENUM(NSUInteger, LDKAccordionSectionType)
{
    LDKAccordionSectionTypeCollapsableView,
    LDKAccordionSectionTypeFixedView,
    LDKAccordionSectionTypeNavigation
};

#endif
