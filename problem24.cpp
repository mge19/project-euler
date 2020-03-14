#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int u=0,fact[10];
	fact[0]=1;
	for(int i=1;i<=9;fact[i]=i*fact[i-1],i++){}
	bool used[10];
	int number[10];
	for(int i=0;i<10;used[i]=false,i++){}
	for(int i=0;i<10;i++)
	{
		int j=0,x=0;
		while(u+j*fact[9-i]<1000000){j++;}
		j--;
		u+=j*fact[9-i];
		for(number[i]=0;x<=j;number[i]++)
		{
			if(!used[number[i]]){x++;}
		}
		number[i]--;
		used[number[i]]=true;
		cout<<number[i];			
	}
	getchar();
	return 0;
}
