#include <bits/stdc++.h>
int main()
{
	int coins[7]={2,5,10,20,50,100,200};
	long int sums[201];
	for(int i=0;i<=200;sums[i]=1,i++){}
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<coins[i];j++)
		{
			for(int k=j+coins[i];k<=200;sums[k]+=sums[k-coins[i]],k+=coins[i]){}
		}
	}
	std::cout<<sums[200];
	getchar();
	return 0;
}
