using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreLogic;
namespace StupidMonkey.CoreData
{
    class State:PropertyType
    {
        public static PropertyManager propertyManager;
        public override PropertyManager getPropertyManager { get { return propertyManager; } set { propertyManager = value; } }

    }

    class Solid:State
    {

    }
}
