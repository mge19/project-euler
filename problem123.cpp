#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> asallar;
	asallar.push_back(2);
	asallar.push_back(3);
	long long int index=2;
	long int number=6;
	bool turn=false;
	while(index%2==0 || 2*index*asallar[index-1]<=10000000000)
	{
		bool isprime=true;
		int sqr;
		if(!turn)
		{
			sqr=sqrt(number-1);
			for(int i=0;asallar[i]<=sqr && isprime;isprime=!((number-1)%asallar[i]==0),i++){}
			if(isprime){asallar.push_back(number-1);}
		}
		else
		{
			sqr=sqrt(number+1);
			for(int i=0;asallar[i]<=sqr && isprime;isprime=!((number+1)%asallar[i]==0),i++){}
			if(isprime){asallar.push_back(number+1);}
			number+=6;
		}
		if(isprime){index++;}
		turn=!turn;
	}
	cout<<index;
	getchar();
	return 0;
}
