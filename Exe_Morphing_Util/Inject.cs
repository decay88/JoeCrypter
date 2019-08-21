using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Diagnostics;

namespace Exe_Morphing_Util
{
    public class Inject
    {
        private enum Enum0 : uint
        {

        }

        [Flags]
        public enum AllocationType
        {
            Commit = 4096,
            Reserve = 8192,
            Decommit = 16384,
            Release = 32768,
            Reset = 524288,
            Physical = 4194304,
            TopDown = 1048576,
            WriteWatch = 2097152,
            LargePages = 536870912
        }

        public struct MEMORY_BASIC_INFORMATION
        {
            public IntPtr BaseAddress;

            public IntPtr AllocationBase;

            public Inject.AllocationProtect AllocationProtect;

            public IntPtr RegionSize;

            public uint State;

            public Inject.AllocationProtect Protect;

            public uint Type;
        }

        public enum AllocationProtect : uint
        {
            PAGE_NOACCESS = 1u,
            PAGE_READONLY,
            PAGE_READWRITE = 4u,
            PAGE_WRITECOPY = 8u,
            PAGE_EXECUTE = 16u,
            PAGE_EXECUTE_READ = 32u,
            PAGE_EXECUTE_READWRITE = 64u,
            PAGE_EXECUTE_WRITECOPY = 128u,
            PAGE_GUARD = 256u,
            PAGE_NOCACHE = 512u,
            PAGE_WRITECOMBINE = 1024u
        }

        public struct MODULEENTRY32
        {
            public int dwSize;

            public int th32ModuleID;

            public int th32ProcessID;

            public int GlblcntUsage;

            public int ProccntUsage;

            public IntPtr modBaseAddr;

            public uint modBaseSize;

