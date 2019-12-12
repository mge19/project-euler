#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=1;
	int max1=1;
	for(long long int i=1;i<1000000;i++)
	{
		int x=1;
		for(long long int j=i;j!=1;x++){j=(j%2==0) ? j/2:3*j+1;}
		result=(x>max1) ? i:result;
		max1=max(x,max1);
	}
	cout<<result;
	getchar();
	return 0;
}
