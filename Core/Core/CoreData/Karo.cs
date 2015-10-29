using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreData.Map
{
    interface IAdjacent<T>
    {
        T[] Adjacent { get; }
    }

    interface IPlot<T> : IAdjacent<T>
    {
        T Up{get;}
        T Down { get; }
        T Left { get; }
        T Right { get; }
    }
    /// <summary>
    /// 接邻实现 
    /// </summary>
    class Karo<TKaro> :Entity,IPlot<TKaro>
    {
        public enum Direction
        {
            Up=0,   
            Right=1,
            Down=2,
            Left=3
        }

        public TKaro[] AdjacentLocations=new TKaro[8];

        public TKaro[] Adjacent
        {
            get { return AdjacentLocations; }
           set { AdjacentLocations = value; }
       }

        public TKaro Up{
            get { return AdjacentLocations[(int)Direction.Up]; }
        }
        public TKaro Right{
            get { return AdjacentLocations[(int)Direction.Right]; }
        }
        public TKaro Down{
            get { return AdjacentLocations[(int)Direction.Down]; }
        }
        public TKaro Left{
            get { return AdjacentLocations[(int)Direction.Left]; }
        }



    }
}