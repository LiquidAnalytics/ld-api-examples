//
//  LDCAnchoredLabel.h
//  LiquidDecisions
//
//  Created by Eric Johnson on 2/7/13.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

typedef enum  {
    LDCAnchoredLabelAnchorLeft,
    LDCAnchoredLabelAnchorRight,
    LDCAnchoredLabelAnchorTop,
    LDCAnchoredLabelAnchorBottom,
    LDCAnchoredLabelAnchorCenter,
    LDCAnchoredLabelAnchorNone
} LDCAnchoredLabelAnchorSide;

@interface LDCAnchoredLabel : UILabel
@property LDCAnchoredLabelAnchorSide anchorSide;
@property CGSize maximumSize;
@property BOOL autosizeLabel;

- (void)setMaximumSize:(CGSize)maxSize;
@end
