//
//  LDCGadgetController.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 12/31/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <Foundation/Foundation.h>

@class LDCGadgetAction, LDMContext, LDMItem, LDCGadget, LDCDefinition, LDCItemProperty;

@interface LDCGadgetController : NSObject

@property (strong) LDMContext * __nullable context;
@property (strong) NSMutableDictionary * __nullable gadgetsByName;
@property (strong, nullable) NSMutableArray *workActions;
@property (strong, nonatomic) NSString * __nullable activeGadgetName;
@property (strong, nonatomic) NSString * __nullable previousActiveGadgetName;
@property (nonatomic, readonly, nullable) NSString *gadgetNameForCurrentAction;
@property (readonly) LDCGadget * __nullable activeGadget;
@property (strong) NSString * __nullable lastExecutedActionName;
@property (nonatomic, copy) void (^ __nullable actionWasExecutedHandler)(NSString *__nonnull gadgetName, NSString * __nullable actionName);
@property (nonatomic, copy) void (^ __nullable gadgetDidChangeHandler)(NSString *__nonnull fromGadgetName, NSString * __nonnull toGadgetName);
@property (nonatomic, strong, nullable) LDMItem *userItem;

+ (LDCGadgetController * __nonnull)sharedInstance;
- (void)restorePreviousActiveGadget;
- (void)gadgetsDidLoad;
- (NSArray * __nullable)actionsForType:(NSString * __nullable)type;
- (LDCGadgetAction * __nullable)actionForType:(NSString * __nullable)type andName:(NSString * __nullable)name;
- (LDCGadgetAction * __nullable)actionNamed:(NSString * __nullable)name;
//- (BOOL (^)(id sender, id arguments, NSString *relation))functionForName:(NSString * __nullable)name;
//- (BOOL (^)(id sender, id arguments, NSString *relation))functionForType:(NSString * __nullable)type andName:(NSString * __nullable)name;
- (void)executeShortHandActionForArray:(NSArray* __nullable)actionArray;
- (void)executeActionForName:(NSString * __nullable)name;
- (void)executeActionForName:(NSString * __nullable)name withSender:(id __nullable)sender;
- (void)executeActionForName:(NSString * __nullable)name withArguments:(id __nullable)arguments withSender:(id __nullable)sender;
- (void)executeActionForType:(NSString * __nullable)type andName:(NSString * __nullable)name;
- (void)executeActionForType:(NSString * __nullable)type andName:(NSString * __nullable)name withSender:(id __nullable)sender;
- (void)executeActionForType:(NSString * __nullable)type andName:(NSString * __nullable)name withArguments:(id __nullable)arguments withSender:(id __nullable)sender;
- (void)executeActionForType:(NSString * __nullable)type andName:(NSString * __nullable)name withArguments:(id __nullable)arguments andRelation:(NSString * __nullable)relation withSender:(id __nullable)sender withOptions:(NSUInteger) options;
- (void)executeActionWithItemPropery:(LDCItemProperty* __nullable) itemProperty withSender:(id __nullable) sender withOptions:(NSUInteger) options;
- (void)executeActionForItem:(LDMItem * __nullable)item andRelation:(NSString * __nullable)relation andName:(NSString * __nullable)name andSender:(id __nullable)sender;
- (void)executeActionForType:(NSString * __nullable)type andRelation:(NSString * __nullable)relation andName:(NSString * __nullable)name andSender:(id __nullable)sender;
- (void)executeTouchAction:(NSDictionary * __nullable)touchAction forItem:(LDMItem * __nullable)item withSender:(id __nullable)sender;
- (NSString * __nullable)gadgetNameForActionNamed:(NSString * __nullable)name;
- (LDCGadget * __nullable)gadgetForActionNamed:(NSString * __nullable)name;
- (void)setActiveGadgetName:(NSString * __nullable)aActiveGadgetName withActionName:(NSString * __nullable)actionName;

- (void)resetGadgetByName:(NSString* __nullable)name;
- (void)reset;
- (void)registerWorkAction:(LDCGadgetAction * __nullable)action;
- (void)actionWasExecuted;
- (void)showGadgetNamed:(NSString * __nullable)name;


@end
