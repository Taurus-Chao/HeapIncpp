//��dequeʵ�����ȶ���.deque֧���±������֧��push��pop���������ȿɱ䡣
#ifndef MYHEAP_H
#define MYHEAP_H
#include<deque>
using namespace std;

class myHeap{
public:
	myHeap() = default;

	int size();
	bool isempty();
	int top();//������Сֵ
	void print();
	void insert(int x);
	int deleteMin();
	void bulidHeap(int *array,int len);//����һ�����齨����
	void decreaseKey(int index, int decreasement);//�ڸ���λ��index��Ԫ�ش���������ֵ�������ѽṹ
	void increaseKey(int index, int increasement);//��������ֵ
private:
	void percelocateUp(int index);//���˲���
	void percelocateDown(int index);//���˲���
private:
	deque<int> elements;
};

#endif