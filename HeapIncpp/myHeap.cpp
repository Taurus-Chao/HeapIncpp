#include"myHeap.h"
#include<iostream>

#define PARENT(x) (((x)-1)/2)
#define LEFTCHILD(x) (2*(x)+1)

int myHeap::size()
{
	return elements.size();
}

bool myHeap::isempty()
{
	if (elements.size() == 0)return true;
	else return false;
}

int myHeap::top()
{
	return elements[0];
}

void myHeap::print()
{
	for (auto it : elements)cout << it << '\t';
}

void myHeap::insert(int k)
{
	elements.push_back(k);
	percelocateUp(elements.size()-1);
}

void myHeap::percelocateUp(int index)//���˲���
{
	int val = elements[index];
	int parentindx = PARENT(index);
	while (index != 0)
	{
		if (elements[parentindx] > val)
		{
			elements[index] = elements[parentindx];
			index = parentindx;
			parentindx = PARENT(index);
		}
		else break;
	}
	elements[index] = val;
}

int myHeap::deleteMin()
{
	int min = elements[0];
	elements[0] = elements.back();
	elements.pop_back();
	percelocateDown(0);
	return min;
}
void myHeap::percelocateDown(int index)//���˲���
{
	int val = elements[index];
	int child = LEFTCHILD(index);
	while (child <= elements.size()-1)
	{
		if (child != elements.size() - 1&&elements[child] > elements[child + 1])
			child++;
		if (elements[child] < val)
		{
			elements[index] = elements[child];
			index = child;
			child = LEFTCHILD(child);
		}
		else break;
	}
	elements[index] = val;
}
void myHeap::bulidHeap(int *array, int len)//����һ�����齨����
{
	for (int i = 0; i < len; i++)
	{
		elements.push_back(array[i]);
	}
	for (int i = PARENT(len - 1); i >= 0; i--)
	{
		percelocateDown(i);
	}
}

void myHeap::decreaseKey(int index, int decreasement)//�ڸ���λ��index��Ԫ�ش���������ֵ�������ѽṹ���Ե����ڵ�����
{
	if (index >= elements.size())
	{
		cout << "outofrange!";
		return;
	}
	elements[index] -= decreasement;
	percelocateUp(index);
}
void myHeap::increaseKey(int index, int increasement)//��������ֵ
{
	if (index >= elements.size())
	{
		cout << "outofrange!";
		return;
	}
	elements[index] -= increasement;
	percelocateDown(index);
}