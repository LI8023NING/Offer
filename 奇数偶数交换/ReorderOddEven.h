#pragma once

bool ReorderOddEven(int number)
{
	if (number % 2 == 0)
		return true;
	else
		return false;
}

bool IsplusOrminus(int number)
{
	if (number < 0)
		return true;
	else
		return false;
}

void ReorderOddEven(int* a, int length,bool (*fun)(int))
{
	
	assert(a);

	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		if (fun(a[left]) && !fun(a[right]))
		{
			swap(a[left], a[right]);
			left++;
			right--;
		}
		else if (fun(a[left]))
		{
			right--;
		}
		else
		{
			left++;
		}
	}
}

void Print(int* a)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void Test()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	ReorderOddEven(a, 10, ReorderOddEven);
	Print(a);
	int b[10] = {-1,2,-3,4,-5,6,-7,8,-9,2};
	ReorderOddEven(b,10,IsplusOrminus);
	Print(b);

	
}