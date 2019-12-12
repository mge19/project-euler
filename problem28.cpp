#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	for(int i=2;i<=1001;i++)
	{
		result+=2*i*i-i+1;
		if(i%2==0){result++;}
	}
	cout<<result+1;
	getchar();
	return 0;
}
