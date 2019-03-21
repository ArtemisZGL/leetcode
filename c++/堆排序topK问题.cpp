/*
海量数据的topk问题的话，由于数据量太大不可以都读进内存里，所以可以用hash(x) % 1024 来划分到不同的文件
然后再在不同的文件里假设有1000000个，前10000个用最小堆，然后把剩下的比堆顶小就直接过滤掉，比堆顶大就替换掉，并且进行调整
最后在每个文件里大的几个数再集合在一起（分治的思想） 

*/

#include<iostream>
using namespace std;

template<int N>
void PrintValues( int (&ia)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << ia[i] << " ";
    }
}

template<int N>
void headAdjust(int (&a)[N], int parent, int len)
{
	int temp = a[parent];
	int child = 2 * parent + 1;
	while(child < len)
	{
		if(child + 1 < len && a[child + 1] < a[child])
			child++;
		
		if(temp <= a[child])
			break;

		a[parent] = a[child];
		parent = child;
		child = 2 * parent + 1;
	}
	a[parent] = temp;
}

template<int N>
void initHeap(int (&a)[N])
{
	for(int i = N/2 - 1; i >= 0; i--)
	{
		headAdjust(a, i, N); 
	}
}



int main()
{
	int k = 3;
	int size = 7;
    int test[] = {16,7,3,20,17,8,21};
    initHeap(test);
    PrintValues(test);
    cout << endl;
    for(int i = size - 1; i > 0; i--)
    {
    	int temp = test[i];
    	test[i] = test[0];
    	test[0] = temp;
    	headAdjust(test, 0, i); 
	}
    PrintValues(test);
}
