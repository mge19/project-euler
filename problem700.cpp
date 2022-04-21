#include <bits/stdc++.h>
#define c 4503599627370517
#define euler 1504170715041707
using namespace std;
long long int inv(long long int a,long long int m)
{
    long long int m0=m,t,q,x0=0,x1=1; 
    while(a>1) 
    {  
        q=a/m; 
        t=m; 
        m=a%m,a=t; 
        t=x0; 
        x0=x1-q*x0; 
    	x1=t; 
    }
    if(x1<0){x1+=m0;}
    return x1;
}
int main()
{
	long long int n=inv(euler,c),m=n,k=n,result=euler+1,s=euler;
	for(long long int x=2;k>=100000000;x++)
	{
		k=(k+n)%c;
		if(k<m)
		{
			m=k;
			result+=x;
		}
	}
	m=euler;
	for(long long int i=2;i<k;i++)
	{
		s=(s+euler)%c;
		if(s<m)
		{
			m=s;
			result+=m;
		}
	}
	cout<<result;
	getchar();
	return 0;
}
