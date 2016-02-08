/**
实现原理:
基类里面用map管理所有需要动态创建 【类名-创建对象的函数指针】
基类声明中需要添加 DECLEAR_DYNCRT_BASE 宏,cpp实现中要添加 IMPLEMENT_DYNCRT_BASE 宏
派生类声明中需要添加 DECLEAR_DYNCRT_CLASS 宏，cpp实现中要添加 IMPLEMENT_DYNCRT_CLASS 宏
派生类宏中创建了一个全局对象向基类map中注册【类名-创建对象的函数指针】
*/
#include <map>
#include <iostream>
using namespace std;


// 声明具有动态创建的基类
#define DECLEAR_DYNCRT_BASE(base) \
public: \
typedef base* (*ClassGen)(); \
static void _register(const char* class_name, ClassGen class_gen) \
{ \
    class_set.insert(std::map<const char*, ClassGen>::value_type(class_name, class_gen)); \
} \
static base* create(const char* class_name) \
{ \
    std::map<const char*, ClassGen>::iterator it = class_set.find(class_name);   \
    if (it != class_set.end()) \
        return (it->second)(); \
    return NULL; \
} \
protected: \
static std::map<const char*, ClassGen> class_set;

// 用于实现基类
#define IMPLEMENT_DYNCRT_BASE(base) \
std::map<const char*, base::ClassGen> base::class_set;


// 用于声明一个能够被动态创建的类(用一个全局对象进行注册)
#define DECLEAR_DYNCRT_CLASS(derived, base) \
public: \
    struct derived##register \
    { \
        derived##register() \
        { \
            static bool bRegister = false; \
            if (!bRegister) \
            { \
                base::_register(#derived, _CreateObjectByName); \
                bRegister = true; \
            } \
        } \
    }; \
    static base* _CreateObjectByName() \
    { \
        return new derived; \
    }


// 用于实现一个能被动态创建的类
#define IMPLEMENT_DYNCRT_CLASS(derived) \
    static derived::derived##register _##derived##global_object;

class Base
{
	DECLEAR_DYNCRT_BASE(Base)
		DECLEAR_DYNCRT_CLASS(Base, Base)
public:
	virtual void Print()
	{
		std::cout << "This is base!" << std::endl;
	}
};

IMPLEMENT_DYNCRT_BASE(Base)
IMPLEMENT_DYNCRT_CLASS(Base)


class Derived : public Base
{
	DECLEAR_DYNCRT_CLASS(Derived, Base)
public:
	virtual void Print()
	{
		cout << "This is derived!" << endl;
	}
};
IMPLEMENT_DYNCRT_CLASS(Derived)




