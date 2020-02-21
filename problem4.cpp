#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	for(int i=100;i<1000;i++)
	{
		for(int j=i;j<1000;j++)
		{
			long int number=i*j;
			if(number>100000)
			{
				int e1=number/100000,e2=(number/10000)%10,e3=(number/1000)%10,e4=(number/100)%10,e5=(number/10)%10,e6=number%10;
				if(e1==e6 && e2==e5 && e3==e4 && number>result){result=number;}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
