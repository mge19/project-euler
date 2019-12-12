#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0,day=2;
	for(int month=1;month<=1200;month++)
	{
		if(month%12==4 || month%12==6 || month%12==9 || month%12==11){day+=2;}
		else if(month%48==38){day+=1;}
		else if(month%12!=2){day+=3;}
		if(day%7==0){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
