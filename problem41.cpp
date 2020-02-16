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
	long int fact[7],result;
	fact[0]=1;
	int number[7];
	for(int i=1;i<7;i++){fact[i]=i*fact[i-1];}
	for(int i=2;i<=7*fact[6];i++)
	{
		long int u=0;
		bool used[7];
		for(int j=0;j<7;used[j]=false,j++){}
		for(int j=0;j<7;j++)
		{
			int y=0,x=0;
			while(u+y*fact[6-j]<i){y++;}
			u+=(y-1)*fact[6-j];
			for(number[j]=0;x<y;number[j]++)
			{
				if(!used[number[j]-1]){x++;}
			}
			number[j]--;
			used[number[j]-1]=true;			
		}
		long int n=number[0]*1000000+number[1]*100000+number[2]*10000+number[3]*1000+number[4]*100+number[5]*10+number[6];
		if(asal(n)){result=n;}
	}
	cout<<result;
	getchar();
	return 0;
}
