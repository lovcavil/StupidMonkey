/**
ʵ��ԭ��:
����������map����������Ҫ��̬���� ������-��������ĺ���ָ�롿
������������Ҫ��� DECLEAR_DYNCRT_BASE ��,cppʵ����Ҫ��� IMPLEMENT_DYNCRT_BASE ��
��������������Ҫ��� DECLEAR_DYNCRT_CLASS �꣬cppʵ����Ҫ��� IMPLEMENT_DYNCRT_CLASS ��
��������д�����һ��ȫ�ֶ��������map��ע�᡾����-��������ĺ���ָ�롿
*/
#include <map>
#include <iostream>
using namespace std;


// �������ж�̬�����Ļ���
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

// ����ʵ�ֻ���
#define IMPLEMENT_DYNCRT_BASE(base) \
std::map<const char*, base::ClassGen> base::class_set;


// ��������һ���ܹ�����̬��������(��һ��ȫ�ֶ������ע��)
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


// ����ʵ��һ���ܱ���̬��������
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




