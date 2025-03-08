import Foundation
import ClassDumpRuntime

public struct CDGenerationOptions: Codable, Hashable, Identifiable {
    public var stripProtocolConformance: Bool
    public var stripOverrides: Bool
    public var stripDuplicates: Bool
    public var stripSynthesized: Bool
    public var stripCtorMethod: Bool
    public var stripDtorMethod: Bool
    public var addSymbolImageComments: Bool
    public var addIvarOffsetComments: Bool
    public var expandIvarRecordTypeMembers: Bool
    public var id: Self { self }

    public init(
        stripProtocolConformance: Bool = false,
        stripOverrides: Bool = false,
        stripDuplicates: Bool = false,
        stripSynthesized: Bool = false,
        stripCtorMethod: Bool = false,
        stripDtorMethod: Bool = false,
        addSymbolImageComments: Bool = false,
        addIvarOffsetComments: Bool = false,
        expandIvarRecordTypeMembers: Bool = false
    ) {
        self.stripProtocolConformance = stripProtocolConformance
        self.stripOverrides = stripOverrides
        self.stripDuplicates = stripDuplicates
        self.stripSynthesized = stripSynthesized
        self.stripCtorMethod = stripCtorMethod
        self.stripDtorMethod = stripDtorMethod
        self.addSymbolImageComments = addSymbolImageComments
        self.addIvarOffsetComments = addIvarOffsetComments
        self.expandIvarRecordTypeMembers = expandIvarRecordTypeMembers
    }
    
}

extension CDGenerationOptions: ReferenceConvertible {
    public typealias ReferenceType = __CDGenerationOptions

    public func _bridgeToObjectiveC() -> __CDGenerationOptions {
        let options = __CDGenerationOptions()
        options.stripProtocolConformance = stripProtocolConformance
        options.stripOverrides = stripOverrides
        options.stripSynthesized = stripSynthesized
        options.stripCtorMethod = stripCtorMethod
        options.stripDtorMethod = stripDtorMethod
        options.addSymbolImageComments = addSymbolImageComments
        options.addIvarOffsetComments = addIvarOffsetComments
        options.expandIvarRecordTypeMembers = expandIvarRecordTypeMembers
        return options
    }

    public static func _forceBridgeFromObjectiveC(_ source: __CDGenerationOptions, result: inout CDGenerationOptions?) {
        result = CDGenerationOptions(
            stripProtocolConformance: source.stripProtocolConformance,
            stripOverrides: source.stripOverrides,
            stripDuplicates: source.stripDuplicates,
            stripSynthesized: source.stripSynthesized,
            stripCtorMethod: source.stripCtorMethod,
            stripDtorMethod: source.stripDtorMethod,
            addSymbolImageComments: source.addSymbolImageComments,
            addIvarOffsetComments: source.addIvarOffsetComments,
            expandIvarRecordTypeMembers: source.expandIvarRecordTypeMembers
        )
    }

    public static func _conditionallyBridgeFromObjectiveC(_ source: __CDGenerationOptions, result: inout CDGenerationOptions?) -> Bool {
        _forceBridgeFromObjectiveC(source, result: &result)
        return true
    }

    public static func _unconditionallyBridgeFromObjectiveC(_ source: __CDGenerationOptions?) -> CDGenerationOptions {
        if let source = source {
            var result: CDGenerationOptions?
            _forceBridgeFromObjectiveC(source, result: &result)
            return result!
        }
        return CDGenerationOptions()
    }

    public var description: String {
        "\(self)"
    }

    public var debugDescription: String {
        description
    }
}

extension CDClassModel {
    public func semanticLines(with options: CDGenerationOptions) -> CDSemanticString {
        __semanticLines(with: options as __CDGenerationOptions)
    }
}

extension CDProtocolModel {
    public func semanticLines(with options: CDGenerationOptions) -> CDSemanticString {
        __semanticLines(with: options as __CDGenerationOptions)
    }
}
