#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0;
	ifstream file("p042_words.txt");
	while(!file.eof())
	{
		char x=file.get();
		x=file.get();
		int cur=0;
		while(x!='"')
		{
			cur+=x-'A'+1;
			x=file.get();
		}
		for(int i=1;(i*(i+1)/2)<=cur;i++){result+=(i*(i+1)/2)==cur;}
		if(!file.eof()){x=file.get();}
	}
	cout<<result;
	getchar();
	return 0;
}
