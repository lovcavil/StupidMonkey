using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreData
{
    class Structure
    {
        private string name;
        public Entity[] entities;

        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }
    }
}
