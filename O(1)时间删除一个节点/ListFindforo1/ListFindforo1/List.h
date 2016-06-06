#pragma once
typedef int DataType;

class ListNode 
{
public:
	ListNode(const DataType& x)
		:_data(x)
		, _next(NULL)
	{}

public:
	DataType _data;
	ListNode* _next;
};

class Slist
{
public:
	Slist()
		:_head(NULL)
		, _tail(NULL)
	{}
	~Slist()
	{
		//����������ɾ���ڵ㣬ɾ��ȫ��
		Destory();
	}

	void Destory()
	{
		ListNode* begin = _head;
		while (begin)
		{
			ListNode* del = begin;
			begin = begin->_next;
			delete del;
		}
	}

public:
	//β��
	void PushBack(const DataType& x)
	{
		if (_head == NULL)
		{
			_head = new ListNode(x);

			_tail = _head;
		}
		else
		{
			_tail->_next = new ListNode(x);
			_tail = _tail->_next;
		}
	}

	//����
	ListNode* Find(const DataType& x)
	{
		ListNode* tmp = _head;
		while (tmp)
		{
			if (tmp->_data == x)
				return tmp;
			else
			{
				tmp = tmp->_next;
			}
		}
		return NULL;
	}

	//

	//��O(1)ʱ���ڣ�ɾ��һ���ڵ㣬��������
	void DeleteNodeNumone(ListNode** phead,ListNode* pToBeDelete)
	{
		if (*phead == nullptr || pToBeDelete == nullptr)
			return;

		//ɾ����β�ڵ�
		if (pToBeDelete->_next != nullptr)
		{
			ListNode* temp = pToBeDelete->_next;
			pToBeDelete->_data = temp->_data;
			pToBeDelete->_next = temp->_next;

			delete temp;
			temp = nullptr;
		}

		//ֻ��һ���ڵ�
		else if (*phead == pToBeDelete)
		{
			delete pToBeDelete;
			pToBeDelete = nullptr;
			*phead = nullptr;
		}

		//���һ�֣�ɾ���ڵ���β�ڵ�
		else
		{
			ListNode* cur = *phead;
			while (cur->_next != pToBeDelete)
			{
				cur = cur->_next;
			}
			delete pToBeDelete;
			pToBeDelete = nullptr;
			cur->_next = nullptr;
		}
	}

	void print()
	{
		ListNode* begin = _head;
		while (begin)
		{
			cout << begin->_data << "->";
			begin = begin->_next;
		}
		cout << "NULL" << endl;
	}


public:
	ListNode* _head;
	ListNode* _tail;
};
void Test()
{
	Slist s1;
	s1.PushBack(5);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(2);
	s1.PushBack(1);
	s1.PushBack(6);
	s1.PushBack(7);
	s1.PushBack(9);
	s1.print();

	ListNode* num =s1.Find(9);

	s1.DeleteNodeNumone(&s1._head, num);

	s1.print();
}