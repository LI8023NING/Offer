/*
*题目：在字符串中找到第一个只出现一次的字符，返回
*作者：李宁
*时间：2016.5.16
*/
#pragma once

char FindFirstCharInStrs(char* str)
{
	assert(str != nullptr);

	const int max = 256;
	int array[max] = {0};
	for (int i = 0; i < strlen(str); ++i)
	{
		array[str[i]]++;
	}

	for (int i = 0; i < strlen(str); ++i)
	{
		if (array[str[i]] == 1)
		{
			return str[i];
		}
	}
}


char FirstNotRepeatingChar(char* pString)
{
	if (pString == nullptr)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
	{
		hashTable[i] = 0;
	}

	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)]++;

	pHashKey = pString;  //继续指向头
	while (*(pHashKey) != '\0')
	{
		if (hashTable[*(pHashKey)] == 1)
		{
			return *(pHashKey);
		}
		pHashKey++;
	}
	return '\0';
}

void Test()
{
	char p[] = "abaccdeff";
	char c = FindFirstCharInStrs(p);
	char b = FirstNotRepeatingChar(p);
	cout << c << endl;
	cout << b << endl;
}