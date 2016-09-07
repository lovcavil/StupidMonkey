#pragma once


#ifndef LX_DLL_CLASS_EXPORTS
#define LX_DLL_CLASS __declspec(dllexport)
#else
#define LX_DLL_CLASS __declspec(dllimport)
#endif
class LX_DLL_CLASS CCore
{
public:
	CCore();
	CCore(const wchar_t *pName, const wchar_t cSex, int iAge);
	void SetName(const wchar_t *pName);
	wchar_t * GetName();
	void SetSex(const wchar_t cSex);
	wchar_t GetSex();
	void SetAge(int iAge);
	int GetAge();
	wchar_t * GetLastError();

	void start0();
private:
	wchar_t m_szName[128];
	wchar_t m_cSex;
	int m_iAge;
	wchar_t m_szLastError[128];
	void ShowError();
};


