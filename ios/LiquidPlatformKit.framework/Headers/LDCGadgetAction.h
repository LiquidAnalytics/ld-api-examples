//
//  LDCGadgetAction.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 12/31/12.
//  Copyright Everglade Solutions, Inc., d/b/a Liquid Analytics. 2008 2009 2010 2011 2012 2013  All rights reserved
//

#import <UIKit/UIKit.h>

@class LDMItem;
@class LDCItemProperty;

@interface LDCGadgetAction : NSObject <NSCopying>

@property (strong) NSString * __nonnull name;
@property (strong) NSString * __nullable label;
@property (strong) UIImage * __nullable image;
@property (strong) NSString * __nullable gadgetName;
@property (nonatomic, copy) BOOL (^ __nullable function)(id __nullable sender, id __nullable arguments, NSString * __nullable relation, NSString * __nullable actionName, id  __nullable arg, NSUInteger options);

- (nonnull instancetype)initWithName:(NSString * __nonnull)name;
- (nonnull instancetype)initWithName:(NSString * __nonnull)name andBlock:(BOOL (^ __nonnull)(id  __nullable sender, id  __nullable arguments, NSString * __nullable relation, NSString * __nullable actionName, id __nullable arg, NSUInteger options))block;

- (void)setFunction:(BOOL (^ __nullable)(id __nullable, id __nullable, NSString * __nullable, NSString * __nullable, id __nullable, NSUInteger))aFunction;
- (BOOL)executeFunctionWithArguments:(id __nullable)arguments;
- (BOOL)executeFunctionWithSender:(id __nullable)sender andArguments:(id __nullable)arguments;
- (BOOL)executeFunctionWithSender:(id __nullable)sender andArguments:(id __nullable)arguments andRelation:(NSString * __nullable)relation withOptions:(NSUInteger) options withName:(NSString* __nullable) name;
- (BOOL)executeFunctionWithType:(NSString * __nullable)type andRelation:(NSString * __nullable)relation andName:(NSString * __nullable)name andSender:(id __nullable)sender withOptions:(NSUInteger)options;
- (BOOL)executeFunctionWithType:(NSString * __nullable)type andName:(NSString * __nullable)name withArguments:(id __nullable)arguments andRelation:(NSString * __nullable)relation withSender:(id __nullable)sender withOptions:(NSUInteger) options;
- (BOOL)executeFunctionWithItemPropery:(LDCItemProperty* __nullable) itemPropery withSender:(id __nullable) sender withOptions:(NSUInteger) options;
@end
