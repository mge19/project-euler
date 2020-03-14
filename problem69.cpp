#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> relprime(1000000,1);
	vector<bool> asal(1000,true);
	double max=0;
	long int result;
	for(long int i=2;i<=1000000;i++)
	{
		if(relprime[i-1]==1)
		{
			relprime[i-1]=i-1;
			for(long int j=2*i;j<=1000000;relprime[j-1]*=i-1,j+=i)
			{
				if(j<=1000){asal[j-1]=false;}
			}	
		}                   		
	}
	for(int i=2;i<=1000000;i++)
	{
		if(i<1000 && asal[i-1])
		{
			for(long int j=i*i;j<=1000000;relprime[j-1]=i*relprime[j/i-1],j+=i*i){}
		}
		double cur=(double)i/(double)relprime[i-1];
		if(cur>max)
		{
			max=cur;
			result=i;
		}
	}
	cout<<result;		
	getchar();
	return 0;
}
