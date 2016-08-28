// ManageCppDll.cpp
#include "stdafx.h"
#include "CoreManageDll.h"
#include <vcclr.h>
namespace CoreManageDll
{
	// �ڹ��캯���д�����CPerson�Ķ��������������н��ö�������
	// ���еĳ�Ա����ʵ�ֶ���ͨ��ָ��m_pImp������CPerson����Ӧ��Ա����ʵ��
	Core::Core()
	{
		m_pImp = new CCore();
	}
	Core::Core(String ^ strName, Char cSex, int iAge)
	{
		// ��stringת����C++��ʶ���ָ��
		pin_ptr<const wchar_t> wcName = PtrToStringChars(strName);
		m_pImp = new CCore(wcName, cSex, iAge);
	}
	Core::~Core()
	{
		// ������������ɾ��CPerson����
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