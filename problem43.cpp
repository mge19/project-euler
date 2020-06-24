#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int fact[11];
	long long int sum=0;
	int asallar[8]={2,3,5,7,11,13,17};
	fact[0]=1;
	for(int i=1;i<=10;fact[i]=i*fact[i-1],i++){}
	for(long int y=fact[9];y<=fact[10];y++)
	{
		bool used[10];
		int number[10];
		long int u=0;
		for(int i=0;i<10;used[i]=false,i++){}
		for(int i=0;i<10;i++)
		{
			int j=0,x=0;
			while(u+j*fact[9-i]<y){j++;}
			j--;
			u+=j*fact[9-i];
			for(number[i]=0;x<=j;number[i]++)
			{
				if(!used[number[i]]){x++;}
			}
			number[i]--;
			used[number[i]]=true;		
		}
		int i=0;
		for(;i<7;i++)
		{
			if(((100*number[i+1]+10*number[i+2]+number[i+3])%asallar[i])!=0){break;}
		}
		if(i==7)
		{
			for(int j=0;j<10;j++){sum+=number[j]*pow(10,9-j);}
		}
	}
	cout<<sum;
	getchar();
	return 0;
}
