#include <bits/stdc++.h>
#define lim 100000
#define N 1000000000000
using namespace std;
int main()
{
	vector<long long int> phis(lim,1);
	long long int result=1,e=N,r=1,x=2,a=0;
	for(long int i=2;i<=lim;i++)
	{
		if(i%2!=0 && i%5!=0){phis[i-1]=(phis[i-2]*i)%lim;}
		else{phis[i-1]=phis[i-2];}
	}
	int max2=log(N)/log(2),max5=log(N)/log(5);
	for(int p2=0;p2<=max2;p2++)
	{
		for(int p5=0;p5<=max5;p5++)
		{
			long long int p=pow(2,p2)*pow(5,p5);
			if(p>N){break;}
			long long int x=N/p;
			for(long long int i=0;i<x/lim;i++){result=(result*phis[lim-1])%lim;}
			if(x%lim!=0){result=(result*phis[(x%lim)-1])%lim;}
		}
	}
	while(e>0)
	{
		e/=2;
		a+=e;
	}
	e=N;
	while(e>0)
	{
		e/=5;
		a-=e;
	}
	while(a>0)
	{
		if(a%2==1){r=(r*x)%lim;}
		x=(x*x)%lim;
		a/=2;
	}
	cout<<(result*r)%lim;
	getchar();
	return 0;
}
