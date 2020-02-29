#include <bits/stdc++.h>
using namespace std;
bool permutation(int a,int b)
{
	int used_a[10]={0,0,0,0,0,0,0,0,0,0},used_b[10]={0,0,0,0,0,0,0,0,0,0};
	for(int x=a,y=b;x!=0;used_a[x%10]++,used_b[y%10]++,x/=10,y/=10){}
	int k=0;
	for(;used_a[k]==used_b[k] && k<10;k++){}
	return k==10;
}
int main()
{
	vector<bool> asal(10000,true);
	vector<int> asallar;
	for(int i=2;i<10000;i++)
	{
		if(asal[i-1])
		{
			for(int j=2*i;j<=10000;asal[j-1]=false,j+=i){}
			if(i>1000){asallar.push_back(i);}
		}
	}
	for(int i=0;i<asallar.size();i++)
	{
		for(int j=i+1;j<asallar.size();j++)
		{
			int a=asallar[i],b=asallar[j],c=2*b-a;
			if(c<9998 && asal[c-1] && a!=1487 && permutation(a,b) && permutation(b,c))
			{
				cout<<a<<b<<c;
				exit(1);			
			}			
		}
	}
	return 0;
}
