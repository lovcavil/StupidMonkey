using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreData;

namespace StupidMonkey.CoreLogic
{
    public class UpdateManager
    {
        List<UpdateCollection> updateCollection;

        public void Update()
        {
            foreach (UpdateCollection updateCollection in updateCollection)
            {
                updateCollection.Update();
            }
        }
        /// <summary>
        /// test Initialize ---basic function only
        /// 提供管理一个唯一的UpdateCollection 
        /// </summary>
        public void Initialize()
        {
            updateCollection = new List<UpdateCollection>();
            var n = new UpdateCollection();
            updateCollection.Add(n);
        }


    }
    public class UpdateCollection
    {
        ///int initial;
        List<Node> nodes = new List<Node>();
        public void Update()
        {
            foreach (Node node in nodes)
            {
                node.Update();
            }
        }

    }
}
