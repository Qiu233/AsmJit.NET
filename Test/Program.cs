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
		static void Main(string[] args)
		{
			CodeInfo info = new CodeInfo(ArchInfo.Id.kIdX86);
			CodeHolder holder = new CodeHolder();
			holder.Initialize(info);
			Assembler asm = new Assembler(holder);
			asm.mov(RegsDef.eax, 20);
			asm.cpuid();
			EmitterImplicitHelper.cpuid(asm);
			Console.WriteLine(info.BaseAddress.ToString("X8"));
		}
	}
}
