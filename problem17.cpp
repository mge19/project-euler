#include <bits/stdc++.h>
int number_to_letter_count(int n)
{
	if(n==0){return 0;}
	else if(n==1 || n==2 || n==6 || n==10){return 3;}
	else if(n==4 || n==5 || n==9){return 4;}
	else if(n==3 || n==7 || n==8 || n==40 || n==50 || n==60){return 5;} 
	else if(n==11 || n==12 || n==20 || n==30 || n==80 || n==90){return 6;}
	else if(n==15 || n==16 || n==70){return 7;}
	else if(n==13 || n==14 || n==18 || n==19){return 8;}
	else if(n==17){return 9;}
	else{return number_to_letter_count(n%10)+number_to_letter_count(n-(n%10));}
}
int main()
{
	int result=0;
	for(int i=1;i<1000;i++)
	{
		result+=number_to_letter_count(i%100)+number_to_letter_count(i/100);
		if(i>=100)
		{
			result+=7;
			if(i%100!=0){result+=3;}
		}
	}
	std::cout<<result+11;
	getchar();
	return 0;
}
