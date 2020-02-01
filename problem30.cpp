#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int limit=9,sum=0;
	for(int n=1;limit<n*9*9*9*9*9;limit=10*limit+9,n++){}
	for(long int i=10;i<limit;i++)
	{
		long int number=i,result=0;
		while(number>0)
		{
			result+=(number%10)*(number%10)*(number%10)*(number%10)*(number%10);
			number/=10;
		}
		if(result==i){sum+=i;}
	}
	cout<<sum;
	getchar();
	return 0;
}
