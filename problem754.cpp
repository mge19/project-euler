#include <bits/stdc++.h>
#define lim 100000000
#define mod 1000000007
using namespace std;
class Number{
	public:
		long int toitient=1,number=lim;
		int val=0;
};
int main()
{
	long long int result=1;
	vector<Number> numbers(lim);
	for(long int i=2;i<lim;i++)
	{
		if(numbers[i-1].val!=-1)
		{
			for(long int j=1;j<=lim/i;j++)
			{
				if(numbers[i-1].val==0)
				{
					numbers[i*j-1].toitient*=i-1;
					numbers[i*j-1].number-=lim/i;
					if(j!=1)
					{
						if(j%i==0){numbers[i*j-1].val=-1;}
						else if(numbers[i*j-1].val!=-1){numbers[i*j-1].val++;}							
					}				
				}
				else if(numbers[i-1].val%2==0){numbers[i*j-1].number+=lim/i;}
				else{numbers[i*j-1].number-=lim/i;}
			}
		}
	}
	for(long int i=2;i<lim;i++)
	{
		if(i<10000 && numbers[i-1].toitient==i-1)
		{
			for(long int j=i*i;j<lim;j+=i*i){numbers[j-1].toitient=i*numbers[j/i-1].toitient;}
		}
		long int n=numbers[i-1].number-numbers[i-1].toitient;
		long long int a=1,b=i;
		while(n>0)
		{
			if(n%2==1){a=(a*b)%mod;}	
			b=(b*b)%mod;
			n/=2;
		}
		result=(result*a)%mod;
	}
	cout<<result;
	getchar();
	return 0;
}
