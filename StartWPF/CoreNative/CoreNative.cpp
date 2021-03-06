
#include "stdafx.h"
#include "CoreNative.h"
#include <iostream>
#include <tchar.h>
using namespace std;


void CCore::start0()
{
	int* a = new int();
	
	return;
}



CCore::CCore()
{
	wcscpy_s(m_szName, _T("No Name"));
	m_cSex = 'N';
	m_iAge = 0;
	wcscpy_s(m_szLastError, _T("No Error"));
	start0();
}

CCore::CCore(const wchar_t *pName, const wchar_t cSex, int iAge)
{
	wcscpy_s(m_szLastError, _T("No Error"));
	SetName(pName);
	SetSex(cSex);
	SetAge(iAge);
}




void CCore::SetName(const wchar_t *pName)
{
	if ((pName == NULL) || (wcslen(pName) == 0) || (wcslen(pName) > 127))
	{
		wcscpy_s(m_szName, _T("No Name"));
		wcscpy_s(m_szLastError, _T("The length of the input name is out of range."));
		ShowError();
		return;
	}
	wcscpy_s(m_szName, pName);
}
wchar_t * CCore::GetName()
{
	return m_szName;
}
void CCore::SetSex(const wchar_t cSex)
{
	if ((cSex != 'F') && (cSex != 'M') && (cSex != 'm') && (cSex != 'f'))
	{
		m_cSex = 'N';
		wcscpy_s(m_szLastError, _T("The input sex is out of [F/M]."));
		ShowError();

		return;
	}
	m_cSex = cSex;
}
wchar_t CCore::GetSex()
{
	return m_cSex;
}
void CCore::SetAge(int iAge)
{
	if ((iAge < 0) || (iAge > 150))
	{
		m_iAge = 0;
		wcscpy_s(m_szLastError, _T("The input age is out of range."));
		ShowError();
		return;
	}
	m_iAge = iAge;
}
int CCore::GetAge()
{
	return m_iAge;
}
wchar_t * CCore::GetLastError()
{
	return m_szLastError;
}
void CCore::ShowError()
{
	cerr << m_szLastError << endl;
}