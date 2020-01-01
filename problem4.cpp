#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	for(long int i=100;i<1000;i++)
	{
		for(long int j=i;j<1000;j++)
		{
			string str;
			stringstream ss;
			ss<<i*j;
			str=ss.str();
			bool correct=true;
			for(int x=0;x<str.length()/2;x++)
			{
				if(str[x]!=str[str.length()-1-x])
				{
					correct=false;
					break;
				}
			}
			if(correct && i*j>result){result=i*j;}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
