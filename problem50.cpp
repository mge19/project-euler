#include <bits/stdc++.h>
int main()
{
	long int result=0;
	int max=0;
	bool asal[1000000];
	std::list<long int> asallar;
	for(long int i=0;i<1000000;asal[i]=true,i++){}
	for(long int i=2;i<1000000;i++)
	{
		if(asal[i-1])
		{
			asallar.push_back(i);
			for(long int k=2*i;k<=1000000;asal[k-1]=false,k+=i){}
		}
	}
	for(std::list<long int>::iterator it=asallar.begin();it!=asallar.end();++it)
	{
		long int temp;
		int i;
		std::list<long int>::iterator it1;		
		for(i=1,it1=it,temp=0;temp<1000000;temp+=(*it1),++it1,++i)
		{
			if(asal[temp-1] && i>max)
			{
				result=temp;
				max=i;
			}
		}
	}
	std::cout<<result;
	getchar();
	return 0;
}
