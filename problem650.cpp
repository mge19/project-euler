#include <bits/stdc++.h>
#define c 1000000007
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
	vector<bool> asallar(20000,true);
	vector<long int> numbers(20000,1);
	long int result=1;
	for(int i=2;i<=20000;i++)
	{
		if(asallar[i-1])
		{
			int factors=0;
			long int a=0;
			for(int j=i;j<=20000;j++)
			{
				if(j%i==0)
				{
					if(j>i){asallar[j-1]=false;}
					int x=j;
					while(x%i==0)
					{
						x/=i;
						factors++;
					}
				}
				long int k=factors*(j-1)+1-a;
				long long int x=1,z=i;
				a+=2*factors;
				while(k>0)
				{
					if(k%2==1){x=(x*z)%c;}
					z=(z*z)%c;
					k/=2;
				}
				x-=1;
				if(x%(i-1)==0){x/=(i-1);}
				else{x=(x*inv(i-1,c))%c;}
				numbers[j-1]=(numbers[j-1]*x)%c;
			}
		}
		result=(result+numbers[i-1])%c;
	}
	cout<<result;
	getchar();
	return 0;
}
