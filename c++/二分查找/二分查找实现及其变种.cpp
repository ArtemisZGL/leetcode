#include <iostream>
using namespace std;

//假设是已经从小到大排序

//基本实现 
int binarySearch(int nums[], int key, int length)
{
	int begin = 0, end = length - 1;
	while(begin <= end)
	{   
		//这样写会溢出 
		//int med = (begin + end) / 2;
		//这样写才不会溢出 
		int med = begin + (end - begin) / 2;
		if(nums[med] == key)
			return med;
		else if(nums[med] > key)
			end = med - 1;
		else
			begin = med + 1;
		
	}
	return -1;	//表明没有找到
	//return begin; 	//用于将key插入到合适的位置 
 } 
 
 //变种1，有重复数字，查找最左边
  int dupLeftBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	while(begin <= end)
  	{
  		int med = begin + (end - begin) / 2;
  		
  		if(nums[med] >= key)
  			end = med -1;		//end是在最左边key值小1的位置 
		else
			begin = med + 1;	//begin是在end+1的位置 
	}
	
	if(begin < length && nums[begin] == key)	//begin可能会溢出，查找大数的时候 
		return begin;							//begin也可能查到的不是key值 
	
	return -1;
  }
  
  //变种2，有重复数字，查最右边
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
   
   //变种3，查找第一个等于或者大于key的元素
   int firEquOrGreatBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[end] < key)		//如果最右边已经比key小，说明肯定找不到，也避免了下面begin溢出的情况 
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
   
   //查找第一个大于key的元素
    int firGreatBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[end] <= key)		//如果最右边已经比key小，说明肯定找不到，也避免了下面begin溢出的情况 
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
   
   //查找最后一个等于或者小于key的元素
    int firEquOrLessBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[begin] > key)		//如果最左边已经大于key 
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
   
   //查找最后一个小于key的元素
    int firLessBS(int nums[], int key, int length)
  {
  	int begin = 0, end = length - 1;
  	
  	if(nums[begin] >= key)		//如果最左边已经大于key 
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
