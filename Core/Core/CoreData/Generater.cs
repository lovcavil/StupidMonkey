using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreLogic;
namespace StupidMonkey.CoreData
{
    interface IGenerator : INodetype 
    {
        Node Generate() ;

    }
    /// <summary>
    /// 自己寻求分配内存的生成器
    /// </summary>
    /// <typeparam name="T"></typeparam>
    class Generater<T> : IGenerator where T : INodetype,new()
    {
        string name;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        private string WorkList;
        public Node Generate()
        {
            Node result = new Node();            
            T nt = new T();
            result.Initialize(0,nt);
            return result;
        }
        public void Update()
        {

        }
    }
}
