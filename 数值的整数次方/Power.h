#pragma once

/*
*base�ǵ��� exponent��ָ��
*/
bool g_Input = false;                     //����ʱ�������㣬����������������

double Power(double base, int exponent)
{
	g_Input = false;

	if (equal(base, 0.0) && exponent < 0) //����Ϊ�㣬ָ��Ϊ���������Ƿ�ĸΪ��
	{
		g_Input = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)        //���ָ��Ϊ�����Ȼ������Ĵ���
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsingnedExponent(base, absExponent);  //���ս��
	if (exponent < 0)        //���ָ��Ϊ����������������ĵ���
		result = 1.0 / result;

	return result;
}

//��һ�����Ĵη���֣�2Ϊ��ֵ�Ԫ ���Ч��
double PowerWithUnsingnedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)    //�����ݹ����
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsingnedExponent(base,exponent>>1); //����1 ��ʾ ��2
	result *= result;
	if (exponent & 0x1 == 1)   //�ж�����ż��
		result *= base;

	return result;
}

//����double���Ƿ���ȣ������þ��Ե������д������double���������£��������
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