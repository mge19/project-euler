#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream file("problem13.txt");
	string numbers[100];
	for(int i=0;i<100;i++){getline(file,numbers[i]);}
	file.close();
	int digits[50];
	for(int i=49;i>=0;i--)
	{
		digits[i]=0;
		for(int j=0;j<100;j++){digits[i]+=numbers[j][i]-'0';}
		if(i<49){digits[i]+=digits[i+1]/10;}
	}
	for(int i=0;i<8;i++)
	{
		if(i==0){cout<<digits[i];}
		else{cout<<digits[i]%10;}
	}
	getchar();
	return 0;
}
