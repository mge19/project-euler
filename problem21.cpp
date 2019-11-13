#include <bits/stdc++.h>
int main()
{
	int sum[9999],result=0;
	for(int i=1;i<10000;i++)
	{
		sum[i]=1;
		for(int x=i,j=2;x!=1;j++)
		{
			int u=j;
			for(;x%j==0;u*=j,x/=j){}
			sum[i]*=(u-1)/(j-1);			
		}
		sum[i]-=i;
	}
	for(int i=1;i<10000;i++)
	{
		if(i!=sum[i] && sum[sum[i]]==i){result+=i;}
	}
	std::cout<<result;
	getchar();
	return 0;
}
