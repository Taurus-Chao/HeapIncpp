#ifndef HEAPFUN_H
#define HEAPFUN_H

#include<string>
#include<vector>
#include<list>
#include<queue>
#include<functional>
using namespace std;

int findKthLargest(int* array,int len,int k);//�ҵ������е�K���Ԫ�أ�O(Nlogk)
void topKFrequent(string str, int k);//��ӡ��������ǰk���Ƶ�ĵ���
bool isUglyNumber(int k);//�ж��Ƿ�Ϊ����������ֻ��2��3��5������
int findKthUglyNumber(int k);//�ҵ���Ȼ�����K��ĳ���
void kSmallestPairs(int *num1, int len1, int *num2, int len2, pair<int, int>* res,int k);//�������������������ҵ�ǰk����С����ϣ����浽res������
void mergeLists(vector<list<int>> &lists, list<int> &res);//�ϲ�k���������������Ӷ�O(Nlogk��

//////////֧�ִ��������������ݣ�addNum���������λ����findMedian�����Զ������ݽṹ
class MedianFinder{
public:
	void addNum(int k);
	double findMedian();
private:
	priority_queue<int,deque<int>,greater<int>>min;//С�˶ѣ����ڴ�Žϴ�һ�������
	priority_queue<int>max;//��˶ѣ���Ž�С��һ������ݡ��涨max�ĳ��Ȳ�С��min�ĳ��ȣ��Ҳ�����min���ȼ�һ��
};

int findMaximizedCapital(int* capitals, int* profits,int len, int W, int k);//������Ŀ�����ʽ�capital����Ŀ����profit��������Ŀ��Ŀlen�������ʽ�W���������ɵ���Ŀ����k��������ܻ�õ��������
//ÿ���һ����Ŀ���������ʽ��������������ֵ

#endif