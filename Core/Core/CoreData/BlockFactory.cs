using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreLogic;

namespace StupidMonkey.CoreData.Map
{
    partial class Block
    {
        /// <summary>
        /// block工厂 未并行，可能需要 可能需要有两种block（不同结构，有无实际内部结构）
        /// </summary>
        public class BlockFactory : Factory<Block>
        {
            public List<Block> Lib = new List<Block>();

            /// <summary>
            /// 构建block数据，再加入block表
            /// </summary>
            /// <param name="data"></param>
            /// <returns></returns>
            public Block Make(string[] data)
            {

                Block result = new Block();
                //for (int i = 1; i < Block.Length; i++)
                //{
                //    for (int j = 1; j < Block.Width; j++)
                //    {
                //        result[i, j].AdjacentLocations[0] = result[i, j - 1];
                //        result[i, j].AdjacentLocations[1] = result[i + 1, j];
                //        result[i, j].AdjacentLocations[2] = result[i, j + 1];
                //        result[i, j].AdjacentLocations[3] = result[i - 1, j];
                //    }
                //}


                //Lib.Add(result);
                return result;
            }
        }
    }
}
