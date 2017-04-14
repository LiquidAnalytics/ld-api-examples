//
//  LDCLocationManager.h
//  LiquidDecisions
//
//  Created by Eric Johnson on 5/25/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface LDCLocationManager : NSObject <CLLocationManagerDelegate>
+ (LDCLocationManager*) sharedInstance;

- (CLLocation *)currentLocation;
- (BOOL)startLocationServices;
- (BOOL)endLocationServices;

- (void)searchGridTopLeft: (CLLocation **)topLeft andBottomRight: (CLLocation **)bottomRight forGridCenter: (CLLocation *) center andWidthInMiles: (float) width;
@end
