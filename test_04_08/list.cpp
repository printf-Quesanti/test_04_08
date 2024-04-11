#include"list.h"

void test1()
{
	List* plist = NULL;
	plist = Listinit(plist);
	Listpushback(plist, 1);
	Listpushback(plist, 2);
	Listpushback(plist, 3);
	Listpushback(plist, 4);
	Listpopback(plist);
	Listpushfront(plist, 1);
	Listpopfront(plist);
	Listprintf(plist);
}

void test2()
{
	List* plist = NULL;
	plist = Listinit(plist);
	Listpushback(plist, 1);
	Listpushback(plist, 2);
	Listpushback(plist, 3);
	Listpushback(plist, 4);
	/*List* pos = Listfind(plist, 2);
	if (pos)
	{
		Listinsert( pos, 2);
	}*/
	//Listpushback(plist, 2);
	List* pos = Listfind(plist, 2);
	if (pos)
	{
		Listerase(pos);
	}
	Listprintf(plist);
	Listdestroy(plist);
}

int main()
{
	//test1();
	test2();
	return 0;
}