#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=1;
	long int counter=9;
	for(int i=1;i<7;i++)
	{
		long int begin=1,end=10;
		for(int j=0;j<i;begin*=10,end*=10,j++){}
		bool found=false;
		for(long int j=begin;j<end;j++)
		{
			counter+=i+1;
			if(counter>end && !found)
			{
				stringstream ss;
				ss<<j;
				string str=ss.str();
				result*=str[counter%(i+1)]-'0';
				found=true;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
