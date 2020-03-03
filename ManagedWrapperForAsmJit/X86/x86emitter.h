#pragma once
#include "../MWAsmJit.h"


#define MWASMJIT_INST_ARGS1(TYPE, NAME, ID, ARG0, ACTUALARG0)																							\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, ARG0) {		\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID, ACTUALARG0);							\
	}																																			\

#define MWASMJIT_INST_ARGS2(TYPE, NAME, ID, ARG0, ARG1, ACTUALARG0, ACTUALARG1)																		\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, ARG0, ARG1) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID, ACTUALARG0, ACTUALARG1);			\
	}																																			\

#define MWASMJIT_INST_ARGS3(TYPE, NAME, ID, ARG0, ARG1, ARG2, ACTUALARG0, ACTUALARG1, ACTUALARG2)																		\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, ARG0, ARG1, ARG2) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID, ACTUALARG0, ACTUALARG1, ACTUALARG2);			\
	}																																			\

#define MWASMJIT_INST_ARGS4(TYPE, NAME, ID, ARG0, ARG1, ARG2, ARG3, ACTUALARG0, ACTUALARG1, ACTUALARG2, ACTUALARG3)																		\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, ARG0, ARG1, ARG2, ARG3) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID, ACTUALARG0, ACTUALARG1, ACTUALARG2, ACTUALARG3);			\
	}																																			\

#define MWASMJIT_INST_ARGS5(TYPE, NAME, ID, ARG0, ARG1, ARG2, ARG3, ARG4, ACTUALARG0, ACTUALARG1, ACTUALARG2, ACTUALARG3, ACTUALARG4)																		\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, ARG0, ARG1, ARG2, ARG3, ARG4) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID, ACTUALARG0, ACTUALARG1, ACTUALARG2, ACTUALARG3, ACTUALARG4);			\
	}																																			\

#define MWASMJIT_INST_ARGS6(TYPE, NAME, ID, ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ACTUALARG0, ACTUALARG1, ACTUALARG2, ACTUALARG3, ACTUALARG4, ACTUALARG5)																		\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID, ACTUALARG0, ACTUALARG1, ACTUALARG2, ACTUALARG3, ACTUALARG4, ACTUALARG5);			\
	}																																			\

#define MWASMJIT_INST_0x(TYPE, NAME, ID)																												\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t) {				\
		return (AsmJit::Core::Globals::Error)t->Emitter()->Emit(asmjit::x86::Inst::kId##ID);										\
	}																																			\

#define MWASMJIT_INST_1x(TYPE, NAME, ID, T0)	MWASMJIT_INST_ARGS1(TYPE, NAME, ID, T0 o0, o0)	\


#define MWASMJIT_INST_1i(TYPE, NAME, ID, T0)													\
	MWASMJIT_INST_ARGS1(TYPE, NAME, ID, T0 o0, o0)							\
	MWASMJIT_INST_ARGS1(TYPE, NAME, ID, int o0, o0)														\
	MWASMJIT_INST_ARGS1(TYPE, NAME, ID, unsigned int o0, o0)												\
	MWASMJIT_INST_ARGS1(TYPE, NAME, ID, int64_t o0, o0)													\
	MWASMJIT_INST_ARGS1(TYPE, NAME, ID, uint64_t o0, o0)													\

