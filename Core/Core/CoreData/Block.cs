using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreData;

namespace StupidMonkey.CoreData.Map
{
    partial class Block:Karo<Block>
    {
        public const short Length=100;
        public const short Width = 100;
        public const int Area = Length * Width;

        /// <summary>
        ///  第一与最后放空  访问方式不合理需改
        /// </summary>
        
        //public Location this[int x, int y]
        //{
        //    get { return (Location)structure.entities[x* Length + y]; }
        //    private set { structure.entities[x * Length + y]=value; }
        //}
        /// <summary>
        /// 分配loc数组内元素的内存
        /// </summary>
        public Block()
        {
            //structure.entities = new Location[(Length + 2) * (Width + 2)];
            //for(int i = 0; i<Length+1; i++)
            //{
            //    for (int j = 0; j < Width+1;j++)
            //    {
            //        this[i, j] = new Location();
            //    }
            //}
        }
    }


}
