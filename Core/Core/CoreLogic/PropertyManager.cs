using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace StupidMonkey.CoreLogic
{
    /// <summary>
    /// 资产管理器总和
    /// </summary>
    class PropertiesManager
    {
        int count_PropertyType = 0;

        /// <summary>
        /// 资产管理器列表
        /// 存放 一个空的实际类型，指向相应的资产管理器
        /// </summary>
        List<PropertyType> lPT=new List<PropertyType>();

        /// <summary>
        /// 新建资产管理器
        /// 新建一个空的实际类型 ，指向一个新建的相应的资产管理器
        /// 加入资产管理器列表
        /// </summary>
        /// <typeparam name="T"></typeparam>
        public void AddPropertyManager<T>() where T : PropertyType,new()
        {
            
            var key = new T();
            var value = new PropertyManager<T>();
            key.getPropertyManager = value;

            lPT.Add(key);
        }


    }

    class PropertyManager<T>: PropertyManager where T : PropertyType
    {
        private List<T> lProterty = new List<T>();
        public T getProperty(int id) 
        {
            T result= lProterty[id];
            return result;
        }
        public  void addProperty(T property)
        {
            lProterty.Add(property );
        }
       

    }
    abstract class PropertyManager
    {
       
    }
    abstract class PropertyType
    {
        int count;
        public abstract PropertyManager getPropertyManager { get; set; }

        string name;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }



        public PropertyType()
        {
            
            ;
        }
    }
 

}
