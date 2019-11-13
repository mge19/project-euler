#include <bits/stdc++.h>
int main()
{
	long int temp,i=1,j=2,result=2;
	while(j<=4000000)
	{
		temp=i;
		i=j;
		j+=temp;
		if(j%2==0){result+=j;}
	}
	std::cout<<result;
	getchar();
	return 0;
}
