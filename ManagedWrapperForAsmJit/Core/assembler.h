#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		public ref class BaseAssembler abstract :AsmJit::Core::BaseEmitter {
			MWASMJIT_NATIVEPOINTER(BaseAssembler, asmjit::BaseAssembler)
		public:
			AsmJit::Core::Operand::Label^ NewLabel() {
				return gcnew AsmJit::Core::Operand::Label(NativePointer->newLabel());
			}
			AsmJit::Core::Operand::Label^ NewNamedLabel(System::String^ name, size_t nameSize, uint32_t type, uint32_t parentId) {
				char* str2 = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name);
				AsmJit::Core::Operand::Label^ result = gcnew AsmJit::Core::Operand::Label(NativePointer->newNamedLabel(str2, nameSize, type, parentId));
				System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)str2);
				return result;
			}
			AsmJit::Core::Operand::Label^ NewNamedLabel(System::String^ name, size_t nameSize, uint32_t type) {
				return NewNamedLabel(name, nameSize, type, asmjit::Globals::kInvalidId);
			}
			AsmJit::Core::Operand::Label^ NewNamedLabel(System::String^ name, size_t nameSize) {
				return NewNamedLabel(name, nameSize, asmjit::Label::kTypeGlobal);
			}
			AsmJit::Core::Operand::Label^ NewNamedLabel(System::String^ name) {
				return NewNamedLabel(name, SIZE_MAX);
			}
			AsmJit::Core::Globals::Error Bind(AsmJit::Core::Operand::Label^ label) {
				return (AsmJit::Core::Globals::Error)NativePointer->bind(*((asmjit::Label*)label->NativePointer));
			}

			~BaseAssembler() {
				delete NativePointer;
			}
		};
	}
}