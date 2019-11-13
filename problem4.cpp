#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
int main()
{
	long int result=0;
	for(long int i=100;i<1000;i++)
	{
		for(long int j=i;j<1000;j++)
		{
			char* str=new char[6];
			itoa(i*j,str,10);
			bool correct=true;
			for(int x=0;x<strlen(str)/2;x++)
			{
				if(str[x]!=str[strlen(str)-1-x])
				{
					correct=false;
					break;
				}
			}
			if(correct && i*j>result){result=i*j;}
			delete str;
		}
	}
	std::cout<<result;
	getchar();
	return 0;
}
