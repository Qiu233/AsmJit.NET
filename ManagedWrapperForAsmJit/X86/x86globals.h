#pragma once
#include "../MWAsmJit.h"

#define ASMJIT_INST_FROM_COND(ID) \
    ID##o, ID##no, ID##b , ID##ae,  \
    ID##e, ID##ne, ID##be, ID##a ,  \
    ID##s, ID##ns, ID##pe, ID##po,  \
    ID##l, ID##ge, ID##le, ID##g


namespace AsmJit {
	namespace X86 {
		public ref class Globals {
		public:
			
			ref class Condition {
			public:
				static array<uint16_t>^ JCCTable;
				static array <uint16_t>^ SETCCTable;
				static array <uint16_t>^ CMOVCCTable;


				static uint32_t ToJCC(uint32_t cond) {
					return JCCTable[cond];
				}
				static uint32_t ToSETCC(uint32_t cond) {
					return SETCCTable[cond];
				}
				static uint32_t ToCMOVCC(uint32_t cond) {
					return CMOVCCTable[cond];
				}
				static Condition() {
					JCCTable = gcnew array<uint16_t>{ ASMJIT_INST_FROM_COND(asmjit::x86::Inst::kIdJ) };
					SETCCTable = gcnew array<uint16_t>{ ASMJIT_INST_FROM_COND(asmjit::x86::Inst::kIdSet) };
					CMOVCCTable = gcnew array<uint16_t>{ ASMJIT_INST_FROM_COND(asmjit::x86::Inst::kIdCmov) };
				}
			};
		};
	}
}
#undef ASMJIT_INST_FROM_COND