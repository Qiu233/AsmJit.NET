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
			asm.mov(RegsDef.eax, 20);
			asm.mov(RegsDef.ebx, 40);
			asm.ret();
			Console.WriteLine("Code Length:{0}", holder.Sections.Length);
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
