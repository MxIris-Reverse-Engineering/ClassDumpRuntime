//
//  CDIvarModel.h
//  ClassDumpRuntime
//
//  Created by Leptos on 4/8/19.
//  Copyright © 2019 Leptos. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#import <ClassDumpRuntime/CDParseType.h>
#import <ClassDumpRuntime/CDGenerationOptions.h>
NS_HEADER_AUDIT_BEGIN(nullability)

@interface CDIvarModel : NSObject
/// The Obj-C runtime @c Ivar
@property (nonatomic, readonly) Ivar backing;
/// The name of the ivar, e.g. @c _name
@property (strong, nonatomic, readonly) NSString *name;
/// The type of the ivar
@property (strong, nonatomic, readonly) CDParseType *type;
/// The offset of the ivar
@property (nonatomic, readonly) ptrdiff_t offset;

- (instancetype)initWithIvar:(Ivar)ivar;
+ (instancetype)modelWithIvar:(Ivar)ivar;

- (CDSemanticString *)semanticStringWithOptions:(CDGenerationOptions *)options;

@end

NS_HEADER_AUDIT_END(nullability)
