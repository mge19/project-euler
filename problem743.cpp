#include <bits/stdc++.h>
#define c 1000000007
#define size 100000000
using namespace std;
long long int inv(long int a,long int m)
{
    long int m0=m,t,q,x0=0,x1=1; 
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
	long long int s=1,a=1,z=2;
	long int result=0,r=2*size;
	vector<long long int> n;
	n.push_back(1);
	n.push_back(1);
	for(long int x=2;x<=size;x++)
	{
		s=(s*x)%c;
		long long int y=inv(x,c);
		n.push_back((n[x-1]*y)%c);
	}
	while(r>0)
	{
		if(r%2==1){a=(a*z)%c;}
		z=(z*z)%c;
		r/=2;
	}
	z=1;
	for(long int ones=0;ones<=size;ones+=2)
	{
		long long int u=(n[(size-ones)/2]*n[(size-ones)/2])%c;
		u=(u*n[ones])%c;
		if(ones>=2){z=(z*a)%c;}	
		u=(s*u)%c;
		u=(u*z)%c;
		result=(result+u)%c;
	}
	cout<<result;
	getchar();
	return 0;
}
