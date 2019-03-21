/*
�������ݵ�topk����Ļ�������������̫�󲻿��Զ������ڴ�����Կ�����hash(x) % 1024 �����ֵ���ͬ���ļ�
Ȼ�����ڲ�ͬ���ļ��������1000000����ǰ10000������С�ѣ�Ȼ���ʣ�µıȶѶ�С��ֱ�ӹ��˵����ȶѶ�����滻�������ҽ��е���
�����ÿ���ļ����ļ������ټ�����һ�𣨷��ε�˼�룩 

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
