#include <bits/stdc++.h>
using namespace std;
long int combination(int n,int r)
{
	if(r>n/2){r=n-r;}
	long int a=1;
	for(int i=0;i<r;i++)
	{
		a*=n-i;
		a/=i+1;
	}
	return a;
}
int main()
{
	vector<long int> v(31,0);
	long int result=0;
	for(int o=0;o<=30;o++)
	{
		for(int aa=0;aa<=o+1 && 2*aa+o<=30;aa++)
		{
			for(int a=0;aa+a<=o+1 && 2*aa+a+o<=30;a++){v[o+2*aa+a]+=combination(o+1,aa)*combination(o+1-aa,a);}
		}
	}
	result+=v[30];
	for(int i=0;i<=14;i++){result+=2*v[i]*v[29-i];}
	cout<<result;
	getchar();
	return 0;
}
