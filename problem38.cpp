#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=1,m=1;
	for(int i=1;i<10000;i++)
	{
		bool contains[9];
		for(int j=0;j<10;j++){contains[j]=false;}
		int digits=0,multiply=1,k=1;
		for(;;multiply++)
		{
			int x=multiply*i,n=0;
			while(x!=0)
			{
				x/=10;
				n++;
			}
			if(n+digits>=10){break;}
			else{digits+=n;}
		}
		if(digits==9)
		{
			for(int j=1;j<multiply;j++)
			{
				int x=j*i;
				while(x!=0)
				{
					contains[x%10]=true;
					x/=10;
				}				
			}
		}
		for(;k<10 && contains[k];k++){}
		if(k==10)
		{
			result=i;
			m=multiply-1;
		}
	}
	for(int i=1;i<=m;i++){cout<<result*i;}
	getchar();
	return 0;
}
