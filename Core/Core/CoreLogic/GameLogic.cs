using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using StupidMonkey.CoreData.Map;
using StupidMonkey.CoreData;


namespace StupidMonkey.CoreLogic
{
    public class GameLogic
    {
        #region gameLogicStatus
        public enum gameLogicStatus
        {
            Noexist=0,
            Initializing=10,
            Running=20,
            Finalizing=30
        }

        public gameLogicStatus Status
        {
            get { return status; }
            set { /*status = value; */}
        }
        private gameLogicStatus status = gameLogicStatus.Noexist;

        #endregion

        
        public GameLogic()
        {
            
        }

        UpdateManager um;
        PropertiesManager pm;
        Log log;

        /// <summary>
        /// test Initialize ---basic function only
        /// 把每个组件都初始化
        /// </summary>
        void Initialize()
        {
            um = new UpdateManager();
            um.Initialize();
            pm = new PropertiesManager();
            pm.AddPropertyManager<Material>();
            pm.AddPropertyManager<State>();

            Material bbb = new Material("ssss",1.2f);
            ///((PropertyManager<Material>)Material.propertyManager).addProperty(bbb);
            
            State ccc = new State();
            ((PropertyManager<State>)State.propertyManager).addProperty(ccc);

            log = new Log();
            CoreTimer.Start();
        }


        public void run()
        {
            Initialize();
            
            
            log.Start();
            //var bf=new Block.BlockFactory();
            //bf.Make(new String[1]);
            //bf.Make(new String[1]);




            var mth = new System.Threading.Thread(mainloop);

            mth.Start();
        }

        public static void mainloop()
        {

        }


    }

    public class Log
    {
        
        int count = 0;
        public void Start()
        {
            
            CoreTimer.NewTickTime += this.Update;
            
        }
        public void Update(object sender, TimeEventArgs e)
        {
            UnityEngine.MonoBehaviour.print(count++.ToString());
        }
    }
}
