//
//  CDSemanticString.h
//  ClassDumpRuntime
//
//  Created by Leptos on 1/1/23.
//  Copyright © 2023 Leptos. All rights reserved.
//

#import <Foundation/Foundation.h>

/// The semantic types that a string may represent in an Objective-C header file
typedef NS_ENUM(NSUInteger, CDSemanticType) {
    // whitespace, colons (':'), semicolons (';'), pointers ('*'),
    // braces ('(', ')'), brackets ('{','}', '[', ']', '<', '>')
    CDSemanticTypeStandard,
    // characters used to start and end a comment, and the contents of the comment
    CDSemanticTypeComment,
    // struct, union, type modifiers, language provided primitive types
    CDSemanticTypeKeyword,
    // the name of a variable- this includes both declaration and usage sites
    CDSemanticTypeVariable,
    // the name portion of a struct or union definition
    CDSemanticTypeRecordName,
    // an Obj-C class (e.g. NSString)
    CDSemanticTypeClass,
    // an Obj-C protocol (e.g. NSFastEnumeration)
    CDSemanticTypeProtocol,
    // a number literal (e.g. 2, 18, 1e5, 7.1)
    CDSemanticTypeNumeric,
    // an Obj-C method (e.g. initWithFrame)
    CDSemanticTypeMethod,
    // an Obj-C method argument (e.g. a0, a1, a2)
    CDSemanticTypeMethodArgument,
    /// The number of valid cases there are in @c CDSemanticType
    CDSemanticTypeCount
};

NS_HEADER_AUDIT_BEGIN(nullability)

/// A string composed of substrings that may have different semantic meanings
@interface CDSemanticString : NSObject <NSSecureCoding>
/// The length of the string
@property (readonly) NSUInteger length;
/// Append another semantic string to the end of this string,
/// keeping all of the semantics of both the parameter and receiver
- (void)appendSemanticString:(CDSemanticString *)semanticString;
/// Append a string with a semantic type to the end of this string
- (void)appendString:(nullable NSString *)string semanticType:(CDSemanticType)type;
/// Whether the first character in this string is equal to @c character
- (BOOL)startsWithChar:(char)character;
/// Whether the last character in this string is equal to @c character
- (BOOL)endWithChar:(char)character;
/// Enumerate the substrings and the associated semantic type that compose this string
- (void)enumerateTypesUsingBlock:(void (NS_NOESCAPE ^)(NSString *string, CDSemanticType type))block;
/// Enumerate the longest effective substrings and the associated semantic type that compose this string
///
/// Each invocation of @c block will have the longest substring of @c type such that the next
/// invocation will have a different @c type
- (void)enumerateLongestEffectiveRangesUsingBlock:(void (NS_NOESCAPE ^)(NSString *string, CDSemanticType type))block;

/// The string representation without semantics
- (NSString *)string;

@end

NS_HEADER_AUDIT_END(nullability)
