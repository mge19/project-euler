#include <bits/stdc++.h>
int main()
{
	bool asal[20];
	long int result=1;
	int temp;
	for(int i=1;i<=20;asal[i-1]=true,i++){}
	for(int i=2;i<=20;i++)
	{
		if(asal[i-1])
		{
			temp=i;
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
	std::cout<<result;
	getchar();
	return 0;
}
