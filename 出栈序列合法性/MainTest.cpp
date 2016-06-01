#include"CheakStackTrue.h"

void Test()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 5, 4, 3, 1, 2 };
	
	bool num = 0;
	num = IsPopOrder(a,b,5);
	if (num == true)
	{
		cout << "合法" << endl;
	}
	else
	{
		cout << "非法" << endl;
	}
}

int main()
{
	Test();
	return 0;
}