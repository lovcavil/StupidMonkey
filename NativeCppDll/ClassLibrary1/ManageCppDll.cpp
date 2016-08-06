// ManageCppDll.cpp
#include "stdafx.h"
#include "ManageCppDll.h"
#include <vcclr.h>
namespace ManageCppDll
{
	// �ڹ��캯���д�����CPerson�Ķ��������������н��ö�������
	// ���еĳ�Ա����ʵ�ֶ���ͨ��ָ��m_pImp������CPerson����Ӧ��Ա����ʵ��
	Person::Person()
	{
		m_pImp = new CPerson();
	}
	Person::Person(String ^ strName, Char cSex, int iAge)
	{
		// ��stringת����C++��ʶ���ָ��
		pin_ptr<const wchar_t> wcName = PtrToStringChars(strName);
		m_pImp = new CPerson(wcName, cSex, iAge);
	}
	Person::~Person()
	{
		// ������������ɾ��CPerson����
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