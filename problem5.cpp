#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool asal[20];
	long int result=1;
	for(int i=0;i<20;asal[i]=true,i++){}
	for(int i=2;i<=20;i++)
	{
		if(asal[i-1])
		{
			int temp=i;
			while(temp<=20)
			{
				temp+=i;
				asal[temp-1]=false;
			}
                        temp=i;
			while(temp<=20)
			{
				temp*=i;
				result*=i;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
