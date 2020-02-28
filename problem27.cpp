#include <bits/stdc++.h>
#include <cmath>
using namespace std;
bool asal(long int number)
{
	int x=round(sqrt(number));
	for(int i=2;i<=x;i++)
	{
		if(number%i==0){return false;}
	}
	return true;
}
int main()
{
	long int result;
	int max=0;
	for(int b=-999;b<=999;b+=2)
	{
		for(int a=-2*round(sqrt(abs(b)))+1;a<2*round(sqrt(abs(b)));a+=2)
		{
			int n=1;
			for(;n*n+a*n+b>1 && asal(n*n+a*n+b);n++){}
			if(n>max)
			{
				max=n;
				result=a*b;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
