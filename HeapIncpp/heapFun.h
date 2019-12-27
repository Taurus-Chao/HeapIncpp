#ifndef HEAPFUN_H
#define HEAPFUN_H

#include<string>
#include<vector>
#include<list>
#include<queue>
#include<functional>
using namespace std;

int findKthLargest(int* array,int len,int k);//找到数组中的K大的元素，O(Nlogk)
void topKFrequent(string str, int k);//打印出句子中前k大词频的单词
bool isUglyNumber(int k);//判断是否为丑数（因数只有2、3、5的数）
int findKthUglyNumber(int k);//找到自然数域第K大的丑数
void kSmallestPairs(int *num1, int len1, int *num2, int len2, pair<int, int>* res,int k);//在两个已排序数组中找到前k个最小的组合，保存到res数组中
void mergeLists(vector<list<int>> &lists, list<int> &res);//合并k个已排序链表，复杂度O(Nlogk）

//////////支持从数据流插入数据（addNum）并获得中位数（findMedian）的自定义数据结构
class MedianFinder{
public:
	void addNum(int k);
	double findMedian();
private:
	priority_queue<int,deque<int>,greater<int>>min;//小端堆，用于存放较大一半的数据
	priority_queue<int>max;//大端堆，存放较小的一半的数据。规定max的长度不小于min的长度，且不多于min长度加一。
};

int findMaximizedCapital(int* capitals, int* profits,int len, int W, int k);//根据项目需求资金capital、项目利润profit、所有项目数目len、启动资金W、和最多完成的项目数量k来求得所能获得的最大利润
//每完成一个项目可在启动资金基础上增加利润值

#endif