#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int u=600851475143,i;
	for(i=2;u!=1;i++)
	{
		while(u%i==0){u/=i;}
	}	
	cout<<i-1;
	getchar();
	return 0;
}
