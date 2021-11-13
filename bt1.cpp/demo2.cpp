#include <iostream>
using namespace std;
template <class temp , class temp1>
void sum(temp inttemp , temp1 doubletemp) 
{
	cout<<inttemp+doubletemp;
}

int main()
{
	int inttemp = 1;
	double doubletemp = 1.1;
	sum(inttemp , doubletemp);
	cout<<endl;
    system("pause");
 return 0;
 }