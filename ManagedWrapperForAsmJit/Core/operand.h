#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		namespace Operand {
			public ref class Operand abstract {
				MWASMJIT_NATIVEPOINTER(Operand, asmjit::Operand)
			internal:
				Operand() {

				}
				Operand(asmjit::Operand op) {
					_NativePointer = new asmjit::Operand(op);
				}
			public:
				~Operand() {
					delete NativePointer;
				}

				property uint32_t BaseID {
					uint32_t get() {
						return NativePointer->_baseId;
					}
					void set(uint32_t value) {
						NativePointer->_baseId = value;
					}
				}
				static operator asmjit::Operand&(Operand^ op) {
					return *(asmjit::Operand*)op->NativePointer;
				}
			};

			public ref class BaseReg abstract :Operand {
			public:
				BaseReg(asmjit::BaseReg br) :Operand(br) {
				}
			};

			public ref class Imm :Operand {
			public:
				Imm() { _NativePointer = new asmjit::Imm(); }
				Imm(int64_t val) { _NativePointer = new asmjit::Imm(val); }

				static operator Imm ^ (int64_t val) { return gcnew Imm(val); }
				static operator asmjit::Imm&(Imm^ op) {
					return *(asmjit::Imm*)op->NativePointer;
				}
			};

			public ref class Label :Operand {
			internal:
				Label(asmjit::Label& id) { _NativePointer = new asmjit::Label(id); }
			public:
				Label(uint32_t id) { _NativePointer = new asmjit::Label(); }
				static operator asmjit::Label&(Label^ op) {
					return *(asmjit::Label*)op->NativePointer;
				}
			};

			public ref class BaseMem abstract :Operand {
			public:
				static operator asmjit::BaseMem&(BaseMem^ op) {
					return *(asmjit::BaseMem*)op->NativePointer;
				}
			};
		}
	}
}