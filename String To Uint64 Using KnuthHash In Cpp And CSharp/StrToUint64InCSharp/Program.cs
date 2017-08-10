using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StrToUint64InCSharp
{
    class Program
    {
        // knuth hash
        static UInt64 CalculateHash(string read)
        {
            UInt64 hashedValue = 3074457345618258791ul;
            for (int i = 0; i < read.Length; i++)
            {
                hashedValue += read[i];
                hashedValue *= 3074457345618258799ul;
            }
            return hashedValue;
        }

        static void Main(string[] args)
        {

            // test code
            string str = @"C:\Users\user\Desktop\제목 없음.png";
            str = str.ToLower();

            Console.WriteLine(str);
            Console.WriteLine(CalculateHash(str));
        }
    }
}
