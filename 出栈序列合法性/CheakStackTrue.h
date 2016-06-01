#pragma once

#include<iostream>
#include<iterator>
using namespace std;
#include<stack>

//判断出栈序列的合法性 push入栈序列 pop待判断序列
bool IsPopOrder(const int* push, const int* pop, int length)
{
	bool bPossible = false;

	if (push != nullptr && pop != nullptr && length > 0)
	{
		const int* ppush = push;
		const int* ppop = pop;

		std::stack<int> st;      //调用临时辅助栈
		while (ppop - pop < length)  //大前提，pop序列没有到达最后，判断完成，以此为准
		{
			while (st.empty() || st.top() != *ppop)
			{
				if (ppush - push == length) //如果pop中的数 在push中根本没有呢
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
