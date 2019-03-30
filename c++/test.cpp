#include <iostream>
#include <string.h>
#include <memory>
#include "test.h" 
using namespace std;

class Base
{
	public:
		void f(int i)
		{
			cout << "int" << endl;
		}
		void f(char c)
		{
			cout << "char" << endl;
		}
		void f(string s)
		{
			cout << "string" << endl;
		}
	private:
		int i;
 };
 
 class Chil:public Base
 {
 	public:
 		void f(double d)
 		{
 			cout << "double" << endl;
		 }
  } ;
  
  int main()
  {
  	Chil c = Chil();
  	c.f("aa");
  }
