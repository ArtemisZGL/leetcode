#include <iostream>
#include <string.h>
#include <memory>
#include "test.h" 
using namespace std;

void fun1()
{
	cout << g_str << endl;
}
int main()
{
	fun1();
	int a;
	cin >> a;
}