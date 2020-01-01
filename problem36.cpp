#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	long int result=0;
	for(long int i=1;i<1000000;i++)
	{
		char* str=new char[20];
		itoa(i,str,10);
		bool correct=true;
		for(int x=0;x<strlen(str)/2;x++)
		{
			if(str[x]!=str[strlen(str)-1-x])
			{
				correct=false;
				break;
			}
		}
		if(correct)
		{
			itoa(i,str,2);
			for(int x=0;x<strlen(stry)/2;x++)
			{
				if(str[x]!=strbinary[strlen(str)-1-x])
				{
					correct=false;
					break;
				}
			}			
		}
		if(correct){result+=i;}
		delete str;
	}
	cout<<result;
	getchar();
	return 0;
}
