#include <bits/stdc++.h>
#define c 1000000007
using namespace std;
int main()
{
	vector<bool> asallar(20000,true);
	vector<long int> numbers(20000,1);
	long int result=1;
	for(int i=2;i<=20000;i++)
	{
		if(asallar[i-1])
		{
			long long int y=1;
			while(y%(i-1)!=0){y+=c;}
			y/=(i-1);
			int factors=0;
			long int a=0;
			for(int j=i;j<=20000;j++)
			{
				if(j%i==0)
				{
					if(j>i){asallar[j-1]=false;}
					int x=j;
					while(x%i==0)
					{
						x/=i;
						factors++;
					}
				}
				long int k=factors*(j-1)+1-a;
				a+=2*factors;
				long long int x=1;
				for(long int n=0;n<k;n++){x=(x*i)%c;}
				x-=1;
				if(x%(i-1)==0){x/=(i-1);}
				else{x=(x*y)%c;}
				numbers[j-1]=(numbers[j-1]*x)%c;
			}
		}
		result=(result+numbers[i-1])%c;
		cout<<i<<" "<<result<<endl;
	}
	getchar();
	return 0;
}
