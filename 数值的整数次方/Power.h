#pragma once

/*
*base是底数 exponent是指数
*/
bool g_Input = false;                     //错误时，返回零，和正常返回零区别

double Power(double base, int exponent)
{
	g_Input = false;

	if (equal(base, 0.0) && exponent < 0) //底数为零，指数为负，即考虑分母为零
	{
		g_Input = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)        //如果指数为负，先换成正的处理
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsingnedExponent(base, absExponent);  //最终结果
	if (exponent < 0)        //如果指数为负，结果就是正数的倒数
		result = 1.0 / result;

	return result;
}

//将一个数的次方拆分，2为拆分单元 提高效率
double PowerWithUnsingnedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)    //两个递归出口
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsingnedExponent(base,exponent>>1); //右移1 表示 除2
	result *= result;
	if (exponent & 0x1 == 1)   //判断奇数偶数
		result *= base;

	return result;
}

//两个double数是否相等，不能用绝对的相等来写，两个double数满足如下，就判相等
bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

void Test()
{
	//PowerWithUnsingnedExponent(2,3);
	Power(2,3);

}