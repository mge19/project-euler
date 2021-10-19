#include <bits/stdc++.h>
using namespace std;
int main()
{
	int maxperiod=1,result;
	for(int i=3;i<1000;i++)
	{
		if(i%2!=0 && i%5!=0)
		{
			int n=9,current=1;
			while(n%i!=0)
			{
				current++;
				n=(10*n+9)%i;
			}
			if(current>maxperiod)
			{
				result=i;
				maxperiod=current;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
