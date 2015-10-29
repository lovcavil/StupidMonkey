using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreLogic
{
    /// <summary>
    /// 预计拿来处理保存update initial的功能
    /// child manage
    /// </summary>
    class Node
    {
        static int id_count=0;
        static object id_lock =new object();
        int id;
        INodetype nt;
        UpdateCollection fatherUpdateCollection;

        public void Update()
        {
            nt.Update();
        }

        public void Initialize() 
        {
            GetNewId();
        }

        private int GetNewId()
        {
            lock (id_lock) {
                id = ++id_count;
                return id;
            }
        }
        public void Initialize(int id,INodetype nt)
        {
            if (id == 0) {
                GetNewId();
            } else {
                this.id = id;
            }
            
            this.nt = nt;
        }

        public void Load()
        {
            throw new System.NotImplementedException();
        }

        public void Save()
        {
            throw new System.NotImplementedException();
        }
    }

    interface INodetype
    {
        string Name { get; set; }
        void Update();
    }
}
