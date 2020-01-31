#include <bits/stdc++.h>
using namespace std;
int main()
{
	int numerator=1,denumerator=1;
	for(int a=1;a<=9;a++)
	{
		for(int b=1;b<=9;b++)
		{
			for(int c=1;c<=9;c++)
			{
				if(a!=b && b!=c && a!=c)
				{
					double x=a,y=b,z=c;
					if((10*x+y)/(10*y+z)==x/z)
					{
						numerator*=a;
						denumerator*=c;
					}
				}
			}
		}
	}
	cout<<denumerator/numerator;
	getchar();
	return 0;
}