            public IntPtr hModule;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 512)]
            public byte[] szModule;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 520)]
            public byte[] szExePath;
        }

        [Flags]
        public enum SnapshotFlags : uint
        {
            HeapList = 1u,
            Process = 2u,
            Thread = 4u,
            Module = 8u,
            Module32 = 16u,
            Inherit = 2147483648u,
            All = 31u,
            NoHeaps = 1073741824u
        }

        public int Bits;

        public int pid;

        public ProcessModule2 MainModule;

        public Dictionary<string, ProcessModule2> LoadedHardDLLs;

        public Dictionary<string, PELoader> SoftDLLs;

        public Dictionary<string, List<ImportDef>> AllImports;

        public HashSet<string> UnresolvedHardDLLs;

        public IntPtr hProcess;

        private byte[] byte_0;

        private byte[] byte_1;

        public Inject(int pid, params object[] dllnames)
		{
			
			this.Bits = 64;
			this.pid = 0;
			this.MainModule = null;
			this.LoadedHardDLLs = new Dictionary<string, ProcessModule2>(StringComparer.OrdinalIgnoreCase);
			this.SoftDLLs = new Dictionary<string, PELoader>(StringComparer.OrdinalIgnoreCase);
			this.AllImports = new Dictionary<string, List<ImportDef>>(StringComparer.OrdinalIgnoreCase);
			this.UnresolvedHardDLLs = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
			this.hProcess = IntPtr.Zero;
			this.byte_0 = new byte[]
			{
				72,
				131,
				236,
				40,
				72,
				137,
				203,
				72,
				141,
				115,
				24,
				72,
				137,
				241,
				255,
				83,
				8,
				102,
				173,
				102,
				133,
				192,
				117,
				249,
				102,
				57,
				6,
				117,
				238,
				198,
				3,
				1,
				15,
				174,
				240,
				185,
				96,
				234,
				0,
				0,
				255,
				83,
				16,
				235,
				246,
				72,
				131,
				196,
				40,
				195,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144,
				144
			};
			this.byte_1 = new byte[]
			{
				85,
				137,
				229,
				139,
				93,
				8,
				141,
				115,
				12,
				86,
				255,
				83,
				4,
				102,
				173,
				102,
				133,
				192,
				117,
				249,
				102,
				57,
				6,
				117,
				240,
				198,
				3,
				1,
				15,
				174,
				240,
				185,
				96,
				234,
				0,
				0,
				81,
				255,
				83,
				8,
				235,
				245,
				201,
				195,
				144,
				144,
				144,
				144
			};
			
			for (int i = 0; i < dllnames.Length; i++)
			{
				object obj = dllnames[i];
				string text = (string)obj;
				this.SoftDLLs.Add(text, new PELoader(text));
			}
			this.pid = pid;
			this.hProcess = Inject.OpenProcess((Inject.Enum0)2097151u, 0, pid);
			if (this.hProcess == IntPtr.Zero)
			{
				throw new Exception("could not open process pid=" + pid);
			}
			this.Bits = (Inject.IsWin64(this.hProcess) ? 64 : 32);
			this.method_24();
			this.AllImports = new Dictionary<string, List<ImportDef>>(StringComparer.OrdinalIgnoreCase);
			this.method_23();
			if (this.UnresolvedHardDLLs.Count > 0)
			{
				HashSet<string> hashSet = new HashSet<string>();
				hashSet.Add(Directory.GetCurrentDirectory());
				this.method_22(this.UnresolvedHardDLLs, hashSet);
				this.method_24();
			}
			this.method_23();
			foreach (KeyValuePair<string, PELoader> current in this.SoftDLLs)
			{
				this.UnresolvedHardDLLs.Add(current.Key);
			}
			if (this.UnresolvedHardDLLs.Count > 0)
			{
				HashSet<string> hashSet = new HashSet<string>();
				hashSet.Add(Directory.GetCurrentDirectory());
				this.method_22(this.UnresolvedHardDLLs, hashSet);
				this.method_24();
			}
		}

        private IntPtr method_0(byte[] byte_2, long long_0, ref ulong ulong_0, PELoader peloader_0 = null)
        {
            IntPtr intPtr = Inject.VirtualAllocEx(this.hProcess, IntPtr.Zero, (IntPtr)byte_2.Length, Inject.AllocationType.Commit | Inject.AllocationType.Reserve, Inject.AllocationProtect.PAGE_EXECUTE_READWRITE);
            ulong_0 = (ulong)((long)intPtr);
            IntPtr zero = IntPtr.Zero;
            Inject.WriteProcessMemory(this.hProcess, intPtr, byte_2, (IntPtr)byte_2.Length, ref zero);
            uint uint_ = 65536u;
            uint num = 0u;
            IntPtr result;
            if (peloader_0 != null)
            {
                IntPtr intPtr2 = Inject.CreateRemoteThread(this.hProcess, IntPtr.Zero, (IntPtr)((long)peloader_0.Header2.SizeOfStackReserve), intPtr, intPtr + (int)long_0, uint_, ref num);
                result = intPtr2;
            }
            else
            {
                IntPtr intPtr2 = Inject.CreateRemoteThread(this.hProcess, IntPtr.Zero, IntPtr.Zero, intPtr, intPtr + (int)long_0, 0u, ref num);
                result = intPtr2;
            }
            return result;
        }

        private T method_1<T>(byte[] byte_2, int int_0) where T : struct
        {
            GCHandle gCHandle = GCHandle.Alloc(byte_2, GCHandleType.Pinned);
            T result = (T)((object)Marshal.PtrToStructure(gCHandle.AddrOfPinnedObject() + int_0, typeof(T)));
            gCHandle.Free();
            return result;
        }

        private Dictionary<string, List<ImportDef>> method_2(PELoader peloader_0)
        {
            Dictionary<string, List<ImportDef>> dictionary = new Dictionary<string, List<ImportDef>>();
            Dictionary<string, List<ImportDef>> result;
            if (peloader_0.Header2.ImportTable.VirtualAddress != 0u)
            {
                ulong num = peloader_0.Base + (ulong)peloader_0.Header2.ImportTable.VirtualAddress;
                long num2 = (long)((ulong)peloader_0.Header2.ImportTable.Size);
                while (num2 > 0L)
                {
                    byte[] array = new byte[20];
                    IntPtr zero = IntPtr.Zero;
                    Inject.ReadProcessMemory(this.hProcess, (IntPtr)((long)num), array, (IntPtr)array.Length, ref zero);
                    if ((int)zero != array.Length)
                    {
                        throw new Exception(string.Format("unable to read import directory at address {0}", num.ToString("x8")));
                    }
                    num += 20uL;
                    num2 -= 20L;
                    ImportDirectory importDirectory = this.method_1<ImportDirectory>(array, 0);
                    if (importDirectory.NameRVA == 0u)
                    {
                   
                        result = dictionary;
                        return result;
                    }
                    string text = this.method_9(peloader_0.Base + (ulong)importDirectory.NameRVA);
                    ulong num3 = peloader_0.Base + (ulong)importDirectory.LookupTableRVA;
                    ulong num4 = peloader_0.Base + (ulong)importDirectory.AddressTableRVA;
                    while (true)
                    {
                        string name = null;
                        ulong number = 0uL;
                        if (this.Bits == 64)
                        {
                            ulong num5 = this.method_11(num3);
                            num3 += 8uL;
                            if (num5 == 0uL)
                            {
                                break;
                            }
                            if (num5 >> 63 != 0uL)
                            {
                                number = (num5 & 65535uL);
                            }
                            else
                            {
                                name = this.method_9(peloader_0.Base + num5 + 2uL);
                            }
                        }
                        else
                        {
                            uint num6 = this.method_12(num3);
                            num3 += 4uL;
                            if (num6 == 0u)
                            {
                                break;
                            }
                            if (num6 >> 31 != 0u)
                            {
                                number = (ulong)(num6 & 65535u);
                            }
                            else
                            {
                                name = this.method_9(peloader_0.Base + (ulong)num6 + 2uL);
                            }
                        }
                        ImportDef item = new ImportDef
                        {
                            Address = num4,
                            DllName = text,
                            Name = name,
                            Number = number
                        };
                        if (!dictionary.ContainsKey(text))
                        {
                            dictionary.Add(text, new List<ImportDef>());
                        }
                        dictionary[text].Add(item);
                        num4 += (ulong)((long)(this.Bits / 8));
                    }
                }
                
            }
            result = dictionary;
            return result;
        }

        private void method_3(PELoader peloader_0)
        {
            foreach (KeyValuePair<string, List<ImportDef>> current in peloader_0.Imports)
            {
                foreach (ImportDef current2 in current.Value)
                {
                    if (this.Bits == 64)
                    {
                        this.method_14(current2.Address, this.method_4(current2));
                    }
                    else
                    {
                        this.method_15(current2.Address, this.method_4(current2));
                    }
                }
            }
        }

        private ulong method_4(ImportDef importDef_0)
        {
            ulong result = 0;
            if (this.LoadedHardDLLs.ContainsKey(importDef_0.DllName))
            {
                result = this.method_5(this.LoadedHardDLLs[importDef_0.DllName].BaseAddress, importDef_0);
            }
            else
            {
                if (!this.SoftDLLs.ContainsKey(importDef_0.DllName))
                {
                    throw new Exception(string.Format("could not find imported DLL {0}", importDef_0.DllName));
                }
                result = this.method_5(this.SoftDLLs[importDef_0.DllName].Base, importDef_0);
            }
            return result;
        }

        private ulong method_5(ulong ulong_0, ImportDef importDef_0)
        {
            ulong num = ulong_0 + (ulong)this.method_12(ulong_0 + 60uL);
            ulong num2 = num + (ulong)((this.Bits == 64) ? 136L : 120L);
            ulong num3 = ulong_0 + (ulong)this.method_12(num2);
            ulong num4 = (ulong)this.method_12(num2 + 4uL);
            ulong arg_5C_0 = (ulong)this.method_12(num3 + 16uL);
            long num5 = (long)((ulong)this.method_12(num3 + 20uL));
            ulong num6 = ulong_0 + (ulong)this.method_12(num3 + 28uL);
            ulong num7 = ulong_0 + (ulong)this.method_12(num3 + 32uL);
            ulong num8 = ulong_0 + (ulong)this.method_12(num3 + 36uL);
            ulong num9 = 0uL;
            uint num10 = 0u;
            while ((ulong)num10 < (ulong)num5)
            {
                if (importDef_0.Name != null)
                {
                    string text = this.method_9(ulong_0 + (ulong)this.method_12(num7 + (ulong)(num10 * 4u)));
                    if (!text.Equals(importDef_0.Name))
                    {
                        num10 += 1u;
                        continue;
                    }
                    if (!this.SoftDLLs.ContainsKey(importDef_0.DllName))
                    {
                        num9 = (ulong)this.method_13(num8 + (ulong)(num10 * 2u));
                    }
                    else
                    {
                        num9 = (ulong)this.method_13(num8 + (ulong)(num10 * 2u));
                    }
                }
                else
                {
                    num9 = importDef_0.Number;
                }
            
                ulong num11 = ulong_0 + (ulong)this.method_12(num6 + num9 * 4uL);
                ulong result = 0;
                if (num11 >= num3 && num11 < num3 + num4)
                {
                    string text2 = this.method_9(num11);
                    int num12 = text2.IndexOf('.');
                    string dllName = text2.Substring(0, num12) + ".dll";
                    string name = text2.Substring(num12 + 1);
                    ImportDef importDef_ = new ImportDef
                    {
                        Address = importDef_0.Address,
                        DllName = dllName,
                        Name = name,
                        Number = 0uL
                    };
                    result = this.method_4(importDef_);
                }
                else
                {
                    result = num11;
                }
                return result;
            }
            return 0;
            
        }

        private void method_6(PELoader peloader_0, ulong ulong_0 = 0uL)
        {
            this.method_18(peloader_0, ulong_0);
            this.method_19(peloader_0);
            this.method_7(peloader_0);
            this.method_8(peloader_0);
        }

        private void method_7(PELoader peloader_0)
        {
            ulong num = peloader_0.Base + (ulong)peloader_0.Header2.BaseRelocationTable.VirtualAddress;
            long num2 = (long)((ulong)peloader_0.Header2.BaseRelocationTable.Size);
            while (num2 > 0L)
            {
                ulong num3 = (ulong)this.method_12(num);
                num += 4uL;
                long num4 = (long)((ulong)this.method_12(num));
                num += 4uL;
                num2 -= num4;
                num4 -= 8L;
                while (num4 > 0L)
                {
                    ulong num5 = (ulong)this.method_13(num);
                    num += 2uL;
                    ulong ulong_ = num3 + (num5 & 4095uL) + peloader_0.Base;
                    ulong num6 = peloader_0.Base - peloader_0.Header2.ImageBase;
                    num4 -= 2L;
                    ulong num7 = num5 >> 12;
                    if (num7 <= 3uL)
                    {
                        if (num7 < 0uL)
                        {
                            goto IL_17B;
                        }
                        switch ((int)num7)
                        {
                            case 0:
                                continue;
                            case 1:
                                num6 = (num6 >> 16) + (ulong)this.method_13(ulong_);
                                this.method_16(ulong_, num6);
                                continue;
                            case 2:
                                goto IL_17B;
                            case 3:
                                num6 += (ulong)this.method_12(ulong_);
                                this.method_15(ulong_, num6);
                                continue;
                        }
                    }
                    if (num7 == 10uL)
                    {
                        num6 += this.method_11(ulong_);
                        this.method_14(ulong_, num6);
                        continue;
                    }
                IL_17B:
                    throw new Exception(string.Format("unknown relocation entry type value={0}", num5.ToString("x4")));
                }
            }
        }

        private void method_8(PELoader peloader_0)
        {
            if (this.Bits == 64)
            {
                this.method_17(peloader_0.Base + peloader_0.ulong_0 + 24uL, peloader_0.Base);
            }
            else
            {
                this.method_17(peloader_0.Base + peloader_0.ulong_0 + 28uL, peloader_0.Base);
            }
        }

        private string method_9(ulong ulong_0)
        {
            int i = 0;
            byte[] array = new byte[4096];
            GCHandle gCHandle = GCHandle.Alloc(array, GCHandleType.Pinned);
            IntPtr pointer = gCHandle.AddrOfPinnedObject();
            while (i < array.Length)
            {
                int value = Math.Min(64, array.Length - i);
                IntPtr zero = IntPtr.Zero;
                Inject.ReadProcessMemory_1(this.hProcess, (IntPtr)((long)(ulong_0 + (ulong)((long)i))), pointer + i, (IntPtr)value, ref zero);
                if ((int)zero <= 0)
                {
                    break;
                }
                int num = 0;
                while (array[i] != 0 && num < (int)zero)
                {
                    i++;
                    num++;
                }
                if (num < (int)zero && array[i] == 0)
                {
                    break;
                }
            }
            pointer = IntPtr.Zero;
            gCHandle.Free();
            return Encoding.ASCII.GetString(array, 0, i);
        }

        private string method_10(ulong ulong_0)
        {
            int i = 0;
            byte[] array = new byte[4096];
            GCHandle gCHandle = GCHandle.Alloc(array, GCHandleType.Pinned);
            IntPtr pointer = gCHandle.AddrOfPinnedObject();
            while (i < array.Length)
            {
                int value = Math.Min(64, array.Length - i);
                IntPtr zero = IntPtr.Zero;
                Inject.ReadProcessMemory_1(this.hProcess, (IntPtr)((long)(ulong_0 + (ulong)((long)i))), pointer + i, (IntPtr)value, ref zero);
                if ((int)zero <= 0)
                {
                    break;
                }
                int num = 0;
                while (array[i] != 0 && array[i + 1] != 0 && num < (int)zero)
                {
                    i++;
                    num++;
                    i++;
                    num++;
                }
                if (num < (int)zero && array[i] == 0 && array[i + 1] == 0)
                {
                    break;
                }
            }
            pointer = IntPtr.Zero;
            gCHandle.Free();
            return Encoding.Unicode.GetString(array, 0, i);
        }

        private ulong method_11(ulong ulong_0)
        {
            IntPtr zero = IntPtr.Zero;
            byte[] array = new byte[8];
            Inject.ReadProcessMemory(this.hProcess, (IntPtr)((long)ulong_0), array, (IntPtr)array.Length, ref zero);
            if (zero != (IntPtr)array.Length)
            {
                throw new Exception(string.Format("Unable to ReadQWORD at address 0x{0}", ulong_0.ToString("x8")));
            }
            return BitConverter.ToUInt64(array, 0);
        }

        private uint method_12(ulong ulong_0)
        {
            IntPtr zero = IntPtr.Zero;
            byte[] array = new byte[4];
            Inject.ReadProcessMemory(this.hProcess, (IntPtr)((long)ulong_0), array, (IntPtr)array.Length, ref zero);
            if (zero != (IntPtr)array.Length)
            {
                throw new Exception(string.Format("Unable to ReadDWORD at address 0x{0}", ulong_0.ToString("x8")));
            }
            return BitConverter.ToUInt32(array, 0);
        }

        private ushort method_13(ulong ulong_0)
        {
            IntPtr zero = IntPtr.Zero;
            byte[] array = new byte[2];
            Inject.ReadProcessMemory(this.hProcess, (IntPtr)((long)ulong_0), array, (IntPtr)array.Length, ref zero);
            if (zero != (IntPtr)array.Length)
            {
                throw new Exception(string.Format("Unable to ReadWORD at address 0x{0}", ulong_0.ToString("x8")));
            }
            return BitConverter.ToUInt16(array, 0);
        }

        private void method_14(ulong ulong_0, ulong ulong_1)
        {
            IntPtr zero = IntPtr.Zero;
            Inject.WriteProcessMemory(this.hProcess, (IntPtr)((long)ulong_0), BitConverter.GetBytes(ulong_1), (IntPtr)8, ref zero);
        }

        private void method_15(ulong ulong_0, ulong ulong_1)
        {
            IntPtr zero = IntPtr.Zero;
            Inject.WriteProcessMemory(this.hProcess, (IntPtr)((long)ulong_0), BitConverter.GetBytes((uint)ulong_1), (IntPtr)4, ref zero);
        }

        private void method_16(ulong ulong_0, ulong ulong_1)
        {
            IntPtr zero = IntPtr.Zero;
            Inject.WriteProcessMemory(this.hProcess, (IntPtr)((long)ulong_0), BitConverter.GetBytes((ushort)ulong_1), (IntPtr)2, ref zero);
        }

        private void method_17(ulong ulong_0, ulong ulong_1)
        {
            if (this.Bits == 64)
            {
                this.method_14(ulong_0, ulong_1);
            }
            else
            {
                this.method_15(ulong_0, (ulong)((uint)ulong_1));
            }
        }

        private void method_18(PELoader peloader_0, ulong ulong_0)
        {
            peloader_0.Base = (ulong)((long)Inject.VirtualAllocEx(this.hProcess, (IntPtr)((long)ulong_0), (IntPtr)((long)peloader_0.MaxSize), Inject.AllocationType.Commit | Inject.AllocationType.Reserve, Inject.AllocationProtect.PAGE_EXECUTE_READWRITE));
            if (peloader_0.Base == 0uL)
            {
                throw new Exception(string.Format("could not allocate 0x{0} bytes for injecting {1}  (process may be stale)", peloader_0.MaxSize.ToString("x8"), peloader_0.Name));
            }
        }

        private void method_19(PELoader peloader_0)
        {
            GCHandle gCHandle = GCHandle.Alloc(peloader_0.Data, GCHandleType.Pinned);
            IntPtr pointer = gCHandle.AddrOfPinnedObject();
            IntPtr zero = IntPtr.Zero;
            Inject.WriteProcessMemory_1(this.hProcess, (IntPtr)((long)peloader_0.Base), pointer + 0, (IntPtr)((long)peloader_0.ulong_1), ref zero);
            if (zero != (IntPtr)((long)peloader_0.ulong_1))
            {
                throw new Exception("WriteProcessMemory failed");
            }
            foreach (SectionHeader current in peloader_0.SectionHeaders)
            {
                zero = IntPtr.Zero;
                Inject.WriteProcessMemory_1(this.hProcess, (IntPtr)((long)(peloader_0.Base + (ulong)current.VirtualAddress)), pointer + (int)current.PointerToRawData, (IntPtr)((long)((ulong)current.SizeOfRawData)), ref zero);
                if (zero != (IntPtr)((long)((ulong)current.SizeOfRawData)))
                {
                    throw new Exception("WriteProcessMemory failed");
                }
            }
            pointer = IntPtr.Zero;
            gCHandle.Free();
        }

        private void method_20(PELoader peloader_0)
        {
            Inject.AllocationProtect allocationProtect_ = Inject.AllocationProtect.PAGE_EXECUTE_READ;
            if (!Inject.VirtualProtectEx(this.hProcess, (IntPtr)((long)peloader_0.Base), (IntPtr)((long)peloader_0.ulong_1), Inject.AllocationProtect.PAGE_EXECUTE_READ, ref allocationProtect_))
            {
                throw new Exception("VirtualProtectEx failed");
            }
            foreach (SectionHeader current in peloader_0.SectionHeaders)
            {
                allocationProtect_ = this.method_21(current.Characteristics);
                if (!Inject.VirtualProtectEx(this.hProcess, (IntPtr)((long)(peloader_0.Base + (ulong)current.VirtualAddress)), (IntPtr)((long)((ulong)current.VirtualSize)), allocationProtect_, ref allocationProtect_))
                {
                    throw new Exception("VirtualProtectEx failed");
                }
            }
        }

        private Inject.AllocationProtect method_21(uint uint_0)
        {
            uint_0 >>= 29;
            Inject.AllocationProtect result = Inject.AllocationProtect.PAGE_NOACCESS;
            switch (uint_0)
            {
                case 0u:
                    result = Inject.AllocationProtect.PAGE_NOACCESS;
                    break;
                case 1u:
                    result = Inject.AllocationProtect.PAGE_EXECUTE;
                    break;
                case 2u:
                    result = Inject.AllocationProtect.PAGE_READONLY;
                    break;
                case 3u:
                    result = Inject.AllocationProtect.PAGE_EXECUTE_READ;
                    break;
                case 4u:
                    result = Inject.AllocationProtect.PAGE_READWRITE;
                    break;
                case 5u:
                    result = Inject.AllocationProtect.PAGE_EXECUTE_READWRITE;
                    break;
                case 6u:
                    result = Inject.AllocationProtect.PAGE_READWRITE;
                    break;
                case 7u:
                    result = Inject.AllocationProtect.PAGE_EXECUTE_READWRITE;
                    break;
            }
            return result;
        }

        private void method_22(HashSet<string> filenames, HashSet<string> librarypaths)
        {
            using (BinaryWriter binaryWriter = new BinaryWriter(new MemoryStream()))
            {
                if (this.Bits == 64)
                {
                    binaryWriter.Write(this.byte_0);
                }
                else
                {
                    binaryWriter.Write(this.byte_1);
                }
                long position = binaryWriter.BaseStream.Position;
                ulong num = this.method_4(new ImportDef
                {
                    DllName = "kernel32.dll",
                    Name = "LoadLibraryW"
                });
                ulong num2 = this.method_4(new ImportDef
                {
                    DllName = "kernel32.dll",
                    Name = "Sleep"
                });
                if (this.Bits == 64)
                {
                    binaryWriter.Write(0uL);
                    binaryWriter.Write(num);
                    binaryWriter.Write(num2);
                }
                else
                {
                    binaryWriter.Write(0u);
                    binaryWriter.Write((uint)num);
                    binaryWriter.Write((uint)num2);
                }
                foreach (string current in filenames)
                {
                    string text = current;
                    if (!text.Contains('/') && !text.Contains('\\'))
                    {
                        foreach (string current2 in librarypaths)
                        {
                            string text2 = Path.Combine(current2, text);
                            if (File.Exists(text2))
                            {
                                text = text2;
                                break;
                            }
                        }
                    }
                    binaryWriter.Write(Encoding.Unicode.GetBytes(text));
                    binaryWriter.Write(0);
                }
                binaryWriter.Write(0);
                long arg_199_0 = binaryWriter.BaseStream.Position;
                byte[] byte_ = ((MemoryStream)binaryWriter.BaseStream).ToArray();
                ulong num3 = 0uL;
                this.method_0(byte_, position, ref num3, null);
                while (this.method_12(num3 + (ulong)position) == 0u)
                {
                    Thread.Sleep(1);
                }
            }
        }

        private void method_23()
        {
            this.UnresolvedHardDLLs = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (KeyValuePair<string, List<ImportDef>> current in this.AllImports)
            {
                if (!this.LoadedHardDLLs.ContainsKey(current.Key) && !this.SoftDLLs.ContainsKey(current.Key))
                {
                    this.UnresolvedHardDLLs.Add(current.Key);
                }
            }
        }

        private static void smethod_0(Dictionary<string, List<ImportDef>> allImports, Dictionary<string, List<ImportDef>> imports)
        {
            foreach (KeyValuePair<string, List<ImportDef>> current in imports)
            {
                if (!allImports.ContainsKey(current.Key))
                {
                    allImports.Add(current.Key, new List<ImportDef>());
                }
                foreach (ImportDef current2 in current.Value)
                {
                    if (!allImports[current.Key].Contains(current2))
                    {
                        allImports[current.Key].Add(current2);
                    }
                }
            }
        }

        [DllImport("Kernel32.dll")]
        private static extern bool ReadProcessMemory(IntPtr intptr_0, IntPtr intptr_1, byte[] byte_2, IntPtr intptr_2, ref IntPtr intptr_3);

        [DllImport("Kernel32.dll", EntryPoint = "ReadProcessMemory")]
        private static extern bool ReadProcessMemory_1(IntPtr intptr_0, IntPtr intptr_1, IntPtr intptr_2, IntPtr intptr_3, ref IntPtr intptr_4);

        [DllImport("Kernel32.dll")]
        private static extern bool WriteProcessMemory(IntPtr intptr_0, IntPtr intptr_1, byte[] byte_2, IntPtr intptr_2, ref IntPtr intptr_3);

        [DllImport("Kernel32.dll", EntryPoint = "WriteProcessMemory")]
        private static extern bool WriteProcessMemory_1(IntPtr intptr_0, IntPtr intptr_1, IntPtr intptr_2, IntPtr intptr_3, ref IntPtr intptr_4);

        [DllImport("Kernel32.dll")]
        private static extern IntPtr CreateRemoteThread(IntPtr intptr_0, IntPtr intptr_1, IntPtr intptr_2, IntPtr intptr_3, IntPtr intptr_4, uint uint_0, ref uint uint_1);

        [DllImport("Kernel32.dll")]
        private static extern IntPtr OpenProcess(Inject.Enum0 enum0_0, int int_0, int int_1);

        [DllImport("Kernel32.dll")]
        private static extern int VirtualQueryEx(IntPtr intptr_0, IntPtr intptr_1, out Inject.MEMORY_BASIC_INFORMATION memory_BASIC_INFORMATION_0, IntPtr intptr_2);

        [DllImport("Kernel32.dll", ExactSpelling = true, SetLastError = true)]
        private static extern IntPtr VirtualAllocEx(IntPtr intptr_0, IntPtr intptr_1, IntPtr intptr_2, Inject.AllocationType allocationType_0, Inject.AllocationProtect allocationProtect_0);

        [DllImport("Kernel32.dll")]
        private static extern bool VirtualProtectEx(IntPtr intptr_0, IntPtr intptr_1, IntPtr intptr_2, Inject.AllocationProtect allocationProtect_0, ref Inject.AllocationProtect allocationProtect_1);

        [DllImport("Kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool IsWow64Process([In] IntPtr intptr_0, out bool bool_0);

        [DllImport("Kernel32.dll", SetLastError = true)]
        private static extern IntPtr GetCurrentProcess();

        public static bool smethod_1()
        {
            bool result;
            if (IntPtr.Size == 8)
            {
                result = true;
            }
            else
            {
                IntPtr currentProcess = Inject.GetCurrentProcess();
                try
                {
                    bool flag = false;
                    Inject.IsWow64Process(currentProcess, out flag);
                    result = flag;
                }
                catch
                {
                    result = false;
                }
            }
            return result;
        }

        public static bool IsWin64(IntPtr hProcess)
        {
            bool result;
            if (!Inject.smethod_1())
            {
                result = false;
            }
            else
            {
                try
                {
                    bool flag = false;
                    Inject.IsWow64Process(hProcess, out flag);
                    result = !flag;
                }
                catch
                {
                    result = false;
                }
            }
            return result;
        }

        [DllImport("Kernel32.dll", SetLastError = true)]
        private static extern IntPtr CreateToolhelp32Snapshot(Inject.SnapshotFlags snapshotFlags_0, int int_0);

        [DllImport("Kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        private static extern bool Module32FirstW(IntPtr intptr_0, ref Inject.MODULEENTRY32 moduleentry32_0);

        [DllImport("Kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        private static extern bool Module32NextW(IntPtr intptr_0, ref Inject.MODULEENTRY32 moduleentry32_0);

        [DllImport("Kernel32.dll", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool CloseHandle(IntPtr intptr_0);

        private void method_24()
        {
            this.LoadedHardDLLs = new Dictionary<string, ProcessModule2>(StringComparer.OrdinalIgnoreCase);
            Inject.MEMORY_BASIC_INFORMATION mEMORY_BASIC_INFORMATION;
            mEMORY_BASIC_INFORMATION.BaseAddress = IntPtr.Zero;
            mEMORY_BASIC_INFORMATION.RegionSize = IntPtr.Zero;
            IntPtr intptr_;
            if (IntPtr.Size == 8 && this.Bits == 64)
            {
                intptr_ = Inject.CreateToolhelp32Snapshot(Inject.SnapshotFlags.Module, this.pid);
            }
            else if (IntPtr.Size == 8 && this.Bits == 32)
            {
                intptr_ = Inject.CreateToolhelp32Snapshot(Inject.SnapshotFlags.Module | Inject.SnapshotFlags.Module32, this.pid);
            }
            else
            {
                if (IntPtr.Size != 4 || this.Bits != 32)
                {
                    throw new Exception(string.Format("unsupported source/target process combination: {0}/{1}", IntPtr.Size * 8, this.Bits));
                }
                intptr_ = Inject.CreateToolhelp32Snapshot(Inject.SnapshotFlags.Module, this.pid);
            }
            Inject.MODULEENTRY32 mODULEENTRY = default(Inject.MODULEENTRY32);
            mODULEENTRY.dwSize = ((IntPtr.Size == 8) ? 1080 : 1064);
            bool flag = Inject.Module32FirstW(intptr_, ref mODULEENTRY);
            while (flag)
            {
                if (IntPtr.Size != 8 || this.Bits != 32 || (long)mODULEENTRY.modBaseAddr < 4294967296L)
                {
                    string fileName = this.method_25(mODULEENTRY.szExePath);
                    string text = this.method_25(mODULEENTRY.szModule);
                    if (!this.LoadedHardDLLs.ContainsKey(text))
                    {
                        this.LoadedHardDLLs.Add(text, new ProcessModule2
                        {
                            BaseAddress = (ulong)((long)mODULEENTRY.modBaseAddr),
                            ModuleMemorySize = (ulong)mODULEENTRY.modBaseSize,
                            FileName = fileName,
                            ModuleName = text
                        });
                    }
                }
                flag = Inject.Module32NextW(intptr_, ref mODULEENTRY);
            }
            Inject.CloseHandle(intptr_);
        }

        private string method_25(byte[] byte_2)
        {
            string @string;
            for (int i = 0; i < byte_2.Length; i += 2)
            {
                if (byte_2[i] == 0 && byte_2[i + 1] == 0)
                {
                    @string = Encoding.Unicode.GetString(byte_2, 0, i);
                    return @string;
                }
            }
            @string = Encoding.Unicode.GetString(byte_2);
            return @string;
        }
    }
    public class ImportDef
    {
        public string DllName;

        public string Name;

        public ulong Number;

        public ulong Address;
    }
    public class PELoader
    {
        public PEHeader Header;

        public PEHeader2_64 Header2;

        public List<SectionHeader> SectionHeaders;

        public ulong MaxSize;

        public ulong Base;

        public byte[] Data;

        public string Name;

        public ulong ulong_0;

        public ulong ulong_1;

        public int pebase;

        public Dictionary<string, List<ImportDef>> Imports;

        public PELoader(string filename)
		{
			
			this.Name = filename;
			byte[] byte_ = File.ReadAllBytes(filename);
			this.method_0(byte_);
		}

        public PELoader(byte[] PEdata, string filename = "unspecified")
		{
			
			this.Name = filename;
			this.method_0(PEdata);
		}

        private void method_0(byte[] byte_0)
        {
            this.Data = byte_0;
            this.method_2(byte_0);
            this.method_3();
        }

        private T method_1<T>(byte[] byte_0, int int_0) where T : struct
        {
            GCHandle gCHandle = GCHandle.Alloc(byte_0, GCHandleType.Pinned);
            T result = (T)((object)Marshal.PtrToStructure(gCHandle.AddrOfPinnedObject() + int_0, typeof(T)));
            gCHandle.Free();
            return result;
        }

        private void method_2(byte[] byte_0)
        {
            this.pebase = BitConverter.ToInt32(byte_0, 60);
            if (BitConverter.ToUInt32(byte_0, this.pebase) != 17744u)
            {
                throw new Exception("missing PE header");
            }
            this.pebase += 4;
            int num = this.pebase + Marshal.SizeOf(typeof(PEHeader));
            int num2 = num;
            this.ulong_0 = (ulong)((long)num2);
            this.Header = this.method_1<PEHeader>(byte_0, this.pebase);
            if (BitConverter.ToUInt16(byte_0, num) == 523)
            {
                this.Header2 = this.method_1<PEHeader2_64>(byte_0, num);
                num2 += Marshal.SizeOf(typeof(PEHeader2_64));
            }
            else
            {
                PEHeader2_32 peheader2_32_ = this.method_1<PEHeader2_32>(byte_0, num);
                this.Header2 = this.method_4(peheader2_32_);
                num2 += Marshal.SizeOf(typeof(PEHeader2_32));
            }
            this.SectionHeaders = new List<SectionHeader>();
            for (int i = 0; i < (int)this.Header.NumberOfSections; i++)
            {
                SectionHeader item = this.method_1<SectionHeader>(byte_0, num2);
                this.SectionHeaders.Add(item);
                num2 += Marshal.SizeOf(typeof(SectionHeader));
            }
            this.ulong_1 = (ulong)((long)num2);
        }

        private void method_3()
        {
            this.MaxSize = 4096uL;
            foreach (SectionHeader current in this.SectionHeaders)
            {
                ulong num = (ulong)(current.VirtualAddress + current.VirtualSize);
                num = (num + 4095uL & 18446744073709547520uL);
                this.MaxSize = Math.Max(this.MaxSize, num);
            }
        }

        private PEHeader2_64 method_4(PEHeader2_32 peheader2_32_0)
        {
            return new PEHeader2_64
            {
                Magic = peheader2_32_0.Magic,
                MajorLinkerVersion = peheader2_32_0.MajorLinkerVersion,
                MinorLinkerVersion = peheader2_32_0.MinorLinkerVersion,
                SizeOfCode = peheader2_32_0.SizeOfCode,
                SizeOfInitializedData = peheader2_32_0.SizeOfInitializedData,
                SizeOfUninitializedData = peheader2_32_0.SizeOfUninitializedData,
                AddressOfEntryPoint = peheader2_32_0.AddressOfEntryPoint,
                BaseOfCode = peheader2_32_0.BaseOfCode,
                ImageBase = (ulong)peheader2_32_0.ImageBase,
                SectionAlignment = peheader2_32_0.SectionAlignment,
                FileAlignment = peheader2_32_0.FileAlignment,
                MajorOperatingSystemVersion = peheader2_32_0.MajorOperatingSystemVersion,
                MinorOperatingSystemVersion = peheader2_32_0.MinorOperatingSystemVersion,
                MajorImageVersion = peheader2_32_0.MajorImageVersion,
                MinorImageVersion = peheader2_32_0.MinorImageVersion,
                MajorSubsystemVersion = peheader2_32_0.MajorSubsystemVersion,
                MinorSubsystemVersion = peheader2_32_0.MinorSubsystemVersion,
                Win32VersionValue = peheader2_32_0.Win32VersionValue,
                SizeOfImage = peheader2_32_0.SizeOfImage,
                SizeOfHeaders = peheader2_32_0.SizeOfHeaders,
                CheckSum = peheader2_32_0.CheckSum,
                Subsystem = peheader2_32_0.Subsystem,
                DllCharacteristics = peheader2_32_0.DllCharacteristics,
                SizeOfStackReserve = (ulong)peheader2_32_0.SizeOfStackReserve,
                SizeOfStackCommit = (ulong)peheader2_32_0.SizeOfStackCommit,
                SizeOfHeapReserve = (ulong)peheader2_32_0.SizeOfHeapReserve,
                SizeOfHeapCommit = (ulong)peheader2_32_0.SizeOfHeapCommit,
                LoaderFlags = peheader2_32_0.LoaderFlags,
                NumberOfRvaAndSizes = peheader2_32_0.NumberOfRvaAndSizes,
                ExportTable = peheader2_32_0.ExportTable,
                ImportTable = peheader2_32_0.ImportTable,
                ResourceTable = peheader2_32_0.ResourceTable,
                ExceptionTable = peheader2_32_0.ExceptionTable,
                CertificateTable = peheader2_32_0.CertificateTable,
                BaseRelocationTable = peheader2_32_0.BaseRelocationTable,
                Debug = peheader2_32_0.Debug,
                Architecture = peheader2_32_0.Architecture,
                GlobalPtr = peheader2_32_0.GlobalPtr,
                TLSTable = peheader2_32_0.TLSTable,
                LoadConfigTable = peheader2_32_0.LoadConfigTable,
                BoundImport = peheader2_32_0.BoundImport,
                IAT = peheader2_32_0.IAT,
                DelayImportDescriptor = peheader2_32_0.DelayImportDescriptor,
                CLRRuntimeHeader = peheader2_32_0.CLRRuntimeHeader,
                Reserved = peheader2_32_0.Reserved
            };
        }
    }

    public struct SectionHeader
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public byte[] Name;

        public uint VirtualSize;

        public uint VirtualAddress;

        public uint SizeOfRawData;

        public uint PointerToRawData;

        public uint PointerToRelocations;

        public uint PointerToLinenumbers;

        public ushort NumberOfRelocations;

        public ushort NumberOfLinenumbers;

        public uint Characteristics;
    }
    public class ProcessModule2
    {
        private ulong? nullable_0;

        private ulong? nullable_1;

        private string string_0;

        private System.Diagnostics.FileVersionInfo fileVersionInfo_0;

        private ulong? nullable_2;

        private string KnexWyvtx;

        public System.Diagnostics.ProcessModule Native;

        public ulong BaseAddress
        {
            get
            {
                ulong result = 0;
                if (this.nullable_0.HasValue)
                {
                    result = this.nullable_0.Value;
                }
                else
                {
                    result = (ulong)((long)this.Native.BaseAddress);
                }
                return result;
            }
            set
            {
                this.nullable_0 = new ulong?(value);
            }
        }

        public ulong EntryPointAddress
        {
            get
            {
                ulong result = 0;
                if (this.nullable_1.HasValue)
                {
                    result = this.nullable_1.Value;
                }
                else
                {
                    result = (ulong)((long)this.Native.EntryPointAddress);
                }
                return result;
            }
            set
            {
                this.nullable_1 = new ulong?(value);
            }
        }

        public string FileName
        {
            get
            {
                string fileName = "";
                if (this.string_0 != null || this.Native == null)
                {
                    fileName = this.string_0;
                }
                else
                {
                    fileName = this.Native.FileName;
                }
                return fileName;
            }
            set
            {
                this.string_0 = value;
            }
        }

        public FileVersionInfo FileVersionInfo
        {
            get
            {
                FileVersionInfo fileVersionInfo;
                if (this.fileVersionInfo_0 != null)
                {
                    fileVersionInfo = this.fileVersionInfo_0;
                }
                else
                {
                    fileVersionInfo = this.Native.FileVersionInfo;
                }
                return fileVersionInfo;
            }
            set
            {
                this.fileVersionInfo_0 = value;
            }
        }

        public ulong ModuleMemorySize
        {
            get
            {
                ulong result = 0;
                if (this.nullable_2.HasValue)
                {
                    result = this.nullable_2.Value;
                }
                else
                {
                    result = (ulong)((long)this.Native.ModuleMemorySize);
                }
                return result;
            }
            set
            {
                this.nullable_2 = new ulong?(value);
            }
        }

        public string ModuleName
        {
            get
            {
                string result = "";
                if (this.KnexWyvtx != null || this.Native == null)
                {
                    result = this.KnexWyvtx;
                }
                else
                {
                    result = this.Native.ModuleName;
                }
                return result;
            }
            set
            {
                this.KnexWyvtx = value;
            }
        }
    }
    public enum PEMagic : ushort
    {
        x86 = 267,
        x64 = 523
    }
    public struct PEHeader2_32
    {
        public PEMagic Magic;

        public byte MajorLinkerVersion;

        public byte MinorLinkerVersion;

        public uint SizeOfCode;

        public uint SizeOfInitializedData;

        public uint SizeOfUninitializedData;

        public uint AddressOfEntryPoint;

        public uint BaseOfCode;

        public uint BaseOfData;

        public uint ImageBase;

        public uint SectionAlignment;

        public uint FileAlignment;

        public ushort MajorOperatingSystemVersion;

        public ushort MinorOperatingSystemVersion;

        public ushort MajorImageVersion;

        public ushort MinorImageVersion;

        public ushort MajorSubsystemVersion;

        public ushort MinorSubsystemVersion;

        public uint Win32VersionValue;

        public uint SizeOfImage;

        public uint SizeOfHeaders;

        public uint CheckSum;

        public ushort Subsystem;

        public ushort DllCharacteristics;

        public uint SizeOfStackReserve;

        public uint SizeOfStackCommit;

        public uint SizeOfHeapReserve;

        public uint SizeOfHeapCommit;

        public uint LoaderFlags;

        public uint NumberOfRvaAndSizes;

        public IDD ExportTable;

        public IDD ImportTable;

        public IDD ResourceTable;

        public IDD ExceptionTable;

        public IDD CertificateTable;

        public IDD BaseRelocationTable;

        public IDD Debug;

        public IDD Architecture;

        public IDD GlobalPtr;

        public IDD TLSTable;

        public IDD LoadConfigTable;

        public IDD BoundImport;

        public IDD IAT;

        public IDD DelayImportDescriptor;

        public IDD CLRRuntimeHeader;

        public IDD Reserved;
    }

    public struct PEHeader
    {
        public PEMachine Machine;

        public ushort NumberOfSections;

        public uint TimeDateStamp;

        public uint PointerToSymbolTable;

        public uint NumberOfSymbols;

        public ushort SizeOfOptionalHeader;

        public ushort Characteristics;
    }
    public enum PEMachine : ushort
    {
        x86 = 332,
        x64 = 34404
    }
    public struct PEHeader2_64
    {
        public PEMagic Magic;

        public byte MajorLinkerVersion;

        public byte MinorLinkerVersion;

        public uint SizeOfCode;

        public uint SizeOfInitializedData;

        public uint SizeOfUninitializedData;

        public uint AddressOfEntryPoint;

        public uint BaseOfCode;

        public ulong ImageBase;

        public uint SectionAlignment;

        public uint FileAlignment;

        public ushort MajorOperatingSystemVersion;

        public ushort MinorOperatingSystemVersion;

        public ushort MajorImageVersion;

        public ushort MinorImageVersion;

        public ushort MajorSubsystemVersion;

        public ushort MinorSubsystemVersion;

        public uint Win32VersionValue;

        public uint SizeOfImage;

        public uint SizeOfHeaders;

        public uint CheckSum;

        public ushort Subsystem;

        public ushort DllCharacteristics;

        public ulong SizeOfStackReserve;

        public ulong SizeOfStackCommit;

        public ulong SizeOfHeapReserve;

        public ulong SizeOfHeapCommit;

        public uint LoaderFlags;

        public uint NumberOfRvaAndSizes;

        public IDD ExportTable;

        public IDD ImportTable;

        public IDD ResourceTable;

        public IDD ExceptionTable;

        public IDD CertificateTable;

        public IDD BaseRelocationTable;

        public IDD Debug;

        public IDD Architecture;

        public IDD GlobalPtr;

        public IDD TLSTable;

        public IDD LoadConfigTable;

        public IDD BoundImport;

        public IDD IAT;

        public IDD DelayImportDescriptor;

        public IDD CLRRuntimeHeader;

        public IDD Reserved;
    }
    public struct IDD
    {
        public uint VirtualAddress;

        public uint Size;
    }
    public struct ImportDirectory
    {
        public uint LookupTableRVA;

        public uint TimeStamp;

        public uint ForwarderChain;

        public uint NameRVA;

        public uint AddressTableRVA;
    }

}
