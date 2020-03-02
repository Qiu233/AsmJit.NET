#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		public ref class BaseEmitter abstract {
			MWASMJIT_NATIVEPOINTER(BaseEmitter, asmjit::BaseEmitter)
		public:
			enum class EmitterType : uint32_t {
				kTypeNone = 0,
				kTypeAssembler = 1,
				kTypeBuilder = 2,
				kTypeCompiler = 3,
				kTypeCount = 4
			};
			enum class EmitterFlags : uint32_t {
				kFlagFinalized = 0x4000u,
				kFlagDestroyed = 0x8000u
			};
			enum class EmitterOptions : uint32_t {
				kOptionLoggingEnabled = 0x00000001u,
				kOptionStrictValidation = 0x00000002u,
				kOptionOptimizedForSize = 0x00000004u,
				kOptionOptimizedAlign = 0x00000008u,
				kOptionPredictedJumps = 0x00000010u
			};
		public:
			property EmitterType Type {
				EmitterType get() {
					return (EmitterType)NativePointer->_type;
				}
				void set(EmitterType value) {
					NativePointer->_type = (uint8_t)value;
				}
			}
			property EmitterFlags Flags {
				EmitterFlags get() {
					return (EmitterFlags)NativePointer->_flags;
				}
				void set(EmitterFlags value) {
					NativePointer->_flags = (uint16_t)value;
				}
			}
			property EmitterOptions Options {
				EmitterOptions get() {
					return (EmitterOptions)NativePointer->_emitterOptions;
				}
				void set(EmitterOptions value) {
					NativePointer->_emitterOptions = (uint32_t)value;
				}
			}
#define OP AsmJit::Core::Operand::Operand
#define ERR AsmJit::Core::Globals::Error
			ERR Emit(uint32_t instId) { return (ERR)NativePointer->emit(instId); }
			ERR Emit(uint32_t instId, OP^ o0) { return (ERR)NativePointer->emit(instId, o0); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1) { return (ERR)NativePointer->emit(instId, o0, o1); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2) { return (ERR)NativePointer->emit(instId, o0, o1, o2); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, OP^ o4) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o4); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, OP^ o4, OP^ o5) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o4, o5); }

			ERR Emit(uint32_t instId, int o0) { return (ERR)NativePointer->emit(instId, o0); }
			ERR Emit(uint32_t instId, OP^ o0, int o1) { return (ERR)NativePointer->emit(instId, o0, o1); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, int o2) { return (ERR)NativePointer->emit(instId, o0, o1, o2); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, int o3) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, int o4) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o4); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, OP^ o4, int o5) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o5); }

			ERR Emit(uint32_t instId, int64_t o0) { return (ERR)NativePointer->emit(instId, o0); }
			ERR Emit(uint32_t instId, OP^ o0, int64_t o1) { return (ERR)NativePointer->emit(instId, o0, o1); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, int64_t o2) { return (ERR)NativePointer->emit(instId, o0, o1, o2); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, int64_t o3) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, int64_t o4) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o4); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, OP^ o4, int64_t o5) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o5); }

			ERR Emit(uint32_t instId, unsigned int o0) { return (ERR)NativePointer->emit(instId, o0); }
			ERR Emit(uint32_t instId, OP^ o0, unsigned int o1) { return (ERR)NativePointer->emit(instId, o0, o1); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, unsigned int o2) { return (ERR)NativePointer->emit(instId, o0, o1, o2); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, unsigned int o3) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, unsigned int o4) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o4); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, OP^ o4, unsigned int o5) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o5); }

			ERR Emit(uint32_t instId, uint64_t o0) { return (ERR)NativePointer->emit(instId, o0); }
			ERR Emit(uint32_t instId, OP^ o0, uint64_t o1) { return (ERR)NativePointer->emit(instId, o0, o1); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, uint64_t o2) { return (ERR)NativePointer->emit(instId, o0, o1, o2); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, uint64_t o3) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, uint64_t o4) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o4); }
			ERR Emit(uint32_t instId, OP^ o0, OP^ o1, OP^ o2, OP^ o3, OP^ o4, uint64_t o5) { return (ERR)NativePointer->emit(instId, o0, o1, o2, o3, o5); }

#undef OP
#undef ERR
		};

	}
}