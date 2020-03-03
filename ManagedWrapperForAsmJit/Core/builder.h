#pragma once
#include "../MWAsmJit.h"
namespace AsmJit {
	namespace Core {
		namespace Nodes {
			public ref class BaseNode {
				MWASMJIT_NATIVEPOINTER(BaseNode, asmjit::BaseNode)
			protected:
				void InitNative(System::IntPtr ptr) {
					_NativePointer = (asmjit::BaseNode*)(void*)ptr;
				}
			public:

			};
			public ref class InstNode :BaseNode {

			};
			public ref class SectionNode :BaseNode {

			};
			public ref class LabelNode :BaseNode {

			};
			public ref class AlignNode :BaseNode {

			};
			public ref class EmbedDataNode :BaseNode {

			};
			public ref class EmbedLabelNode :BaseNode {

			};
			public ref class ConstPoolNode :LabelNode {
			};
			public ref class CommentNode :BaseNode {
			};
			public ref class SentinelNode :BaseNode {
			};

			/*
			public ref class LabelDeltaNode {
			};
			*/
		}
		public ref class BaseBuilder abstract :AsmJit::Core::BaseEmitter {
		public:
			LabelNode* NewLabelNode() {

			}
			AlignNode* newAlignNode(uint32_t alignMode, uint32_t alignment) noexcept;
			EmbedDataNode* newEmbedDataNode(const void* data, uint32_t size) noexcept;
			ConstPoolNode* newConstPoolNode() noexcept;
			CommentNode* newCommentNode(const char* data, size_t size) noexcept;

			InstNode* newInstNode(uint32_t instId, uint32_t instOptions, const Operand_& o0) noexcept;
			InstNode* newInstNode(uint32_t instId, uint32_t instOptions, const Operand_& o0, const Operand_& o1) noexcept;
			InstNode* newInstNode(uint32_t instId, uint32_t instOptions, const Operand_& o0, const Operand_& o1, const Operand_& o2) noexcept;
			InstNode* newInstNode(uint32_t instId, uint32_t instOptions, const Operand_& o0, const Operand_& o1, const Operand_& o2, const Operand_& o3) noexcept;
			InstNode* newInstNodeRaw(uint32_t instId, uint32_t instOptions, uint32_t opCount) noexcept;
		};
	}
}