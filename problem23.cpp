#include <bits/stdc++.h>
int main()
{
	int sum[28123];
	bool can_be_written[28123];
	long int result=0;
	for(int i=1;i<=28123;i++)
	{
		sum[i-1]=1;
		can_be_written[i-1]=false;
		for(int x=i,j=2;x!=1;j++)
		{
			int u=j;
			for(;x%j==0;u*=j,x/=j){}
			sum[i-1]*=(u-1)/(j-1);			
		}
		sum[i-1]-=i;
	}
	for(int i=1;i<=28123;i++)
	{
		for(int j=i;i+j<=28123;j++)
		{
			if(sum[i-1]>i && sum[j-1]>j){can_be_written[i+j-1]=true;}
		}
	}
	for(int i=1;i<=28123;i++)
	{
		if(!can_be_written[i-1]){result+=i;}
	}
	std::cout<<result;
	getchar();
	return 0;
}
