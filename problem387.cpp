#include <bits/stdc++.h>
using namespace std;
class Number{
	public:
		long long int value;
		int sum;
};
int main()
{
	unsigned long long int result=0;
	vector<Number> numbers;
	for(int i=1;i<10;i++)
	{
		Number n;
		n.value=i;
		n.sum=i;
		numbers.push_back(n);
	} 
	for(long int i=0;numbers[i].value!=1000000000000;i++)
	{
		for(int j=0;j<=9;j++)
		{
			Number n=numbers[i];
			n.value=10*n.value+j;
			n.sum+=j;
			if(n.value%n.sum==0){numbers.push_back(n);}
		}
	}
	vector<long int> asallar;
	asallar.push_back(2);
	asallar.push_back(3);
	for(long int i=6;i<=10000000;i+=6)
	{
		long int a=i-1,b=i+1,j=0;
		for(;a%asallar[j]!=0 && asallar[j]<=floor(sqrt(a));j++){}
		if(asallar[j]>floor(sqrt(a))){asallar.push_back(a);}
		j=0;
		for(;b%asallar[j]!=0 && asallar[j]<=floor(sqrt(b));j++){}
		if(asallar[j]>floor(sqrt(b))){asallar.push_back(b);}
	}
	numbers.erase(numbers.begin(),numbers.begin()+9);
	for(long int i=0;i<numbers.size();)
	{
		long int j=0;
		for(;(numbers[i].value/numbers[i].sum)%asallar[j]!=0 && asallar[j]<=floor(sqrt(numbers[i].value/numbers[i].sum));j++){}
		if(asallar[j]>floor(sqrt(numbers[i].value/numbers[i].sum))){i++;}
		else{numbers.erase(numbers.begin()+i,numbers.begin()+i+1);}
	}
	for(long int i=0;i<numbers.size();i++)
	{
		long long int test1=10*numbers[i].value+1,test2=10*numbers[i].value+3,test3=10*numbers[i].value+7,test4=10*numbers[i].value+9;
		long int j=0;
		for(;test1%asallar[j]!=0 && asallar[j]<=floor(sqrt(test1));j++){}
		if(asallar[j]>floor(sqrt(test1))){result+=test1;}
		j=0;
		for(;test2%asallar[j]!=0 && asallar[j]<=floor(sqrt(test2));j++){}
		if(asallar[j]>floor(sqrt(test2))){result+=test2;}
		j=0;
		for(;test3%asallar[j]!=0 && asallar[j]<=floor(sqrt(test3));j++){}
		if(asallar[j]>floor(sqrt(test3))){result+=test3;}
		j=0;
		for(;test4%asallar[j]!=0 && asallar[j]<=floor(sqrt(test4));j++){}
		if(asallar[j]>floor(sqrt(test4))){result+=test4;}
	}
	cout<<result;
	getchar();
	return 0;
}
