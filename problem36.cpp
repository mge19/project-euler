#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
int main()
{
	long int result=0;
	for(long int i=1;i<1000000;i++)
	{
		char* str=new char[6],*strbinary=new char[20];
		itoa(i,str,10);
		itoa(i,strbinary,2);
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
			for(int x=0;x<strlen(strbinary)/2;x++)
			{
				if(strbinary[x]!=strbinary[strlen(strbinary)-1-x])
				{
					correct=false;
					break;
				}
			}			
		}
		if(correct)
		{
			result+=i;
		}
		delete str;
		delete strbinary;
	}
	std::cout<<result;
	getchar();
	return 0;
}
