#include <iostream>
using namespace std;
/*
自顶向下，在向上 
先分治，一直分成很小很小的 
然后进行归，归就是两个有序数组排序 

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
