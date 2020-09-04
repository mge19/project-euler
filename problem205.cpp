#include <bits/stdc++.h>
using namespace std;
void increment(vector<int>& numbers,int index,int limit)
{
	if(numbers[index]==limit)
	{
		if(index>0)
		{
			numbers[index]=1;
			increment(numbers,index-1,limit);
		}
	}
	else{numbers[index]++;}
}
int main()
{
	long long int result=0;
	long int sum=0;
	vector<int> peter(9,1),colin(6,1);
	vector<long int> sums_peter(36,0),sums_colin(36,0);
	while(sum<36)
	{
		sum=0;
		for(int i=0;i<9;i++){sum+=peter[i];}
		sums_peter[sum-1]++;
		increment(peter,8,4);
	}
	sum=0;
	while(sum<36)
	{
		sum=0;
		for(int i=0;i<6;i++){sum+=colin[i];}
		sums_colin[sum-1]++;
		increment(colin,5,6);
	}
	for(int i=0;i<36;i++)
	{
		sum=0;
		for(int j=0;j<i;j++){sum+=sums_colin[j];}
		result+=sums_peter[i]*sum;
	}
	cout<<setprecision(7)<<(double)result/((long long int)4*4*4*4*4*4*4*4*4*6*6*6*6*6*6);
	getchar();
	return 0;
}
