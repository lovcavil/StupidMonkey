using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var th = new System.Threading.Thread(testthread);
            th.Start();
            Console.ReadLine();
            Console.ReadLine();
        }

        static void testthread()
        {
            Console.WriteLine("thread");
        }
    }
}
