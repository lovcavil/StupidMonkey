// ManageCppDll.cpp
#include "stdafx.h"
#include "CoreManageDll.h"
#include <vcclr.h>
namespace CoreManageDll
{
	// 在构造函数中创建类CPerson的对象并在析构函数中将该对象销毁
	// 所有的成员函数实现都是通过指针m_pImp调用类CPerson的相应成员函数实现
	Core::Core()
	{
		m_pImp = new CCore();
	}
	Core::Core(String ^ strName, Char cSex, int iAge)
	{
		// 将string转换成C++能识别的指针
		pin_ptr<const wchar_t> wcName = PtrToStringChars(strName);
		m_pImp = new CCore(wcName, cSex, iAge);
	}
	Core::~Core()
	{
		// 在析构函数中删除CPerson对象
		delete m_pImp;
	}
	void Core::Name::set(String ^ strName)
	{
		pin_ptr<const wchar_t> wcName = PtrToStringChars(strName);
		m_pImp->SetName(wcName);
	}
	String ^ Core::Name::get()
	{
		return gcnew String(m_pImp->GetName());
	}
	void Core::Sex::set(Char cSex)
	{
		m_pImp->SetSex(cSex);
	}
	Char Core::Sex::get()
	{
		return m_pImp->GetSex();
	}
	void Core::Age::set(int iAge)
	{
		m_pImp->SetAge(iAge);
	}
	int  Core::Age::get()
	{
		return m_pImp->GetAge();
	}
	String ^ Core::GetLastError()
	{
		return gcnew String(m_pImp->GetLastError());
	}
};