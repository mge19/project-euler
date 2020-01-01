#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool asallar[999999];
	long int result=0;	
	for(int i=0;i<999999;asallar[i]=true,i++){}
	for(int i=2;i<1000000;i++)
	{
		if(asallar[i-1])
		{
			for(int k=2*i;k<1000000;asallar[k-1]=false,k+=i){}
		}
	}
	for(long int i=2;i<1000000;i++)
	{
		if(asallar[i-1])
		{
			if(i>=2 && i<10){result++;}
			else 
			{
				string str;
				stringstream ss;
				ss<<i;
				str=ss.str();
				bool circular_prime=true;
				for(int j=0;j<str.length() && circular_prime==true;j++)
				{
					char temp=str[0];
					for(int k=1;k<str.length();k++){str[k-1]=str[k];}
					str[str.length()-1]=temp;
					long int number=atoi(str.c_str());
					if(!asallar[number-1]){circular_prime=false;}
				}
				if(circular_prime){result++;}
			}
		}
	}
	cout<<result;	
	getchar();
	return 0;
}
