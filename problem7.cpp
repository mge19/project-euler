#include <bits/stdc++.h>
int main()
{
	bool asal[1000000];
	for(long int i=0;i<1000000;i++){asal[i]=true;}
	int u=0;
	long int k;
	for(k=2;u!=10001;k++)
	{
		if(asal[k])
		{
			for(long int j=2*k;j<1000000;j+=k){asal[j]=false;}
			u++;
		}
	}
	std::cout<<k-1;
	getchar();
	return 0;
}
