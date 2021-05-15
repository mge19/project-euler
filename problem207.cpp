#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int a=1,b=3,x=4;
	for(;b<=12345*a;b++)
	{
		if(b==x)
		{
			a++;
			x*=2;
		}
	}
	cout<<b*b+b;
	getchar();
	return 0;
}
