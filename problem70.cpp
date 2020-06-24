#include <bits/stdc++.h>
using namespace std;
bool permutation(long int x,long int y)
{
	int used_x[10]={0,0,0,0,0,0,0,0,0,0},used_y[10]={0,0,0,0,0,0,0,0,0,0};
	string str1,str2;
	stringstream ss1,ss2;
	ss1<<x;
	str1=ss1.str();
	ss2<<y;
	str2=ss2.str();
	for(int i=0;i<str1.size();used_x[str1[i]-'0']++,i++){}
	for(int i=0;i<str2.size();used_y[str2[i]-'0']++,i++){}
	int i=0;
	while(i<10 && used_x[i]==used_y[i]){i++;}
	return i==10;
}
int main()
{
	vector<long int> relprime(9999999,1);
	double min=99;
	long int result;
	for(long int i=2;i<10000000;i++)
	{
		if(relprime[i-1]==1)
		{
			relprime[i-1]=i-1;
			for(long int j=2*i;j<10000000;relprime[j-1]*=i-1,j+=i){}	
		}                   		
	}
	for(int i=2;i<10000000;i++)
	{
		if(i*i<10000000 && asal[i-1])
		{
			for(long int j=i*i;j<10000000;relprime[j-1]=i*relprime[j/i-1],j+=i*i){}
		}
		double cur=(double)i/(double)relprime[i-1];
		if(cur<min)
		{
			if(permutation(i,relprime[i-1]))
			{
				min=cur;
				result=i;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
