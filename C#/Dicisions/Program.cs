using System;

namespace Dicisions
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Door:1,2 or 3");
            Console.Write("Choose a Door:");
            string chooseValue = Console.ReadLine();
            string msg = "";
            if(chooseValue == "1")
            {
                msg = "You earn a car!";
            }
            else if(chooseValue == "2")
            {
                msg = "You earn a cat!";
            }
            else if(chooseValue == "3")
            {
                msg = "You earn a pen!";
            }

            Console.WriteLine("you enter {0},therefore {1}",chooseValue,msg);

            Console.ReadLine();
        }
    }
}
