#include <bits/stdc++.h>
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
	long long int result=0;
	vector<bool> asal(100000000,true);
	for(long int i=2;i<=100000000;i++)
	{
		if(asal[i-1])
		{
			for(long int j=2*i;j<=100000000;j+=i){asal[j-1]=false;}
			if(i>=5)
			{
				long int temp=0,x=1;
				for(int j=2;j<=4;j++)
				{
					x=(x*inv(i-j,i))%i;
					temp=(temp+x)%i;
				}
				result+=temp;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
