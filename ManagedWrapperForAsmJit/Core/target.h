#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		public ref class CodeInfo {
			MWASMJIT_NATIVEPOINTER(CodeInfo, asmjit::CodeInfo)
		private:
			AsmJit::Core::ArchInfo^ _ArchInfo;
		public:
			CodeInfo() {
				_NativePointer = new asmjit::CodeInfo();
				_ArchInfo = gcnew AsmJit::Core::ArchInfo(&_NativePointer->_archInfo);

			}
			CodeInfo(ArchInfo::Id archId, ArchInfo::SubType archMode, uint64_t baseAddress) {
				_NativePointer = new asmjit::CodeInfo((uint32_t)archId, (uint32_t)archMode, baseAddress);
				_ArchInfo = gcnew AsmJit::Core::ArchInfo(&_NativePointer->_archInfo);
			}
			CodeInfo(ArchInfo::Id archId, ArchInfo::SubType archMode) {
				this->CodeInfo::CodeInfo(archId, archMode, asmjit::Globals::kNoBaseAddress);
			}
			CodeInfo(ArchInfo::Id archId) {
				this->CodeInfo::CodeInfo(archId, AsmJit::Core::ArchInfo::SubType::kSubIdNone, asmjit::Globals::kNoBaseAddress);
			}
			~CodeInfo()
			{
				delete _ArchInfo;
				delete NativePointer;
			}
			property AsmJit::Core::ArchInfo^ ArchInfo {
				AsmJit::Core::ArchInfo^ get() {
					return this->_ArchInfo;
				}
			}
			MWASMJIT_NATIVEPROPERTY_WRAPPER(uint8_t, StackAlignment, _stackAlignment);
			MWASMJIT_NATIVEPROPERTY_WRAPPER(uint8_t, CdcelCallConv, _cdeclCallConv);
			MWASMJIT_NATIVEPROPERTY_WRAPPER(uint8_t, StdCallConv, _stdCallConv);
			MWASMJIT_NATIVEPROPERTY_WRAPPER(uint8_t, FastCallConv, _fastCallConv);
			MWASMJIT_NATIVEPROPERTY_WRAPPER(uint64_t, BaseAddress, _baseAddress);
		};
	}
}