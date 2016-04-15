# DoubeListCpp
双向链表的c++实现
#include "DoubleList.h"

ostream& operator<<(ostream& os, DouList& l)
{
	Node* cur = l._head;
	while (cur)
	{
		os << cur->_data << "<=>";
		cur = cur->_next;
	}
	cout << "over";
	return os;
}

void DouList::PushBack(const DataType& d)
{
	Node* newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}
}

void DouList::PopBack()
{
	if (_head == NULL)
	{
		return;
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
		return;
	}
	Node* del = _tail;
	_tail = _tail->_prev;
	_tail->_next = NULL;
	delete del;
}

void DouList::PushFront(const DataType& d)
{
	Node* newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		newNode->_next = _head;
		_head->_prev = newNode;
		_head = newNode;
	}

}

void DouList::PopFront()
{
	if (_head == NULL)
	{
		return;
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
		return;
	}
	Node* del = _head;
	_head = _head->_next;
	_head->_prev = NULL;
	delete del;
}

Node* DouList::Find(const DataType& d)
{
	Node* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void DouList::Insert(Node* pos, const DataType& d)
{
	if (pos == NULL)
	{
		return;
	}
	Node* newNode = new Node(d);
	if (pos != _tail)//非尾节点插入
	{
		newNode->_next = pos->_next;
		newNode->_prev = pos;
		pos->_next = newNode;
	}
	else//尾节点插入
	{
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}
}

void DouList::BubbSort()
{
	Node* cur = _head;
	Node* end = NULL;
	bool flag = true;
	while (cur->_next != end && flag)
	{
		flag = false;
		while (cur->_next != end && cur)
		{
			if (cur->_data > cur->_next->_data)
			{
				flag = true;
				swap(cur->_data, cur->_next->_data);
			}
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}

void DouList::Reverse()
{
	Node* cur = _head;
	Node* newHead = NULL;
	Node* tmp = NULL;
	while (cur)
	{
		tmp = cur->_next;
		cur->_next = newHead;
		if (newHead)
		{
			newHead->_prev = cur;
		}
		newHead = cur;
		newHead->_prev = NULL;
		cur = tmp;
	}
	swap(_head, _tail);
}

void DouList::Remove(const DataType& d)
{
	if (_head == NULL)//无节点
	{
		return;
	}
	Node* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			if (cur == _head)//第一个相等
			{
				PopFront();
				return;
			}
			else if (cur == _tail&& _head != _tail)//最后一个节点相等
			{
				PopBack();
				return;
			}
			else//其他节点
			{
				cur->_prev->_next = cur->_next;
				cur->_next->_prev = cur->_prev;
				delete cur;
				return;
			}
		}
		cur = cur->_next;
	}
}

void DouList::RemoveAll(const DataType& d)
{
	Node* cur = _head;
	//bool flag = true;
	while (cur)
	{
		//flag = true;
		Node* tmp=cur->_next;
		if (cur->_data == d)
		{
			//flag = false;
			cur = cur->_next;
			Remove(d);
		}
		cur = tmp;
	}
}

void DouList::Erase(Node* pos)
{
	if (pos == NULL)//
	{
		return;
	}
	if (pos == _head)//删除第一个节点
	{
		PopFront();
		return;
	}
	if (pos == _tail)//删除最后一个节点
	{
		PopBack();
		return;
	}
	//非尾节点的删除
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	delete pos;
}
