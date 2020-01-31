#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	long int result=9999999;
	for(long int a=1;a<=10000;a++)
	{
		for(long int b=1;b<=a;b++)
		{
			if(round(sqrt((6*a-1)*(6*a-1)+(6*b-1)*(6*b-1)-1))==sqrt((6*a-1)*(6*a-1)+(6*b-1)*(6*b-1)-1))
			{
				long int x=sqrt((6*a-1)*(6*a-1)+(6*b-1)*(6*b-1)-1);
				if(x%6==5)
				{
					if(round(sqrt((6*a-1)*(6*a-1)-(6*b-1)*(6*b-1)+1))==sqrt((6*a-1)*(6*a-1)-(6*b-1)*(6*b-1)+1))
					{
						long int y=sqrt((6*a-1)*(6*a-1)-(6*b-1)*(6*b-1)+1);
						if(y%6==5){result=min(result,(a*(3*a-1)-b*(3*b-1))/2);}
					}
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
