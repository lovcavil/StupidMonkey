
// NativeCppDll.h
#pragma once
#ifndef LX_DLL_CLASS_EXPORTS
#define LX_DLL_CLASS __declspec(dllexport)
#else
#define LX_DLL_CLASS __declspec(dllimport)
#endif
class LX_DLL_CLASS CPerson
{
public:
	CPerson();
	CPerson(const wchar_t *pName, const wchar_t cSex, int iAge);
	void SetName(const wchar_t *pName);
	wchar_t * GetName();
	void SetSex(const wchar_t cSex);
	wchar_t GetSex();
	void SetAge(int iAge);
	int GetAge();
	wchar_t * GetLastError();
private:
	wchar_t m_szName[128];
	wchar_t m_cSex;
	int m_iAge;
	wchar_t m_szLastError[128];
	void ShowError();
};
// NativeCppDll.cpp
#include "stdafx.h"
#include "NativeCppDll.h"
#include <iostream>
#include <tchar.h>
using namespace std;
CPerson::CPerson()
{
	wcscpy_s(m_szName, _T("No Name"));
	m_cSex = 'N';
	m_iAge = 0;
	wcscpy_s(m_szLastError, _T("No Error"));
}
CPerson::CPerson(const wchar_t *pName, const wchar_t cSex, int iAge)
{
	wcscpy_s(m_szLastError, _T("No Error"));
	SetName(pName);
	SetSex(cSex);
	SetAge(iAge);
}
void CPerson::SetName(const wchar_t *pName)
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
wchar_t * CPerson::GetName()
{
	return m_szName;
}
void CPerson::SetSex(const wchar_t cSex)
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
wchar_t CPerson::GetSex()
{
	return m_cSex;
}
void CPerson::SetAge(int iAge)
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
int CPerson::GetAge()
{
	return m_iAge;
}
wchar_t * CPerson::GetLastError()
{
	return m_szLastError;
}
void CPerson::ShowError()
{
	cerr << m_szLastError << endl;
}