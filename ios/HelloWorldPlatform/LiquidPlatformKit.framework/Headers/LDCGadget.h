//
//  LDCGadget.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 12/31/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDCGadgetAction, LDCGadgetController, LDMItem;

@interface LDCGadget : NSObject

@property (strong) NSString * __nonnull name;
@property (strong) NSMutableDictionary * __nonnull actionsByType;
@property (strong) NSMutableDictionary * __nonnull actionsByName;
@property (weak) LDCGadgetController * __nullable gadgetController;
@property (strong, nonatomic) LDMItem * __nullable appDef;
@property (assign, nonatomic) BOOL allowStacking;
@property (assign, nonatomic) BOOL disableRandomUniqueIdentifier;

typedef NS_OPTIONS(NSUInteger, GadgetOption)
{
    GadgetOptionNone = 0,
    GadgetOptionLongTap = 1 << 0,
    GadgetOptionFromInsight = 1 << 1,
    GadgetOptionDoNotChangeActive = 1 << 2
    
//  rename as you go!!
//    GadgetOptionTwo = 1 << 1,
//    GadgetOptionThree = 1 << 2
};

- (id __nonnull)initWithController:(LDCGadgetController * __nonnull)controller andName:(NSString * __nonnull)name;

- (void)setup;
- (void)gadgetDidLoad;
- (void)registerAction:(LDCGadgetAction * __nonnull)action ForType:(NSString * __nonnull)type withName:(NSString * __nonnull)name;
- (LDCGadgetAction * __nullable)actionNamed:(NSString * __nonnull)name;
- (NSArray * __nonnull)actionsForType:(NSString * __nonnull)type;
//- (void)setAsActiveGadgetFromActionName:(NSString *)actionName;
- (void)reset;
- (void)show;
@end
