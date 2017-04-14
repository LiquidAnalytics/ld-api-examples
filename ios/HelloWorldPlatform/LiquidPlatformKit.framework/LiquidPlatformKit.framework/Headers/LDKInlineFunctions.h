//
//  LDKInlineFunctions.h
//  LDCore
//
//  Created by Bryan Nagle on 8/3/15.
//  Copyright (c) 2015 Liquid Analytics. All rights reserved.
//

#ifndef LDCore_LDKInlineFunctions_h
#define LDCore_LDKInlineFunctions_h

#define LDK_EDITABLE_TOUCH_NOTIFICATION                           @"LDKEditableTouchNotification"

CG_INLINE CGRect
LDKMakeCGRectCenteredInside(CGRect parent, CGFloat aWidth)
{
    CGFloat x = parent.origin.x + (parent.size.width - aWidth)/2.0f;
    CGFloat y = parent.origin.y + (parent.size.height - aWidth)/2.0f;
    CGFloat height = aWidth;
    CGFloat width = aWidth;
    return CGRectMake(x, y, width, height);
}

CG_INLINE CGRect
LDKMakeCGRectFromPoint(CGPoint point, CGFloat padding)
{
    CGFloat x = point.x - padding/2.0f;
    CGFloat y = point.y - padding/2.0f;
    CGFloat width = padding/2.0f;
    CGFloat height = padding/2.0f;
    return CGRectMake(x, y, width, height);
}

CG_INLINE
NSArray *LDKStandardClassPrefixes()
{
    return @[@"LDK", @"LDC", @"LDM", @"LLS"];
}

CG_INLINE
Class LDKGetClass(NSString *className)
{
    return  className.length > 0 ? NSClassFromString(className): nil;
}

CG_INLINE
Class LDKFindClassForPostfix(NSString *postFix)
{
    for (NSString *prefix in LDKStandardClassPrefixes())
    {
        NSString *className = [prefix stringByAppendingString:postFix];
        Class classForType = LDKGetClass(className);
        if (classForType != nil) return classForType;
    }
    
    return nil;
}

CG_INLINE
Class LDKUpgradeClass(Class class)
{
    NSString *baseName = [NSStringFromClass(class) substringFromIndex:3];
    return LDKFindClassForPostfix(baseName);
}

CG_INLINE
CGVector LDKVectorFromRadians(float radians)
{
    return CGVectorMake(sin(radians), cos(radians));
}

#endif
