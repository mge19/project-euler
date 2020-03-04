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
bool factor(int n)
{
	if(asal(n)){return false;}
	int result=0;
	for(int x=2,y=n;y>1;x++)
	{
		if(y%x==0){result+=1;}
		for(;y%x==0;y/=x){}
	}
	return (result==4);	
}
int main()
{
	bool correct[4];
	correct[0]=factor(210),correct[1]=factor(211),correct[2]=factor(212);
	long int i=214;
	for(;!(correct[0] && correct[1] && correct[2] && correct[3]);i++)
	{
		for(int j=0;j<3;j++){correct[j]=correct[j+1];}
		correct[3]=factor(i);
	}
	cout<<i-4;
	getchar();
	return 0;
}
