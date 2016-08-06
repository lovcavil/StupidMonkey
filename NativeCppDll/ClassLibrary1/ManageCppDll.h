// ManageCppDll.h
#pragma once
#define LX_DLL_CLASS_EXPORTS
#include "../NativeCppDll/NativeCppDll.h"
using namespace System;
namespace ManageCppDll
{
	public ref class Person
	{
		// 包装所有类CPerson的公有成员函数
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
		// 类CPerson的指针，用来调用类CPerson的成员函数
		CPerson *m_pImp;
	};
};