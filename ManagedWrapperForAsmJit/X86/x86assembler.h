#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace X86 {
		public ref class Assembler :AsmJit::Core::BaseAssembler, EmitterImplicit {
		public:
			Assembler(AsmJit::Core::CodeHolder^ holder) {
				_NativePointer = new asmjit::x86::Assembler(holder->NativePointer);
			}
			~Assembler() {
				delete NativePointer;
			}


			virtual AsmJit::Core::BaseEmitter^ Emitter() {
				return this;
			}

		};
	}
}