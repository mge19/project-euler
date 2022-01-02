#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=1,prev,next=2,n=16;
	vector<int> v(32,1);
	for(int i=2;i<=32;i++)
	{
		int bolensayisi=0,x=i,j=2;
		for(;bolensayisi<2 && x!=1;j++)
		{
			if(x%j==0)
			{
				bolensayisi++;
				while(x%j==0){x/=j;}
			}
		}
		if(bolensayisi==1){v[i-1]=j-1;}
	}
	for(int i=2;i<=31;n*=4,i++)
	{
		if(v[i]!=1)
		{
			prev=next;
			next*=v[i];
			result+=((n-1-((n-1)%prev))/prev)-((n-1-((n-1)%next))/next);
		}
	}
	cout<<result;
	getchar();
	return 0;
}
