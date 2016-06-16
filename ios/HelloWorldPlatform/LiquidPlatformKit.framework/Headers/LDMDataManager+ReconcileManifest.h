//
//  LDMDataManager_ReconcileManifest.h
//  LDCore
//
//  Created by David Ellis on 11/6/2013.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//

#import "LDMDataManager.h"


@interface LDMDataManager (LDMDataManager_ReconcileManifest)

- (unsigned long) crc32ForType: (NSString *) type;
- (NSString *) buildTypeSummaryManifest;
- (void) buildDetailManifest: (NSArray *) types filename: (NSString *)temporaryFile;


@end
