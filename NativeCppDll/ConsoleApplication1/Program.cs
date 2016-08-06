using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManageCppDll;
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Person person = new Person();
            person.Name = "StarLee";
            person.Sex = 'M';
            person.Age = 28;
        }
    }
}

