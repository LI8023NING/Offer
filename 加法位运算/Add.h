#pragma once

int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = num1^num2;  //实现不进位加法 每次都一样
		carry = (num1 & num2) << 1;  //每次与之后，都知道需要进位的位置
		                             //进位的位置知道，而且进位是1，需要加在原数上，又是一轮异或
		                             //如果没有进位，那么原先两个数异或的结果 就是加的结果 所以结束

		num1 = sum;
		num2 = carry;
	} 
	while (num2 != 0);
	
	return num1;
}