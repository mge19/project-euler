#include <bits/stdc++.h>
using namespace std;
int main()
{
	int max=0,result;
	for(int p=12;p<=1000;p++)
	{
		int cur=0;
		for(int a=3;a<p;a++)
		{
			for(int b=a+1;b<p;b++){cur+=2*a*p+2*b*p==2*a*b+p*p;}
		}
		if(cur>max)
		{
			max=cur;
			result=p;		
		}
	}
	cout<<result;
	getchar();
	return 0;
}
