#include <bits/stdc++.h>
using namespace std;
int main()
{
	long double r=1.0;
	for(long double n=10;n<=1e+13;n*=10)
	{
		for(long double i=1;i<=9;i++)
		{
			r+=1/n;
			long double x=(pow(r,5000)*(4700*r-4701)+300*r-299)/pow((r-1),2);
			if(x>2e+11)
			{
				r-=1/n;
				break;
			}
		}
	}
	cout<<setprecision(13)<<r;
	getchar();
	return 0;
}
