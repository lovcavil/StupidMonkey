using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Collections.Specialized;
using StupidMonkey.CoreLogic;
namespace StupidMonkey.CoreData
{
    /// <summary>
    /// provide time (and space?)
    /// </summary>
    class Universe:INodetype
    {
        string name;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        Node[] himmelskoerpers;
        public void Update()
        {

        }
    }

    class Himmelskoerper : INodetype
    {
        string name;
        double[] position;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public void Update()
        {

        }

    }
}
