using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreLogic
{
    class BaseGameConstructor:INodetype
    {
        string name;
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
