#include <bits/stdc++.h>
using namespace std;
int main()
{
	for(long int a=1;a<=332;a++)
	{
		for(long int b=a+1;2*b+a<1000;b++)
		{
			long int c=1000-a-b;
			if(a*a+b*b==c*c)
                        {
                                cout<<a*b*c;
                                break;
                        }
		}
	}
	getchar();
	return 0;
}
