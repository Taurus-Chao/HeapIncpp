## The implementation of heap(priority-queue) in C++ on platform VS2013.

The project consists of:
1. myHeap.h and myHeap.cpp The definition and the implementation of heap including data members and the permitted operations on the data structure. Deque is used as the underlying container here. The operations contain:
* int size();
return the size of the structure.
* 	bool isempty();
return the heap is empty or not.
* 	int top();
return the top of the heap(minmum element).
* 	void print();
print all elements in order of layers.
* 	void insert(int x);
insert elements.
* 	int deleteMin();
delete elements.
* 	void bulidHeap(int *array,int len);
build a heap with an array.
* 	void decreaseKey(int index, int decreasement);
decrease the value of the key given the position of the element.
* 	void increaseKey(int index, int increasement);
increase the value of the key.

2. heapFun.h and heapFun.cpp includes some functions realized by the priority_queue, which is a kind of STL container defined in C++11.

* int findKthLargest(int* array,int len,int k);
find the Kth bigger elements in the array
* void topKFrequent(string str, int k);
print out the kth most frequent words int the sentence.
* bool isUglyNumber(int k);
judge a number is an ugly number or not.（the numbers whose facors are 2,3,5 only）
* int findKthUglyNumber(int k);
find the Kth biggest ugly number in the natural number field
* void kSmallestPairs(int \*num1, int len1, int \*num2, int len2, pair<int, int>\* res,int k);
find the first k smallest combinations in the two sorted arrays
* void mergeLists(vector<list<int>> &lists, list<int> &res);
merge k sorted linked lists
* class MedianFinder
a data structure that support inserting data (addNum) from the data stream and getting the median (findMedian)
* int findMaximizedCapital(int* capitals, int* profits,int len, int W, int k);
according to the project demand capital, project profit, the number of all projects len, start-up capital W, and the most completed projects k to obtain the maximum profit