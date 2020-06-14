#include <bits/stdc++.h>
using namespace std;
int sum_of_digits(long int n)
{
	int r=0;
	while(n>0)
	{
		r+=(n%10);
		n/=10;
	}
	return r;
}
int sam_clock(int x)
{
	if(x==0 || x==6 || x==9){return 6;}
	else if(x==1){return 2;}
	else if(x==2 || x==3 || x==5){return 5;}
	else if(x==4 || x==7){return 4;}
	else{return 7;}
}
void max_clock(bool edges[],int n)
{
	if(n==1 || n==4){edges[0]=false;}
	if(n==1 || n==2 || n==3){edges[1]=false;}
	if(n==5 || n==6){edges[2]=false;}
	if(n==0 || n==1 || n==7){edges[3]=false;}
	if(n==1 || n==3 || n==4 || n==5 || n==7 || n==9){edges[4]=false;}
	if(n==2){edges[5]=false;}
	if(n==1 || n==4 || n==7){edges[6]=false;}
}
int main()
{
	long int result=0;
	vector<bool> asal(20000000,true);
	for(long int i=2;i<20000000;i++)
	{
		if(asal[i-1])
		{
			for(long int j=2*i;j<=20000000;asal[j-1]=false,j+=i){}
			if(i>10000000)
			{
				long int number1=i;
				while(number1>=10)
				{
					long int x=number1%100;
					int number2=sum_of_digits(number1),y=number2;
					while(y>0)
					{
						bool first[7]={true,true,true,true,true,true,true},second[7]={true,true,true,true,true,true,true};
						max_clock(first,x%10);
						max_clock(second,y%10);
						for(int j=0;j<7;j++){result-=first[j] xor second[j];}
						result+=sam_clock(x%10)+sam_clock(y%10);
						x/=10;			
						y/=10;
					}
					number1=number2;
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
