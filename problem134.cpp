#include <bits/stdc++.h>
using namespace std;
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
int main()
{
	vector<long int> asallar;
	asallar.push_back(2);
	asallar.push_back(3);
	long long int result=0;
	for(long int i=6;;i+=6)
	{
		long int a=i-1,b=i+1,j=0;
		for(;a%asallar[j]!=0 && asallar[j]<=floor(sqrt(a));j++){}
		if(asallar[j]>floor(sqrt(a)))
		{
			asallar.push_back(a);
			if(a>1000000){break;}
		}
		j=0;
		for(;b%asallar[j]!=0 && asallar[j]<=floor(sqrt(b));j++){}
		if(asallar[j]>floor(sqrt(b)))
		{
			asallar.push_back(b);
			if(b>1000000){break;}
		}
	}
	long int m=10;
	for(long int i=2;i<asallar.size()-1;i++)
	{
		if(asallar[i]>m){m*=10;}
		long long int y=(inv(m%asallar[i+1],asallar[i+1])*(asallar[i+1]-asallar[i]))%asallar[i+1];
		result+=y*m+asallar[i];
	}
	cout<<result;
	getchar();
	return 0;
}
