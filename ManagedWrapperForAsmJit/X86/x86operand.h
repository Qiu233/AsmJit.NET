#pragma once
#include "../MWAsmJit.h"

#define MWASMJIT_X86_REG_CLASSDEF(NAME,BASE) \
	public ref class NAME :BASE { \
		internal: NAME(asmjit::x86::##NAME reg) :##BASE(reg) {} \
		static operator asmjit::x86::NAME##&(NAME^ t) { \
			return *((asmjit::x86::NAME*)t->NativePointer); \
		}\
	};
#define MWASMJIT_X86_REF_WRAPPER(TYPE,NAME) private:static TYPE^ _##NAME = gcnew TYPE(asmjit::x86::##NAME); \
											public:static property TYPE^ NAME{ TYPE^ get() { return _##NAME; } };


#define MWASMJIT_MEM_PTR(FUNC, PTRSIZE)																								\
  static Mem^ FUNC(AsmJit::X86::Operand::Gp^ base, int32_t offset) {															\
    return Pointer(base, offset, PTRSIZE);																							\
  }																																	\
  static Mem^ FUNC(AsmJit::X86::Operand::Gp^ base, AsmJit::X86::Operand::Gp^ index, uint32_t shift, int32_t offset) {	\
    return Pointer(base, index, shift, offset, PTRSIZE);																			\
  }																																	\
  static Mem^ FUNC(AsmJit::X86::Operand::Gp^ base, AsmJit::X86::Operand::Vec^ index, uint32_t shift, int32_t offset) {	\
    return Pointer(base, index, shift, offset, PTRSIZE);																			\
  }																																	\
  static Mem^ FUNC(AsmJit::Core::Operand::Label^ base, int32_t offset) {															\
    return Pointer(base, offset, PTRSIZE);																				            \
  }																																	\
  static Mem^ FUNC(AsmJit::Core::Operand::Label^ base, AsmJit::X86::Operand::Gp^ index, uint32_t shift, int32_t offset) {		\
    return Pointer(base, index, shift, offset, PTRSIZE);																			\
  }																																	\
  static Mem^ FUNC(AsmJit::X86::Operand::Rip^ rip_, int32_t offset) {															\
    return Pointer(rip_, offset, PTRSIZE);																							\
  }																																	\
  static Mem^ FUNC(uint64_t base) {																									\
    return Pointer(base, PTRSIZE);																									\
  }																																	\
  static Mem^ FUNC(uint64_t base, AsmJit::X86::Operand::Gp^ index, uint32_t shift) {											\
    Mem^ m = gcnew Mem();																											\
    m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Gp*)index->NativePointer, shift, PTRSIZE);						\
    return m;																														\
  }																																	\
  static Mem^ FUNC(uint64_t base, AsmJit::X86::Operand::Vec^ index, uint32_t shift) {											\
    return Pointer(base, index, shift, PTRSIZE);																					\
  }																																	\
																																	\
  static Mem^ FUNC##_Absolute(uint64_t base) {																						\
    Mem^ m = gcnew Mem();																											\
    m->_NativePointer = new asmjit::x86::Mem(base, PTRSIZE, asmjit::BaseMem::kSignatureMemAbs);										\
    return m;																														\
  }																																	\
  static Mem^ FUNC##_Absolute(uint64_t base, AsmJit::X86::Operand::Gp^ index, uint32_t shift) {								\
    Mem^ m = gcnew Mem();																											\
    m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Gp*)index->NativePointer, shift, PTRSIZE, asmjit::BaseMem::kSignatureMemAbs);		\
    return m;																																		\
  }																																					\
  static Mem^ FUNC##_Absolute(uint64_t base, AsmJit::X86::Operand::Vec^ index, uint32_t shift) {												\
    Mem^ m = gcnew Mem();																															\
    m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Vec*)index->NativePointer, shift, PTRSIZE, asmjit::BaseMem::kSignatureMemAbs);    \
    return m;                 																														\
  }																																					\
																																					\
  static Mem^ FUNC##_Relative(uint64_t base) {																										\
    Mem^ m = gcnew Mem();																															\
    m->_NativePointer = new asmjit::x86::Mem(base, PTRSIZE, asmjit::BaseMem::kSignatureMemRel);														\
    return m;                 																														\
  }																																					\
  static Mem^ FUNC##_Relative(uint64_t base, AsmJit::X86::Operand::Gp^ index, uint32_t shift) {												\
    Mem^ m = gcnew Mem();																															\
    m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Gp*)index->NativePointer, shift, PTRSIZE, asmjit::BaseMem::kSignatureMemRel);		\
    return m;																																		\
  }																																					\
  static Mem^ FUNC##_Relative(uint64_t base, AsmJit::X86::Operand::Vec^ index, uint32_t shift) {												\
    Mem^ m = gcnew Mem();																															\
    m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Vec*)index->NativePointer, shift, PTRSIZE, asmjit::BaseMem::kSignatureMemRel);    \
    return m;																																		\
  }																																					\

