#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result;
	for(int i=1;;i++)
	{
		long int begin=1,end=10;
		for(int j=0;j<i;begin*=10,end*=10,j++){}
		for(long int j=begin;6*j<end;j++)
		{
			bool digits[10];
			for(int k=0;k<10;k++){digits[k]=false;}
			for(long int k=j;k!=0;digits[k%10]=true,k/=10){}
			int a=0;
			for(int k=2;k<=6;k++)
			{
				for(long int x=k*j;x!=0 && digits[x%10];a++,x/=10){}
			}
			if(a==5*i+5)
			{
				result=j;
				cout<<result;
				getchar();
				exit(1);
			}
		}
	}
	return 0;
}
