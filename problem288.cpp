#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int a=61,b=1,c=290797,result=0;
	for(long int i=1;i<=10000000;i++)
	{
		c=(c*c)%50515093;
		long long int n=(c%61)*b;
		if(i<10)
		{
			b+=a;
			a*=61;
			result+=n;
		}
		else{result=(result+n)%a;}
	}
	cout<<result;
	getchar();
	return 0;
}
