#include<iostream>
using namespace std;

#include"BinaryTreeDoubleList.h"


void Test()
{
	int a[] = { 5, 3, 4, 1, 7, 2, 6};
	SBTree<int, int> s1;
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		s1.Insert(a[i], a[i]);
	}

	cout << "��������������������" << endl;
	s1.InOrder(s1._root);
	cout << endl;
	cout << "˫������ı��������" << endl;
	s1.TreaveList();
}



int main()
{
	Test();
	return 0;
}