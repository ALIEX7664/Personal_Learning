using System;
using System.Linq;

namespace UnderstandingArrays
{
    class Program
    {
        static void Main(string[] args)
        {
            //Define type of "int" Array
            int[] arrInt =new int[3];

            arrInt[0] = 1;
            arrInt[1] = 2;
            arrInt[2] = 3;

            for(int i = 0; i < arrInt.Length; i++)
            {
                Console.WriteLine(arrInt[i]);
            }

            //Define type  of "string" Array
            String[] arrStr = new String[] {"Aliex","Aruiy","Vader" };
            
            foreach(String str in arrStr)
            {
                Console.WriteLine(str);
            }

  

            //How to reserve a string
            String strs = "Nothing is impossible";

            char[] ch = strs.ToCharArray();

            Array.Reverse(ch);
            foreach(char c in ch)
            {
                Console.Write(c);
            }
            Console.ReadLine();
           
        }
    }
}
