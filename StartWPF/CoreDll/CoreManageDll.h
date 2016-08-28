// ManageCppDll.h
#pragma once
#define LX_DLL_CLASS_EXPORTS
#include "../CoreNative/CoreNative.h"
using namespace System;
namespace CoreManageDll
{
	public ref class Core
	{
		// ��װ������CPerson�Ĺ��г�Ա����
	public:
		Core();
		Core(String ^ strName, Char cSex, int iAge);
		~Core();
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
		CCore *m_pImp;
	};
};