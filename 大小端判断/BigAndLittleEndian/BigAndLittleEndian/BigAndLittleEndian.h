#pragma once

int CheckSystem()
{
	union check
	{
		int i;
		char ch;
	}c;

	c.i = 0x00000001;
	c.ch = 2;
	return (c.ch == 1);
}

void Test()
{
	int check = CheckSystem();
	if (check == 1)
		cout << "��ǰϵͳΪС��" << endl;
	else
		cout << "��ǰϵͳΪ���" << endl;
}