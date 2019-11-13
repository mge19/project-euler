#include <bits/stdc++.h>
int main()
{
	for(long int a=1;a<=333;a++)
	{
		for(long int b=a;2*b+a<1000;b++)
		{
			long int c=1000-a-b;
			if(a*a+b*b==c*c){std::cout<<a*b*c;}
		}
	}
	getchar();
	return 0;
}
