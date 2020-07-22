#include <bits/stdc++.h>
using namespace std;
int gcd(long int a,long int b)
{
	if(b==0){return a;}
	return gcd(b,a%b);
}
long int inv(long int a,long int m)
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
long long int chinese_leftover(long long int a,long long int n,long long int b,long long int m)
{
	long long int x=a,y=b;
	x=(x*inv(m,n))%(m*n);
	x=(x*m)%(m*n);
	y=(y*inv(n,m))%(m*n);
	y=(y*n)%(m*n);
	return (x+y)%(m*n);
}
int main()
{
	long long int sum=0;
	vector<long int> toitient(1004999,1);
	for(long int i=2;i<1005000;i++)
	{
		if(toitient[i-1]==1)
		{
			toitient[i-1]=i-1;
			for(long int j=2*i;j<1005000;toitient[j-1]*=i-1,j+=i){}	
		}                   		
	}
	for(long int i=2;i*i<1005000;i++)
	{
		if(toitient[i-1]==i-1)
		{
			for(long int j=i*i;j<1005000;toitient[j-1]=i*toitient[j/i-1],j+=i*i){}
		}
	}	
	for(long int i=1000000;i<1005000;i++)
	{
		for(long int j=i+1;j<1005000;j++)
		{
			if(gcd(i,j)==1){sum+=chinese_leftover(toitient[i-1],i,toitient[j-1],j);}
			else
			{
				int x=gcd(i,j);
				if((toitient[i-1]%x)==(toitient[j-1]%x))
				{
					int y=(toitient[i-1]%x==0)?0:x-(toitient[j-1]%x);
					sum+=x*chinese_leftover((toitient[i-1]+y)/x,i/x,(toitient[j-1]+y)/x,j/x)-y;
				}
			}	
		}
	}
	cout<<sum;
	getchar();
	return 0;	
}
