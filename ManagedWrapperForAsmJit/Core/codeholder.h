#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		public ref class CodeHolder {
			MWASMJIT_NATIVEPOINTER(CodeHolder, asmjit::CodeHolder);
		public:
			ref class CodeBuffer {
				MWASMJIT_NATIVEPOINTER(CodeBuffer, asmjit::CodeBuffer);
			public:
				enum class CodeBufferFlags : uint32_t {
					kFlagIsExternal = 0x00000001u,
					kFlagIsFixed = 0x00000002u
				};
				MWASMJIT_NATIVEPROPERTY_WRAPPER_GETTERONLY(uint8_t*, Data, _data);
				MWASMJIT_NATIVEPROPERTY_WRAPPER_GETTERONLY(size_t, Size, _size);
				MWASMJIT_NATIVEPROPERTY_WRAPPER_GETTERONLY(size_t, Capacity, _capacity);

				property System::IntPtr DataPointer {
					System::IntPtr get() {
						return (System::IntPtr)_NativePointer->_data;
					}
				};

				property CodeBufferFlags Flags {
					CodeBufferFlags get() {
						return (CodeBufferFlags)_NativePointer->_flags;
					}
					void set(CodeBufferFlags f) {
						_NativePointer->_flags = (uint32_t)f;
					}
				};

			internal:
				CodeBuffer(asmjit::CodeBuffer& cb) {
					_NativePointer = &cb;
				}
			public:
				CodeBuffer() {
					_NativePointer = new asmjit::CodeBuffer();
				}
				~CodeBuffer() {
					delete NativePointer;
				}
			};

			ref class Section {
				MWASMJIT_NATIVEPOINTER(Section, asmjit::Section);
			public:
				enum class SectionFlags :uint32_t {
					kFlagExec = 0x00000001u,
					kFlagConst = 0x00000002u,
					kFlagZero = 0x00000004u,
					kFlagInfo = 0x00000008u,
					kFlagImplicit = 0x80000000u
				};
			private:CodeBuffer^ _Buffer;
			public:

			internal:
				Section(asmjit::Section& section) {
					_NativePointer = &section;
					_Buffer = gcnew CodeBuffer(_NativePointer->_buffer);
				}
			public:

				Section() {
					_NativePointer = new asmjit::Section();
					_Buffer = gcnew CodeBuffer(_NativePointer->_buffer);
				}
				~Section() {
					delete NativePointer;
				}

				MWASMJIT_NATIVEPROPERTY_WRAPPER(uint32_t, ID, _id);
				MWASMJIT_NATIVEPROPERTY_WRAPPER(uint32_t, Alignment, _alignment);
				MWASMJIT_NATIVEPROPERTY_WRAPPER(uint32_t, Reserved, _reserved);
				MWASMJIT_NATIVEPROPERTY_WRAPPER(uint64_t, Offset, _offset);
				MWASMJIT_NATIVEPROPERTY_WRAPPER(uint64_t, VirtualSize, _virtualSize);

				property SectionFlags Flags {
					SectionFlags get() {
						return (SectionFlags)_NativePointer->_flags;
					}
					void set(SectionFlags f) {
						_NativePointer->_flags = (uint32_t)f;
					}
				};
				property CodeBuffer^ Buffer {
					CodeBuffer^ get() {
						return _Buffer;
					}
				};
				property System::String^ Name {
					System::String^ get() {
						return gcnew System::String(NativePointer->_name.str);
					}
					void set(System::String^ f) {
						if (f->Length > asmjit::Globals::kMaxSectionNameSize)
							throw gcnew System::Exception(System::String::Format("The name is too long:{0}", f));
						char* str2 = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(f);
						int i = 0;
						for (i = 0; i < f->Length; i++)
						{
							_NativePointer->_name.str[i] = str2[i];
						}
						_NativePointer->_name.str[i] = 0;
						System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)str2);
					}
				};
			};

			property array<Section^>^ Sections {
				array<Section^>^ get() {
					size_t srcLen = _NativePointer->_sections.size();
					array<Section^>^ a = gcnew array<Section^>(srcLen);
					for (size_t i = 0; i < srcLen; i++)
					{
						a[i] = gcnew Section(*_NativePointer->_sections[i]);
					}
					return a;
				}
			}


			CodeHolder() {
				_NativePointer = new asmjit::CodeHolder();
			}
			~CodeHolder() {
				delete NativePointer;
			}
			void Initialize(CodeInfo^ info) {
				_NativePointer->init(*info->NativePointer);
			}

			bool IsInitialized() {
				return NativePointer->isInitialized();
			}

			void Reset(AsmJit::Core::Globals::ResetPolicy policy) {
				NativePointer->reset((uint32_t)policy);
			}


		};
	}
}