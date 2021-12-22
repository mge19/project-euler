#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
	long long int a=1,b=1,result=1;
	for(int i=3;i<=90;i++)
	{
		long long int temp=a;
		a=b;
		b+=temp;
		int x=b%9;
		long long int n=(b-x)/9,m=1,u=10;
		while(n!=0)
		{
			if(n%2==1){m=(m*u)%mod;}
			u=(u*u)%mod;
			n/=2;
		}
		m=(m*((x+1)*(x+2)/2+5))%mod;
		m-=(b+6)%mod;
		if(m<0){m+=mod;}
		result=(result+m)%mod;
	}
	cout<<result;
	getchar();
	return 0;
}
