// ManageCppDll.h
#pragma once
#define LX_DLL_CLASS_EXPORTS
#include "../CoreNative/CoreNative.h"
using namespace System;
namespace CoreManageDll
{
	public ref class Core
	{
		// 包装所有类CPerson的公有成员函数
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
		// 类CPerson的指针，用来调用类CPerson的成员函数
		CCore *m_pImp;
	};
};