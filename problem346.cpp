#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<unsigned long long int> numbers;
	unsigned long long int result=1;
	for(unsigned long long int i=2;i*i+i+1<1000000000000;i++)
	{
		int power=3;
		unsigned long long int number=i*i+i+1;
		while(number<1000000000000)
		{
			numbers.insert(number);
			number+=pow(i,power);
			power++;
		}
	}	
	for(set<unsigned long long int>::iterator it=numbers.begin();it!=numbers.end();result+=*it,++it){}
	cout<<result;
	getchar();
	return 0;
}
