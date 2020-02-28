#include <bits/stdc++.h>
using namespace std;
bool correct(int i,int j)
{
	bool used[9]={false,false,false,false,false,false,false,false,false};
	stringstream ss;
	string str;
	int number=i*j;
	ss<<i;	
	ss<<j;
	ss<<number;
	str=ss.str();
	for(int i=0;i<9;i++)
	{
		if(str[i]=='0'){return false;}
		used[str[i]-'0'-1]=true;
	}
	return used[0] && used[1] && used[2] && used[3] && used[4] && used[5] && used[6] && used[7] && used[8];
}
int main()
{
	set<int> numbers;
	long int sum=0;
	for(int i=1234;i<=9876;i++)
	{
		for(int j=2;i*j<10000;j++)
		{
			if(correct(i,j)){numbers.insert(i*j);}
		}
	}
	for(int i=123;i<=987;i++)
	{
		for(int j=12;i*j<10000;j++)
		{
			if(correct(i,j)){numbers.insert(i*j);}
		}
	}
	for(set<int>::iterator it=numbers.begin();it!=numbers.end();it++){sum+=*it;}
	cout<<sum;
	getchar();
	return 0;
}
