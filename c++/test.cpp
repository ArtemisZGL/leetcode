#include <iostream>
#include <string.h>
#include <memory>
#include "test.h" 
using namespace std;
char g_str[] = "123456";
void fun1()
{
    cout << g_str << endl;
}
int main()
{
	fun1();
}
