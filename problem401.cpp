#include <bits/stdc++.h>
#define limit 1000000000000000
#define mod 1000000000
using namespace std;
int main()
{
	long long int result=0;
	for(long int i=1;i<=trunc(sqrt(limit));i++)
	{
		long long int x=limit/i,a=x,b=x+1,c=2*x+1,n;
		if(a%2==0){a/=2;}
		if(a%3==0){a/=3;}
		if(b%2==0){b/=2;}
		if(b%3==0){b/=3;}
		if(c%3==0){c/=3;}
		a%=mod;
		b%=mod;
		c%=mod;
		n=(a*b)%mod;
		n=(n*c)%mod;
		result=(result+n)%mod;
		if(i!=x)
		{
			n=(x*i)%mod;
			n=(n*i)%mod;
			result=(result+n)%mod;
		}
		if(i==trunc(sqrt(limit)))
		{
			x=limit/(i+1),a=x,b=x+1,c=2*x+1;
			if(a%2==0){a/=2;}
			if(a%3==0){a/=3;}
			if(b%2==0){b/=2;}
			if(b%3==0){b/=3;}
			if(c%3==0){c/=3;}
			a%=mod;
			b%=mod;
			c%=mod;
			n=(a*b)%mod;
			n=(n*c)%mod;
			n=(n*i)%mod;
			result=(result-n)%mod;		
		}
	}
	
	cout<<result;
	getchar();
	return 0;
}