namespace AsmJit {
	namespace X86 {
		namespace Operand {

			MWASMJIT_X86_REG_CLASSDEF(Reg, AsmJit::Core::Operand::BaseReg);
			MWASMJIT_X86_REG_CLASSDEF(Gp, Reg);
			MWASMJIT_X86_REG_CLASSDEF(Vec, Reg);
			MWASMJIT_X86_REG_CLASSDEF(SReg, Reg);
			MWASMJIT_X86_REG_CLASSDEF(Gpb, Gp);
			MWASMJIT_X86_REG_CLASSDEF(GpbLo, Gpb);
			MWASMJIT_X86_REG_CLASSDEF(GpbHi, Gpb);
			MWASMJIT_X86_REG_CLASSDEF(Gpw, Gp);
			MWASMJIT_X86_REG_CLASSDEF(Gpd, Gp);
			MWASMJIT_X86_REG_CLASSDEF(Gpq, Gp);
			MWASMJIT_X86_REG_CLASSDEF(Xmm, Vec);
			MWASMJIT_X86_REG_CLASSDEF(Ymm, Vec);
			MWASMJIT_X86_REG_CLASSDEF(Zmm, Vec);
			MWASMJIT_X86_REG_CLASSDEF(Mm, Reg);
			MWASMJIT_X86_REG_CLASSDEF(KReg, Reg);
			MWASMJIT_X86_REG_CLASSDEF(CReg, Reg);
			MWASMJIT_X86_REG_CLASSDEF(DReg, Reg);
			MWASMJIT_X86_REG_CLASSDEF(St, Reg);
			MWASMJIT_X86_REG_CLASSDEF(Bnd, Reg);
			MWASMJIT_X86_REG_CLASSDEF(Rip, Reg);
			public ref class RegsDef abstract sealed {
			public:
				MWASMJIT_X86_REF_WRAPPER(Gp, al);
				MWASMJIT_X86_REF_WRAPPER(Gp, bl);
				MWASMJIT_X86_REF_WRAPPER(Gp, cl);
				MWASMJIT_X86_REF_WRAPPER(Gp, dl);
				MWASMJIT_X86_REF_WRAPPER(Gp, spl);
				MWASMJIT_X86_REF_WRAPPER(Gp, bpl);
				MWASMJIT_X86_REF_WRAPPER(Gp, sil);
				MWASMJIT_X86_REF_WRAPPER(Gp, dil);
				MWASMJIT_X86_REF_WRAPPER(Gp, r8b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r9b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r10b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r11b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r12b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r13b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r14b);
				MWASMJIT_X86_REF_WRAPPER(Gp, r15b);

				MWASMJIT_X86_REF_WRAPPER(Gp, ah);
				MWASMJIT_X86_REF_WRAPPER(Gp, bh);
				MWASMJIT_X86_REF_WRAPPER(Gp, ch);
				MWASMJIT_X86_REF_WRAPPER(Gp, dh);

				MWASMJIT_X86_REF_WRAPPER(Gp, ax);
				MWASMJIT_X86_REF_WRAPPER(Gp, bx);
				MWASMJIT_X86_REF_WRAPPER(Gp, cx);
				MWASMJIT_X86_REF_WRAPPER(Gp, dx);
				MWASMJIT_X86_REF_WRAPPER(Gp, sp);
				MWASMJIT_X86_REF_WRAPPER(Gp, bp);
				MWASMJIT_X86_REF_WRAPPER(Gp, si);
				MWASMJIT_X86_REF_WRAPPER(Gp, di);
				MWASMJIT_X86_REF_WRAPPER(Gp, r8w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r9w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r10w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r11w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r12w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r13w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r14w);
				MWASMJIT_X86_REF_WRAPPER(Gp, r15w);

				MWASMJIT_X86_REF_WRAPPER(Gp, eax);
				MWASMJIT_X86_REF_WRAPPER(Gp, ebx);
				MWASMJIT_X86_REF_WRAPPER(Gp, ecx);
				MWASMJIT_X86_REF_WRAPPER(Gp, edx);
				MWASMJIT_X86_REF_WRAPPER(Gp, esp);
				MWASMJIT_X86_REF_WRAPPER(Gp, ebp);
				MWASMJIT_X86_REF_WRAPPER(Gp, esi);
				MWASMJIT_X86_REF_WRAPPER(Gp, edi);
				MWASMJIT_X86_REF_WRAPPER(Gp, r8d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r9d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r10d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r11d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r12d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r13d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r14d);
				MWASMJIT_X86_REF_WRAPPER(Gp, r15d);

				MWASMJIT_X86_REF_WRAPPER(Gp, rax);
				MWASMJIT_X86_REF_WRAPPER(Gp, rbx);
				MWASMJIT_X86_REF_WRAPPER(Gp, rcx);
				MWASMJIT_X86_REF_WRAPPER(Gp, rdx);
				MWASMJIT_X86_REF_WRAPPER(Gp, rsp);
				MWASMJIT_X86_REF_WRAPPER(Gp, rbp);
				MWASMJIT_X86_REF_WRAPPER(Gp, rsi);
				MWASMJIT_X86_REF_WRAPPER(Gp, rdi);
				MWASMJIT_X86_REF_WRAPPER(Gp, r8);
				MWASMJIT_X86_REF_WRAPPER(Gp, r9);
				MWASMJIT_X86_REF_WRAPPER(Gp, r10);
				MWASMJIT_X86_REF_WRAPPER(Gp, r11);
				MWASMJIT_X86_REF_WRAPPER(Gp, r12);
				MWASMJIT_X86_REF_WRAPPER(Gp, r13);
				MWASMJIT_X86_REF_WRAPPER(Gp, r14);
				MWASMJIT_X86_REF_WRAPPER(Gp, r15);

				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm0);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm1);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm2);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm3);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm4);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm5);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm6);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm7);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm8);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm9);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm10);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm11);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm12);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm13);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm14);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm15);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm16);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm17);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm18);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm19);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm20);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm21);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm22);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm23);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm24);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm25);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm26);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm27);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm28);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm29);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm30);
				MWASMJIT_X86_REF_WRAPPER(Xmm, xmm31);

				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm0);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm1);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm2);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm3);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm4);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm5);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm6);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm7);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm8);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm9);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm10);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm11);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm12);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm13);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm14);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm15);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm16);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm17);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm18);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm19);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm20);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm21);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm22);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm23);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm24);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm25);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm26);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm27);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm28);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm29);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm30);
				MWASMJIT_X86_REF_WRAPPER(Ymm, ymm31);

				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm0);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm1);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm2);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm3);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm4);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm5);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm6);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm7);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm8);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm9);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm10);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm11);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm12);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm13);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm14);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm15);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm16);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm17);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm18);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm19);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm20);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm21);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm22);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm23);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm24);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm25);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm26);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm27);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm28);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm29);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm30);
				MWASMJIT_X86_REF_WRAPPER(Zmm, zmm31);

				MWASMJIT_X86_REF_WRAPPER(Mm, mm0);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm1);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm2);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm3);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm4);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm5);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm6);
				MWASMJIT_X86_REF_WRAPPER(Mm, mm7);

				MWASMJIT_X86_REF_WRAPPER(KReg, k0);
				MWASMJIT_X86_REF_WRAPPER(KReg, k1);
				MWASMJIT_X86_REF_WRAPPER(KReg, k2);
				MWASMJIT_X86_REF_WRAPPER(KReg, k3);
				MWASMJIT_X86_REF_WRAPPER(KReg, k4);
				MWASMJIT_X86_REF_WRAPPER(KReg, k5);
				MWASMJIT_X86_REF_WRAPPER(KReg, k6);
				MWASMJIT_X86_REF_WRAPPER(KReg, k7);

				MWASMJIT_X86_REF_WRAPPER(SReg, no_seg);
				MWASMJIT_X86_REF_WRAPPER(SReg, es);
				MWASMJIT_X86_REF_WRAPPER(SReg, cs);
				MWASMJIT_X86_REF_WRAPPER(SReg, ss);
				MWASMJIT_X86_REF_WRAPPER(SReg, ds);
				MWASMJIT_X86_REF_WRAPPER(SReg, fs);
				MWASMJIT_X86_REF_WRAPPER(SReg, gs);

				MWASMJIT_X86_REF_WRAPPER(CReg, cr0);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr1);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr2);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr3);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr4);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr5);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr6);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr7);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr8);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr9);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr10);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr11);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr12);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr13);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr14);
				MWASMJIT_X86_REF_WRAPPER(CReg, cr15);

				MWASMJIT_X86_REF_WRAPPER(DReg, dr0);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr1);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr2);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr3);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr4);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr5);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr6);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr7);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr8);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr9);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr10);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr11);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr12);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr13);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr14);
				MWASMJIT_X86_REF_WRAPPER(DReg, dr15);

				MWASMJIT_X86_REF_WRAPPER(St, st0);
				MWASMJIT_X86_REF_WRAPPER(St, st1);
				MWASMJIT_X86_REF_WRAPPER(St, st2);
				MWASMJIT_X86_REF_WRAPPER(St, st3);
				MWASMJIT_X86_REF_WRAPPER(St, st4);
				MWASMJIT_X86_REF_WRAPPER(St, st5);
				MWASMJIT_X86_REF_WRAPPER(St, st6);
				MWASMJIT_X86_REF_WRAPPER(St, st7);

				MWASMJIT_X86_REF_WRAPPER(Bnd, bnd0);
				MWASMJIT_X86_REF_WRAPPER(Bnd, bnd1);
				MWASMJIT_X86_REF_WRAPPER(Bnd, bnd2);
				MWASMJIT_X86_REF_WRAPPER(Bnd, bnd3);

				MWASMJIT_X86_REF_WRAPPER(Rip, rip);
			};
			public ref class Mem :AsmJit::Core::Operand::BaseMem {
			internal:
				Mem() {
					_NativePointer = new asmjit::x86::Mem();
				}
				Mem(asmjit::x86::Mem mem) {
					_NativePointer = new asmjit::x86::Mem(mem);
				}
			public:
				static operator asmjit::x86::Mem&(Mem^ op) {
					return *(asmjit::x86::Mem*)op->NativePointer;
				}

				static Mem^ Pointer(AsmJit::X86::Operand::Gp^ base, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::x86::Gp*)base->NativePointer, offset, size);
					return m;
				}
				static Mem^ Pointer(AsmJit::X86::Operand::Gp^ base, AsmJit::X86::Operand::Gp^ index, uint32_t shift, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::x86::Gp*)base->NativePointer, *(asmjit::x86::Gp*)index->NativePointer, shift, offset, size);
					return m;
				}
				static Mem^ Pointer(AsmJit::X86::Operand::Gp^ base, AsmJit::X86::Operand::Vec^ index, uint32_t shift, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::x86::Gp*)base->NativePointer, *(asmjit::x86::Vec*)index->NativePointer, shift, offset, size);
					return m;
				}

				static Mem^ Pointer(Core::Operand::Label^ base, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::Label*)base->NativePointer, offset, size);
					return m;
				}
				static Mem^ Pointer(AsmJit::Core::Operand::Label^ base, AsmJit::X86::Operand::Gp^ index, uint32_t shift, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::Label*)base->NativePointer, *(asmjit::x86::Gp*)index->NativePointer, shift, offset, size);
					return m;
				}
				static Mem^ Pointer(AsmJit::Core::Operand::Label^ base, AsmJit::X86::Operand::Vec^ index, uint32_t shift, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::Label*)base->NativePointer, *(asmjit::x86::Vec*)index->NativePointer, shift, offset, size);
					return m;
				}

				static Mem^ Pointer(AsmJit::X86::Operand::Rip^ rip_, int32_t offset, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(*(asmjit::x86::Rip*)rip_->NativePointer, offset, size);
					return m;
				}

				static Mem^ Pointer(uint64_t base, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, size);
					return m;
				}
				static Mem^ Pointer(uint64_t base, AsmJit::X86::Operand::Reg^ index, uint32_t shift, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Reg*)index->NativePointer, shift, size);
					return m;
				}
				static Mem^ Pointer(uint64_t base, AsmJit::X86::Operand::Vec^ index, uint32_t shift, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Vec*)index->NativePointer, shift, size);
					return m;
				}

				static Mem^ Pointer_Absolute(uint64_t base, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, size, asmjit::BaseMem::kSignatureMemAbs);
					return m;
				}
				static Mem^ Pointer_Absolute(uint64_t base, AsmJit::X86::Operand::Reg^ index, uint32_t shift, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Reg*)index->NativePointer, shift, size, asmjit::BaseMem::kSignatureMemAbs);
					return m;
				}
				static Mem^ Pointer_Absolute(uint64_t base, AsmJit::X86::Operand::Vec^ index, uint32_t shift, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Vec*)index->NativePointer, shift, size, asmjit::BaseMem::kSignatureMemAbs);
					return m;
				}

				static Mem^ Pointer_Relative(uint64_t base, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, size, asmjit::BaseMem::kSignatureMemRel);
					return m;
				}
				static Mem^ Pointer_Relative(uint64_t base, AsmJit::X86::Operand::Reg^ index, uint32_t shift, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Reg*)index->NativePointer, shift, size, asmjit::BaseMem::kSignatureMemRel);
					return m;
				}
				static Mem^ Pointer_Relative(uint64_t base, AsmJit::X86::Operand::Vec^ index, uint32_t shift, uint32_t size) {
					Mem^ m = gcnew Mem();
					m->_NativePointer = new asmjit::x86::Mem(base, *(asmjit::x86::Vec*)index->NativePointer, shift, size, asmjit::BaseMem::kSignatureMemRel);
					return m;
				}

				MWASMJIT_MEM_PTR(Pointer_8, 1);
				MWASMJIT_MEM_PTR(Pointer_16, 2);
				MWASMJIT_MEM_PTR(Pointer_32, 4);
				MWASMJIT_MEM_PTR(Pointer_48, 6);
				MWASMJIT_MEM_PTR(Pointer_64, 8);
				MWASMJIT_MEM_PTR(Pointer_80, 10);
				MWASMJIT_MEM_PTR(Pointer_128, 16);
				MWASMJIT_MEM_PTR(Pointer_256, 32);
				MWASMJIT_MEM_PTR(Pointer_512, 64);

				MWASMJIT_MEM_PTR(BYTE_Pointer, 1);
				MWASMJIT_MEM_PTR(WORD_Pointer, 2);
				MWASMJIT_MEM_PTR(DWORD_Pointer, 4);
				MWASMJIT_MEM_PTR(QWORD_Pointer, 8);
				MWASMJIT_MEM_PTR(RWORD_Pointer, 10);
				MWASMJIT_MEM_PTR(OWORD_Pointer, 16);
				MWASMJIT_MEM_PTR(DQWORD_ptr, 16);
				MWASMJIT_MEM_PTR(QQWORD_ptr, 32);
				MWASMJIT_MEM_PTR(XMMWORD_ptr, 16);
				MWASMJIT_MEM_PTR(YMMWORD_ptr, 32);
				MWASMJIT_MEM_PTR(ZMMWORD_ptr, 64);
			};
		}
	}
}

#undef MWASMJIT_X86_REG_CLASSDEF
#undef MWASMJIT_X86_REF_WRAPPER