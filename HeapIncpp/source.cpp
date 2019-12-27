#include<iostream>
#include"heapFun.h"
using namespace std;

int main()
{
	//int a[10] = {2,5,4,6,35,28,87,45,26,12};
	//cout << findKthLargest(a, 10, 5);

	//string s = "My name is CHAO His name is LEE We all have name";
	//topKFrequent(s, 3);

	//cout << findKthUglyNumber(6);

	//int num1[] = { 1, 3, 11 };
	//int num2[] = { 2, 4, 6 };
	//pair<int, int> res[30];
	//kSmallestPairs(num1, 3, num2, 3, res, 30);
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << res[i].first << ',' << res[i].second << endl;
	//}

	//list<int >l1= {1, 3, 4, 5};
	//list<int>l2 = { 6, 7, 8, 9 };
	//list<int>l3 = { 2, 4, 12 };
	//vector<list<int>>lists{ l1, l2, l3 };
	//list<int>res;
	//mergeLists(lists, res);
	//for (auto t : res)cout << t << '\t';

	//MedianFinder mf;
	//mf.addNum(2);
	//mf.addNum(336);
	//mf.addNum(421);
	//mf.addNum(52);
	//cout << mf.findMedian();

	int k = 3;
	int W = 2;
	int p[] = { 1, 2, 3,5 };
	int c[] = { 0, 1, 1,3 };
	cout << findMaximizedCapital(c, p, 4, W, k);

	system("pause");
}