# DoubeListCpp
双向链表的c++实现
#include"DoubleList.h"
void test1()
{
	DouList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(5);
	l1.PushFront(6);
	cout << l1 << endl;
	l1.PopFront();
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	l1.PopFront();
	cout << l1 << endl;
}
void test2()
{
	DouList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	cout << l1 << endl;
	l1.Insert(l1.Find(1), 7);
	l1.Insert(l1.Find(2), 8);
	l1.Insert(l1.Find(3), 9);
	l1.Insert(l1.Find(4), 10);
	l1.Insert(l1.Find(7), 0);
	l1.BubbSort();
	cout << l1 << endl;
	l1.Reverse();
	cout << l1 << endl;

}
void test3()
{
	DouList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	cout << l1 << endl;
	l1.RemoveAll(3);
	cout << l1 << endl;
	l1.RemoveAll(2);
	cout << l1 << endl;
	l1.RemoveAll(1);
	/*l1.Erase(l1.Find(4));*/
	cout << l1 << endl;
	l1.RemoveAll(4);
	cout << l1 << endl;
	/*l1.Reverse();
	cout << l1 << endl;*/
}
void test4()
{
	DouList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	cout << l1 << endl;
	DouList l2(l1);
	cout << l2 << endl;
	DouList l3;
	l3 = l2;
	cout << l3 << endl;
	/*l1.Erase(l1.Find(3));*/
}
int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	getchar();
	return 0;
}
