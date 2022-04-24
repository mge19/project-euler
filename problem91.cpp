#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0){return a;}
	return gcd(b,a%b);
}
int main()
{
	int result=2500;
	for(int x1=0;x1<=50;x1++)
	{
		for(int y1=0;y1<=50;y1++)
		{
			if(x1!=0 || y1!=0)
			{
				int a,b;
				if(x1==0)
				{
					a=1;
					b=0;
				}
				if(y1==0)
				{
					a=0;
					b=1;
				}
				else
				{
					a=y1/gcd(x1,y1);
					b=x1/gcd(x1,y1);
				}
				int x2=x1,y2=y1;
				while(x2-a>=0 && y2+b<=50)
				{
					x2-=a;
					y2+=b;
					result++;
				}
				x2=x1,y2=y1;
				while(x2+a<=50 && y2-b>=0)
				{
					x2+=a;
					y2-=b;
					result++;
				}				
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
