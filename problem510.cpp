#include <bits/stdc++.h>
using namespace std;
long int gcd(long int a,long int b)
{
	if(b==0){return a;}
	return gcd(b,a%b);
}
int main()
{
	long long int result=0;
	long int x=1000000000;
	for(long long int i=1;i*i<x;i++)
	{
		for(long long int j=i;j*j*(i+j)*(i+j)<x;j++)
		{
			if(gcd(j,i)==1 || i==1)
			{
				long long int k=i*i,l=j*j,m=(i+j)*(i+j),n=x/(l*m);
				result+=n*(n+1)*((k+l)*m+k*l)/2;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
