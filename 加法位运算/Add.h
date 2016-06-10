#pragma once

int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = num1^num2;  //ʵ�ֲ���λ�ӷ� ÿ�ζ�һ��
		carry = (num1 & num2) << 1;  //ÿ����֮�󣬶�֪����Ҫ��λ��λ��
		                             //��λ��λ��֪�������ҽ�λ��1����Ҫ����ԭ���ϣ�����һ�����
		                             //���û�н�λ����ôԭ�����������Ľ�� ���ǼӵĽ�� ���Խ���

		num1 = sum;
		num2 = carry;
	} 
	while (num2 != 0);
	
	return num1;
}