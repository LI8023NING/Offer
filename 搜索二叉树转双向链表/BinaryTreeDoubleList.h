#pragma once

template<class K, class V>
struct SBTNode
{
	K key;
	V value;

	SBTNode<K, V> *_left;
	SBTNode<K, V> *_right;

	SBTNode(const K& key, const V& value)
		:key(key)
		, value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class SBTree
{
	typedef SBTNode<K, V> Node;
public:
	SBTree()
		:_root(nullptr)
	{}

	~SBTree()
	{}

public:
	//非递归插入
	bool Insert(const K& key, const V& value)
	{
		return _Insert(key, value);
	}

	//递归插入
	bool Insert_R(const K& key, const V& value);

	//非递归查找节点
	SBTNode<K, V>* Find(const K& key)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}

		SBTNode<K, V> *cur = _root;
		while (cur->_left || cur->_right)
		{
			if (cur->key == key)
			{
				return cur;
			}
			else if (cur->key > key)
			{
				cur = cur->_left;
			}
			else if (cur->key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return nullptr;
			}
		}
	}

	bool _Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new SBTNode<K, V>(key, value);
			return true;
		}

		SBTNode<K, V> *parent = nullptr; //指向cur 的前驱
		SBTNode<K, V> *cur = _root;
		while (cur)
		{
			if (cur->key > key)  //插左边
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		if (parent->key < key)
		{
			SBTNode<K, V> *node = new SBTNode<K, V>(key, value);
			parent->_right = node;
			return true;
		}

		else if (parent->key > key)
		{
			SBTNode<K, V> *node = new SBTNode<K, V>(key, value);
			parent->_left = node;
			return true;
		}
		else
		{
			return false;
		}
	}

	Node* BinaryToDoubleList()
	{
		return _BinaryToDoubleList(_root);
	}

	Node* _BinaryToDoubleList(Node* root)
	{
		//1.找到双向链表的头；
		Node* head = root;
		while(head->_left != nullptr)
		{
			head = head->_left;
		}

		Node* prev = nullptr;
		_Change(root,prev);    //转换函数

		return head;
	}

	void _Change(Node* cur,Node*& prev)
	{
		if (cur == nullptr)
			return;
		//1.找到最左边
		_Change(cur->_left,prev);
		cur->_left = prev;  //此时prev为空

		if (prev != nullptr)
			prev->_right = cur;

		prev = cur;

		_Change(cur->_right, prev);
	}

	//中序遍历
	void InOrder(SBTNode<K, V>* root)
	{
		if (root == nullptr)
		{
			return; //递归结束出口
		}

		SBTNode<K, V> *cur = root;
		InOrder(cur->_left);
		cout << cur->key << " ";
		InOrder(cur->_right);
	}

	//顺序遍历双向链表
	void TreaveList()
	{
		Node* cur = BinaryToDoubleList();
		while (cur)
		{
			cout << cur->key<< " ";
			cur = cur->_right;
		}
		cout << endl;
	}

public:
	SBTNode<K, V> *_root;
};