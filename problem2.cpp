#include <bits/stdc++.h>
using namespace std;
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
	cout<<result;
	getchar();
	return 0;
}
