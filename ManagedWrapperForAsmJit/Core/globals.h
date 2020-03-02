#pragma once
#define MWASMJIT_NATIVEPOINTER(NAME, T)	internal: T* _NativePointer; \
										public: property T* NativePointer{ T* get() { return _NativePointer; } };

#define MWASMJIT_NATIVEPOINTERCTOR(NAME, T)	internal: NAME(T* ptr) { _NativePointer = ptr; }

#define MWASMJIT_NATIVEPROPERTY_WRAPPER(TYPE, NAME, NATIVENAME)	public: property TYPE NAME { TYPE get() { return _NativePointer->NATIVENAME; } void set(TYPE value) { _NativePointer->NATIVENAME = value; } }

#define MWASMJIT_EXTENSION_METHOD(TYPE) generic<typename T> where T : TYPE[ExtensionAttribute] static 

namespace AsmJit {
	namespace Core {
		namespace  Globals {
			public enum class ResetPolicy : uint32_t {
				kResetSoft = 0,
				kResetHard = 1
			};
			public enum class Error : uint32_t {
				kErrorOk = 0,
				kErrorOutOfMemory,
				kErrorInvalidArgument,
				kErrorInvalidState,
				kErrorInvalidArch,
				kErrorNotInitialized,
				kErrorAlreadyInitialized,
				kErrorFeatureNotEnabled,
				kErrorTooManyHandles,
				kErrorTooLarge,
				kErrorNoCodeGenerated,
				kErrorInvalidDirective,
				kErrorInvalidLabel,
				kErrorTooManyLabels,
				kErrorLabelAlreadyBound,
				kErrorLabelAlreadyDefined,
				kErrorLabelNameTooLong,
				kErrorInvalidLabelName,
				kErrorInvalidParentLabel,
				kErrorNonLocalLabelCantHaveParent,
				kErrorInvalidSection,
				kErrorTooManySections,
				kErrorInvalidSectionName,
				kErrorTooManyRelocations,
				kErrorInvalidRelocEntry,
				kErrorRelocOffsetOutOfRange,
				kErrorInvalidAssignment,
				kErrorInvalidInstruction,
				kErrorInvalidRegType,
				kErrorInvalidRegGroup,
				kErrorInvalidPhysId,
				kErrorInvalidVirtId,
				kErrorInvalidPrefixCombination,
				kErrorInvalidLockPrefix,
				kErrorInvalidXAcquirePrefix,
				kErrorInvalidXReleasePrefix,
				kErrorInvalidRepPrefix,
				kErrorInvalidRexPrefix,
				kErrorInvalidExtraReg,
				kErrorInvalidKMaskUse,
				kErrorInvalidKZeroUse,
				kErrorInvalidBroadcast,
				kErrorInvalidEROrSAE,
				kErrorInvalidAddress,
				kErrorInvalidAddressIndex,
				kErrorInvalidAddressScale,
				kErrorInvalidAddress64Bit,
				kErrorInvalidAddress64BitZeroExtension,
				kErrorInvalidDisplacement,
				kErrorInvalidSegment,
				kErrorInvalidImmediate,
				kErrorInvalidOperandSize,
				kErrorAmbiguousOperandSize,
				kErrorOperandSizeMismatch,
				kErrorInvalidOption,
				kErrorOptionAlreadyDefined,
				kErrorInvalidTypeId,
				kErrorInvalidUseOfGpbHi,
				kErrorInvalidUseOfGpq,
				kErrorInvalidUseOfF80,
				kErrorNotConsecutiveRegs,
				kErrorNoMorePhysRegs,
				kErrorOverlappedRegs,
				kErrorOverlappingStackRegWithRegArg,
				kErrorExpressionLabelNotBound,
				kErrorExpressionOverflow,
				kErrorCount
			};
		};
	}
}