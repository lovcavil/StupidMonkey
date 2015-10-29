using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreData
{
    class Entity: CoreLogic.INodetype
    {
        string name;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }


        float Mass;
        //energy energy;
        Material material;
        Structure structure;

        public void Update()
        {

        }
    }
}
