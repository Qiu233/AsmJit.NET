using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AsmJit.Core;
using AsmJit.X86;
using AsmJit.Core.Operand;
using AsmJit.X86.Operand;

namespace Test
{
	class Program
	{
		unsafe static void Main(string[] args)
		{
			CodeInfo info = new CodeInfo(ArchInfo.Id.kIdX86);
			CodeHolder holder = new CodeHolder();
			holder.Initialize(info);
			Assembler asm = new Assembler(holder);
			Label l1 = asm.NewLabel();
			var err = asm.jmp(l1);
			asm.mov(RegsDef.eax, 20);
			asm.Bind(l1);
			Console.WriteLine("ErrorCode:{0}", err);
			Console.WriteLine("Code Length:{0}", holder.Sections[0].Buffer.Size);
			byte* b = holder.Sections[0].Buffer.Data;
			for (int i = 0; i < holder.Sections[0].Buffer.Size; i++)
			{
				Console.Write("{0:X2} ", *(b + i));
			}
			asm.Dispose();//equivalent to delete;
			holder.Dispose();
			info.Dispose();
		}
	}
}
