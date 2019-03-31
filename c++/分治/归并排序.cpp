#include <iostream>
using namespace std;
/*
�Զ����£������� 
�ȷ��Σ�һֱ�ֳɺ�С��С�� 
Ȼ����й飬��������������������� 

*/
void merge(int* array, int begin, int med, int end)
{
	int bidx = begin, eidx = med + 1, sortidx = 0;
	int* temp = new int[end - begin + 1];
	while(bidx <= med && eidx <= end)
	{
		if(array[bidx] < array[eidx])
		{
			temp[sortidx++] = array[bidx++];
		}
		else
		{
			temp[sortidx++] = array[eidx++];
		}  
	}
	while(bidx <= med)
		temp[sortidx++] = array[bidx++];
	while(eidx <= end)
		temp[sortidx++] = array[eidx++];
	
	for(int i = begin; i <= end; i++)
		array[i] = temp[i-begin];
}

void mergeSort(int* array, int begin, int end)
{
	if(begin < end)
	{
		int med = begin + (end - begin) / 2;
		mergeSort(array, begin, med);
		mergeSort(array, med + 1, end);
		merge(array, begin, med, end);
	}
 } 
int main()
{
	int a[10] = {1, 3, -2, 5, 2, 9, 6, 0, 88, -11};
	mergeSort(a, 0, 9);
	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";
 } 
