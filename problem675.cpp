#include <bits/stdc++.h>
#define c 1000000087
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
class Number{
	public:
		long long int a=1,b=1;
};
int main()
{
	vector<Number> v(10000000);
	long long int result=0,d=1;
	for(long int i=2;i<=10000000;i++)
	{
		if(v[i-1].b==1)
		{
			long int x=1;
			for(long int j=i;j<=10000000;j+=i)
			{
				v[j-1].b=(v[j-1].b*x)%c;
				long int k=j;
				while(k%i==0)
				{
					k/=i;
					x+=2;
				}	
				v[j-1].a=(v[j-1].a*x)%c;
			}
		}
		d=(d*v[i-1].a)%c;
		d=(d*inv(v[i-1].b,c))%c;
		result=(result+d)%c;
	}
	cout<<result;
	getchar();
	return 0;
}
