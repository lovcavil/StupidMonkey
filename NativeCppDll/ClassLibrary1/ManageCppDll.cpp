// ManageCppDll.cpp
#include "stdafx.h"
#include "ManageCppDll.h"
#include <vcclr.h>
namespace ManageCppDll
{
	// 在构造函数中创建类CPerson的对象并在析构函数中将该对象销毁
	// 所有的成员函数实现都是通过指针m_pImp调用类CPerson的相应成员函数实现
	Person::Person()
	{
		m_pImp = new CPerson();
	}
	Person::Person(String ^ strName, Char cSex, int iAge)
	{
		// 将string转换成C++能识别的指针
		pin_ptr<const wchar_t> wcName = PtrToStringChars(strName);
		m_pImp = new CPerson(wcName, cSex, iAge);
	}
	Person::~Person()
	{
		// 在析构函数中删除CPerson对象
		delete m_pImp;
	}
	void Person::Name::set(String ^ strName)
	{
		pin_ptr<const wchar_t> wcName = PtrToStringChars(strName);
		m_pImp->SetName(wcName);
	}
	String ^ Person::Name::get()
	{
		return gcnew String(m_pImp->GetName());
	}
	void Person::Sex::set(Char cSex)
	{
		m_pImp->SetSex(cSex);
	}
	Char Person::Sex::get()
	{
		return m_pImp->GetSex();
	}
	void Person::Age::set(int iAge)
	{
		m_pImp->SetAge(iAge);
	}
	int  Person::Age::get()
	{
		return m_pImp->GetAge();
	}
	String ^ Person::GetLastError()
	{
		return gcnew String(m_pImp->GetLastError());
	}
};