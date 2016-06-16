#pragma once

long long StrToIntCore(const char* str, bool minus);

enum Status 
{ 
	kValid = 0,//�Ϸ�����
	kInvalid   //�Ƿ�����
};

int g_nStatus = kValid;    //һ��ȫ��״̬���ƣ���ʼ��Ϊ�Ϸ�

int StrToInt(const char* str)
{
	g_nStatus = kInvalid;  //�Ƿ�
	long long num = 0;     //װ��󷵻ص��������

	if (str != NULL && *str != '\0')
	{
		bool minus = false;//�ǲ��Ǹ��ţ���ʼ��Ϊ����
		if (*str == '+')   //��������
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;  //�Ǹ��ţ�minus��Ϊ��
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

	while (*digit != '\0')              //�����Ŵ������
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;  //���������
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF)                //�������
				|| (minus && num < (signed int)0x80000000)) //������С
			{
				num = 0;
				break;
			}

			digit++;
		}
		else                            //���ַǷ��ַ�
		{
			num = 0;
			break;
		}
	}

	if (*digit == '\0')                 //���֡�\0��Ϊ�Ϸ�
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

	//��Ч�����������, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//��Ч����С������, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");
}