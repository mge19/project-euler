#include <bits/stdc++.h>
int main()
{
	long long int u=600851475143,i;
	for(i=2;u!=1;i++)
	{
		while(u%i==0){u/=i;}
	}	
	std::cout<<i-1;
	getchar();
	return 0;
}
