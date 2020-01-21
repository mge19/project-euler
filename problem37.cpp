#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int sum=0,num=0;
	vector<bool> asal(1000000,true);
	asal[0]=false;
	for(long int i=2;num<11;i++)
	{
		if(asal[i-1])
		{
			for(long int j=2*i-1;j<1000000;asal[j]=false,j+=i){}
			if(i>10)
			{
				long int number=i/10;
				while(number>0 && asal[number-1]){number/=10;}
				if(number==0)
				{
					long int x=10;
					while(x<i && asal[(i%x)-1]){x*=10;}
					if(x>i)
					{
						num++;
						sum+=i;
					}
				}
			}
		}
	}
	cout<<sum;
	getchar();
	return 0;
}
