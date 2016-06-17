#pragma once

template<class T>
class  MinNumber
{
public:
	MinNumber()
	{}
	~MinNumber()
	{}
public:
	void Push(const T& key);
	void Pop();
	T Top();
	T Min();
	T Size();
private:
	stack<T> m_data;
	stack<T> min_temp;
};

template<class T>
void MinNumber<T>::Push(const T& key)
{
	m_data.push(key);
	if (min_temp.size() == 0 || key < min_temp.top())
		min_temp.push(key);
	else
		min_temp.push(min_temp.top());
}

template<class T>
void MinNumber<T>::Pop()
{
	assert(m_data.size() > 0 && min_temp.size() > 0);
	m_data.pop();
	min_temp.pop();
}

template<class T>
T MinNumber<T>::Min()
{
	return min_temp.top();
}

template<class T>
T MinNumber<T>::Size()
{
	return m_data.size();
}

void Test()
{
	MinNumber<int> s1;
	s1.Push(2);
	s1.Push(5);
	s1.Push(6);
	s1.Push(7);
	s1.Push(8);
	s1.Push(3);
	s1.Push(3);
	s1.Push(1);

	s1.Min();
	s1.Pop();
	s1.Min();
	
}