#include <iostream>
using namespace std;

//�������Ѿ���С��������

//����ʵ�� 
int binarySearch(int nums[], int key, int length)
{
	int begin = 0, end = length - 1;
	while(begin <= end)
	{   
		//����д����� 
		//int med = (begin + end) / 2;
		//����д�Ų������ 
		int med = begin + (end - begin) / 2;
		if(nums[med] == key)
			return med;
		else if(nums[med] > key)
			end = med - 1;
		else
			begin = med + 1;
		
	}
	return -1;	//����û���ҵ�
	//return begin; 	//���ڽ�key���뵽���ʵ�λ�� 
 } 
 
 //����1�����ظ����֣����������
  int dupLeftBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] >= key)
  			end = med -1;		//end���������keyֵС1��λ�� 
		else
			begin = med + 1;	//begin����end+1��λ�� 
	}
	
	if(begin < length && nums[begin] == key)	//begin���ܻ���������Ҵ�����ʱ�� 
		return begin;							//beginҲ���ܲ鵽�Ĳ���keyֵ 
	
	return -1;
  }
  
  //����2�����ظ����֣������ұ�
  int dupRightBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] <= key)
  			begin = med + 1;
  		else
  			end = med - 1;
	  }
	
	if(end >= 0 && nums[end] == key)
		return end;
	
	return -1;
   } 
   
   //����3�����ҵ�һ�����ڻ��ߴ���key��Ԫ��
   int firEquOrGreatBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[end] < key)		//������ұ��Ѿ���keyС��˵���϶��Ҳ�����Ҳ����������begin�������� 
	  return -1;
	   
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] >= key)
  			end = med - 1;
  		else
  			begin = med + 1;
	  }
	return begin;
   } 
   
   //���ҵ�һ������key��Ԫ��
    int firGreatBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[end] <= key)		//������ұ��Ѿ���keyС��˵���϶��Ҳ�����Ҳ����������begin�������� 
	  return -1;
	   
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] > key)
  			end = med - 1;
  		else
  			begin = med + 1;
	  }
	return begin;
   } 
   
   //�������һ�����ڻ���С��key��Ԫ��
    int firEquOrLessBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[begin] > key)		//���������Ѿ�����key 
	  return -1;
	   
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] <= key)
  			begin = med + 1;
  		else
  			end = med - 1;
	  }
	return end;
   } 
   
   //�������һ��С��key��Ԫ��
    int firLessBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[begin] >= key)		//���������Ѿ�����key 
	  return -1;
	   
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] < key)
  			begin = med + 1;
  		else
  			end = med - 1;
	  }
	return end;
   } 
   
int main()
{
	int num[] = {1,2,2,4,4,5};
	cout << firLessBS(num, 7, 6);
 } 
