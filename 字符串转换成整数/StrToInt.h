#pragma once

long long StrToIntCore(const char* str, bool minus);

enum Status 
{ 
	kValid = 0,//合法输入
	kInvalid   //非法输入
};

int g_nStatus = kValid;    //一个全局状态控制，初始化为合法

int StrToInt(const char* str)
{
	g_nStatus = kInvalid;  //非法
	long long num = 0;     //装最后返回的整数结果

	if (str != NULL && *str != '\0')
	{
		bool minus = false;//是不是负号，初始化为不是
		if (*str == '+')   //考虑正号
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;  //是负号，minus置为真
		}

		if (*str != '\0')  
		{
			num = StrToIntCore(str, minus);
		}
	}

	return (int)num;
}

long long StrToIntCore(const char* digit, bool minus)
{
	long long num = 0;

	while (*digit != '\0')              //正负号处理完成
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;  //整正负结果
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF)                //正数最大
				|| (minus && num < (signed int)0x80000000)) //负数最小
			{
				num = 0;
				break;
			}

			digit++;
		}
		else                            //出现非法字符
		{
			num = 0;
			break;
		}
	}

	if (*digit == '\0')                 //这种‘\0’为合法
	{
		g_nStatus = kValid;
	}

	return num;
}


void Test(char* string)
{
	int result = StrToInt(string);
	if (result == 0 && g_nStatus == kInvalid)
		printf("the input %s is invalid.\n", string);
	else
		printf("number for %s is: %d.\n", string, result);
}

void _Test()
{
	Test(NULL);

	Test("");

	Test("123");

	Test("+123");

	Test("-123");

	Test("1a33");

	Test("+0");

	Test("-0");

	//有效的最大正整数, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//有效的最小负整数, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");
}