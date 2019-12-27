//用deque实现优先队列.deque支持下标操作且支持push和pop操作，长度可变。
#ifndef MYHEAP_H
#define MYHEAP_H
#include<deque>
using namespace std;

class myHeap{
public:
	myHeap() = default;

	int size();
	bool isempty();
	int top();//返回最小值
	void print();
	void insert(int x);
	int deleteMin();
	void bulidHeap(int *array,int len);//根据一个数组建立堆
	void decreaseKey(int index, int decreasement);//在给定位置index的元素处降低优先值，调整堆结构
	void increaseKey(int index, int increasement);//提升优先值
private:
	void percelocateUp(int index);//上滤操作
	void percelocateDown(int index);//下滤操作
private:
	deque<int> elements;
};

#endif