#define MWASMJIT_INST_1c(TYPE, NAME, ID, CONV, T0)																									\
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, uint32_t cc, T0 o0) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->NativePointer->emit(CONV(cc), o0);								\
	}																																					\
																																						\
	MWASMJIT_INST_1x(TYPE, NAME##a, ID##a, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##ae, ID##ae, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##b, ID##b, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##be, ID##be, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##c, ID##c, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##e, ID##e, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##g, ID##g, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##ge, ID##ge, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##l, ID##l, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##le, ID##le, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##na, ID##na, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nae, ID##nae, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nb, ID##nb, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nbe, ID##nbe, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nc, ID##nc, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##ne, ID##ne, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##ng, ID##ng, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nge, ID##nge, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nl, ID##nl, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nle, ID##nle, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##no, ID##no, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##np, ID##np, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##ns, ID##ns, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##nz, ID##nz, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##o, ID##o, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##p, ID##p, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##pe, ID##pe, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##po, ID##po, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##s, ID##s, T0)\
	MWASMJIT_INST_1x(TYPE, NAME##z, ID##z, T0)\

#define MWASMJIT_INST_2x(TYPE, NAME, ID, T0, T1) MWASMJIT_INST_ARGS2(TYPE, NAME, ID, T0 o0, T1 o1, o0, o1)	\

#define MWASMJIT_INST_2i(TYPE, NAME, ID, T0, T1) \
	MWASMJIT_INST_ARGS2(TYPE, NAME, ID, T0 o0, T1 o1, o0, o1) \
	MWASMJIT_INST_ARGS2(TYPE, NAME, ID, T0 o0, int o1, o0, o1) \
	MWASMJIT_INST_ARGS2(TYPE, NAME, ID, T0 o0, unsigned int o1, o0, o1) \
	MWASMJIT_INST_ARGS2(TYPE, NAME, ID, T0 o0, int64_t o1, o0, o1) \
	MWASMJIT_INST_ARGS2(TYPE, NAME, ID, T0 o0, uint64_t o1, o0, o1) \

#define MWASMJIT_INST_2c(TYPE, NAME, ID, CONV, T0, T1) \
	generic<typename T> where T: TYPE [ExtensionAttribute] static AsmJit::Core::Globals::Error NAME(T t, uint32_t cc, T0 o0, T1 o1) {	\
		return (AsmJit::Core::Globals::Error)t->Emitter()->NativePointer->emit(CONV(cc), o0, o1);		\
	}																																							\
	MWASMJIT_INST_2x(TYPE, NAME##a, ID##a, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##ae, ID##ae, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##b, ID##b, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##be, ID##be, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##c, ID##c, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##e, ID##e, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##g, ID##g, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##ge, ID##ge, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##l, ID##l, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##le, ID##le, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##na, ID##na, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nae, ID##nae, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nb, ID##nb, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nbe, ID##nbe, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nc, ID##nc, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##ne, ID##ne, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##ng, ID##ng, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nge, ID##nge, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nl, ID##nl, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nle, ID##nle, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##no, ID##no, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##np, ID##np, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##ns, ID##ns, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##nz, ID##nz, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##o, ID##o, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##p, ID##p, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##pe, ID##pe, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##po, ID##po, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##s, ID##s, T0, T1)\
	MWASMJIT_INST_2x(TYPE, NAME##z, ID##z, T0, T1)\

#define MWASMJIT_INST_3x(TYPE, NAME, ID, T0, T1, T2) MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, o0, o1, o2)	\

#define MWASMJIT_INST_3i(TYPE, NAME, ID, T0, T1, T2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, o0, o1, o2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, int o2, o0, o1, o2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, unsigned int o2, o0, o1, o2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, int64_t o2, o0, o1, o2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, uint64_t o2, o0, o1, o2) \

#define MWASMJIT_INST_3ii(TYPE, NAME, ID, T0, T1, T2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, o0, o1, o2) \
	MWASMJIT_INST_ARGS3(TYPE, NAME, ID, T0 o0, int o1, int o2, o0, gcnew AsmJit::Core::Operand::Imm(o1), asmjit::Support::asInt(o2)) \

#define MWASMJIT_INST_4x(TYPE, NAME, ID, T0, T1, T2, T3) MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, o0, o1, o2, o3)	\

#define MWASMJIT_INST_4i(TYPE, NAME, ID, T0, T1, T2, T3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, o0, o1, o2, o3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, int o3, o0, o1, o2, o3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, unsigned int o3, o0, o1, o2, o3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, int64_t o3, o0, o1, o2, o3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, uint64_t o3, o0, o1, o2, o3) \

#define MWASMJIT_INST_4ii(TYPE, NAME, ID, T0, T1, T2, T3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, o0, o1, o2, o3) \
	MWASMJIT_INST_ARGS4(TYPE, NAME, ID, T0 o0, T1 o1, int o2, int o3, o0, o1, gcnew AsmJit::Core::Operand::Imm(o2), asmjit::Support::asInt(o3)) \

#define MWASMJIT_INST_5x(TYPE, NAME, ID, T0, T1, T2, T3, T4) MWASMJIT_INST_ARGS5(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, T4 o4, o0, o1, o2, o3, o4)	\

#define MWASMJIT_INST_5i(TYPE, NAME, ID, T0, T1, T2, T3, T4) \
	MWASMJIT_INST_ARGS5(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, T4 o4, o0, o1, o2, o3, o4) \
	MWASMJIT_INST_ARGS5(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, int o4, o0, o1, o2, o3, o4) \
	MWASMJIT_INST_ARGS5(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, unsigned int o4, o0, o1, o2, o3, o4) \
	MWASMJIT_INST_ARGS5(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, int64_t o4, o0, o1, o2, o3, o4) \
	MWASMJIT_INST_ARGS5(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, uint64_t o4, o0, o1, o2, o3, o4) \

#define MWASMJIT_INST_6x(TYPE, NAME, ID, T0, T1, T2, T3, T4, T5) MWASMJIT_INST_ARGS6(TYPE, NAME, ID, T0 o0, T1 o1, T2 o2, T3 o3, T4 o4, T5 o5, o0, o1, o2, o3, o4, o5)	\


#define MLabel AsmJit::Core::Operand::Label^
#define MGp AsmJit::X86::Operand::Gp^
#define MVec AsmJit::X86::Operand::Vec^
#define MXmm AsmJit::X86::Operand::Xmm^
#define MYmm AsmJit::X86::Operand::Ymm^
#define MZmm AsmJit::X86::Operand::Zmm^
#define MImm AsmJit::Core::Operand::Imm^
#define MMem AsmJit::X86::Operand::Mem^
#define MMm AsmJit::X86::Operand::Mm^
#define MSt AsmJit::X86::Operand::St^
#define MBnd AsmJit::X86::Operand::Bnd^
#define MRip AsmJit::X86::Operand::Rip^
#define MKReg AsmJit::X86::Operand::KReg^
#define MSReg AsmJit::X86::Operand::SReg^
#define MDReg AsmJit::X86::Operand::DReg^
#define MCReg AsmJit::X86::Operand::CReg^

#define ERR AsmJit::Core::Globals::Error

typedef AsmJit::X86::Operand::Gp^ AL;
typedef AsmJit::X86::Operand::Gp^ AH;
typedef AsmJit::X86::Operand::Gp^ CL;
typedef AsmJit::X86::Operand::Gp^ AX;
typedef AsmJit::X86::Operand::Gp^ DX;

typedef AsmJit::X86::Operand::Gp^ EAX;
typedef AsmJit::X86::Operand::Gp^ EBX;
typedef AsmJit::X86::Operand::Gp^ ECX;
typedef AsmJit::X86::Operand::Gp^ EDX;

typedef AsmJit::X86::Operand::Gp^ RAX;
typedef AsmJit::X86::Operand::Gp^ RBX;
typedef AsmJit::X86::Operand::Gp^ RCX;
typedef AsmJit::X86::Operand::Gp^ RDX;

typedef AsmJit::X86::Operand::Gp^ ZAX;
typedef AsmJit::X86::Operand::Gp^ ZBX;
typedef AsmJit::X86::Operand::Gp^ ZCX;
typedef AsmJit::X86::Operand::Gp^ ZDX;

typedef AsmJit::X86::Operand::Mem^ DS_ZAX; // ds:[zax]
typedef AsmJit::X86::Operand::Mem^ DS_ZDI; // ds:[zdi]
typedef AsmJit::X86::Operand::Mem^ ES_ZDI; // es:[zdi]
typedef AsmJit::X86::Operand::Mem^ DS_ZSI; // ds:[zsi]

typedef AsmJit::X86::Operand::Xmm^ XMM0;

using namespace System::Runtime::CompilerServices;
namespace AsmJit {
	namespace X86 {
		public interface class EmitterExplicit {
		public:
			AsmJit::Core::BaseEmitter^ Emitter();
		};
		public interface class EmitterImplicit :EmitterExplicit {
		};
		[ExtensionAttribute]
		public ref class EmitterExplicitHelper abstract sealed {
		public:
			//For test
			/*MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, clc, Clc);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, bswap, Bswap, MGp);
			MWASMJIT_INST_1i(AsmJit::X86::EmitterExplicit, call, Call, MImm);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, j, J, AsmJit::X86::Globals::Condition::ToJCC, MLabel);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, j, J, AsmJit::X86::Globals::Condition::ToJCC, MImm);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, j, J, AsmJit::X86::Globals::Condition::ToJCC, uint64_t);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adc, Adc, MGp, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, adc, Adc, MGp, MImm);
			MWASMJIT_INST_2c(AsmJit::X86::EmitterExplicit, cmov, Cmov, AsmJit::X86::Globals::Condition::ToCMOVCC, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, cmpxchg, Cmpxchg, MGp, MGp, ZAX);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MGp, MImm);
			MWASMJIT_INST_3ii(AsmJit::X86::EmitterExplicit, extrq, Extrq, MXmm, MImm, MImm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, pcmpistri, Pcmpistri, MXmm, MXmm, MImm, ECX);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4ii(AsmJit::X86::EmitterExplicit, insertq, Insertq, MXmm, MXmm, MImm, MImm);
			MWASMJIT_INST_5x(AsmJit::X86::EmitterExplicit, cmpxchg16b, Cmpxchg16b, MMem, RDX, RAX, RCX, RBX);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MXmm, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, pcmpestri, Pcmpestri, MXmm, MXmm, MImm, ECX, EAX, EDX)   // SSE4_2 [EXPLICIT]*/

			/*AsmJit::X86::Operand::Gp^ Gpz(uint32_t id) { return Gp(_emitter()->_gpRegInfo.signature(), id); }
			AsmJit::X86::Operand::Gp^ Zax() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdAx); }
			AsmJit::X86::Operand::Gp^ Zcx() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdCx); }
			AsmJit::X86::Operand::Gp^ Zdx() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdDx); }
			AsmJit::X86::Operand::Gp^ Zbx() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdBx); }
			AsmJit::X86::Operand::Gp^ Zsp() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdSp); }
			AsmJit::X86::Operand::Gp^ Zbp() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdBp); }
			AsmJit::X86::Operand::Gp^ Zsi() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdSi); }
			AsmJit::X86::Operand::Gp^ Zdi() { return Gp(_emitter()->_gpRegInfo.signature(), Gp::kIdDi); }*/



			generic<typename T> where T: AsmJit::X86::EmitterExplicit[ExtensionAttribute] static MMem Pointer_Base(T t, uint32_t baseId, int32_t off, uint32_t size) {
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(asmjit::x86::Mem::Decomposed{ t->Emitter()->NativePointer->_gpRegInfo.type(), baseId, 0, 0, off, size, 0 }));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zax(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdAx, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zcx(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdCx, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zdx(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdDx, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zbx(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdBx, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zsp(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdSp, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zbp(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdBp, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zsi(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdSi, off, size); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zdi(T t, int32_t off, uint32_t size) { return Pointer_Base(t, asmjit::x86::Gp::kIdDi, off, size); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zax(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdAx, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zcx(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdCx, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zdx(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdDx, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zbx(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdBx, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zsp(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdSp, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zbp(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdBp, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zsi(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdSi, off, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zdi(T t, int32_t off) { return Pointer_Base(t, asmjit::x86::Gp::kIdDi, off, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zax(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdAx, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zcx(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdCx, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zdx(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdDx, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zbx(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdBx, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zsp(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdSp, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zbp(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdBp, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zsi(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdSi, 0, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem Pointer_zdi(T t) { return Pointer_Base(t, asmjit::x86::Gp::kIdDi, 0, 0); }



			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base) { return IntPtr_Pointer(t, base, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, MGp index, uint32_t shift, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, index, shift, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, MGp index, uint32_t shift) { return IntPtr_Pointer(t, base, index, shift, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, MGp index) { return IntPtr_Pointer(t, base, index, 0, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, MVec index, uint32_t shift, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, index, shift, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, MVec index, uint32_t shift) { return IntPtr_Pointer(t, base, index, shift, 0); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MGp base, MVec index) { return IntPtr_Pointer(t, base, index, 0, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MLabel base, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MLabel base) { return IntPtr_Pointer(t, base, 0); }


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MLabel base, MGp index, uint32_t shift, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, index, shift, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MLabel base, MGp index, uint32_t shift) { return IntPtr_Pointer(t, base, index, shift, 0); }


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MLabel base, MVec index, uint32_t shift, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, index, shift, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MLabel base, MVec index, uint32_t shift) { return IntPtr_Pointer(t, base, index, shift, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MRip rip, int32_t offset) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(rip, offset, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, MRip rip) { return IntPtr_Pointer(t, rip, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, uint64_t base) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, nativeGpSize));
			}

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, uint64_t base, MGp index, uint32_t shift) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, index, shift, nativeGpSize));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer(T t, uint64_t base, MGp index) { return IntPtr_Pointer(t, base, index, 0); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer_Abs(T t, uint64_t base) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, nativeGpSize, asmjit::BaseMem::kSignatureMemAbs));
			}

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer_Abs(T t, uint64_t base, MGp index, uint32_t shift) {
				uint32_t nativeGpSize = t->Emitter()->NativePointer->gpSize();
				return gcnew AsmJit::X86::Operand::Mem(asmjit::x86::Mem(base, index, shift, nativeGpSize, asmjit::BaseMem::kSignatureMemAbs));
			}
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) MMem IntPtr_Pointer_Abs(T t, uint64_t base, MGp index) { return IntPtr_Pointer_Abs(t, base, index, 0); }



			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR DB(T t, uint8_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, 1); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR DW(T t, uint16_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, 2); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR DD(T t, uint32_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, 4); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR DQ(T t, uint64_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, 8); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dint8(T t, int8_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(int8_t)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Duint8(T t, uint8_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(uint8_t)); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dint16(T t, int16_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(int16_t)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Duint16(T t, uint16_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(uint16_t)); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dint32(T t, int32_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(int32_t)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Duint32(T t, uint32_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(uint32_t)); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dint64(T t, int64_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(int64_t)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Duint64(T t, uint64_t x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(uint64_t)); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dfloat(T t, float x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(float)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Ddouble(T t, double x) { return (ERR)t->Emitter()->NativePointer->embed(&x, sizeof(double)); }

			//MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dmm(T t, Data64& x) { return t->Emitter()->NativePointer->embed(&x, sizeof(Data64)); }
			//MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dxmm(T t, Data128& x) { return t->Emitter()->NativePointer->embed(&x, sizeof(Data128)); }
			//MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) ERR Dymm(T t, Data256& x) { return t->Emitter()->NativePointer->embed(&x, sizeof(Data256)); }

			//template<typename T>
			//Error dstruct(T& x) { return t->Emitter()->NativePointer->embed(&x, uint32_t(sizeof(T))); }

		//for some reason this is converted to public
		//protected:
		public:
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void AddInstOptions(T t, uint32_t options) {
				t->Emitter()->NativePointer->addInstOptions(options);
			}
		public:


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Short_(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionShortForm); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Long_(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionLongForm); }




			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Mod_mr(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionModMR); }



			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Taken(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionTaken); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void NotTaken(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionNotTaken); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Lock(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionLock); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Xacquire(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionXAcquire); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Xrelease(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionXRelease); }


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Bnd(T t) { AddInstOptions(t, asmjit::x86::Inst::kOptionRepne); }


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Rep(T t, MGp zcx) {
				t->Emitter()->NativePointer->_extraReg.init(zcx);
				AddInstOptions(t, asmjit::x86::Inst::kOptionRep);
			}


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Repe(T t, MGp zcx) { return Rep(t, zcx); }


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Repz(T t, MGp zcx) { return Rep(t, zcx); }


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void Repne(T t, MGp zcx) {
				t->Emitter()->NativePointer->_extraReg.init(zcx);
				AddInstOptions(t, asmjit::x86::Inst::kOptionRepne);
			}


			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void repnz(T t, MGp zcx) { return Repne(t, zcx); }





			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rex(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionRex); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rex_b(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionOpCodeB); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rex_x(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionOpCodeX); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rex_r(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionOpCodeR); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rex_w(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionOpCodeW); }



			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void vex3(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionVex3); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void evex(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionEvex); }



			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void k(T t, MKReg kreg) {
				t->Emitter()->NativePointer->_extraReg.init(kreg);
			}

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void z(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionZMask); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void sae(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionSAE); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rn_sae(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionER | asmjit::x86::Inst::kOptionRN_SAE); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rd_sae(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionER | asmjit::x86::Inst::kOptionRD_SAE); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void ru_sae(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionER | asmjit::x86::Inst::kOptionRU_SAE); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterExplicit) void rz_sae(T t) { return AddInstOptions(t, asmjit::x86::Inst::kOptionER | asmjit::x86::Inst::kOptionRZ_SAE); }


			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adc, Adc, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adc, Adc, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, adc, Adc, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adc, Adc, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, adc, Adc, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, add, Add, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, add, Add, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, add, Add, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, add, Add, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, add, Add, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, and_, And, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, and_, And, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, and_, And, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, and_, And, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, and_, And, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, arpl, Arpl, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, arpl, Arpl, MMem, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bound, Bound, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bsf, Bsf, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bsf, Bsf, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bsr, Bsr, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bsr, Bsr, MGp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, bswap, Bswap, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bt, Bt, MGp, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, bt, Bt, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bt, Bt, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, bt, Bt, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, btc, Btc, MGp, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, btc, Btc, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, btc, Btc, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, btc, Btc, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, btr, Btr, MGp, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, btr, Btr, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, btr, Btr, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, btr, Btr, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bts, Bts, MGp, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, bts, Bts, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bts, Bts, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, bts, Bts, MMem, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, cbw, Cbw, AX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cdq, Cdq, EDX, EAX);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, cdqe, Cdqe, EAX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cqo, Cqo, RDX, RAX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cwd, Cwd, DX, AX);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, cwde, Cwde, EAX);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, call, Call, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, call, Call, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, call, Call, MLabel);
			MWASMJIT_INST_1i(AsmJit::X86::EmitterExplicit, call, Call, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, clc, Clc);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, cld, Cld);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, cli, Cli);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, clts, Clts);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, cmc, Cmc);
			MWASMJIT_INST_2c(AsmJit::X86::EmitterExplicit, cmov, Cmov, AsmJit::X86::Globals::Condition::ToCMOVCC, MGp, MGp);
			MWASMJIT_INST_2c(AsmJit::X86::EmitterExplicit, cmov, Cmov, AsmJit::X86::Globals::Condition::ToCMOVCC, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cmp, Cmp, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cmp, Cmp, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, cmp, Cmp, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cmp, Cmp, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, cmp, Cmp, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cmps, Cmps, DS_ZSI, ES_ZDI);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, cmpxchg, Cmpxchg, MGp, MGp, ZAX);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, cmpxchg, Cmpxchg, MMem, MGp, ZAX);
			MWASMJIT_INST_5x(AsmJit::X86::EmitterExplicit, cmpxchg16b, Cmpxchg16b, MMem, RDX, RAX, RCX, RBX);;
			MWASMJIT_INST_5x(AsmJit::X86::EmitterExplicit, cmpxchg8b, Cmpxchg8b, MMem, EDX, EAX, ECX, EBX);;
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, cpuid, Cpuid, EAX, EBX, ECX, EDX);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, daa, Daa, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, das, Das, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, dec, Dec, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, dec, Dec, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, div, Div, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, div, Div, MGp, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, div, Div, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, div, Div, MGp, MGp, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, emms, Emms);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, enter, Enter, MImm, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, hlt, Hlt);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, idiv, Idiv, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, idiv, Idiv, MGp, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, idiv, Idiv, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, idiv, Idiv, MGp, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, imul, Imul, MGp, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, in, In, ZAX, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, in, In, ZAX, DX);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, inc, Inc, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, inc, Inc, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ins, Ins, ES_ZDI, DX);
			MWASMJIT_INST_1i(AsmJit::X86::EmitterExplicit, int_, Int, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, int3, Int3);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, into, Into);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, invd, Invd);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, invlpg, Invlpg, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, invpcid, Invpcid, MGp, MMem);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, j, J, AsmJit::X86::Globals::Condition::ToJCC, MLabel);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, j, J, AsmJit::X86::Globals::Condition::ToJCC, MImm);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, j, J, AsmJit::X86::Globals::Condition::ToJCC, uint64_t);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, jecxz, Jecxz, MGp, MLabel);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, jecxz, Jecxz, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, jecxz, Jecxz, MGp, uint64_t);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, jmp, Jmp, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, jmp, Jmp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, jmp, Jmp, MLabel);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, jmp, Jmp, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, jmp, Jmp, uint64_t);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lahf, Lahf, AH);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lar, Lar, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lar, Lar, MGp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, ldmxcsr, Ldmxcsr, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lds, Lds, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lea, Lea, MGp, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, leave, Leave);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, les, Les, MGp, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, lfence, Lfence);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lfs, Lfs, MGp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lgdt, Lgdt, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lgs, Lgs, MGp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lidt, Lidt, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lldt, Lldt, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lldt, Lldt, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lmsw, Lmsw, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, lmsw, Lmsw, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lods, Lods, ZAX, DS_ZSI);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loop, Loop, ZCX, MLabel);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loop, Loop, ZCX, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loop, Loop, ZCX, uint64_t);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loope, Loope, ZCX, MLabel);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loope, Loope, ZCX, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loope, Loope, ZCX, uint64_t);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loopne, Loopne, ZCX, MLabel);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loopne, Loopne, ZCX, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, loopne, Loopne, ZCX, uint64_t);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lsl, Lsl, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lsl, Lsl, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lss, Lss, MGp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, ltr, Ltr, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, ltr, Ltr, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, mfence, Mfence);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, mov, Mov, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, mov, Mov, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MGp, MCReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MCReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MGp, MDReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MDReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MGp, MSReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MMem, MSReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MSReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mov, Mov, MSReg, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movnti, Movnti, MMem, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movs, Movs, ES_ZDI, DS_ZSI);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsx, Movsx, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsx, Movsx, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsxd, Movsxd, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsxd, Movsxd, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movzx, Movzx, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movzx, Movzx, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mul, Mul, AX, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mul, Mul, AX, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, mul, Mul, ZDX, ZAX, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, mul, Mul, ZDX, ZAX, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, neg, Neg, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, neg, Neg, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, nop, Nop);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, nop, Nop, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, nop, Nop, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, not_, Not, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, not_, Not, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, or_, Or, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, or_, Or, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, or_, Or, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, or_, Or, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, or_, Or, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, out, Out, MImm, ZAX);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, out, Out, DX, ZAX);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, outs, Outs, DX, DS_ZSI);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pause, Pause);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, pop, Pop, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, pop, Pop, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, pop, Pop, MSReg);;
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, popa, Popa);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, popad, Popad);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, popf, Popf);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, popfd, Popfd);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, popfq, Popfq);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetch, Prefetch, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetchnta, Prefetchnta, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetcht0, Prefetcht0, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetcht1, Prefetcht1, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetcht2, Prefetcht2, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetchw, Prefetchw, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, prefetchwt1, Prefetchwt1, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, push, Push, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, push, Push, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, push, Push, MSReg);
			MWASMJIT_INST_1i(AsmJit::X86::EmitterExplicit, push, Push, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pusha, Pusha);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pushad, Pushad);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pushf, Pushf);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pushfd, Pushfd);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pushfq, Pushfq);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcl, Rcl, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcl, Rcl, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, rcl, Rcl, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, rcl, Rcl, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcr, Rcr, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcr, Rcr, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, rcr, Rcr, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, rcr, Rcr, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, rdmsr, Rdmsr, EDX, EAX, ECX);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, rdpmc, Rdpmc, EDX, EAX, ECX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rdtsc, Rdtsc, EDX, EAX);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, rdtscp, Rdtscp, EDX, EAX, ECX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rol, Rol, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rol, Rol, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, rol, Rol, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, rol, Rol, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ror, Ror, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ror, Ror, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, ror, Ror, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, ror, Ror, MMem, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, rsm, Rsm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sbb, Sbb, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sbb, Sbb, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sbb, Sbb, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sbb, Sbb, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sbb, Sbb, MMem, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, sahf, Sahf, AH);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sal, Sal, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sal, Sal, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sal, Sal, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sal, Sal, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sar, Sar, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sar, Sar, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sar, Sar, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sar, Sar, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, scas, Scas, ZAX, ES_ZDI);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, set, Set, AsmJit::X86::Globals::Condition::ToSETCC, MGp);
			MWASMJIT_INST_1c(AsmJit::X86::EmitterExplicit, set, Set, AsmJit::X86::Globals::Condition::ToSETCC, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, sfence, Sfence);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, sgdt, Sgdt, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, shl, Shl, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, shl, Shl, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, shl, Shl, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, shl, Shl, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, shr, Shr, MGp, CL);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, shr, Shr, MMem, CL);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, shr, Shr, MGp, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, shr, Shr, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shld, Shld, MGp, MGp, CL);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shld, Shld, MMem, MGp, CL);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shld, Shld, MGp, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shld, Shld, MMem, MGp, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shrd, Shrd, MGp, MGp, CL);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shrd, Shrd, MMem, MGp, CL);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shrd, Shrd, MGp, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shrd, Shrd, MMem, MGp, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, sidt, Sidt, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, sldt, Sldt, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, sldt, Sldt, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, smsw, Smsw, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, smsw, Smsw, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, stc, Stc);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, std, Std);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, sti, Sti);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, stmxcsr, Stmxcsr, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, stos, Stos, ES_ZDI, ZAX);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, str, Str, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, str, Str, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sub, Sub, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sub, Sub, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sub, Sub, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sub, Sub, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, sub, Sub, MMem, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, swapgs, Swapgs);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, test, Test, MGp, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, test, Test, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, test, Test, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, test, Test, MMem, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, ud2, Ud2);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, verr, Verr, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, verr, Verr, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, verw, Verw, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, verw, Verw, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, wrmsr, Wrmsr, EDX, EAX, ECX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xadd, Xadd, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xadd, Xadd, MMem, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xchg, Xchg, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xchg, Xchg, MMem, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xchg, Xchg, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xor_, Xor, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xor_, Xor, MGp, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, xor_, Xor, MGp, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xor_, Xor, MMem, MGp);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, xor_, Xor, MMem, MImm);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adcx, Adcx, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adcx, Adcx, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adox, Adox, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, adox, Adox, MGp, MMem);






			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, andn, Andn, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, andn, Andn, MGp, MGp, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, bextr, Bextr, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, bextr, Bextr, MGp, MMem, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsi, Blsi, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsi, Blsi, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsmsk, Blsmsk, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsmsk, Blsmsk, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsr, Blsr, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsr, Blsr, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, tzcnt, Tzcnt, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, tzcnt, Tzcnt, MGp, MMem);






			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, bzhi, Bzhi, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, bzhi, Bzhi, MGp, MMem, MGp);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, mulx, Mulx, MGp, MGp, MGp, ZDX);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, mulx, Mulx, MGp, MGp, MMem, ZDX);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, pdep, Pdep, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, pdep, Pdep, MGp, MGp, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, pext, Pext, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, pext, Pext, MGp, MGp, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, rorx, Rorx, MGp, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, rorx, Rorx, MGp, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, sarx, Sarx, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, sarx, Sarx, MGp, MMem, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shlx, Shlx, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shlx, Shlx, MGp, MMem, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shrx, Shrx, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, shrx, Shrx, MGp, MMem, MGp);






			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, cldemote, Cldemote, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, clflush, Clflush, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, clflushopt, Clflushopt, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, clwb, Clwb, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, clzero, Clzero, DS_ZAX);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, wbnoinvd, Wbnoinvd);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, crc32, Crc32, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, crc32, Crc32, MGp, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, enqcmd, Enqcmd, MMem, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, enqcmds, Enqcmds, MMem, MMem);






			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, rdfsbase, Rdfsbase, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, rdgsbase, Rdgsbase, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, wrfsbase, Wrfsbase, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, wrgsbase, Wrgsbase, MGp);






			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fxrstor, Fxrstor, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fxrstor64, Fxrstor64, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fxsave, Fxsave, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fxsave64, Fxsave64, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, xgetbv, Xgetbv, EDX, EAX, ECX);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, xsetbv, Xsetbv, EDX, EAX, ECX);






			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, llwpcb, Llwpcb, MGp);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, lwpins, Lwpins, MGp, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, lwpins, Lwpins, MGp, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, lwpval, Lwpval, MGp, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, lwpval, Lwpval, MGp, MMem, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, slwpcb, Slwpcb, MGp);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lzcnt, Lzcnt, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lzcnt, Lzcnt, MGp, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movbe, Movbe, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movbe, Movbe, MMem, MGp);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdiri, Movdiri, MMem, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdir64b, Movdir64b, MMem, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndcl, Bndcl, MBnd, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndcl, Bndcl, MBnd, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndcn, Bndcn, MBnd, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndcn, Bndcn, MBnd, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndcu, Bndcu, MBnd, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndcu, Bndcu, MBnd, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndldx, Bndldx, MBnd, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndmk, Bndmk, MBnd, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndmov, Bndmov, MBnd, MBnd);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndmov, Bndmov, MBnd, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndmov, Bndmov, MMem, MBnd);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, bndstx, Bndstx, MMem, MBnd);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, popcnt, Popcnt, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, popcnt, Popcnt, MGp, MMem);






			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, rdrand, Rdrand, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, rdseed, Rdseed, MGp);






			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, xabort, Xabort);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, xbegin, Xbegin, MLabel);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, xbegin, Xbegin, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, xbegin, Xbegin, uint64_t);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, xend, Xend);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, xtest, Xtest);






			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, clac, Clac);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, stac, Stac);






			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, clgi, Clgi);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, invlpga, Invlpga, MGp, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, skinit, Skinit, MGp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, stgi, Stgi);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmload, Vmload, MGp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vmmcall, Vmmcall);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmrun, Vmrun, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmsave, Vmsave, MGp);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcfill, Blcfill, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcfill, Blcfill, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blci, Blci, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blci, Blci, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcic, Blcic, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcic, Blcic, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcmsk, Blcmsk, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcmsk, Blcmsk, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcs, Blcs, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blcs, Blcs, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsfill, Blsfill, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsfill, Blsfill, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsic, Blsic, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, blsic, Blsic, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, t1mskc, T1mskc, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, t1mskc, T1mskc, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, tzmsk, Tzmsk, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, tzmsk, Tzmsk, MGp, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, invept, Invept, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, invvpid, Invvpid, MGp, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vmcall, Vmcall);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmclear, Vmclear, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vmfunc, Vmfunc);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vmlaunch, Vmlaunch);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmptrld, Vmptrld, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmptrst, Vmptrst, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmread, Vmread, MMem, MGp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vmresume, Vmresume);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmwrite, Vmwrite, MGp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vmxon, Vmxon, MMem);






			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, getsec, Getsec);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, pcommit, Pcommit);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, rdpid, Rdpid, MGp);






			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, f2xm1, F2xm1);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fabs, Fabs);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, fadd, Fadd, MSt, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fadd, Fadd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, faddp, Faddp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, faddp, Faddp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fbld, Fbld, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fbstp, Fbstp, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fchs, Fchs);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fclex, Fclex);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovb, Fcmovb, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovbe, Fcmovbe, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmove, Fcmove, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovnb, Fcmovnb, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovnbe, Fcmovnbe, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovne, Fcmovne, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovnu, Fcmovnu, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcmovu, Fcmovu, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcom, Fcom, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fcom, Fcom);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcom, Fcom, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcomp, Fcomp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fcomp, Fcomp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcomp, Fcomp, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fcompp, Fcompp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcomi, Fcomi, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fcomip, Fcomip, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fcos, Fcos);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fdecstp, Fdecstp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, fdiv, Fdiv, MSt, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fdiv, Fdiv, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fdivp, Fdivp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fdivp, Fdivp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, fdivr, Fdivr, MSt, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fdivr, Fdivr, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fdivrp, Fdivrp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fdivrp, Fdivrp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, ffree, Ffree, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fiadd, Fiadd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, ficom, Ficom, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, ficomp, Ficomp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fidiv, Fidiv, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fidivr, Fidivr, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fild, Fild, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fimul, Fimul, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fincstp, Fincstp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, finit, Finit);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fisub, Fisub, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fisubr, Fisubr, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fninit, Fninit);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fist, Fist, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fistp, Fistp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fisttp, Fisttp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fld, Fld, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fld, Fld, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fld1, Fld1);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fldl2t, Fldl2t);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fldl2e, Fldl2e);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fldpi, Fldpi);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fldlg2, Fldlg2);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fldln2, Fldln2);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fldz, Fldz);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fldcw, Fldcw, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fldenv, Fldenv, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, fmul, Fmul, MSt, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fmul, Fmul, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fmulp, Fmulp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fmulp, Fmulp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fnclex, Fnclex);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fnop, Fnop);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fnsave, Fnsave, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fnstenv, Fnstenv, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fnstcw, Fnstcw, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fpatan, Fpatan);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fprem, Fprem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fprem1, Fprem1);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fptan, Fptan);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, frndint, Frndint);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, frstor, Frstor, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fsave, Fsave, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fscale, Fscale);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fsin, Fsin);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fsincos, Fsincos);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fsqrt, Fsqrt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fst, Fst, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fst, Fst, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fstp, Fstp, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fstp, Fstp, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fstcw, Fstcw, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fstenv, Fstenv, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, fsub, Fsub, MSt, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fsub, Fsub, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fsubp, Fsubp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fsubp, Fsubp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, fsubr, Fsubr, MSt, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fsubr, Fsubr, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fsubrp, Fsubrp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fsubrp, Fsubrp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, ftst, Ftst);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fucom, Fucom, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fucom, Fucom);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fucomi, Fucomi, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fucomip, Fucomip, MSt);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fucomp, Fucomp, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fucomp, Fucomp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fucompp, Fucompp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fwait, Fwait);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fxam, Fxam);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fxch, Fxch, MSt);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fxtract, Fxtract);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fyl2x, Fyl2x);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, fyl2xp1, Fyl2xp1);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fstsw, Fstsw, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fstsw, Fstsw, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fnstsw, Fnstsw, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, fnstsw, Fnstsw, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addpd, Addpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addpd, Addpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addps, Addps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addps, Addps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addsd, Addsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addsd, Addsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addss, Addss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addss, Addss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addsubpd, Addsubpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addsubpd, Addsubpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addsubps, Addsubps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, addsubps, Addsubps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andnpd, Andnpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andnpd, Andnpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andnps, Andnps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andnps, Andnps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andpd, Andpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andpd, Andpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andps, Andps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, andps, Andps, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, blendpd, Blendpd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, blendpd, Blendpd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, blendps, Blendps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, blendps, Blendps, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, blendvpd, Blendvpd, MXmm, MXmm, XMM0);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, blendvpd, Blendvpd, MXmm, MMem, XMM0);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, blendvps, Blendvps, MXmm, MXmm, XMM0);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, blendvps, Blendvps, MXmm, MMem, XMM0);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmppd, Cmppd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmppd, Cmppd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmpps, Cmpps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmpps, Cmpps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmpsd, Cmpsd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmpsd, Cmpsd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmpss, Cmpss, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, cmpss, Cmpss, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, comisd, Comisd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, comisd, Comisd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, comiss, Comiss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, comiss, Comiss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtdq2pd, Cvtdq2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtdq2pd, Cvtdq2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtdq2ps, Cvtdq2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtdq2ps, Cvtdq2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpd2dq, Cvtpd2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpd2dq, Cvtpd2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpd2pi, Cvtpd2pi, MMm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpd2pi, Cvtpd2pi, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpd2ps, Cvtpd2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpd2ps, Cvtpd2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpi2pd, Cvtpi2pd, MXmm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpi2pd, Cvtpi2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpi2ps, Cvtpi2ps, MXmm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtpi2ps, Cvtpi2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtps2dq, Cvtps2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtps2dq, Cvtps2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtps2pd, Cvtps2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtps2pd, Cvtps2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtps2pi, Cvtps2pi, MMm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtps2pi, Cvtps2pi, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsd2si, Cvtsd2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsd2si, Cvtsd2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsd2ss, Cvtsd2ss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsd2ss, Cvtsd2ss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsi2sd, Cvtsi2sd, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsi2sd, Cvtsi2sd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsi2ss, Cvtsi2ss, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtsi2ss, Cvtsi2ss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtss2sd, Cvtss2sd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtss2sd, Cvtss2sd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtss2si, Cvtss2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvtss2si, Cvtss2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttpd2pi, Cvttpd2pi, MMm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttpd2pi, Cvttpd2pi, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttpd2dq, Cvttpd2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttpd2dq, Cvttpd2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttps2dq, Cvttps2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttps2dq, Cvttps2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttps2pi, Cvttps2pi, MMm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttps2pi, Cvttps2pi, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttsd2si, Cvttsd2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttsd2si, Cvttsd2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttss2si, Cvttss2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, cvttss2si, Cvttss2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divpd, Divpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divpd, Divpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divps, Divps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divps, Divps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divsd, Divsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divsd, Divsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divss, Divss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, divss, Divss, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, dppd, Dppd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, dppd, Dppd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, dpps, Dpps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, dpps, Dpps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, extractps, Extractps, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, extractps, Extractps, MMem, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, extrq, Extrq, MXmm, MXmm);
			MWASMJIT_INST_3ii(AsmJit::X86::EmitterExplicit, extrq, Extrq, MXmm, MImm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, gf2p8affineinvqb, Gf2p8affineinvqb, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, gf2p8affineinvqb, Gf2p8affineinvqb, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, gf2p8affineqb, Gf2p8affineqb, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, gf2p8affineqb, Gf2p8affineqb, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, gf2p8mulb, Gf2p8mulb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, gf2p8mulb, Gf2p8mulb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, haddpd, Haddpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, haddpd, Haddpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, haddps, Haddps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, haddps, Haddps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, hsubpd, Hsubpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, hsubpd, Hsubpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, hsubps, Hsubps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, hsubps, Hsubps, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, insertps, Insertps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, insertps, Insertps, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, insertq, Insertq, MXmm, MXmm);
			MWASMJIT_INST_4ii(AsmJit::X86::EmitterExplicit, insertq, Insertq, MXmm, MXmm, MImm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, lddqu, Lddqu, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, maskmovq, Maskmovq, MMm, MMm, DS_ZDI);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, maskmovdqu, Maskmovdqu, MXmm, MXmm, DS_ZDI);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxpd, Maxpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxpd, Maxpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxps, Maxps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxps, Maxps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxsd, Maxsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxsd, Maxsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxss, Maxss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, maxss, Maxss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minpd, Minpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minpd, Minpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minps, Minps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minps, Minps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minsd, Minsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minsd, Minsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minss, Minss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, minss, Minss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movapd, Movapd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movapd, Movapd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movapd, Movapd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movaps, Movaps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movaps, Movaps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movaps, Movaps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MMem, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MGp, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MMm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movd, Movd, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movddup, Movddup, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movddup, Movddup, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdq2q, Movdq2q, MMm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdqa, Movdqa, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdqa, Movdqa, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdqa, Movdqa, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdqu, Movdqu, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdqu, Movdqu, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movdqu, Movdqu, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movhlps, Movhlps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movhpd, Movhpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movhpd, Movhpd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movhps, Movhps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movhps, Movhps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movlhps, Movlhps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movlpd, Movlpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movlpd, Movlpd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movlps, Movlps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movlps, Movlps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movmskps, Movmskps, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movmskpd, Movmskpd, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntdq, Movntdq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntdqa, Movntdqa, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntpd, Movntpd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntps, Movntps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntsd, Movntsd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntss, Movntss, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movntq, Movntq, MMem, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MMem, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MGp, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MMm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq, Movq, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movq2dq, Movq2dq, MXmm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsd, Movsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsd, Movsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsd, Movsd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movshdup, Movshdup, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movshdup, Movshdup, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsldup, Movsldup, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movsldup, Movsldup, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movss, Movss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movss, Movss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movss, Movss, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movupd, Movupd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movupd, Movupd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movupd, Movupd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movups, Movups, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movups, Movups, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, movups, Movups, MMem, MXmm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, mpsadbw, Mpsadbw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, mpsadbw, Mpsadbw, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulpd, Mulpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulpd, Mulpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulps, Mulps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulps, Mulps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulsd, Mulsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulsd, Mulsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulss, Mulss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, mulss, Mulss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, orpd, Orpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, orpd, Orpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, orps, Orps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, orps, Orps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packssdw, Packssdw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packssdw, Packssdw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packssdw, Packssdw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packssdw, Packssdw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packsswb, Packsswb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packsswb, Packsswb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packsswb, Packsswb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packsswb, Packsswb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packusdw, Packusdw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packusdw, Packusdw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packuswb, Packuswb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packuswb, Packuswb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packuswb, Packuswb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, packuswb, Packuswb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsb, Pabsb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsb, Pabsb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsb, Pabsb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsb, Pabsb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsd, Pabsd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsd, Pabsd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsd, Pabsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsd, Pabsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsw, Pabsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsw, Pabsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsw, Pabsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pabsw, Pabsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddb, Paddb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddb, Paddb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddb, Paddb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddb, Paddb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddd, Paddd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddd, Paddd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddd, Paddd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddd, Paddd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddq, Paddq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddq, Paddq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddq, Paddq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddq, Paddq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsb, Paddsb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsb, Paddsb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsb, Paddsb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsb, Paddsb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsw, Paddsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsw, Paddsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsw, Paddsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddsw, Paddsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusb, Paddusb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusb, Paddusb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusb, Paddusb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusb, Paddusb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusw, Paddusw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusw, Paddusw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusw, Paddusw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddusw, Paddusw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddw, Paddw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddw, Paddw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddw, Paddw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, paddw, Paddw, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, palignr, Palignr, MMm, MMm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, palignr, Palignr, MMm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, palignr, Palignr, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, palignr, Palignr, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pand, Pand, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pand, Pand, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pand, Pand, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pand, Pand, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pandn, Pandn, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pandn, Pandn, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pandn, Pandn, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pandn, Pandn, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgb, Pavgb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgb, Pavgb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgb, Pavgb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgb, Pavgb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgw, Pavgw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgw, Pavgw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgw, Pavgw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgw, Pavgw, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, pblendvb, Pblendvb, MXmm, MXmm, XMM0);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, pblendvb, Pblendvb, MXmm, MMem, XMM0);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pblendw, Pblendw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pblendw, Pblendw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pclmulqdq, Pclmulqdq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pclmulqdq, Pclmulqdq, MXmm, MMem, MImm);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, pcmpestri, Pcmpestri, MXmm, MXmm, MImm, ECX, EAX, EDX);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, pcmpestri, Pcmpestri, MXmm, MMem, MImm, ECX, EAX, EDX);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, pcmpestrm, Pcmpestrm, MXmm, MXmm, MImm, XMM0, EAX, EDX);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, pcmpestrm, Pcmpestrm, MXmm, MMem, MImm, XMM0, EAX, EDX);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqb, Pcmpeqb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqb, Pcmpeqb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqb, Pcmpeqb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqb, Pcmpeqb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqd, Pcmpeqd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqd, Pcmpeqd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqd, Pcmpeqd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqd, Pcmpeqd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqq, Pcmpeqq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqq, Pcmpeqq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqw, Pcmpeqw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqw, Pcmpeqw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqw, Pcmpeqw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpeqw, Pcmpeqw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtb, Pcmpgtb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtb, Pcmpgtb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtb, Pcmpgtb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtb, Pcmpgtb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtd, Pcmpgtd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtd, Pcmpgtd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtd, Pcmpgtd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtd, Pcmpgtd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtq, Pcmpgtq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtq, Pcmpgtq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtw, Pcmpgtw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtw, Pcmpgtw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtw, Pcmpgtw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pcmpgtw, Pcmpgtw, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, pcmpistri, Pcmpistri, MXmm, MXmm, MImm, ECX);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, pcmpistri, Pcmpistri, MXmm, MMem, MImm, ECX);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, pcmpistrm, Pcmpistrm, MXmm, MXmm, MImm, XMM0);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, pcmpistrm, Pcmpistrm, MXmm, MMem, MImm, XMM0);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrb, Pextrb, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrb, Pextrb, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrd, Pextrd, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrd, Pextrd, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrq, Pextrq, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrq, Pextrq, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrw, Pextrw, MGp, MMm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrw, Pextrw, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pextrw, Pextrw, MMem, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddd, Phaddd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddd, Phaddd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddd, Phaddd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddd, Phaddd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddsw, Phaddsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddsw, Phaddsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddsw, Phaddsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddsw, Phaddsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddw, Phaddw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddw, Phaddw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddw, Phaddw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phaddw, Phaddw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phminposuw, Phminposuw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phminposuw, Phminposuw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubd, Phsubd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubd, Phsubd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubd, Phsubd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubd, Phsubd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubsw, Phsubsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubsw, Phsubsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubsw, Phsubsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubsw, Phsubsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubw, Phsubw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubw, Phsubw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubw, Phsubw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, phsubw, Phsubw, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrb, Pinsrb, MXmm, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrb, Pinsrb, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrd, Pinsrd, MXmm, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrd, Pinsrd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrq, Pinsrq, MXmm, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrq, Pinsrq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrw, Pinsrw, MMm, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrw, Pinsrw, MMm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrw, Pinsrw, MXmm, MGp, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pinsrw, Pinsrw, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddubsw, Pmaddubsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddubsw, Pmaddubsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddubsw, Pmaddubsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddubsw, Pmaddubsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddwd, Pmaddwd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddwd, Pmaddwd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddwd, Pmaddwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaddwd, Pmaddwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsb, Pmaxsb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsb, Pmaxsb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsd, Pmaxsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsd, Pmaxsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsw, Pmaxsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsw, Pmaxsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsw, Pmaxsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxsw, Pmaxsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxub, Pmaxub, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxub, Pmaxub, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxub, Pmaxub, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxub, Pmaxub, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxud, Pmaxud, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxud, Pmaxud, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxuw, Pmaxuw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmaxuw, Pmaxuw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsb, Pminsb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsb, Pminsb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsd, Pminsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsd, Pminsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsw, Pminsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsw, Pminsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsw, Pminsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminsw, Pminsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminub, Pminub, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminub, Pminub, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminub, Pminub, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminub, Pminub, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminud, Pminud, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminud, Pminud, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminuw, Pminuw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pminuw, Pminuw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovmskb, Pmovmskb, MGp, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovmskb, Pmovmskb, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxbd, Pmovsxbd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxbd, Pmovsxbd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxbq, Pmovsxbq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxbq, Pmovsxbq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxbw, Pmovsxbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxbw, Pmovsxbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxdq, Pmovsxdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxdq, Pmovsxdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxwd, Pmovsxwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxwd, Pmovsxwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxwq, Pmovsxwq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovsxwq, Pmovsxwq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxbd, Pmovzxbd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxbd, Pmovzxbd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxbq, Pmovzxbq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxbq, Pmovzxbq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxbw, Pmovzxbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxbw, Pmovzxbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxdq, Pmovzxdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxdq, Pmovzxdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxwd, Pmovzxwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxwd, Pmovzxwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxwq, Pmovzxwq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmovzxwq, Pmovzxwq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmuldq, Pmuldq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmuldq, Pmuldq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhrsw, Pmulhrsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhrsw, Pmulhrsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhrsw, Pmulhrsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhrsw, Pmulhrsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhw, Pmulhw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhw, Pmulhw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhw, Pmulhw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhw, Pmulhw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhuw, Pmulhuw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhuw, Pmulhuw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhuw, Pmulhuw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhuw, Pmulhuw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulld, Pmulld, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulld, Pmulld, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmullw, Pmullw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmullw, Pmullw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmullw, Pmullw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmullw, Pmullw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmuludq, Pmuludq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmuludq, Pmuludq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmuludq, Pmuludq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmuludq, Pmuludq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, por, Por, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, por, Por, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, por, Por, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, por, Por, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psadbw, Psadbw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psadbw, Psadbw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psadbw, Psadbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psadbw, Psadbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pslld, Pslld, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pslld, Pslld, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, pslld, Pslld, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pslld, Pslld, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pslld, Pslld, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, pslld, Pslld, MXmm, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, pslldq, Pslldq, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllq, Psllq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllq, Psllq, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psllq, Psllq, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllq, Psllq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllq, Psllq, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psllq, Psllq, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllw, Psllw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllw, Psllw, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psllw, Psllw, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllw, Psllw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psllw, Psllw, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psllw, Psllw, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrad, Psrad, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrad, Psrad, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrad, Psrad, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrad, Psrad, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrad, Psrad, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrad, Psrad, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psraw, Psraw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psraw, Psraw, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psraw, Psraw, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psraw, Psraw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psraw, Psraw, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psraw, Psraw, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pshufb, Pshufb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pshufb, Pshufb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pshufb, Pshufb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pshufb, Pshufb, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshufd, Pshufd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshufd, Pshufd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshufhw, Pshufhw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshufhw, Pshufhw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshuflw, Pshuflw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshuflw, Pshuflw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshufw, Pshufw, MMm, MMm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, pshufw, Pshufw, MMm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignb, Psignb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignb, Psignb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignb, Psignb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignb, Psignb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignd, Psignd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignd, Psignd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignd, Psignd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignd, Psignd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignw, Psignw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignw, Psignw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignw, Psignw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psignw, Psignw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrld, Psrld, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrld, Psrld, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrld, Psrld, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrld, Psrld, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrld, Psrld, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrld, Psrld, MXmm, MImm);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrldq, Psrldq, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlq, Psrlq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlq, Psrlq, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrlq, Psrlq, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlq, Psrlq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlq, Psrlq, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrlq, Psrlq, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlw, Psrlw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlw, Psrlw, MMm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrlw, Psrlw, MMm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlw, Psrlw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psrlw, Psrlw, MXmm, MMem);
			MWASMJIT_INST_2i(AsmJit::X86::EmitterExplicit, psrlw, Psrlw, MXmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubb, Psubb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubb, Psubb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubb, Psubb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubb, Psubb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubd, Psubd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubd, Psubd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubd, Psubd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubd, Psubd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubq, Psubq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubq, Psubq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubq, Psubq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubq, Psubq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsb, Psubsb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsb, Psubsb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsb, Psubsb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsb, Psubsb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsw, Psubsw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsw, Psubsw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsw, Psubsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubsw, Psubsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusb, Psubusb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusb, Psubusb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusb, Psubusb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusb, Psubusb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusw, Psubusw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusw, Psubusw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusw, Psubusw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubusw, Psubusw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubw, Psubw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubw, Psubw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubw, Psubw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, psubw, Psubw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ptest, Ptest, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ptest, Ptest, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhbw, Punpckhbw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhbw, Punpckhbw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhbw, Punpckhbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhbw, Punpckhbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhdq, Punpckhdq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhdq, Punpckhdq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhdq, Punpckhdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhdq, Punpckhdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhqdq, Punpckhqdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhqdq, Punpckhqdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhwd, Punpckhwd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhwd, Punpckhwd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhwd, Punpckhwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckhwd, Punpckhwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklbw, Punpcklbw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklbw, Punpcklbw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklbw, Punpcklbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklbw, Punpcklbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckldq, Punpckldq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckldq, Punpckldq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckldq, Punpckldq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpckldq, Punpckldq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklqdq, Punpcklqdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklqdq, Punpcklqdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklwd, Punpcklwd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklwd, Punpcklwd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklwd, Punpcklwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, punpcklwd, Punpcklwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pxor, Pxor, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pxor, Pxor, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pxor, Pxor, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pxor, Pxor, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcpps, Rcpps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcpps, Rcpps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcpss, Rcpss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rcpss, Rcpss, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundpd, Roundpd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundpd, Roundpd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundps, Roundps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundps, Roundps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundsd, Roundsd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundsd, Roundsd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundss, Roundss, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, roundss, Roundss, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rsqrtps, Rsqrtps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rsqrtps, Rsqrtps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rsqrtss, Rsqrtss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, rsqrtss, Rsqrtss, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shufpd, Shufpd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shufpd, Shufpd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shufps, Shufps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, shufps, Shufps, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtpd, Sqrtpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtpd, Sqrtpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtps, Sqrtps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtps, Sqrtps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtsd, Sqrtsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtsd, Sqrtsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtss, Sqrtss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sqrtss, Sqrtss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subpd, Subpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subpd, Subpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subps, Subps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subps, Subps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subsd, Subsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subsd, Subsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subss, Subss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, subss, Subss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ucomisd, Ucomisd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ucomisd, Ucomisd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ucomiss, Ucomiss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ucomiss, Ucomiss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpckhpd, Unpckhpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpckhpd, Unpckhpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpckhps, Unpckhps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpckhps, Unpckhps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpcklpd, Unpcklpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpcklpd, Unpcklpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpcklps, Unpcklps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, unpcklps, Unpcklps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xorpd, Xorpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xorpd, Xorpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xorps, Xorps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, xorps, Xorps, MXmm, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgusb, Pavgusb, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pavgusb, Pavgusb, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pf2id, Pf2id, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pf2id, Pf2id, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pf2iw, Pf2iw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pf2iw, Pf2iw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfacc, Pfacc, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfacc, Pfacc, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfadd, Pfadd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfadd, Pfadd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfcmpeq, Pfcmpeq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfcmpeq, Pfcmpeq, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfcmpge, Pfcmpge, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfcmpge, Pfcmpge, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfcmpgt, Pfcmpgt, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfcmpgt, Pfcmpgt, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfmax, Pfmax, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfmax, Pfmax, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfmin, Pfmin, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfmin, Pfmin, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfmul, Pfmul, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfmul, Pfmul, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfnacc, Pfnacc, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfnacc, Pfnacc, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfpnacc, Pfpnacc, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfpnacc, Pfpnacc, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcp, Pfrcp, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcp, Pfrcp, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcpit1, Pfrcpit1, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcpit1, Pfrcpit1, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcpit2, Pfrcpit2, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcpit2, Pfrcpit2, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcpv, Pfrcpv, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrcpv, Pfrcpv, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrsqit1, Pfrsqit1, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrsqit1, Pfrsqit1, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrsqrt, Pfrsqrt, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrsqrt, Pfrsqrt, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrsqrtv, Pfrsqrtv, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfrsqrtv, Pfrsqrtv, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfsub, Pfsub, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfsub, Pfsub, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfsubr, Pfsubr, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pfsubr, Pfsubr, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pi2fd, Pi2fd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pi2fd, Pi2fd, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pi2fw, Pi2fw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pi2fw, Pi2fw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhrw, Pmulhrw, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pmulhrw, Pmulhrw, MMm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pswapd, Pswapd, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, pswapd, Pswapd, MMm, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, femms, Femms);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesdec, Aesdec, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesdec, Aesdec, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesdeclast, Aesdeclast, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesdeclast, Aesdeclast, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesenc, Aesenc, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesenc, Aesenc, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesenclast, Aesenclast, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesenclast, Aesenclast, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesimc, Aesimc, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, aesimc, Aesimc, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, aeskeygenassist, Aeskeygenassist, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, aeskeygenassist, Aeskeygenassist, MXmm, MMem, MImm);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha1msg1, Sha1msg1, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha1msg1, Sha1msg1, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha1msg2, Sha1msg2, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha1msg2, Sha1msg2, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha1nexte, Sha1nexte, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha1nexte, Sha1nexte, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, sha1rnds4, Sha1rnds4, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, sha1rnds4, Sha1rnds4, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha256msg1, Sha256msg1, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha256msg1, Sha256msg1, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha256msg2, Sha256msg2, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, sha256msg2, Sha256msg2, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, sha256rnds2, Sha256rnds2, MXmm, MXmm, XMM0);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, sha256rnds2, Sha256rnds2, MXmm, MMem, XMM0);






			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kaddb, Kaddb, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kaddd, Kaddd, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kaddq, Kaddq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kaddw, Kaddw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandb, Kandb, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandd, Kandd, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandnb, Kandnb, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandnd, Kandnd, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandnq, Kandnq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandnw, Kandnw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandq, Kandq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kandw, Kandw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovb, Kmovb, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovb, Kmovb, MKReg, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovb, Kmovb, MKReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovb, Kmovb, MMem, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovb, Kmovb, MGp, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovd, Kmovd, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovd, Kmovd, MKReg, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovd, Kmovd, MKReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovd, Kmovd, MMem, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovd, Kmovd, MGp, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovq, Kmovq, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovq, Kmovq, MKReg, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovq, Kmovq, MKReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovq, Kmovq, MMem, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovq, Kmovq, MGp, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovw, Kmovw, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovw, Kmovw, MKReg, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovw, Kmovw, MKReg, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovw, Kmovw, MMem, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kmovw, Kmovw, MGp, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, knotb, Knotb, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, knotd, Knotd, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, knotq, Knotq, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, knotw, Knotw, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, korb, Korb, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kord, Kord, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, korq, Korq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kortestb, Kortestb, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kortestd, Kortestd, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kortestq, Kortestq, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, kortestw, Kortestw, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, korw, Korw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftlb, Kshiftlb, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftld, Kshiftld, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftlq, Kshiftlq, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftlw, Kshiftlw, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftrb, Kshiftrb, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftrd, Kshiftrd, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftrq, Kshiftrq, MKReg, MKReg, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, kshiftrw, Kshiftrw, MKReg, MKReg, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ktestb, Ktestb, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ktestd, Ktestd, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ktestq, Ktestq, MKReg, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, ktestw, Ktestw, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kunpckbw, Kunpckbw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kunpckdq, Kunpckdq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kunpckwd, Kunpckwd, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxnorb, Kxnorb, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxnord, Kxnord, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxnorq, Kxnorq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxnorw, Kxnorw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxorb, Kxorb, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxord, Kxord, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxorq, Kxorq, MKReg, MKReg, MKReg);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, kxorw, Kxorw, MKReg, MKReg, MKReg);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, v4fmaddps, V4fmaddps, MZmm, MZmm, MZmm, MZmm, MZmm, MMem);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, v4fmaddss, V4fmaddss, MXmm, MXmm, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, v4fnmaddps, V4fnmaddps, MZmm, MZmm, MZmm, MZmm, MZmm, MMem);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, v4fnmaddss, V4fnmaddss, MXmm, MXmm, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddpd, Vaddpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddpd, Vaddpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddpd, Vaddpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddpd, Vaddpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddpd, Vaddpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddpd, Vaddpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddps, Vaddps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddps, Vaddps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddps, Vaddps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddps, Vaddps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddps, Vaddps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddps, Vaddps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsd, Vaddsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsd, Vaddsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddss, Vaddss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddss, Vaddss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubpd, Vaddsubpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubpd, Vaddsubpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubpd, Vaddsubpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubpd, Vaddsubpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubps, Vaddsubps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubps, Vaddsubps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubps, Vaddsubps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaddsubps, Vaddsubps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdec, Vaesdec, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdec, Vaesdec, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdec, Vaesdec, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdec, Vaesdec, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdec, Vaesdec, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdec, Vaesdec, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdeclast, Vaesdeclast, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdeclast, Vaesdeclast, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdeclast, Vaesdeclast, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdeclast, Vaesdeclast, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdeclast, Vaesdeclast, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesdeclast, Vaesdeclast, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenc, Vaesenc, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenc, Vaesenc, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenc, Vaesenc, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenc, Vaesenc, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenc, Vaesenc, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenc, Vaesenc, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenclast, Vaesenclast, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenclast, Vaesenclast, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenclast, Vaesenclast, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenclast, Vaesenclast, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenclast, Vaesenclast, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vaesenclast, Vaesenclast, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vaesimc, Vaesimc, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vaesimc, Vaesimc, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vaeskeygenassist, Vaeskeygenassist, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vaeskeygenassist, Vaeskeygenassist, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignd, Valignd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignq, Valignq, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignq, Valignq, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignq, Valignq, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignq, Valignq, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignq, Valignq, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, valignq, Valignq, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnpd, Vandnpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnpd, Vandnpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnpd, Vandnpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnpd, Vandnpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnpd, Vandnpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnpd, Vandnpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnps, Vandnps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnps, Vandnps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnps, Vandnps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnps, Vandnps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnps, Vandnps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandnps, Vandnps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandpd, Vandpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandpd, Vandpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandpd, Vandpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandpd, Vandpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandpd, Vandpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandpd, Vandpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandps, Vandps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandps, Vandps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandps, Vandps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandps, Vandps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandps, Vandps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vandps, Vandps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmb, Vblendmb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmb, Vblendmb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmb, Vblendmb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmb, Vblendmb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmb, Vblendmb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmb, Vblendmb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmd, Vblendmd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmd, Vblendmd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmd, Vblendmd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmd, Vblendmd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmd, Vblendmd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmd, Vblendmd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmpd, Vblendmpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmpd, Vblendmpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmpd, Vblendmpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmpd, Vblendmpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmpd, Vblendmpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmpd, Vblendmpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmps, Vblendmps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmps, Vblendmps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmps, Vblendmps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmps, Vblendmps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmps, Vblendmps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmps, Vblendmps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmq, Vblendmq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmq, Vblendmq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmq, Vblendmq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmq, Vblendmq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmq, Vblendmq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmq, Vblendmq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmw, Vblendmw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmw, Vblendmw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmw, Vblendmw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmw, Vblendmw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmw, Vblendmw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vblendmw, Vblendmw, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendpd, Vblendpd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendpd, Vblendpd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendpd, Vblendpd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendpd, Vblendpd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendps, Vblendps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendps, Vblendps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendps, Vblendps, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vblendps, Vblendps, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvpd, Vblendvpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvpd, Vblendvpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvpd, Vblendvpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvpd, Vblendvpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvps, Vblendvps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvps, Vblendvps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvps, Vblendvps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vblendvps, Vblendvps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf128, Vbroadcastf128, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x2, Vbroadcastf32x2, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x2, Vbroadcastf32x2, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x2, Vbroadcastf32x2, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x2, Vbroadcastf32x2, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x4, Vbroadcastf32x4, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x4, Vbroadcastf32x4, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf32x8, Vbroadcastf32x8, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf64x2, Vbroadcastf64x2, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf64x2, Vbroadcastf64x2, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastf64x4, Vbroadcastf64x4, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti128, Vbroadcasti128, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x2, Vbroadcasti32x2, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x2, Vbroadcasti32x2, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x2, Vbroadcasti32x2, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x2, Vbroadcasti32x2, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x2, Vbroadcasti32x2, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x2, Vbroadcasti32x2, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x4, Vbroadcasti32x4, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x4, Vbroadcasti32x4, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti32x8, Vbroadcasti32x8, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti64x2, Vbroadcasti64x2, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti64x2, Vbroadcasti64x2, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti64x2, Vbroadcasti64x2, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti64x2, Vbroadcasti64x2, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti64x4, Vbroadcasti64x4, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcasti64x4, Vbroadcasti64x4, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastsd, Vbroadcastsd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastsd, Vbroadcastsd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastsd, Vbroadcastsd, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastsd, Vbroadcastsd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastss, Vbroadcastss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastss, Vbroadcastss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastss, Vbroadcastss, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastss, Vbroadcastss, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastss, Vbroadcastss, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vbroadcastss, Vbroadcastss, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmppd, Vcmppd, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpps, Vcmpps, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpsd, Vcmpsd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpsd, Vcmpsd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpsd, Vcmpsd, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpsd, Vcmpsd, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpss, Vcmpss, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpss, Vcmpss, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpss, Vcmpss, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vcmpss, Vcmpss, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcomisd, Vcomisd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcomisd, Vcomisd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcomiss, Vcomiss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcomiss, Vcomiss, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompresspd, Vcompresspd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompresspd, Vcompresspd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompresspd, Vcompresspd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompresspd, Vcompresspd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompresspd, Vcompresspd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompresspd, Vcompresspd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompressps, Vcompressps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompressps, Vcompressps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompressps, Vcompressps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompressps, Vcompressps, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompressps, Vcompressps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcompressps, Vcompressps, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2pd, Vcvtdq2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2pd, Vcvtdq2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2pd, Vcvtdq2pd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2pd, Vcvtdq2pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2pd, Vcvtdq2pd, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2pd, Vcvtdq2pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2ps, Vcvtdq2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2ps, Vcvtdq2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2ps, Vcvtdq2ps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2ps, Vcvtdq2ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2ps, Vcvtdq2ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtdq2ps, Vcvtdq2ps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtne2ps2bf16, Vcvtne2ps2bf16, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtne2ps2bf16, Vcvtne2ps2bf16, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtne2ps2bf16, Vcvtne2ps2bf16, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtne2ps2bf16, Vcvtne2ps2bf16, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtne2ps2bf16, Vcvtne2ps2bf16, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtne2ps2bf16, Vcvtne2ps2bf16, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtneps2bf16, Vcvtneps2bf16, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtneps2bf16, Vcvtneps2bf16, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtneps2bf16, Vcvtneps2bf16, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtneps2bf16, Vcvtneps2bf16, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtneps2bf16, Vcvtneps2bf16, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2dq, Vcvtpd2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2dq, Vcvtpd2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2dq, Vcvtpd2dq, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2dq, Vcvtpd2dq, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2dq, Vcvtpd2dq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2ps, Vcvtpd2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2ps, Vcvtpd2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2ps, Vcvtpd2ps, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2ps, Vcvtpd2ps, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2ps, Vcvtpd2ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2qq, Vcvtpd2qq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2qq, Vcvtpd2qq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2qq, Vcvtpd2qq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2qq, Vcvtpd2qq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2qq, Vcvtpd2qq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2qq, Vcvtpd2qq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2udq, Vcvtpd2udq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2udq, Vcvtpd2udq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2udq, Vcvtpd2udq, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2udq, Vcvtpd2udq, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2udq, Vcvtpd2udq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2uqq, Vcvtpd2uqq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2uqq, Vcvtpd2uqq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2uqq, Vcvtpd2uqq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2uqq, Vcvtpd2uqq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2uqq, Vcvtpd2uqq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtpd2uqq, Vcvtpd2uqq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtph2ps, Vcvtph2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtph2ps, Vcvtph2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtph2ps, Vcvtph2ps, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtph2ps, Vcvtph2ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtph2ps, Vcvtph2ps, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtph2ps, Vcvtph2ps, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2dq, Vcvtps2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2dq, Vcvtps2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2dq, Vcvtps2dq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2dq, Vcvtps2dq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2dq, Vcvtps2dq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2dq, Vcvtps2dq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2pd, Vcvtps2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2pd, Vcvtps2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2pd, Vcvtps2pd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2pd, Vcvtps2pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2pd, Vcvtps2pd, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2pd, Vcvtps2pd, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vcvtps2ph, Vcvtps2ph, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vcvtps2ph, Vcvtps2ph, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vcvtps2ph, Vcvtps2ph, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vcvtps2ph, Vcvtps2ph, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vcvtps2ph, Vcvtps2ph, MYmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vcvtps2ph, Vcvtps2ph, MMem, MZmm, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2qq, Vcvtps2qq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2qq, Vcvtps2qq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2qq, Vcvtps2qq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2qq, Vcvtps2qq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2qq, Vcvtps2qq, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2qq, Vcvtps2qq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2udq, Vcvtps2udq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2udq, Vcvtps2udq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2udq, Vcvtps2udq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2udq, Vcvtps2udq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2udq, Vcvtps2udq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2udq, Vcvtps2udq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2uqq, Vcvtps2uqq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2uqq, Vcvtps2uqq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2uqq, Vcvtps2uqq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2uqq, Vcvtps2uqq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2uqq, Vcvtps2uqq, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtps2uqq, Vcvtps2uqq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2pd, Vcvtqq2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2pd, Vcvtqq2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2pd, Vcvtqq2pd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2pd, Vcvtqq2pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2pd, Vcvtqq2pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2pd, Vcvtqq2pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2ps, Vcvtqq2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2ps, Vcvtqq2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2ps, Vcvtqq2ps, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2ps, Vcvtqq2ps, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtqq2ps, Vcvtqq2ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtsd2si, Vcvtsd2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtsd2si, Vcvtsd2si, MGp, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtsd2ss, Vcvtsd2ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtsd2ss, Vcvtsd2ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtsd2usi, Vcvtsd2usi, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtsd2usi, Vcvtsd2usi, MGp, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtsi2sd, Vcvtsi2sd, MXmm, MXmm, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtsi2sd, Vcvtsi2sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtsi2ss, Vcvtsi2ss, MXmm, MXmm, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtsi2ss, Vcvtsi2ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtss2sd, Vcvtss2sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtss2sd, Vcvtss2sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtss2si, Vcvtss2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtss2si, Vcvtss2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtss2usi, Vcvtss2usi, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtss2usi, Vcvtss2usi, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2dq, Vcvttpd2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2dq, Vcvttpd2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2dq, Vcvttpd2dq, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2dq, Vcvttpd2dq, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2dq, Vcvttpd2dq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2qq, Vcvttpd2qq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2qq, Vcvttpd2qq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2qq, Vcvttpd2qq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2qq, Vcvttpd2qq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2qq, Vcvttpd2qq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2qq, Vcvttpd2qq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2udq, Vcvttpd2udq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2udq, Vcvttpd2udq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2udq, Vcvttpd2udq, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2udq, Vcvttpd2udq, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2udq, Vcvttpd2udq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2uqq, Vcvttpd2uqq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2uqq, Vcvttpd2uqq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2uqq, Vcvttpd2uqq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2uqq, Vcvttpd2uqq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2uqq, Vcvttpd2uqq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttpd2uqq, Vcvttpd2uqq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2dq, Vcvttps2dq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2dq, Vcvttps2dq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2dq, Vcvttps2dq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2dq, Vcvttps2dq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2dq, Vcvttps2dq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2dq, Vcvttps2dq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2qq, Vcvttps2qq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2qq, Vcvttps2qq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2qq, Vcvttps2qq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2qq, Vcvttps2qq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2qq, Vcvttps2qq, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2qq, Vcvttps2qq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2udq, Vcvttps2udq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2udq, Vcvttps2udq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2udq, Vcvttps2udq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2udq, Vcvttps2udq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2udq, Vcvttps2udq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2udq, Vcvttps2udq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2uqq, Vcvttps2uqq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2uqq, Vcvttps2uqq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2uqq, Vcvttps2uqq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2uqq, Vcvttps2uqq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2uqq, Vcvttps2uqq, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttps2uqq, Vcvttps2uqq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttsd2si, Vcvttsd2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttsd2si, Vcvttsd2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttsd2usi, Vcvttsd2usi, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttsd2usi, Vcvttsd2usi, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttss2si, Vcvttss2si, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttss2si, Vcvttss2si, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttss2usi, Vcvttss2usi, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvttss2usi, Vcvttss2usi, MGp, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2pd, Vcvtudq2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2pd, Vcvtudq2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2pd, Vcvtudq2pd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2pd, Vcvtudq2pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2pd, Vcvtudq2pd, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2pd, Vcvtudq2pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2ps, Vcvtudq2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2ps, Vcvtudq2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2ps, Vcvtudq2ps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2ps, Vcvtudq2ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2ps, Vcvtudq2ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtudq2ps, Vcvtudq2ps, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2pd, Vcvtuqq2pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2pd, Vcvtuqq2pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2pd, Vcvtuqq2pd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2pd, Vcvtuqq2pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2pd, Vcvtuqq2pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2pd, Vcvtuqq2pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2ps, Vcvtuqq2ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2ps, Vcvtuqq2ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2ps, Vcvtuqq2ps, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2ps, Vcvtuqq2ps, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vcvtuqq2ps, Vcvtuqq2ps, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtusi2sd, Vcvtusi2sd, MXmm, MXmm, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtusi2sd, Vcvtusi2sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtusi2ss, Vcvtusi2ss, MXmm, MXmm, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vcvtusi2ss, Vcvtusi2ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdbpsadbw, Vdbpsadbw, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdbpsadbw, Vdbpsadbw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdbpsadbw, Vdbpsadbw, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdbpsadbw, Vdbpsadbw, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdbpsadbw, Vdbpsadbw, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdbpsadbw, Vdbpsadbw, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivpd, Vdivpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivpd, Vdivpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivpd, Vdivpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivpd, Vdivpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivpd, Vdivpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivpd, Vdivpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivps, Vdivps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivps, Vdivps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivps, Vdivps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivps, Vdivps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivps, Vdivps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivps, Vdivps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivsd, Vdivsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivsd, Vdivsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivss, Vdivss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdivss, Vdivss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdpbf16ps, Vdpbf16ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdpbf16ps, Vdpbf16ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdpbf16ps, Vdpbf16ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdpbf16ps, Vdpbf16ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdpbf16ps, Vdpbf16ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vdpbf16ps, Vdpbf16ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdppd, Vdppd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdppd, Vdppd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdpps, Vdpps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdpps, Vdpps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdpps, Vdpps, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vdpps, Vdpps, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexp2pd, Vexp2pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexp2pd, Vexp2pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexp2ps, Vexp2ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexp2ps, Vexp2ps, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandpd, Vexpandpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandpd, Vexpandpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandpd, Vexpandpd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandpd, Vexpandpd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandpd, Vexpandpd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandpd, Vexpandpd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandps, Vexpandps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandps, Vexpandps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandps, Vexpandps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandps, Vexpandps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandps, Vexpandps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vexpandps, Vexpandps, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf128, Vextractf128, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf128, Vextractf128, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf32x4, Vextractf32x4, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf32x4, Vextractf32x4, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf32x4, Vextractf32x4, MXmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf32x4, Vextractf32x4, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf32x8, Vextractf32x8, MYmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf32x8, Vextractf32x8, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf64x2, Vextractf64x2, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf64x2, Vextractf64x2, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf64x2, Vextractf64x2, MXmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf64x2, Vextractf64x2, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf64x4, Vextractf64x4, MYmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractf64x4, Vextractf64x4, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti128, Vextracti128, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti128, Vextracti128, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti32x4, Vextracti32x4, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti32x4, Vextracti32x4, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti32x4, Vextracti32x4, MXmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti32x4, Vextracti32x4, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti32x8, Vextracti32x8, MYmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti32x8, Vextracti32x8, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti64x2, Vextracti64x2, MXmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti64x2, Vextracti64x2, MMem, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti64x2, Vextracti64x2, MXmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti64x2, Vextracti64x2, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti64x4, Vextracti64x4, MYmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextracti64x4, Vextracti64x4, MMem, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractps, Vextractps, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vextractps, Vextractps, MMem, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmpd, Vfixupimmpd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmpd, Vfixupimmpd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmpd, Vfixupimmpd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmpd, Vfixupimmpd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmpd, Vfixupimmpd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmpd, Vfixupimmpd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmps, Vfixupimmps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmps, Vfixupimmps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmps, Vfixupimmps, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmps, Vfixupimmps, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmps, Vfixupimmps, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmps, Vfixupimmps, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmsd, Vfixupimmsd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmsd, Vfixupimmsd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmss, Vfixupimmss, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vfixupimmss, Vfixupimmss, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132pd, Vfmadd132pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132pd, Vfmadd132pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132pd, Vfmadd132pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132pd, Vfmadd132pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132pd, Vfmadd132pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132pd, Vfmadd132pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ps, Vfmadd132ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ps, Vfmadd132ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ps, Vfmadd132ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ps, Vfmadd132ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ps, Vfmadd132ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ps, Vfmadd132ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132sd, Vfmadd132sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132sd, Vfmadd132sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ss, Vfmadd132ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd132ss, Vfmadd132ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213pd, Vfmadd213pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213pd, Vfmadd213pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213pd, Vfmadd213pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213pd, Vfmadd213pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213pd, Vfmadd213pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213pd, Vfmadd213pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ps, Vfmadd213ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ps, Vfmadd213ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ps, Vfmadd213ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ps, Vfmadd213ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ps, Vfmadd213ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ps, Vfmadd213ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213sd, Vfmadd213sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213sd, Vfmadd213sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ss, Vfmadd213ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd213ss, Vfmadd213ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231pd, Vfmadd231pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231pd, Vfmadd231pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231pd, Vfmadd231pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231pd, Vfmadd231pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231pd, Vfmadd231pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231pd, Vfmadd231pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ps, Vfmadd231ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ps, Vfmadd231ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ps, Vfmadd231ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ps, Vfmadd231ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ps, Vfmadd231ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ps, Vfmadd231ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231sd, Vfmadd231sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231sd, Vfmadd231sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ss, Vfmadd231ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmadd231ss, Vfmadd231ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132pd, Vfmaddsub132pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132pd, Vfmaddsub132pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132pd, Vfmaddsub132pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132pd, Vfmaddsub132pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132pd, Vfmaddsub132pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132pd, Vfmaddsub132pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132ps, Vfmaddsub132ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132ps, Vfmaddsub132ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132ps, Vfmaddsub132ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132ps, Vfmaddsub132ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132ps, Vfmaddsub132ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub132ps, Vfmaddsub132ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213pd, Vfmaddsub213pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213pd, Vfmaddsub213pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213pd, Vfmaddsub213pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213pd, Vfmaddsub213pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213pd, Vfmaddsub213pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213pd, Vfmaddsub213pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213ps, Vfmaddsub213ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213ps, Vfmaddsub213ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213ps, Vfmaddsub213ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213ps, Vfmaddsub213ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213ps, Vfmaddsub213ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub213ps, Vfmaddsub213ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231pd, Vfmaddsub231pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231pd, Vfmaddsub231pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231pd, Vfmaddsub231pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231pd, Vfmaddsub231pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231pd, Vfmaddsub231pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231pd, Vfmaddsub231pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231ps, Vfmaddsub231ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231ps, Vfmaddsub231ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231ps, Vfmaddsub231ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231ps, Vfmaddsub231ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231ps, Vfmaddsub231ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmaddsub231ps, Vfmaddsub231ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132pd, Vfmsub132pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132pd, Vfmsub132pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132pd, Vfmsub132pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132pd, Vfmsub132pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132pd, Vfmsub132pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132pd, Vfmsub132pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ps, Vfmsub132ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ps, Vfmsub132ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ps, Vfmsub132ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ps, Vfmsub132ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ps, Vfmsub132ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ps, Vfmsub132ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132sd, Vfmsub132sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132sd, Vfmsub132sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ss, Vfmsub132ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub132ss, Vfmsub132ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213pd, Vfmsub213pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213pd, Vfmsub213pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213pd, Vfmsub213pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213pd, Vfmsub213pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213pd, Vfmsub213pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213pd, Vfmsub213pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ps, Vfmsub213ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ps, Vfmsub213ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ps, Vfmsub213ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ps, Vfmsub213ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ps, Vfmsub213ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ps, Vfmsub213ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213sd, Vfmsub213sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213sd, Vfmsub213sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ss, Vfmsub213ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub213ss, Vfmsub213ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231pd, Vfmsub231pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231pd, Vfmsub231pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231pd, Vfmsub231pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231pd, Vfmsub231pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231pd, Vfmsub231pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231pd, Vfmsub231pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ps, Vfmsub231ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ps, Vfmsub231ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ps, Vfmsub231ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ps, Vfmsub231ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ps, Vfmsub231ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ps, Vfmsub231ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231sd, Vfmsub231sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231sd, Vfmsub231sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ss, Vfmsub231ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsub231ss, Vfmsub231ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132pd, Vfmsubadd132pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132pd, Vfmsubadd132pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132pd, Vfmsubadd132pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132pd, Vfmsubadd132pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132pd, Vfmsubadd132pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132pd, Vfmsubadd132pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132ps, Vfmsubadd132ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132ps, Vfmsubadd132ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132ps, Vfmsubadd132ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132ps, Vfmsubadd132ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132ps, Vfmsubadd132ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd132ps, Vfmsubadd132ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213pd, Vfmsubadd213pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213pd, Vfmsubadd213pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213pd, Vfmsubadd213pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213pd, Vfmsubadd213pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213pd, Vfmsubadd213pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213pd, Vfmsubadd213pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213ps, Vfmsubadd213ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213ps, Vfmsubadd213ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213ps, Vfmsubadd213ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213ps, Vfmsubadd213ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213ps, Vfmsubadd213ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd213ps, Vfmsubadd213ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231pd, Vfmsubadd231pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231pd, Vfmsubadd231pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231pd, Vfmsubadd231pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231pd, Vfmsubadd231pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231pd, Vfmsubadd231pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231pd, Vfmsubadd231pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231ps, Vfmsubadd231ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231ps, Vfmsubadd231ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231ps, Vfmsubadd231ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231ps, Vfmsubadd231ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231ps, Vfmsubadd231ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfmsubadd231ps, Vfmsubadd231ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132pd, Vfnmadd132pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132pd, Vfnmadd132pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132pd, Vfnmadd132pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132pd, Vfnmadd132pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132pd, Vfnmadd132pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132pd, Vfnmadd132pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ps, Vfnmadd132ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ps, Vfnmadd132ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ps, Vfnmadd132ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ps, Vfnmadd132ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ps, Vfnmadd132ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ps, Vfnmadd132ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132sd, Vfnmadd132sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132sd, Vfnmadd132sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ss, Vfnmadd132ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd132ss, Vfnmadd132ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213pd, Vfnmadd213pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213pd, Vfnmadd213pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213pd, Vfnmadd213pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213pd, Vfnmadd213pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213pd, Vfnmadd213pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213pd, Vfnmadd213pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ps, Vfnmadd213ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ps, Vfnmadd213ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ps, Vfnmadd213ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ps, Vfnmadd213ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ps, Vfnmadd213ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ps, Vfnmadd213ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213sd, Vfnmadd213sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213sd, Vfnmadd213sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ss, Vfnmadd213ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd213ss, Vfnmadd213ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231pd, Vfnmadd231pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231pd, Vfnmadd231pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231pd, Vfnmadd231pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231pd, Vfnmadd231pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231pd, Vfnmadd231pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231pd, Vfnmadd231pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ps, Vfnmadd231ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ps, Vfnmadd231ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ps, Vfnmadd231ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ps, Vfnmadd231ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ps, Vfnmadd231ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ps, Vfnmadd231ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231sd, Vfnmadd231sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231sd, Vfnmadd231sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ss, Vfnmadd231ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmadd231ss, Vfnmadd231ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132pd, Vfnmsub132pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132pd, Vfnmsub132pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132pd, Vfnmsub132pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132pd, Vfnmsub132pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132pd, Vfnmsub132pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132pd, Vfnmsub132pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ps, Vfnmsub132ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ps, Vfnmsub132ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ps, Vfnmsub132ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ps, Vfnmsub132ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ps, Vfnmsub132ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ps, Vfnmsub132ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132sd, Vfnmsub132sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132sd, Vfnmsub132sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ss, Vfnmsub132ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub132ss, Vfnmsub132ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213pd, Vfnmsub213pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213pd, Vfnmsub213pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213pd, Vfnmsub213pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213pd, Vfnmsub213pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213pd, Vfnmsub213pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213pd, Vfnmsub213pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ps, Vfnmsub213ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ps, Vfnmsub213ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ps, Vfnmsub213ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ps, Vfnmsub213ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ps, Vfnmsub213ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ps, Vfnmsub213ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213sd, Vfnmsub213sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213sd, Vfnmsub213sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ss, Vfnmsub213ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub213ss, Vfnmsub213ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231pd, Vfnmsub231pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231pd, Vfnmsub231pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231pd, Vfnmsub231pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231pd, Vfnmsub231pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231pd, Vfnmsub231pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231pd, Vfnmsub231pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ps, Vfnmsub231ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ps, Vfnmsub231ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ps, Vfnmsub231ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ps, Vfnmsub231ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ps, Vfnmsub231ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ps, Vfnmsub231ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231sd, Vfnmsub231sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231sd, Vfnmsub231sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ss, Vfnmsub231ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vfnmsub231ss, Vfnmsub231ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclasspd, Vfpclasspd, MKReg, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclasspd, Vfpclasspd, MKReg, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclasspd, Vfpclasspd, MKReg, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclasspd, Vfpclasspd, MKReg, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclassps, Vfpclassps, MKReg, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclassps, Vfpclassps, MKReg, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclassps, Vfpclassps, MKReg, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclassps, Vfpclassps, MKReg, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclasssd, Vfpclasssd, MKReg, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclasssd, Vfpclasssd, MKReg, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclassss, Vfpclassss, MKReg, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vfpclassss, Vfpclassss, MKReg, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherdpd, Vgatherdpd, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherdpd, Vgatherdpd, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherdpd, Vgatherdpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherdpd, Vgatherdpd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherdpd, Vgatherdpd, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherdps, Vgatherdps, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherdps, Vgatherdps, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherdps, Vgatherdps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherdps, Vgatherdps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherdps, Vgatherdps, MZmm, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf0dpd, Vgatherpf0dpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf0dps, Vgatherpf0dps, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf0qpd, Vgatherpf0qpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf0qps, Vgatherpf0qps, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf1dpd, Vgatherpf1dpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf1dps, Vgatherpf1dps, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf1qpd, Vgatherpf1qpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vgatherpf1qps, Vgatherpf1qps, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherqpd, Vgatherqpd, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherqpd, Vgatherqpd, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherqpd, Vgatherqpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherqpd, Vgatherqpd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherqpd, Vgatherqpd, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgatherqps, Vgatherqps, MXmm, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherqps, Vgatherqps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherqps, Vgatherqps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgatherqps, Vgatherqps, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexppd, Vgetexppd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexppd, Vgetexppd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexppd, Vgetexppd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexppd, Vgetexppd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexppd, Vgetexppd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexppd, Vgetexppd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexpps, Vgetexpps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexpps, Vgetexpps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexpps, Vgetexpps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexpps, Vgetexpps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexpps, Vgetexpps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vgetexpps, Vgetexpps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgetexpsd, Vgetexpsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgetexpsd, Vgetexpsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgetexpss, Vgetexpss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgetexpss, Vgetexpss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantpd, Vgetmantpd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantpd, Vgetmantpd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantpd, Vgetmantpd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantpd, Vgetmantpd, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantpd, Vgetmantpd, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantpd, Vgetmantpd, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantps, Vgetmantps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantps, Vgetmantps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantps, Vgetmantps, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantps, Vgetmantps, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantps, Vgetmantps, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vgetmantps, Vgetmantps, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgetmantsd, Vgetmantsd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgetmantsd, Vgetmantsd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgetmantss, Vgetmantss, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgetmantss, Vgetmantss, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineinvqb, Vgf2p8affineinvqb, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineinvqb, Vgf2p8affineinvqb, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineinvqb, Vgf2p8affineinvqb, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineinvqb, Vgf2p8affineinvqb, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineinvqb, Vgf2p8affineinvqb, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineinvqb, Vgf2p8affineinvqb, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineqb, Vgf2p8affineqb, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineqb, Vgf2p8affineqb, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineqb, Vgf2p8affineqb, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineqb, Vgf2p8affineqb, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineqb, Vgf2p8affineqb, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vgf2p8affineqb, Vgf2p8affineqb, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgf2p8mulb, Vgf2p8mulb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgf2p8mulb, Vgf2p8mulb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgf2p8mulb, Vgf2p8mulb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgf2p8mulb, Vgf2p8mulb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgf2p8mulb, Vgf2p8mulb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vgf2p8mulb, Vgf2p8mulb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddpd, Vhaddpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddpd, Vhaddpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddpd, Vhaddpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddpd, Vhaddpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddps, Vhaddps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddps, Vhaddps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddps, Vhaddps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhaddps, Vhaddps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubpd, Vhsubpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubpd, Vhsubpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubpd, Vhsubpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubpd, Vhsubpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubps, Vhsubps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubps, Vhsubps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubps, Vhsubps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vhsubps, Vhsubps, MYmm, MYmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf128, Vinsertf128, MYmm, MYmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf128, Vinsertf128, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf32x4, Vinsertf32x4, MYmm, MYmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf32x4, Vinsertf32x4, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf32x4, Vinsertf32x4, MZmm, MZmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf32x4, Vinsertf32x4, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf32x8, Vinsertf32x8, MZmm, MZmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf32x8, Vinsertf32x8, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf64x2, Vinsertf64x2, MYmm, MYmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf64x2, Vinsertf64x2, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf64x2, Vinsertf64x2, MZmm, MZmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf64x2, Vinsertf64x2, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf64x4, Vinsertf64x4, MZmm, MZmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertf64x4, Vinsertf64x4, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti128, Vinserti128, MYmm, MYmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti128, Vinserti128, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti32x4, Vinserti32x4, MYmm, MYmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti32x4, Vinserti32x4, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti32x4, Vinserti32x4, MZmm, MZmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti32x4, Vinserti32x4, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti32x8, Vinserti32x8, MZmm, MZmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti32x8, Vinserti32x8, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti64x2, Vinserti64x2, MYmm, MYmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti64x2, Vinserti64x2, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti64x2, Vinserti64x2, MZmm, MZmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti64x2, Vinserti64x2, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti64x4, Vinserti64x4, MZmm, MZmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinserti64x4, Vinserti64x4, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertps, Vinsertps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vinsertps, Vinsertps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vlddqu, Vlddqu, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vlddqu, Vlddqu, MYmm, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vldmxcsr, Vldmxcsr, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovdqu, Vmaskmovdqu, MXmm, MXmm, DS_ZDI);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovpd, Vmaskmovpd, MMem, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovpd, Vmaskmovpd, MMem, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovpd, Vmaskmovpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovpd, Vmaskmovpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovps, Vmaskmovps, MMem, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovps, Vmaskmovps, MMem, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovps, Vmaskmovps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaskmovps, Vmaskmovps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxpd, Vmaxpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxpd, Vmaxpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxpd, Vmaxpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxpd, Vmaxpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxpd, Vmaxpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxpd, Vmaxpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxps, Vmaxps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxps, Vmaxps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxps, Vmaxps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxps, Vmaxps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxps, Vmaxps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxps, Vmaxps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxsd, Vmaxsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxsd, Vmaxsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxss, Vmaxss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmaxss, Vmaxss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminpd, Vminpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminpd, Vminpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminpd, Vminpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminpd, Vminpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminpd, Vminpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminpd, Vminpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminps, Vminps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminps, Vminps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminps, Vminps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminps, Vminps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminps, Vminps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminps, Vminps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminsd, Vminsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminsd, Vminsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminss, Vminss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vminss, Vminss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovapd, Vmovapd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovaps, Vmovaps, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovd, Vmovd, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovd, Vmovd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovd, Vmovd, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovd, Vmovd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovddup, Vmovddup, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovddup, Vmovddup, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovddup, Vmovddup, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovddup, Vmovddup, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovddup, Vmovddup, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovddup, Vmovddup, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa, Vmovdqa, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa, Vmovdqa, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa, Vmovdqa, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa, Vmovdqa, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa, Vmovdqa, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa, Vmovdqa, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa32, Vmovdqa32, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqa64, Vmovdqa64, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu, Vmovdqu, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu, Vmovdqu, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu, Vmovdqu, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu, Vmovdqu, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu, Vmovdqu, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu, Vmovdqu, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu16, Vmovdqu16, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu32, Vmovdqu32, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu64, Vmovdqu64, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovdqu8, Vmovdqu8, MMem, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovhlps, Vmovhlps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovhpd, Vmovhpd, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovhpd, Vmovhpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovhps, Vmovhps, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovhps, Vmovhps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovlhps, Vmovlhps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovlpd, Vmovlpd, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovlpd, Vmovlpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovlps, Vmovlps, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovlps, Vmovlps, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovmskpd, Vmovmskpd, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovmskpd, Vmovmskpd, MGp, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovmskps, Vmovmskps, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovmskps, Vmovmskps, MGp, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntdq, Vmovntdq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntdq, Vmovntdq, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntdq, Vmovntdq, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntdqa, Vmovntdqa, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntdqa, Vmovntdqa, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntdqa, Vmovntdqa, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntpd, Vmovntpd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntpd, Vmovntpd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntpd, Vmovntpd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntps, Vmovntps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntps, Vmovntps, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovntps, Vmovntps, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovq, Vmovq, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovq, Vmovq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovq, Vmovq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovq, Vmovq, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovq, Vmovq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsd, Vmovsd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsd, Vmovsd, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovsd, Vmovsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovshdup, Vmovshdup, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovshdup, Vmovshdup, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovshdup, Vmovshdup, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovshdup, Vmovshdup, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovshdup, Vmovshdup, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovshdup, Vmovshdup, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsldup, Vmovsldup, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsldup, Vmovsldup, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsldup, Vmovsldup, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsldup, Vmovsldup, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsldup, Vmovsldup, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovsldup, Vmovsldup, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovss, Vmovss, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovss, Vmovss, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmovss, Vmovss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovupd, Vmovupd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vmovups, Vmovups, MMem, MZmm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vmpsadbw, Vmpsadbw, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vmpsadbw, Vmpsadbw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vmpsadbw, Vmpsadbw, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vmpsadbw, Vmpsadbw, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulpd, Vmulpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulpd, Vmulpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulpd, Vmulpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulpd, Vmulpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulpd, Vmulpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulpd, Vmulpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulps, Vmulps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulps, Vmulps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulps, Vmulps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulps, Vmulps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulps, Vmulps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulps, Vmulps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulsd, Vmulsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulsd, Vmulsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulss, Vmulss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vmulss, Vmulss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorpd, Vorpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorpd, Vorpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorpd, Vorpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorpd, Vorpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorpd, Vorpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorpd, Vorpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorps, Vorps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorps, Vorps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorps, Vorps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorps, Vorps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorps, Vorps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vorps, Vorps, MZmm, MZmm, MMem);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, vp4dpwssd, Vp4dpwssd, MZmm, MZmm, MZmm, MZmm, MZmm, MMem);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, vp4dpwssds, Vp4dpwssds, MZmm, MZmm, MZmm, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsb, Vpabsb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsb, Vpabsb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsb, Vpabsb, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsb, Vpabsb, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsb, Vpabsb, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsb, Vpabsb, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsd, Vpabsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsd, Vpabsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsd, Vpabsd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsd, Vpabsd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsd, Vpabsd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsd, Vpabsd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsq, Vpabsq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsq, Vpabsq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsq, Vpabsq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsq, Vpabsq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsq, Vpabsq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsq, Vpabsq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsw, Vpabsw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsw, Vpabsw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsw, Vpabsw, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsw, Vpabsw, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsw, Vpabsw, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpabsw, Vpabsw, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackssdw, Vpackssdw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackssdw, Vpackssdw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackssdw, Vpackssdw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackssdw, Vpackssdw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackssdw, Vpackssdw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackssdw, Vpackssdw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpacksswb, Vpacksswb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpacksswb, Vpacksswb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpacksswb, Vpacksswb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpacksswb, Vpacksswb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpacksswb, Vpacksswb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpacksswb, Vpacksswb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackusdw, Vpackusdw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackusdw, Vpackusdw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackusdw, Vpackusdw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackusdw, Vpackusdw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackusdw, Vpackusdw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackusdw, Vpackusdw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackuswb, Vpackuswb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackuswb, Vpackuswb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackuswb, Vpackuswb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackuswb, Vpackuswb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackuswb, Vpackuswb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpackuswb, Vpackuswb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddb, Vpaddb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddb, Vpaddb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddb, Vpaddb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddb, Vpaddb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddb, Vpaddb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddb, Vpaddb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddd, Vpaddd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddd, Vpaddd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddd, Vpaddd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddd, Vpaddd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddd, Vpaddd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddd, Vpaddd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddq, Vpaddq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddq, Vpaddq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddq, Vpaddq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddq, Vpaddq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddq, Vpaddq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddq, Vpaddq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsb, Vpaddsb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsb, Vpaddsb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsb, Vpaddsb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsb, Vpaddsb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsb, Vpaddsb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsb, Vpaddsb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsw, Vpaddsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsw, Vpaddsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsw, Vpaddsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsw, Vpaddsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsw, Vpaddsw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddsw, Vpaddsw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusb, Vpaddusb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusb, Vpaddusb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusb, Vpaddusb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusb, Vpaddusb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusb, Vpaddusb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusb, Vpaddusb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusw, Vpaddusw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusw, Vpaddusw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusw, Vpaddusw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusw, Vpaddusw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusw, Vpaddusw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddusw, Vpaddusw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddw, Vpaddw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddw, Vpaddw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddw, Vpaddw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddw, Vpaddw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddw, Vpaddw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpaddw, Vpaddw, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpalignr, Vpalignr, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpalignr, Vpalignr, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpalignr, Vpalignr, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpalignr, Vpalignr, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpalignr, Vpalignr, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpalignr, Vpalignr, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpand, Vpand, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpand, Vpand, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpand, Vpand, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpand, Vpand, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandd, Vpandd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandd, Vpandd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandd, Vpandd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandd, Vpandd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandd, Vpandd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandd, Vpandd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandn, Vpandn, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandn, Vpandn, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandn, Vpandn, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandn, Vpandn, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnd, Vpandnd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnd, Vpandnd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnd, Vpandnd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnd, Vpandnd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnd, Vpandnd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnd, Vpandnd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnq, Vpandnq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnq, Vpandnq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnq, Vpandnq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnq, Vpandnq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnq, Vpandnq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandnq, Vpandnq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandq, Vpandq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandq, Vpandq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandq, Vpandq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandq, Vpandq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandq, Vpandq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpandq, Vpandq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgb, Vpavgb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgb, Vpavgb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgb, Vpavgb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgb, Vpavgb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgb, Vpavgb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgb, Vpavgb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgw, Vpavgw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgw, Vpavgw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgw, Vpavgw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgw, Vpavgw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgw, Vpavgw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpavgw, Vpavgw, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendd, Vpblendd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendd, Vpblendd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendd, Vpblendd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendd, Vpblendd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpblendvb, Vpblendvb, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpblendvb, Vpblendvb, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpblendvb, Vpblendvb, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpblendvb, Vpblendvb, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendw, Vpblendw, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendw, Vpblendw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendw, Vpblendw, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpblendw, Vpblendw, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MYmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MZmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastb, Vpbroadcastb, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MYmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MZmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastd, Vpbroadcastd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastmb2d, Vpbroadcastmb2d, MXmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastmb2d, Vpbroadcastmb2d, MYmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastmb2d, Vpbroadcastmb2d, MZmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastmb2q, Vpbroadcastmb2q, MXmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastmb2q, Vpbroadcastmb2q, MYmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastmb2q, Vpbroadcastmb2q, MZmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MYmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MZmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastq, Vpbroadcastq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MXmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MYmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MZmm, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpbroadcastw, Vpbroadcastw, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpclmulqdq, Vpclmulqdq, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpclmulqdq, Vpclmulqdq, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpclmulqdq, Vpclmulqdq, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpclmulqdq, Vpclmulqdq, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpclmulqdq, Vpclmulqdq, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpclmulqdq, Vpclmulqdq, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpb, Vpcmpb, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpb, Vpcmpb, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpb, Vpcmpb, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpb, Vpcmpb, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpb, Vpcmpb, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpb, Vpcmpb, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpd, Vpcmpd, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpd, Vpcmpd, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpd, Vpcmpd, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpd, Vpcmpd, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpd, Vpcmpd, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpd, Vpcmpd, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqb, Vpcmpeqb, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqd, Vpcmpeqd, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqq, Vpcmpeqq, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpeqw, Vpcmpeqw, MKReg, MZmm, MMem);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, vpcmpestri, Vpcmpestri, MXmm, MXmm, MImm, ECX, EAX, EDX);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, vpcmpestri, Vpcmpestri, MXmm, MMem, MImm, ECX, EAX, EDX);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, vpcmpestrm, Vpcmpestrm, MXmm, MXmm, MImm, XMM0, EAX, EDX);
			MWASMJIT_INST_6x(AsmJit::X86::EmitterExplicit, vpcmpestrm, Vpcmpestrm, MXmm, MMem, MImm, XMM0, EAX, EDX);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtb, Vpcmpgtb, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtd, Vpcmpgtd, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtq, Vpcmpgtq, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpcmpgtw, Vpcmpgtw, MKReg, MZmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmpistri, Vpcmpistri, MXmm, MXmm, MImm, ECX);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmpistri, Vpcmpistri, MXmm, MMem, MImm, ECX);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmpistrm, Vpcmpistrm, MXmm, MXmm, MImm, XMM0);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmpistrm, Vpcmpistrm, MXmm, MMem, MImm, XMM0);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpq, Vpcmpq, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpq, Vpcmpq, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpq, Vpcmpq, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpq, Vpcmpq, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpq, Vpcmpq, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpq, Vpcmpq, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpub, Vpcmpub, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpub, Vpcmpub, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpub, Vpcmpub, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpub, Vpcmpub, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpub, Vpcmpub, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpub, Vpcmpub, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpud, Vpcmpud, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpud, Vpcmpud, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpud, Vpcmpud, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpud, Vpcmpud, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpud, Vpcmpud, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpud, Vpcmpud, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuq, Vpcmpuq, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuq, Vpcmpuq, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuq, Vpcmpuq, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuq, Vpcmpuq, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuq, Vpcmpuq, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuq, Vpcmpuq, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuw, Vpcmpuw, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuw, Vpcmpuw, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuw, Vpcmpuw, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuw, Vpcmpuw, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuw, Vpcmpuw, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpuw, Vpcmpuw, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpw, Vpcmpw, MKReg, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpw, Vpcmpw, MKReg, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpw, Vpcmpw, MKReg, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpw, Vpcmpw, MKReg, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpw, Vpcmpw, MKReg, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcmpw, Vpcmpw, MKReg, MZmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressb, Vpcompressb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressb, Vpcompressb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressb, Vpcompressb, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressb, Vpcompressb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressb, Vpcompressb, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressb, Vpcompressb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressd, Vpcompressd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressd, Vpcompressd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressd, Vpcompressd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressd, Vpcompressd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressd, Vpcompressd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressd, Vpcompressd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressq, Vpcompressq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressq, Vpcompressq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressq, Vpcompressq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressq, Vpcompressq, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressq, Vpcompressq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressq, Vpcompressq, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressw, Vpcompressw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressw, Vpcompressw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressw, Vpcompressw, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressw, Vpcompressw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressw, Vpcompressw, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpcompressw, Vpcompressw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictd, Vpconflictd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictd, Vpconflictd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictd, Vpconflictd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictd, Vpconflictd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictd, Vpconflictd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictd, Vpconflictd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictq, Vpconflictq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictq, Vpconflictq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictq, Vpconflictq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictq, Vpconflictq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictq, Vpconflictq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpconflictq, Vpconflictq, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusd, Vpdpbusd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusd, Vpdpbusd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusd, Vpdpbusd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusd, Vpdpbusd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusd, Vpdpbusd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusd, Vpdpbusd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusds, Vpdpbusds, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusds, Vpdpbusds, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusds, Vpdpbusds, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusds, Vpdpbusds, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusds, Vpdpbusds, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpbusds, Vpdpbusds, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssd, Vpdpwssd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssd, Vpdpwssd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssd, Vpdpwssd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssd, Vpdpwssd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssd, Vpdpwssd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssd, Vpdpwssd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssds, Vpdpwssds, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssds, Vpdpwssds, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssds, Vpdpwssds, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssds, Vpdpwssds, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssds, Vpdpwssds, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpdpwssds, Vpdpwssds, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vperm2f128, Vperm2f128, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vperm2f128, Vperm2f128, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vperm2i128, Vperm2i128, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vperm2i128, Vperm2i128, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermb, Vpermb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermb, Vpermb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermb, Vpermb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermb, Vpermb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermb, Vpermb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermb, Vpermb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermd, Vpermd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermd, Vpermd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermd, Vpermd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermd, Vpermd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2b, Vpermi2b, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2b, Vpermi2b, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2b, Vpermi2b, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2b, Vpermi2b, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2b, Vpermi2b, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2b, Vpermi2b, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2d, Vpermi2d, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2d, Vpermi2d, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2d, Vpermi2d, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2d, Vpermi2d, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2d, Vpermi2d, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2d, Vpermi2d, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2pd, Vpermi2pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2pd, Vpermi2pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2pd, Vpermi2pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2pd, Vpermi2pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2pd, Vpermi2pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2pd, Vpermi2pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2ps, Vpermi2ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2ps, Vpermi2ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2ps, Vpermi2ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2ps, Vpermi2ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2ps, Vpermi2ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2ps, Vpermi2ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2q, Vpermi2q, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2q, Vpermi2q, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2q, Vpermi2q, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2q, Vpermi2q, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2q, Vpermi2q, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2q, Vpermi2q, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2w, Vpermi2w, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2w, Vpermi2w, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2w, Vpermi2w, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2w, Vpermi2w, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2w, Vpermi2w, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermi2w, Vpermi2w, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilpd, Vpermilpd, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermilps, Vpermilps, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermpd, Vpermpd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermpd, Vpermpd, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermps, Vpermps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermps, Vpermps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpermq, Vpermq, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2b, Vpermt2b, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2b, Vpermt2b, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2b, Vpermt2b, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2b, Vpermt2b, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2b, Vpermt2b, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2b, Vpermt2b, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2d, Vpermt2d, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2d, Vpermt2d, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2d, Vpermt2d, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2d, Vpermt2d, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2d, Vpermt2d, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2d, Vpermt2d, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2pd, Vpermt2pd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2pd, Vpermt2pd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2pd, Vpermt2pd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2pd, Vpermt2pd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2pd, Vpermt2pd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2pd, Vpermt2pd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2ps, Vpermt2ps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2ps, Vpermt2ps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2ps, Vpermt2ps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2ps, Vpermt2ps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2ps, Vpermt2ps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2ps, Vpermt2ps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2q, Vpermt2q, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2q, Vpermt2q, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2q, Vpermt2q, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2q, Vpermt2q, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2q, Vpermt2q, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2q, Vpermt2q, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2w, Vpermt2w, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2w, Vpermt2w, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2w, Vpermt2w, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2w, Vpermt2w, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2w, Vpermt2w, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermt2w, Vpermt2w, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermw, Vpermw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermw, Vpermw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermw, Vpermw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermw, Vpermw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermw, Vpermw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpermw, Vpermw, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandb, Vpexpandb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandb, Vpexpandb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandb, Vpexpandb, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandb, Vpexpandb, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandb, Vpexpandb, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandb, Vpexpandb, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandd, Vpexpandd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandd, Vpexpandd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandd, Vpexpandd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandd, Vpexpandd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandd, Vpexpandd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandd, Vpexpandd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandq, Vpexpandq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandq, Vpexpandq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandq, Vpexpandq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandq, Vpexpandq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandq, Vpexpandq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandq, Vpexpandq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandw, Vpexpandw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandw, Vpexpandw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandw, Vpexpandw, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandw, Vpexpandw, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandw, Vpexpandw, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpexpandw, Vpexpandw, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrb, Vpextrb, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrb, Vpextrb, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrd, Vpextrd, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrd, Vpextrd, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrq, Vpextrq, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrq, Vpextrq, MMem, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrw, Vpextrw, MGp, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpextrw, Vpextrw, MMem, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherdd, Vpgatherdd, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherdd, Vpgatherdd, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherdd, Vpgatherdd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherdd, Vpgatherdd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherdd, Vpgatherdd, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherdq, Vpgatherdq, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherdq, Vpgatherdq, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherdq, Vpgatherdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherdq, Vpgatherdq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherdq, Vpgatherdq, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherqd, Vpgatherqd, MXmm, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherqd, Vpgatherqd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherqd, Vpgatherqd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherqd, Vpgatherqd, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherqq, Vpgatherqq, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpgatherqq, Vpgatherqq, MYmm, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherqq, Vpgatherqq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherqq, Vpgatherqq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpgatherqq, Vpgatherqq, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddd, Vphaddd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddd, Vphaddd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddd, Vphaddd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddd, Vphaddd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddsw, Vphaddsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddsw, Vphaddsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddsw, Vphaddsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddsw, Vphaddsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddw, Vphaddw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddw, Vphaddw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddw, Vphaddw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphaddw, Vphaddw, MYmm, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphminposuw, Vphminposuw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphminposuw, Vphminposuw, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubd, Vphsubd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubd, Vphsubd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubd, Vphsubd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubd, Vphsubd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubsw, Vphsubsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubsw, Vphsubsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubsw, Vphsubsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubsw, Vphsubsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubw, Vphsubw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubw, Vphsubw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubw, Vphsubw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vphsubw, Vphsubw, MYmm, MYmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrb, Vpinsrb, MXmm, MXmm, MGp, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrb, Vpinsrb, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrd, Vpinsrd, MXmm, MXmm, MGp, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrd, Vpinsrd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrq, Vpinsrq, MXmm, MXmm, MGp, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrq, Vpinsrq, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrw, Vpinsrw, MXmm, MXmm, MGp, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpinsrw, Vpinsrw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntd, Vplzcntd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntd, Vplzcntd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntd, Vplzcntd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntd, Vplzcntd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntd, Vplzcntd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntd, Vplzcntd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntq, Vplzcntq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntq, Vplzcntq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntq, Vplzcntq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntq, Vplzcntq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntq, Vplzcntq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vplzcntq, Vplzcntq, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52huq, Vpmadd52huq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52huq, Vpmadd52huq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52huq, Vpmadd52huq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52huq, Vpmadd52huq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52huq, Vpmadd52huq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52huq, Vpmadd52huq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52luq, Vpmadd52luq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52luq, Vpmadd52luq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52luq, Vpmadd52luq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52luq, Vpmadd52luq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52luq, Vpmadd52luq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmadd52luq, Vpmadd52luq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddubsw, Vpmaddubsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddubsw, Vpmaddubsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddubsw, Vpmaddubsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddubsw, Vpmaddubsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddubsw, Vpmaddubsw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddubsw, Vpmaddubsw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddwd, Vpmaddwd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddwd, Vpmaddwd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddwd, Vpmaddwd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddwd, Vpmaddwd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddwd, Vpmaddwd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaddwd, Vpmaddwd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovd, Vpmaskmovd, MMem, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovd, Vpmaskmovd, MMem, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovd, Vpmaskmovd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovd, Vpmaskmovd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovq, Vpmaskmovq, MMem, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovq, Vpmaskmovq, MMem, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovq, Vpmaskmovq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaskmovq, Vpmaskmovq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsb, Vpmaxsb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsb, Vpmaxsb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsb, Vpmaxsb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsb, Vpmaxsb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsb, Vpmaxsb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsb, Vpmaxsb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsd, Vpmaxsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsd, Vpmaxsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsd, Vpmaxsd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsd, Vpmaxsd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsd, Vpmaxsd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsd, Vpmaxsd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsq, Vpmaxsq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsq, Vpmaxsq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsq, Vpmaxsq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsq, Vpmaxsq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsq, Vpmaxsq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsq, Vpmaxsq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsw, Vpmaxsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsw, Vpmaxsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsw, Vpmaxsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsw, Vpmaxsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsw, Vpmaxsw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxsw, Vpmaxsw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxub, Vpmaxub, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxub, Vpmaxub, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxub, Vpmaxub, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxub, Vpmaxub, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxub, Vpmaxub, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxub, Vpmaxub, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxud, Vpmaxud, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxud, Vpmaxud, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxud, Vpmaxud, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxud, Vpmaxud, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxud, Vpmaxud, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxud, Vpmaxud, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuq, Vpmaxuq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuq, Vpmaxuq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuq, Vpmaxuq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuq, Vpmaxuq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuq, Vpmaxuq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuq, Vpmaxuq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuw, Vpmaxuw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuw, Vpmaxuw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuw, Vpmaxuw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuw, Vpmaxuw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuw, Vpmaxuw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmaxuw, Vpmaxuw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsb, Vpminsb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsb, Vpminsb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsb, Vpminsb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsb, Vpminsb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsb, Vpminsb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsb, Vpminsb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsd, Vpminsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsd, Vpminsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsd, Vpminsd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsd, Vpminsd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsd, Vpminsd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsd, Vpminsd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsq, Vpminsq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsq, Vpminsq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsq, Vpminsq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsq, Vpminsq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsq, Vpminsq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsq, Vpminsq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsw, Vpminsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsw, Vpminsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsw, Vpminsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsw, Vpminsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsw, Vpminsw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminsw, Vpminsw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminub, Vpminub, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminub, Vpminub, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminub, Vpminub, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminub, Vpminub, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminub, Vpminub, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminub, Vpminub, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminud, Vpminud, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminud, Vpminud, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminud, Vpminud, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminud, Vpminud, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminud, Vpminud, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminud, Vpminud, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuq, Vpminuq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuq, Vpminuq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuq, Vpminuq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuq, Vpminuq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuq, Vpminuq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuq, Vpminuq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuw, Vpminuw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuw, Vpminuw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuw, Vpminuw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuw, Vpminuw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuw, Vpminuw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpminuw, Vpminuw, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovb2m, Vpmovb2m, MKReg, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovb2m, Vpmovb2m, MKReg, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovb2m, Vpmovb2m, MKReg, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovd2m, Vpmovd2m, MKReg, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovd2m, Vpmovd2m, MKReg, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovd2m, Vpmovd2m, MKReg, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdb, Vpmovdb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdb, Vpmovdb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdb, Vpmovdb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdb, Vpmovdb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdb, Vpmovdb, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdb, Vpmovdb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdw, Vpmovdw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdw, Vpmovdw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdw, Vpmovdw, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdw, Vpmovdw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdw, Vpmovdw, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovdw, Vpmovdw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2b, Vpmovm2b, MXmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2b, Vpmovm2b, MYmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2b, Vpmovm2b, MZmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2d, Vpmovm2d, MXmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2d, Vpmovm2d, MYmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2d, Vpmovm2d, MZmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2q, Vpmovm2q, MXmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2q, Vpmovm2q, MYmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2q, Vpmovm2q, MZmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2w, Vpmovm2w, MXmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2w, Vpmovm2w, MYmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovm2w, Vpmovm2w, MZmm, MKReg);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovmskb, Vpmovmskb, MGp, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovmskb, Vpmovmskb, MGp, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovq2m, Vpmovq2m, MKReg, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovq2m, Vpmovq2m, MKReg, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovq2m, Vpmovq2m, MKReg, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqb, Vpmovqb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqb, Vpmovqb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqb, Vpmovqb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqb, Vpmovqb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqb, Vpmovqb, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqb, Vpmovqb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqd, Vpmovqd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqd, Vpmovqd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqd, Vpmovqd, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqd, Vpmovqd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqd, Vpmovqd, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqd, Vpmovqd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqw, Vpmovqw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqw, Vpmovqw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqw, Vpmovqw, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqw, Vpmovqw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqw, Vpmovqw, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovqw, Vpmovqw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdb, Vpmovsdb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdb, Vpmovsdb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdb, Vpmovsdb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdb, Vpmovsdb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdb, Vpmovsdb, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdb, Vpmovsdb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdw, Vpmovsdw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdw, Vpmovsdw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdw, Vpmovsdw, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdw, Vpmovsdw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdw, Vpmovsdw, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsdw, Vpmovsdw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqb, Vpmovsqb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqb, Vpmovsqb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqb, Vpmovsqb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqb, Vpmovsqb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqb, Vpmovsqb, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqb, Vpmovsqb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqd, Vpmovsqd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqd, Vpmovsqd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqd, Vpmovsqd, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqd, Vpmovsqd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqd, Vpmovsqd, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqd, Vpmovsqd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqw, Vpmovsqw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqw, Vpmovsqw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqw, Vpmovsqw, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqw, Vpmovsqw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqw, Vpmovsqw, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsqw, Vpmovsqw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovswb, Vpmovswb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovswb, Vpmovswb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovswb, Vpmovswb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovswb, Vpmovswb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovswb, Vpmovswb, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovswb, Vpmovswb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbd, Vpmovsxbd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbd, Vpmovsxbd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbd, Vpmovsxbd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbd, Vpmovsxbd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbd, Vpmovsxbd, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbd, Vpmovsxbd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbq, Vpmovsxbq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbq, Vpmovsxbq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbq, Vpmovsxbq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbq, Vpmovsxbq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbq, Vpmovsxbq, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbq, Vpmovsxbq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbw, Vpmovsxbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbw, Vpmovsxbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbw, Vpmovsxbw, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbw, Vpmovsxbw, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbw, Vpmovsxbw, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxbw, Vpmovsxbw, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxdq, Vpmovsxdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxdq, Vpmovsxdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxdq, Vpmovsxdq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxdq, Vpmovsxdq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxdq, Vpmovsxdq, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxdq, Vpmovsxdq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwd, Vpmovsxwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwd, Vpmovsxwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwd, Vpmovsxwd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwd, Vpmovsxwd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwd, Vpmovsxwd, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwd, Vpmovsxwd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwq, Vpmovsxwq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwq, Vpmovsxwq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwq, Vpmovsxwq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwq, Vpmovsxwq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwq, Vpmovsxwq, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovsxwq, Vpmovsxwq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdb, Vpmovusdb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdb, Vpmovusdb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdb, Vpmovusdb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdb, Vpmovusdb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdb, Vpmovusdb, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdb, Vpmovusdb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdw, Vpmovusdw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdw, Vpmovusdw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdw, Vpmovusdw, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdw, Vpmovusdw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdw, Vpmovusdw, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusdw, Vpmovusdw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqb, Vpmovusqb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqb, Vpmovusqb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqb, Vpmovusqb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqb, Vpmovusqb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqb, Vpmovusqb, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqb, Vpmovusqb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqd, Vpmovusqd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqd, Vpmovusqd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqd, Vpmovusqd, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqd, Vpmovusqd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqd, Vpmovusqd, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqd, Vpmovusqd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqw, Vpmovusqw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqw, Vpmovusqw, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqw, Vpmovusqw, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqw, Vpmovusqw, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqw, Vpmovusqw, MXmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovusqw, Vpmovusqw, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovuswb, Vpmovuswb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovuswb, Vpmovuswb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovuswb, Vpmovuswb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovuswb, Vpmovuswb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovuswb, Vpmovuswb, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovuswb, Vpmovuswb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovw2m, Vpmovw2m, MKReg, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovw2m, Vpmovw2m, MKReg, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovw2m, Vpmovw2m, MKReg, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovwb, Vpmovwb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovwb, Vpmovwb, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovwb, Vpmovwb, MXmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovwb, Vpmovwb, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovwb, Vpmovwb, MYmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovwb, Vpmovwb, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbd, Vpmovzxbd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbd, Vpmovzxbd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbd, Vpmovzxbd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbd, Vpmovzxbd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbd, Vpmovzxbd, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbd, Vpmovzxbd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbq, Vpmovzxbq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbq, Vpmovzxbq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbq, Vpmovzxbq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbq, Vpmovzxbq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbq, Vpmovzxbq, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbq, Vpmovzxbq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbw, Vpmovzxbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbw, Vpmovzxbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbw, Vpmovzxbw, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbw, Vpmovzxbw, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbw, Vpmovzxbw, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxbw, Vpmovzxbw, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxdq, Vpmovzxdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxdq, Vpmovzxdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxdq, Vpmovzxdq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxdq, Vpmovzxdq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxdq, Vpmovzxdq, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxdq, Vpmovzxdq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwd, Vpmovzxwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwd, Vpmovzxwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwd, Vpmovzxwd, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwd, Vpmovzxwd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwd, Vpmovzxwd, MZmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwd, Vpmovzxwd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwq, Vpmovzxwq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwq, Vpmovzxwq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwq, Vpmovzxwq, MYmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwq, Vpmovzxwq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwq, Vpmovzxwq, MZmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpmovzxwq, Vpmovzxwq, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuldq, Vpmuldq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuldq, Vpmuldq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuldq, Vpmuldq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuldq, Vpmuldq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuldq, Vpmuldq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuldq, Vpmuldq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhrsw, Vpmulhrsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhrsw, Vpmulhrsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhrsw, Vpmulhrsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhrsw, Vpmulhrsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhrsw, Vpmulhrsw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhrsw, Vpmulhrsw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhuw, Vpmulhuw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhuw, Vpmulhuw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhuw, Vpmulhuw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhuw, Vpmulhuw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhuw, Vpmulhuw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhuw, Vpmulhuw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhw, Vpmulhw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhw, Vpmulhw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhw, Vpmulhw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhw, Vpmulhw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhw, Vpmulhw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulhw, Vpmulhw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulld, Vpmulld, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulld, Vpmulld, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulld, Vpmulld, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulld, Vpmulld, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulld, Vpmulld, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmulld, Vpmulld, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullq, Vpmullq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullq, Vpmullq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullq, Vpmullq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullq, Vpmullq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullq, Vpmullq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullq, Vpmullq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullw, Vpmullw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullw, Vpmullw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullw, Vpmullw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullw, Vpmullw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullw, Vpmullw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmullw, Vpmullw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmultishiftqb, Vpmultishiftqb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmultishiftqb, Vpmultishiftqb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmultishiftqb, Vpmultishiftqb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmultishiftqb, Vpmultishiftqb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmultishiftqb, Vpmultishiftqb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmultishiftqb, Vpmultishiftqb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuludq, Vpmuludq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuludq, Vpmuludq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuludq, Vpmuludq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuludq, Vpmuludq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuludq, Vpmuludq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpmuludq, Vpmuludq, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntb, Vpopcntb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntb, Vpopcntb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntb, Vpopcntb, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntb, Vpopcntb, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntb, Vpopcntb, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntb, Vpopcntb, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntd, Vpopcntd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntd, Vpopcntd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntd, Vpopcntd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntd, Vpopcntd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntd, Vpopcntd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntd, Vpopcntd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntq, Vpopcntq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntq, Vpopcntq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntq, Vpopcntq, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntq, Vpopcntq, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntq, Vpopcntq, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntq, Vpopcntq, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntw, Vpopcntw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntw, Vpopcntw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntw, Vpopcntw, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntw, Vpopcntw, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntw, Vpopcntw, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpopcntw, Vpopcntw, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpor, Vpor, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpor, Vpor, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpor, Vpor, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpor, Vpor, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpord, Vpord, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpord, Vpord, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpord, Vpord, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpord, Vpord, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpord, Vpord, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpord, Vpord, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vporq, Vporq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vporq, Vporq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vporq, Vporq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vporq, Vporq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vporq, Vporq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vporq, Vporq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprold, Vprold, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprold, Vprold, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprold, Vprold, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprold, Vprold, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprold, Vprold, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprold, Vprold, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprolq, Vprolq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprolq, Vprolq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprolq, Vprolq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprolq, Vprolq, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprolq, Vprolq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprolq, Vprolq, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvd, Vprolvd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvd, Vprolvd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvd, Vprolvd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvd, Vprolvd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvd, Vprolvd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvd, Vprolvd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvq, Vprolvq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvq, Vprolvq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvq, Vprolvq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvq, Vprolvq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvq, Vprolvq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprolvq, Vprolvq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprord, Vprord, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprord, Vprord, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprord, Vprord, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprord, Vprord, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprord, Vprord, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprord, Vprord, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprorq, Vprorq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprorq, Vprorq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprorq, Vprorq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprorq, Vprorq, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprorq, Vprorq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprorq, Vprorq, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvd, Vprorvd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvd, Vprorvd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvd, Vprorvd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvd, Vprorvd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvd, Vprorvd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvd, Vprorvd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvq, Vprorvq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvq, Vprorvq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvq, Vprorvq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvq, Vprorvq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvq, Vprorvq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprorvq, Vprorvq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsadbw, Vpsadbw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsadbw, Vpsadbw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsadbw, Vpsadbw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsadbw, Vpsadbw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsadbw, Vpsadbw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsadbw, Vpsadbw, MZmm, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterdd, Vpscatterdd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterdd, Vpscatterdd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterdd, Vpscatterdd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterdq, Vpscatterdq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterdq, Vpscatterdq, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterdq, Vpscatterdq, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterqd, Vpscatterqd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterqd, Vpscatterqd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterqq, Vpscatterqq, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterqq, Vpscatterqq, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vpscatterqq, Vpscatterqq, MMem, MZmm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshldd, Vpshldd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshldd, Vpshldd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshldd, Vpshldd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshldd, Vpshldd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshldd, Vpshldd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshldd, Vpshldd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvd, Vpshldvd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvd, Vpshldvd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvd, Vpshldvd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvd, Vpshldvd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvd, Vpshldvd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvd, Vpshldvd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvq, Vpshldvq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvq, Vpshldvq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvq, Vpshldvq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvq, Vpshldvq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvq, Vpshldvq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvq, Vpshldvq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvw, Vpshldvw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvw, Vpshldvw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvw, Vpshldvw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvw, Vpshldvw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvw, Vpshldvw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshldvw, Vpshldvw, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdd, Vpshrdd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdd, Vpshrdd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdd, Vpshrdd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdd, Vpshrdd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdd, Vpshrdd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdd, Vpshrdd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvd, Vpshrdvd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvd, Vpshrdvd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvd, Vpshrdvd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvd, Vpshrdvd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvd, Vpshrdvd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvd, Vpshrdvd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvq, Vpshrdvq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvq, Vpshrdvq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvq, Vpshrdvq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvq, Vpshrdvq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvq, Vpshrdvq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvq, Vpshrdvq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvw, Vpshrdvw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvw, Vpshrdvw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvw, Vpshrdvw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvw, Vpshrdvw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvw, Vpshrdvw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshrdvw, Vpshrdvw, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdw, Vpshrdw, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdw, Vpshrdw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdw, Vpshrdw, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdw, Vpshrdw, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdw, Vpshrdw, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpshrdw, Vpshrdw, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufb, Vpshufb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufb, Vpshufb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufb, Vpshufb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufb, Vpshufb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufb, Vpshufb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufb, Vpshufb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufbitqmb, Vpshufbitqmb, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufbitqmb, Vpshufbitqmb, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufbitqmb, Vpshufbitqmb, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufbitqmb, Vpshufbitqmb, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufbitqmb, Vpshufbitqmb, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshufbitqmb, Vpshufbitqmb, MKReg, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufd, Vpshufd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufd, Vpshufd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufd, Vpshufd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufd, Vpshufd, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufd, Vpshufd, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufd, Vpshufd, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufhw, Vpshufhw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufhw, Vpshufhw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufhw, Vpshufhw, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufhw, Vpshufhw, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufhw, Vpshufhw, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshufhw, Vpshufhw, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshuflw, Vpshuflw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshuflw, Vpshuflw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshuflw, Vpshuflw, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshuflw, Vpshuflw, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshuflw, Vpshuflw, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpshuflw, Vpshuflw, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignb, Vpsignb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignb, Vpsignb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignb, Vpsignb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignb, Vpsignb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignd, Vpsignd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignd, Vpsignd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignd, Vpsignd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignd, Vpsignd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignw, Vpsignw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignw, Vpsignw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignw, Vpsignw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsignw, Vpsignw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslld, Vpslld, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslldq, Vpslldq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslldq, Vpslldq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslldq, Vpslldq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslldq, Vpslldq, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslldq, Vpslldq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpslldq, Vpslldq, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllq, Vpsllq, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvd, Vpsllvd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvd, Vpsllvd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvd, Vpsllvd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvd, Vpsllvd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvd, Vpsllvd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvd, Vpsllvd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvq, Vpsllvq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvq, Vpsllvq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvq, Vpsllvq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvq, Vpsllvq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvq, Vpsllvq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvq, Vpsllvq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvw, Vpsllvw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvw, Vpsllvw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvw, Vpsllvw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvw, Vpsllvw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvw, Vpsllvw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllvw, Vpsllvw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsllw, Vpsllw, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrad, Vpsrad, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraq, Vpsraq, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravd, Vpsravd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravd, Vpsravd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravd, Vpsravd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravd, Vpsravd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravd, Vpsravd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravd, Vpsravd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravq, Vpsravq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravq, Vpsravq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravq, Vpsravq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravq, Vpsravq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravq, Vpsravq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravq, Vpsravq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravw, Vpsravw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravw, Vpsravw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravw, Vpsravw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravw, Vpsravw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravw, Vpsravw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsravw, Vpsravw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsraw, Vpsraw, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrld, Vpsrld, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrldq, Vpsrldq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrldq, Vpsrldq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrldq, Vpsrldq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrldq, Vpsrldq, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrldq, Vpsrldq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrldq, Vpsrldq, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlq, Vpsrlq, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvd, Vpsrlvd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvd, Vpsrlvd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvd, Vpsrlvd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvd, Vpsrlvd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvd, Vpsrlvd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvd, Vpsrlvd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvq, Vpsrlvq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvq, Vpsrlvq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvq, Vpsrlvq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvq, Vpsrlvq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvq, Vpsrlvq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvq, Vpsrlvq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvw, Vpsrlvw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvw, Vpsrlvw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvw, Vpsrlvw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvw, Vpsrlvw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvw, Vpsrlvw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlvw, Vpsrlvw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MYmm, MYmm, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MYmm, MYmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MYmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MZmm, MZmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vpsrlw, Vpsrlw, MZmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubb, Vpsubb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubb, Vpsubb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubb, Vpsubb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubb, Vpsubb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubb, Vpsubb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubb, Vpsubb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubd, Vpsubd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubd, Vpsubd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubd, Vpsubd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubd, Vpsubd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubd, Vpsubd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubd, Vpsubd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubq, Vpsubq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubq, Vpsubq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubq, Vpsubq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubq, Vpsubq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubq, Vpsubq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubq, Vpsubq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsb, Vpsubsb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsb, Vpsubsb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsb, Vpsubsb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsb, Vpsubsb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsb, Vpsubsb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsb, Vpsubsb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsw, Vpsubsw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsw, Vpsubsw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsw, Vpsubsw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsw, Vpsubsw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsw, Vpsubsw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubsw, Vpsubsw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusb, Vpsubusb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusb, Vpsubusb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusb, Vpsubusb, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusb, Vpsubusb, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusb, Vpsubusb, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusb, Vpsubusb, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusw, Vpsubusw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusw, Vpsubusw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusw, Vpsubusw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusw, Vpsubusw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusw, Vpsubusw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubusw, Vpsubusw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubw, Vpsubw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubw, Vpsubw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubw, Vpsubw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubw, Vpsubw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubw, Vpsubw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpsubw, Vpsubw, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogd, Vpternlogd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogd, Vpternlogd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogd, Vpternlogd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogd, Vpternlogd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogd, Vpternlogd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogd, Vpternlogd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogq, Vpternlogq, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogq, Vpternlogq, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogq, Vpternlogq, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogq, Vpternlogq, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogq, Vpternlogq, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpternlogq, Vpternlogq, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vptest, Vptest, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vptest, Vptest, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vptest, Vptest, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vptest, Vptest, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmb, Vptestmb, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmb, Vptestmb, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmb, Vptestmb, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmb, Vptestmb, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmb, Vptestmb, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmb, Vptestmb, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmd, Vptestmd, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmd, Vptestmd, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmd, Vptestmd, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmd, Vptestmd, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmd, Vptestmd, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmd, Vptestmd, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmq, Vptestmq, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmq, Vptestmq, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmq, Vptestmq, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmq, Vptestmq, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmq, Vptestmq, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmq, Vptestmq, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmw, Vptestmw, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmw, Vptestmw, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmw, Vptestmw, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmw, Vptestmw, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmw, Vptestmw, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestmw, Vptestmw, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmb, Vptestnmb, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmb, Vptestnmb, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmb, Vptestnmb, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmb, Vptestnmb, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmb, Vptestnmb, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmb, Vptestnmb, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmd, Vptestnmd, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmd, Vptestnmd, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmd, Vptestnmd, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmd, Vptestnmd, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmd, Vptestnmd, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmd, Vptestnmd, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmq, Vptestnmq, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmq, Vptestnmq, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmq, Vptestnmq, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmq, Vptestnmq, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmq, Vptestnmq, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmq, Vptestnmq, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmw, Vptestnmw, MKReg, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmw, Vptestnmw, MKReg, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmw, Vptestnmw, MKReg, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmw, Vptestnmw, MKReg, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmw, Vptestnmw, MKReg, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vptestnmw, Vptestnmw, MKReg, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhbw, Vpunpckhbw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhbw, Vpunpckhbw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhbw, Vpunpckhbw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhbw, Vpunpckhbw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhbw, Vpunpckhbw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhbw, Vpunpckhbw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhdq, Vpunpckhdq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhdq, Vpunpckhdq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhdq, Vpunpckhdq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhdq, Vpunpckhdq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhdq, Vpunpckhdq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhdq, Vpunpckhdq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhqdq, Vpunpckhqdq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhqdq, Vpunpckhqdq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhqdq, Vpunpckhqdq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhqdq, Vpunpckhqdq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhqdq, Vpunpckhqdq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhqdq, Vpunpckhqdq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhwd, Vpunpckhwd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhwd, Vpunpckhwd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhwd, Vpunpckhwd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhwd, Vpunpckhwd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhwd, Vpunpckhwd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckhwd, Vpunpckhwd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklbw, Vpunpcklbw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklbw, Vpunpcklbw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklbw, Vpunpcklbw, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklbw, Vpunpcklbw, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklbw, Vpunpcklbw, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklbw, Vpunpcklbw, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckldq, Vpunpckldq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckldq, Vpunpckldq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckldq, Vpunpckldq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckldq, Vpunpckldq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckldq, Vpunpckldq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpckldq, Vpunpckldq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklqdq, Vpunpcklqdq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklqdq, Vpunpcklqdq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklqdq, Vpunpcklqdq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklqdq, Vpunpcklqdq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklqdq, Vpunpcklqdq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklqdq, Vpunpcklqdq, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklwd, Vpunpcklwd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklwd, Vpunpcklwd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklwd, Vpunpcklwd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklwd, Vpunpcklwd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklwd, Vpunpcklwd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpunpcklwd, Vpunpcklwd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxor, Vpxor, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxor, Vpxor, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxor, Vpxor, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxor, Vpxor, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxord, Vpxord, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxord, Vpxord, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxord, Vpxord, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxord, Vpxord, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxord, Vpxord, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxord, Vpxord, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxorq, Vpxorq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxorq, Vpxorq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxorq, Vpxorq, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxorq, Vpxorq, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxorq, Vpxorq, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpxorq, Vpxorq, MZmm, MZmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangepd, Vrangepd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangepd, Vrangepd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangepd, Vrangepd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangepd, Vrangepd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangepd, Vrangepd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangepd, Vrangepd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangeps, Vrangeps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangeps, Vrangeps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangeps, Vrangeps, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangeps, Vrangeps, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangeps, Vrangeps, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangeps, Vrangeps, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangesd, Vrangesd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangesd, Vrangesd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangess, Vrangess, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrangess, Vrangess, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14pd, Vrcp14pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14pd, Vrcp14pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14pd, Vrcp14pd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14pd, Vrcp14pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14pd, Vrcp14pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14pd, Vrcp14pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14ps, Vrcp14ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14ps, Vrcp14ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14ps, Vrcp14ps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14ps, Vrcp14ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14ps, Vrcp14ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp14ps, Vrcp14ps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp14sd, Vrcp14sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp14sd, Vrcp14sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp14ss, Vrcp14ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp14ss, Vrcp14ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp28pd, Vrcp28pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp28pd, Vrcp28pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp28ps, Vrcp28ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcp28ps, Vrcp28ps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp28sd, Vrcp28sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp28sd, Vrcp28sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp28ss, Vrcp28ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcp28ss, Vrcp28ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcpps, Vrcpps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcpps, Vrcpps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcpps, Vrcpps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrcpps, Vrcpps, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcpss, Vrcpss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrcpss, Vrcpss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreducepd, Vreducepd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreducepd, Vreducepd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreducepd, Vreducepd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreducepd, Vreducepd, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreducepd, Vreducepd, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreducepd, Vreducepd, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreduceps, Vreduceps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreduceps, Vreduceps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreduceps, Vreduceps, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreduceps, Vreduceps, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreduceps, Vreduceps, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vreduceps, Vreduceps, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vreducesd, Vreducesd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vreducesd, Vreducesd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vreducess, Vreducess, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vreducess, Vreducess, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscalepd, Vrndscalepd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscalepd, Vrndscalepd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscalepd, Vrndscalepd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscalepd, Vrndscalepd, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscalepd, Vrndscalepd, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscalepd, Vrndscalepd, MZmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscaleps, Vrndscaleps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscaleps, Vrndscaleps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscaleps, Vrndscaleps, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscaleps, Vrndscaleps, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscaleps, Vrndscaleps, MZmm, MZmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vrndscaleps, Vrndscaleps, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrndscalesd, Vrndscalesd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrndscalesd, Vrndscalesd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrndscaless, Vrndscaless, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vrndscaless, Vrndscaless, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundpd, Vroundpd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundpd, Vroundpd, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundpd, Vroundpd, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundpd, Vroundpd, MYmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundps, Vroundps, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundps, Vroundps, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundps, Vroundps, MYmm, MYmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vroundps, Vroundps, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vroundsd, Vroundsd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vroundsd, Vroundsd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vroundss, Vroundss, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vroundss, Vroundss, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14pd, Vrsqrt14pd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14pd, Vrsqrt14pd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14pd, Vrsqrt14pd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14pd, Vrsqrt14pd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14pd, Vrsqrt14pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14pd, Vrsqrt14pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14ps, Vrsqrt14ps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14ps, Vrsqrt14ps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14ps, Vrsqrt14ps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14ps, Vrsqrt14ps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14ps, Vrsqrt14ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt14ps, Vrsqrt14ps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt14sd, Vrsqrt14sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt14sd, Vrsqrt14sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt14ss, Vrsqrt14ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt14ss, Vrsqrt14ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt28pd, Vrsqrt28pd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt28pd, Vrsqrt28pd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt28ps, Vrsqrt28ps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrt28ps, Vrsqrt28ps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt28sd, Vrsqrt28sd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt28sd, Vrsqrt28sd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt28ss, Vrsqrt28ss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrt28ss, Vrsqrt28ss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrtps, Vrsqrtps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrtps, Vrsqrtps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrtps, Vrsqrtps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vrsqrtps, Vrsqrtps, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrtss, Vrsqrtss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vrsqrtss, Vrsqrtss, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefpd, Vscalefpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefpd, Vscalefpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefpd, Vscalefpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefpd, Vscalefpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefpd, Vscalefpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefpd, Vscalefpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefps, Vscalefps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefps, Vscalefps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefps, Vscalefps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefps, Vscalefps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefps, Vscalefps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefps, Vscalefps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefsd, Vscalefsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefsd, Vscalefsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefss, Vscalefss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vscalefss, Vscalefss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterdpd, Vscatterdpd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterdpd, Vscatterdpd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterdpd, Vscatterdpd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterdps, Vscatterdps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterdps, Vscatterdps, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterdps, Vscatterdps, MMem, MZmm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf0dpd, Vscatterpf0dpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf0dps, Vscatterpf0dps, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf0qpd, Vscatterpf0qpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf0qps, Vscatterpf0qps, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf1dpd, Vscatterpf1dpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf1dps, Vscatterpf1dps, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf1qpd, Vscatterpf1qpd, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vscatterpf1qps, Vscatterpf1qps, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterqpd, Vscatterqpd, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterqpd, Vscatterqpd, MMem, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterqpd, Vscatterqpd, MMem, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterqps, Vscatterqps, MMem, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vscatterqps, Vscatterqps, MMem, MYmm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff32x4, Vshuff32x4, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff32x4, Vshuff32x4, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff32x4, Vshuff32x4, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff32x4, Vshuff32x4, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff64x2, Vshuff64x2, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff64x2, Vshuff64x2, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff64x2, Vshuff64x2, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshuff64x2, Vshuff64x2, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi32x4, Vshufi32x4, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi32x4, Vshufi32x4, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi32x4, Vshufi32x4, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi32x4, Vshufi32x4, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi64x2, Vshufi64x2, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi64x2, Vshufi64x2, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi64x2, Vshufi64x2, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufi64x2, Vshufi64x2, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufpd, Vshufpd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufpd, Vshufpd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufpd, Vshufpd, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufpd, Vshufpd, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufpd, Vshufpd, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufpd, Vshufpd, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufps, Vshufps, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufps, Vshufps, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufps, Vshufps, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufps, Vshufps, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufps, Vshufps, MZmm, MZmm, MZmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vshufps, Vshufps, MZmm, MZmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtpd, Vsqrtpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtpd, Vsqrtpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtpd, Vsqrtpd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtpd, Vsqrtpd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtpd, Vsqrtpd, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtpd, Vsqrtpd, MZmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtps, Vsqrtps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtps, Vsqrtps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtps, Vsqrtps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtps, Vsqrtps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtps, Vsqrtps, MZmm, MZmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vsqrtps, Vsqrtps, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsqrtsd, Vsqrtsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsqrtsd, Vsqrtsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsqrtss, Vsqrtss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsqrtss, Vsqrtss, MXmm, MXmm, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterExplicit, vstmxcsr, Vstmxcsr, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubpd, Vsubpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubpd, Vsubpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubpd, Vsubpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubpd, Vsubpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubpd, Vsubpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubpd, Vsubpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubps, Vsubps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubps, Vsubps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubps, Vsubps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubps, Vsubps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubps, Vsubps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubps, Vsubps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubsd, Vsubsd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubsd, Vsubsd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubss, Vsubss, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vsubss, Vsubss, MXmm, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestpd, Vtestpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestpd, Vtestpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestpd, Vtestpd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestpd, Vtestpd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestps, Vtestps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestps, Vtestps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestps, Vtestps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vtestps, Vtestps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vucomisd, Vucomisd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vucomisd, Vucomisd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vucomiss, Vucomiss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vucomiss, Vucomiss, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhpd, Vunpckhpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhpd, Vunpckhpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhpd, Vunpckhpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhpd, Vunpckhpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhpd, Vunpckhpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhpd, Vunpckhpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhps, Vunpckhps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhps, Vunpckhps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhps, Vunpckhps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhps, Vunpckhps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhps, Vunpckhps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpckhps, Vunpckhps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklpd, Vunpcklpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklpd, Vunpcklpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklpd, Vunpcklpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklpd, Vunpcklpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklpd, Vunpcklpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklpd, Vunpcklpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklps, Vunpcklps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklps, Vunpcklps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklps, Vunpcklps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklps, Vunpcklps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklps, Vunpcklps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vunpcklps, Vunpcklps, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorpd, Vxorpd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorpd, Vxorpd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorpd, Vxorpd, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorpd, Vxorpd, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorpd, Vxorpd, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorpd, Vxorpd, MZmm, MZmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorps, Vxorps, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorps, Vxorps, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorps, Vxorps, MYmm, MYmm, MYmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorps, Vxorps, MYmm, MYmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorps, Vxorps, MZmm, MZmm, MZmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vxorps, Vxorps, MZmm, MZmm, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vzeroall, Vzeroall);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterExplicit, vzeroupper, Vzeroupper);






			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddpd, Vfmaddpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddpd, Vfmaddpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddpd, Vfmaddpd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddpd, Vfmaddpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddpd, Vfmaddpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddpd, Vfmaddpd, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddps, Vfmaddps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddps, Vfmaddps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddps, Vfmaddps, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddps, Vfmaddps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddps, Vfmaddps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddps, Vfmaddps, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsd, Vfmaddsd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsd, Vfmaddsd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsd, Vfmaddsd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddss, Vfmaddss, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddss, Vfmaddss, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddss, Vfmaddss, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubpd, Vfmaddsubpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubpd, Vfmaddsubpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubpd, Vfmaddsubpd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubpd, Vfmaddsubpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubpd, Vfmaddsubpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubpd, Vfmaddsubpd, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubps, Vfmaddsubps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubps, Vfmaddsubps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubps, Vfmaddsubps, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubps, Vfmaddsubps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubps, Vfmaddsubps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmaddsubps, Vfmaddsubps, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddpd, Vfmsubaddpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddpd, Vfmsubaddpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddpd, Vfmsubaddpd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddpd, Vfmsubaddpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddpd, Vfmsubaddpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddpd, Vfmsubaddpd, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddps, Vfmsubaddps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddps, Vfmsubaddps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddps, Vfmsubaddps, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddps, Vfmsubaddps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddps, Vfmsubaddps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubaddps, Vfmsubaddps, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubpd, Vfmsubpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubpd, Vfmsubpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubpd, Vfmsubpd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubpd, Vfmsubpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubpd, Vfmsubpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubpd, Vfmsubpd, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubps, Vfmsubps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubps, Vfmsubps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubps, Vfmsubps, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubps, Vfmsubps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubps, Vfmsubps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubps, Vfmsubps, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubsd, Vfmsubsd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubsd, Vfmsubsd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubsd, Vfmsubsd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubss, Vfmsubss, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubss, Vfmsubss, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfmsubss, Vfmsubss, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddpd, Vfnmaddpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddpd, Vfnmaddpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddpd, Vfnmaddpd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddpd, Vfnmaddpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddpd, Vfnmaddpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddpd, Vfnmaddpd, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddps, Vfnmaddps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddps, Vfnmaddps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddps, Vfnmaddps, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddps, Vfnmaddps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddps, Vfnmaddps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddps, Vfnmaddps, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddsd, Vfnmaddsd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddsd, Vfnmaddsd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddsd, Vfnmaddsd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddss, Vfnmaddss, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddss, Vfnmaddss, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmaddss, Vfnmaddss, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubpd, Vfnmsubpd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubpd, Vfnmsubpd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubpd, Vfnmsubpd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubpd, Vfnmsubpd, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubpd, Vfnmsubpd, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubpd, Vfnmsubpd, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubps, Vfnmsubps, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubps, Vfnmsubps, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubps, Vfnmsubps, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubps, Vfnmsubps, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubps, Vfnmsubps, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubps, Vfnmsubps, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubsd, Vfnmsubsd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubsd, Vfnmsubsd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubsd, Vfnmsubsd, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubss, Vfnmsubss, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubss, Vfnmsubss, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vfnmsubss, Vfnmsubss, MXmm, MXmm, MXmm, MMem);






			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczpd, Vfrczpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczpd, Vfrczpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczpd, Vfrczpd, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczpd, Vfrczpd, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczps, Vfrczps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczps, Vfrczps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczps, Vfrczps, MYmm, MYmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczps, Vfrczps, MYmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczsd, Vfrczsd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczsd, Vfrczsd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczss, Vfrczss, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vfrczss, Vfrczss, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmov, Vpcmov, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmov, Vpcmov, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmov, Vpcmov, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmov, Vpcmov, MYmm, MYmm, MYmm, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmov, Vpcmov, MYmm, MYmm, MMem, MYmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpcmov, Vpcmov, MYmm, MYmm, MYmm, MMem);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomb, Vpcomb, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomb, Vpcomb, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomd, Vpcomd, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomd, Vpcomd, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomq, Vpcomq, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomq, Vpcomq, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomw, Vpcomw, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomw, Vpcomw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomub, Vpcomub, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomub, Vpcomub, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomud, Vpcomud, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomud, Vpcomud, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomuq, Vpcomuq, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomuq, Vpcomuq, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomuw, Vpcomuw, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_4i(AsmJit::X86::EmitterExplicit, vpcomuw, Vpcomuw, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MXmm, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MXmm, MXmm, MMem, MXmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MXmm, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MYmm, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MYmm, MYmm, MMem, MYmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2pd, Vpermil2pd, MYmm, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2ps, Vpermil2ps, MXmm, MXmm, MXmm, MXmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2ps, Vpermil2ps, MXmm, MXmm, MMem, MXmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2ps, Vpermil2ps, MXmm, MXmm, MXmm, MMem, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2ps, Vpermil2ps, MYmm, MYmm, MYmm, MYmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2ps, Vpermil2ps, MYmm, MYmm, MMem, MYmm, MImm);
			MWASMJIT_INST_5i(AsmJit::X86::EmitterExplicit, vpermil2ps, Vpermil2ps, MYmm, MYmm, MYmm, MMem, MImm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddbd, Vphaddbd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddbd, Vphaddbd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddbq, Vphaddbq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddbq, Vphaddbq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddbw, Vphaddbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddbw, Vphaddbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphadddq, Vphadddq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphadddq, Vphadddq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddwd, Vphaddwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddwd, Vphaddwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddwq, Vphaddwq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddwq, Vphaddwq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddubd, Vphaddubd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddubd, Vphaddubd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddubq, Vphaddubq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddubq, Vphaddubq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddubw, Vphaddubw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddubw, Vphaddubw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddudq, Vphaddudq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphaddudq, Vphaddudq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphadduwd, Vphadduwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphadduwd, Vphadduwd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphadduwq, Vphadduwq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphadduwq, Vphadduwq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphsubbw, Vphsubbw, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphsubbw, Vphsubbw, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphsubdq, Vphsubdq, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphsubdq, Vphsubdq, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphsubwd, Vphsubwd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterExplicit, vphsubwd, Vphsubwd, MXmm, MMem);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsdd, Vpmacsdd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsdd, Vpmacsdd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsdqh, Vpmacsdqh, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsdqh, Vpmacsdqh, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsdql, Vpmacsdql, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsdql, Vpmacsdql, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacswd, Vpmacswd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacswd, Vpmacswd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsww, Vpmacsww, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsww, Vpmacsww, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssdd, Vpmacssdd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssdd, Vpmacssdd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssdqh, Vpmacssdqh, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssdqh, Vpmacssdqh, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssdql, Vpmacssdql, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssdql, Vpmacssdql, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsswd, Vpmacsswd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacsswd, Vpmacsswd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssww, Vpmacssww, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmacssww, Vpmacssww, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmadcsswd, Vpmadcsswd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmadcsswd, Vpmadcsswd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmadcswd, Vpmadcswd, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpmadcswd, Vpmadcswd, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpperm, Vpperm, MXmm, MXmm, MXmm, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpperm, Vpperm, MXmm, MXmm, MMem, MXmm);
			MWASMJIT_INST_4x(AsmJit::X86::EmitterExplicit, vpperm, Vpperm, MXmm, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotb, Vprotb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotb, Vprotb, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotb, Vprotb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotb, Vprotb, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotb, Vprotb, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotd, Vprotd, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotd, Vprotd, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotd, Vprotd, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotd, Vprotd, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotd, Vprotd, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotq, Vprotq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotq, Vprotq, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotq, Vprotq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotq, Vprotq, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotq, Vprotq, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotw, Vprotw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotw, Vprotw, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vprotw, Vprotw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotw, Vprotw, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterExplicit, vprotw, Vprotw, MXmm, MMem, MImm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshab, Vpshab, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshab, Vpshab, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshab, Vpshab, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshad, Vpshad, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshad, Vpshad, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshad, Vpshad, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshaq, Vpshaq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshaq, Vpshaq, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshaq, Vpshaq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshaw, Vpshaw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshaw, Vpshaw, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshaw, Vpshaw, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlb, Vpshlb, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlb, Vpshlb, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlb, Vpshlb, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshld, Vpshld, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshld, Vpshld, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshld, Vpshld, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlq, Vpshlq, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlq, Vpshlq, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlq, Vpshlq, MXmm, MXmm, MMem);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlw, Vpshlw, MXmm, MXmm, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlw, Vpshlw, MXmm, MMem, MXmm);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterExplicit, vpshlw, Vpshlw, MXmm, MXmm, MMem);

		};

		[ExtensionAttribute]
		public ref class EmitterImplicitHelper abstract sealed {
		public:

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void Rep(T t) { return EmitterExplicitHelper::AddInstOptions(t, asmjit::x86::Inst::kOptionRep); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void Repe(T t) { return Rep(t); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void Repz(T t) { return Rep(t); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void Repne(T t) { return EmitterExplicitHelper::AddInstOptions(t, asmjit::x86::Inst::kOptionRepne); }

			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void Repnz(T t) { return Repne(t); }


			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cbw, Cbw);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cdq, Cdq);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cdqe, Cdqe);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, cmpxchg, Cmpxchg, MGp, MGp);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, cmpxchg, Cmpxchg, MMem, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, cmpxchg16b, Cmpxchg16b, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, cmpxchg8b, Cmpxchg8b, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cpuid, Cpuid);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cqo, Cqo);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cwd, Cwd);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, cwde, Cwde);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, daa, Daa);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, das, Das);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, div, Div, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, div, Div, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, idiv, Idiv, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, idiv, Idiv, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, imul, Imul, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, imul, Imul, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, iret, Iret);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, iretd, Iretd);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, iretq, Iretq);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, iretw, Iretw);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, jecxz, Jecxz, MLabel);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, jecxz, Jecxz, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, jecxz, Jecxz, uint64_t);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, lahf, Lahf);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loop, Loop, MLabel);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loop, Loop, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loop, Loop, uint64_t);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loope, Loope, MLabel);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loope, Loope, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loope, Loope, uint64_t);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loopne, Loopne, MLabel);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loopne, Loopne, MImm);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, loopne, Loopne, uint64_t);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, mul, Mul, MGp);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, mul, Mul, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, rdmsr, Rdmsr);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, rdpmc, Rdpmc);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, rdtsc, Rdtsc);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, rdtscp, Rdtscp);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, ret, Ret);
			MWASMJIT_INST_1i(AsmJit::X86::EmitterImplicit, ret, Ret, MImm);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, sahf, Sahf);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, syscall, Syscall);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, sysenter, Sysenter);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, sysexit, Sysexit);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, sysexit64, Sysexit64);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, sysret, Sysret);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, sysret64, Sysret64);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, wrmsr, Wrmsr);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, xlatb, Xlatb);



			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void cmpsb(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdCmps, EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 1), EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 1)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void cmpsd(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdCmps, EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 4), EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 4)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void cmpsq(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdCmps, EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 8), EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 8)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void cmpsw(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdCmps, EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 2), EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 2)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void lodsb(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdLods, AsmJit::X86::Operand::RegsDef::al, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 1)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void lodsd(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdLods, AsmJit::X86::Operand::RegsDef::eax, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 4)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void lodsq(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdLods, AsmJit::X86::Operand::RegsDef::rax, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 8)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void lodsw(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdLods, AsmJit::X86::Operand::RegsDef::ax, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 2)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void movsb(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdMovs, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 1), EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 1)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void movsd(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdMovs, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 4), EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 4)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void movsq(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdMovs, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 8), EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 8)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void movsw(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdMovs, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 2), EmitterExplicitHelper::Pointer_zsi((AsmJit::X86::EmitterExplicit^)t, 0, 2)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void scasb(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdScas, AsmJit::X86::Operand::RegsDef::al, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 1)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void scasd(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdScas, AsmJit::X86::Operand::RegsDef::eax, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 4)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void scasq(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdScas, AsmJit::X86::Operand::RegsDef::rax, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 8)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void scasw(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdScas, AsmJit::X86::Operand::RegsDef::ax, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 2)); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void stosb(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdStos, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 1), AsmJit::X86::Operand::RegsDef::al); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void stosd(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdStos, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 4), AsmJit::X86::Operand::RegsDef::eax); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void stosq(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdStos, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 8), AsmJit::X86::Operand::RegsDef::rax); }
			MWASMJIT_EXTENSION_METHOD(AsmJit::X86::EmitterImplicit) void stosw(T t) { t->Emitter()->Emit(asmjit::x86::Inst::kIdStos, EmitterExplicitHelper::Pointer_zdi((AsmJit::X86::EmitterExplicit^)t, 0, 2), AsmJit::X86::Operand::RegsDef::ax); }



			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, clzero, Clzero);



			MWASMJIT_INST_3x(AsmJit::X86::EmitterImplicit, mulx, Mulx, MGp, MGp, MGp);
			MWASMJIT_INST_3x(AsmJit::X86::EmitterImplicit, mulx, Mulx, MGp, MGp, MMem);



			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, xgetbv, Xgetbv);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xrstor, Xrstor, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xrstor64, Xrstor64, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xrstors, Xrstors, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xrstors64, Xrstors64, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsave, Xsave, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsave64, Xsave64, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsavec, Xsavec, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsavec64, Xsavec64, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsaveopt, Xsaveopt, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsaveopt64, Xsaveopt64, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsaves, Xsaves, MMem);
			MWASMJIT_INST_1x(AsmJit::X86::EmitterImplicit, xsaves64, Xsaves64, MMem);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, xsetbv, Xsetbv);



			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, monitor, Monitor);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, monitorx, Monitorx);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, mwait, Mwait);
			MWASMJIT_INST_0x(AsmJit::X86::EmitterImplicit, mwaitx, Mwaitx);














			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, blendvpd, Blendvpd, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, blendvpd, Blendvpd, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, blendvps, Blendvps, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, blendvps, Blendvps, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, pblendvb, Pblendvb, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, pblendvb, Pblendvb, MXmm, MMem);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, maskmovq, Maskmovq, MMm, MMm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, maskmovdqu, Maskmovdqu, MXmm, MXmm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpestri, Pcmpestri, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpestri, Pcmpestri, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpestrm, Pcmpestrm, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpestrm, Pcmpestrm, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpistri, Pcmpistri, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpistri, Pcmpistri, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpistrm, Pcmpistrm, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, pcmpistrm, Pcmpistrm, MXmm, MMem, MImm);




			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, sha256rnds2, Sha256rnds2, MXmm, MXmm);
			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, sha256rnds2, Sha256rnds2, MXmm, MMem);








			MWASMJIT_INST_2x(AsmJit::X86::EmitterImplicit, vmaskmovdqu, Vmaskmovdqu, MXmm, MXmm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpestri, Vpcmpestri, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpestri, Vpcmpestri, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpestrm, Vpcmpestrm, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpestrm, Vpcmpestrm, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpistri, Vpcmpistri, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpistri, Vpcmpistri, MXmm, MMem, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpistrm, Vpcmpistrm, MXmm, MXmm, MImm);
			MWASMJIT_INST_3i(AsmJit::X86::EmitterImplicit, vpcmpistrm, Vpcmpistrm, MXmm, MMem, MImm);

		};
	}
}