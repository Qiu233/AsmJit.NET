#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		public ref class ArchInfo {
			MWASMJIT_NATIVEPOINTER(ArchInfo, asmjit::ArchInfo);
		public:
			enum class Id : uint8_t {
				kIdNone = 0,
				kIdX86 = 1,
				kIdX64 = 2,
				kIdA32 = 3,
				kIdA64 = 4,
			};
			enum class SubType : uint8_t {
				kSubIdNone = 0,
				kSubIdX86_AVX = 1,
				kSubIdX86_AVX2 = 2,
				kSubIdX86_AVX512 = 3,
				kSubIdX86_AVX512VL = 4,
				kSubIdA32_Thumb = 8,
			};
		public:
			property Id ID {
				Id get() {
					return (Id)NativePointer->_id;
				}
				void set(Id value) {
					NativePointer->_id = (uint8_t)value;
				}
			}
			property SubType SubId {
				SubType get() {
					return (SubType)NativePointer->_subId;
				}
				void set(SubType value) {
					NativePointer->_subId = (uint8_t)value;
				}
			}
			property uint8_t GPSize {
				uint8_t get() {
					return NativePointer->_gpSize;
				}
				void set(uint8_t value) {
					NativePointer->_gpSize = value;
				}
			}
			property uint8_t GPCount {
				uint8_t get() {
					return NativePointer->_gpCount;
				}
				void set(uint8_t value) {
					NativePointer->_gpCount = value;
				}
			}
			property uint32_t Signature {
				uint32_t get() {
					return NativePointer->_signature;
				}
				void set(uint32_t value) {
					NativePointer->_signature = value;
				}
			}

		internal:ArchInfo(asmjit::ArchInfo& ai) { _NativePointer = &ai; }
		public:
			ArchInfo() { _NativePointer = new asmjit::ArchInfo(); }
			ArchInfo(Id type, SubType subType) { _NativePointer = new asmjit::ArchInfo((uint32_t)type, (uint32_t)subType); }
			~ArchInfo() {
				delete NativePointer;
			}

			bool IsInitialized() {
				return NativePointer->isInitialized();
			}

			void Initialize(Id type, SubType subType) {
				NativePointer->init((uint32_t)type, (uint32_t)subType);
			}

			void Reset() {
				NativePointer->reset();
			}

			bool Is32Bit() {
				return NativePointer->is32Bit();
			}
			bool Is64Bit() {
				return NativePointer->is64Bit();
			}

			bool IsX86Family() {
				return NativePointer->isX86Family();
			}
			bool IsArmFamily() {
				return NativePointer->isArmFamily();
			}

			static ArchInfo^ Host() {
				asmjit::ArchInfo host = asmjit::ArchInfo::host();
				ArchInfo^ info = gcnew ArchInfo();
				info->ID = (Id)host._id;
				info->SubId = (SubType)host._subId;
				info->GPSize = host._gpSize;
				info->GPCount = host._gpSize;
				return info;
			}

		};
	}
}