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
	long int result_a,result_b;
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
				result_a=a;
				result_b=b;
			}
		}
	}
	cout<<result_a<<"*"<<result_b<<"="<<result_a*result_b<<"\n"<<max-1<<" consecutive primes:";
	for(int i=1;i<max;i++){cout<<i*i+result_a*i+result_b<<" ";}
	getchar();
	return 0;
}
