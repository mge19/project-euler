#include <bits/stdc++.h>
using namespace std;
bool asal(long int number)
{
	int x=round(sqrt(number));
	for(int i=2;i<=x;i++)
	{
		if(number%i==0){return false;}
	}
	return true;
}
int main()
{
	long int result=1;
	int cur;
	while(cur<1000)
	{
		cur=1;
		result++;
		long int x=result,y=2;
		if(!asal(x))
		{
			while(x!=1)
			{
				int z=1;
				while(x%y==0)
				{
					x/=y;
					z+=2;
				}
				cur*=z;
				y++;
			}	
		}
		cur=(cur+1)/2;
	}
	cout<<result;
	getchar();
	return 0;
}
