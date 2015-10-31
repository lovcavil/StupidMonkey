using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreLogic
{
    public class TimeEventArgs:EventArgs
    {
        public TimeEventArgs()
        { }
    }
    static class CoreTimer
    {

        public static event EventHandler<TimeEventArgs> NewTickTime;
        static void NewTick(object o)
        {
            RaiseNewTick();
        }
        private static System.Threading.Timer t; 
        public static void Start()
        {
             t = new System.Threading.Timer(NewTick, null, TimeSpan.FromMilliseconds(100), TimeSpan.FromMilliseconds(100));
        }

        public static void Stop()
        {
            t.Dispose();
            t = null;
        }

        private static void RaiseNewTick()
        {
            var newTickTime = NewTickTime;
            if(NewTickTime!=null)
            {
                newTickTime(null, new TimeEventArgs());
            }
        }


    }


}
