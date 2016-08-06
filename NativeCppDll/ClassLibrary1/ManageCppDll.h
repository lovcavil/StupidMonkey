// ManageCppDll.h
#pragma once
#define LX_DLL_CLASS_EXPORTS
#include "../NativeCppDll/NativeCppDll.h"
using namespace System;
namespace ManageCppDll
{
	public ref class Person
	{
		// ��װ������CPerson�Ĺ��г�Ա����
	public:
		Person();
		Person(String ^ strName, Char cSex, int iAge);
		~Person();
		property String ^ Name
		{
			void set(String ^ strName);
			String ^ get();
		}
		property Char Sex
		{
			void set(Char cSex);
			Char get();
		}
		property int Age
		{
			void set(int iAge);
			int get();
		}
		String ^ GetLastError();
	private:
		// ��CPerson��ָ�룬����������CPerson�ĳ�Ա����
		CPerson *m_pImp;
	};
};