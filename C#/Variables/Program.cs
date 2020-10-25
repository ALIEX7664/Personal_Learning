using System;

namespace Variables
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            int
               x = 1,
               y = 2;

            Console.WriteLine(x + y);
            */


            Console.WriteLine("Show NAME");
            Console.Write("Type your name:");
            String name;
            name = Console.ReadLine();

            String lastName = Console.ReadLine();

            Console.WriteLine("HELLO"+ name);
        }
    }
}
