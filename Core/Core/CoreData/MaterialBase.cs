using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreLogic;

namespace StupidMonkey.CoreData
{ 

    class Material:PropertyType
    {
        public static PropertyManager propertyManager;
        public override PropertyManager getPropertyManager { get { return propertyManager; }set { propertyManager = value; }  }

        public void add()
        {
            ((PropertyManager<Material>)Material.propertyManager).addProperty(this );
        }


        float density;
        public float Density
        {
            get { return density; }
            set { density = value; }
        }

        State state;

        public Material()
        {
           
        }

        public Material(string name, float density)
        {
            Name = name;
            Density = density;
            add();
        }

    }

    class Element
    {

    }
}
