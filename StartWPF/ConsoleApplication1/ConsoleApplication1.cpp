// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "boost/pool/pool.hpp"
void func();
void func1();
int main()
{
	func();
//	func1();
    return 0;
}

void func()
{
	for (int i = 0; i < 10000000; ++i)
	{
		int *  t = new int();
		// Do something with t; don't take the time to free() it.
	}
	boost::pool<> p(sizeof(int));
	for (int i = 0; i < 10000000; ++i)
	{
		int * const t =(int * const) p.malloc();
		 // Do something with t; don't take the time to free() it.
	}
} // on function exit, p is destroyed, and all malloc()'ed ints are implicitly freed.
void func1()
{
	
	for (int i = 0; i < 10; ++i)
	{
		int *  t = new int[100000000]() ;
		// Do something with t; don't take the time to free() it.
	}
} // on function exit, p is destroyed, and all malloc()'ed ints are implicitly freed.
