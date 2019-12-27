#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<functional>
#include<unordered_map>
#include"heapFun.h"
using namespace std;

int findKthLargest(int* array, int len, int k)//找到数组中的K大的元素，O(Nlogk)
{
	priority_queue<int,deque<int>,greater<int>>q(array, array + k);
	for (int i = k; i <= len - 1; i++)
	{
		if (array[i] > q.top())
		{
			q.pop();
			q.push(array[i]);
		}
	}
	return q.top();
}

////////////////////////////////////////////打印出句子中前k大词频的单词
//需要借助自定义对象来代表单词和词频
class Element{
public:
	Element(string s, int k) :str(s), num(k){}
	bool operator<(const Element e)const
	{
		return num < e.num;
	}
	bool operator>(const Element e)const//重载运算符用于优先队列priority_queue的使用
	{
		return num > e.num;
	}
	int count()
	{
		return num;
	}
	string getword()
	{
		return str;
	}
private:
	string str;
	int num;
};
void topKFrequent(string str, int k)//打印出句子中前k大词频的单词
{
	vector<string>words;
	string tmp = "";
	for (int i = 0; i < str.size(); i++)//划分单词
	{
		if (str[i] == ' ')
		{
			words.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp += str[i];
	}
	words.push_back(tmp);

	unordered_map<string, int>m;//统计单词
	for (auto t : words)
		m[t]++;

	priority_queue<Element, deque<Element>, greater<Element>>q;//放到heap中找前k个最大的词频对应的单词
	auto iter = m.begin();
	for (int i = 0; i < k; i++)
	{
		q.emplace(iter->first, iter->second);
		iter++;
	}
	for (; iter !=m.end(); iter++)
	{
		if (iter->second > q.top().count())
		{
			q.pop();
			q.emplace(iter->first, iter->second);
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << q.top().getword() << ":" << q.top().count() << endl;
		q.pop();
	}
}

///////////////////////////////
bool isUglyNumber(int k)//判断是否为丑数（因数只有2、3、5的数）
{
	if (k == 0||k==1)return false;
	while (1)
	{
		if (k == 1)return true;
		if (!(k % 2))
		{
			k /= 2; continue;
		}
		if (!(k % 3))
		{
			k /= 3; continue;
		}
		if (!(k % 5))
		{
			k /= 5; continue;
		}
		return false;
	}
}
int findKthUglyNumber(int k)//找到自然数域第K大的丑数
{
	priority_queue<int, deque<int>, greater<int>>q;
	q.push(2); q.push(3); q.push(5);
	int u = 1;
	int i = 0;
	while (i != k)
	{
		if (u == q.top())
		{
			q.pop();
			continue;
		}
		u = q.top();
		q.pop();
		q.push(u * 2);
		q.push(u * 3);
		q.push(u * 5);
		i++;
	}
	return u;
}

////////////////////////////在两个数组中找到前k个最小的组合，保存到res数组中
class Numpair//需借助自定义的对象来使用堆保存pair的下标与对应值的和
{
public:
	Numpair(int index1, int index2, int s) :i(index1), j(index2), sum(s){}
	int geti(){ return i; }
	int getj(){ return j; }
	int getsum(){ return sum; }
	bool operator>(Numpair e)const
	{
		return sum > e.sum;
	}
private:
	int i;
	int j;
	int sum;
};
void kSmallestPairs(int *num1, int len1, int *num2, int len2, pair<int, int>* res,int k)//在两个数组中找到前k个最小的组合，保存到res数组中
{
	priority_queue<Numpair, deque<Numpair>, greater<Numpair>>q;
	int i = 0, j = 0, sum = num1[0] + num2[0];
	q.emplace(i,j,sum);
	for (int count = 0; count < k&&q.size()>0; count++)
	{
		Numpair eletmp = q.top();
		q.pop();
		i = eletmp.geti();
		j = eletmp.getj();
		*(res + count) = make_pair(num1[i], num2[j]);
		if (j == 0 && (i+1)<len1)
			q.emplace(i + 1,0, num1[i+1] + num2[0]);
		if ((j+1)<len2)
			q.emplace(i, j+1, num1[i] + num2[j+1]);
	}
}

/////////////////////////////合并k个已排序链表，复杂度O(Nlogk）
class Lnode//需借助自定义的对象来使用堆保存链表元素的迭代器与对应的元素值
{
public:
	Lnode(list<int>::iterator i, int v,int n): it(i), val(v),num(n){}
	list<int>::iterator  getit(){ return it; }
	int getval(){ return val; }
	int getnum(){ return num; }
	bool operator>(Lnode n)const
	{
		return val > n.val;
	}
private:
	list<int>::iterator it;
	int val;
	int num;//用来存放链表的序号，判断是否到end（）
};

void mergeLists(vector<list<int>> &lists, list<int> &res)//合并k个已排序链表，复杂度O(Nlogk）
{
	int k = lists.size();
	priority_queue<Lnode, deque<Lnode>, greater<Lnode>>q;
	for (int i = 0; i < k; i++)
	{
		q.emplace(lists[i].begin(),lists[i].front(),i);
	}
	while (!q.empty())
	{
		auto iter = q.top().getit();
		int num = q.top().getnum();
		q.pop();
		res.push_back(*iter);
		if (++iter!=lists[num].end())
			q.emplace(iter, *iter, num); 
	}
}

/////////////////////////支持从数据流插入数据（addNum）并获得中位数（findMedian）的自定义数据结构
void MedianFinder::addNum(int k)
{
	if (max.empty())
	{
		max.push(k);
		return;
	}
	if (min.empty())
	{
		if (k >= max.top())min.push(k);
		else
		{
			min.push(max.top());
			max.pop();
			max.push(k);
		}
		return;
	}
	int small = max.top();
	int big = min.top();
	if (k <= big)
	{
		max.push(k);
		if (max.size() > min.size() + 1)
		{
			min.push(max.top());
			max.pop();
		}
	}
	else
	{
		min.push(k);
		if (max.size() < min.size() )
		{
			max.push(min.top());
			min.pop();
		}
	}
}
double MedianFinder::findMedian()
{
	if (max.size() == min.size())return (max.top() + min.top()) / 2.0;
	else return max.top();
}

/////////根据项目需求资金capital、项目利润profit、启动资金W、和最多完成的项目数量k来求得所能获得的最大利润。每完成一个项目可在启动资金基础上增加利润值

class Project{  //自定义类型，每一个对象代表一个项目，包含需求资金和项目利润。
public:
	Project(int cap, int pro) :capital(cap), profit(pro){}
	int getcap(){ return capital; }
	int getpro(){ return profit; }
	bool operator<(Project p)const//这里重载的运算符用于堆的构造
	{
		return profit < p.profit;
	}
	bool operator>(Project p) const
	{
		return profit > p.profit;
	}
private:
	int capital;
	int profit;
};

bool mycmp(Project &p1, Project &p2)//用于vector的排序
{
	return p1.getcap() < p2.getcap();
}

int findMaximizedCapital(int* capitals, int* profits,int len, int W, int k)
{
	vector<Project>v;
	for (int i = 0; i < len; i++)
	{
		v.emplace_back(capitals[i], profits[i]);
	}
	sort(v.begin(), v.end(),mycmp);
	/*int profitsum = 0;*/
	int num = len;
	priority_queue < Project > q;
	while (k != 0 )
	{
		vector<Project>tmp;
		int i = 0;
		for (; i < num; i++)
		{
			if (v[i].getcap() > W)break;
			else
			{
				q.push(v[i]);
			}
		}
		if (q.empty())break;//如果没有可进行的项目，则停止循环。
		tmp.assign(v.begin() + i, v.end());
		tmp.swap(v);//将已经进入堆的项目从v中排除掉
		W += q.top().getpro();
		q.pop();
		k--; num=num-q.size()-1;

	}
	return W;
}