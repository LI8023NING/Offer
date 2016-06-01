#pragma once

#include<iostream>
#include<iterator>
using namespace std;
#include<stack>

//�жϳ�ջ���еĺϷ��� push��ջ���� pop���ж�����
bool IsPopOrder(const int* push, const int* pop, int length)
{
	bool bPossible = false;

	if (push != nullptr && pop != nullptr && length > 0)
	{
		const int* ppush = push;
		const int* ppop = pop;

		std::stack<int> st;      //������ʱ����ջ
		while (ppop - pop < length)  //��ǰ�ᣬpop����û�е�������ж���ɣ��Դ�Ϊ׼
		{
			while (st.empty() || st.top() != *ppop)
			{
				if (ppush - push == length) //���pop�е��� ��push�и���û����
					break;
				st.push(*ppush);
				ppush++;
			}

			if (st.top() == *ppop)
			{
				st.pop();
				ppop++;
			}
			else
			{
				break;
			}
		}

		if (st.empty() && ppop - pop == length)
			bPossible = true;
	}
	return bPossible;
}
