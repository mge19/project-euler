#include <bits/stdc++.h>
using namespace std;
class Number{
	public:
		string value;
		double prob=1;
};
int convert_number(string& str)
{
	int result=0,i=0,j,k;
	while(i<str.size() && (str[i]=='C' || str[i]=='D' || str[i]=='M')){i++;}
	j=i;
	while(j<str.size() && (str[j]=='L' || str[j]=='X' || str[j]=='C')){j++;}
	k=j;
	while(k<str.size() && (str[k]=='V' || str[k]=='I' || str[k]=='X')){k++;}
	string s1=str.substr(0,i),s2=str.substr(i,j-i),s3=str.substr(j,k-j);
	if(s1.size()==4){result+=800;}
	else if(s1.size()==3)
	{
		if(s1[0]=='D'){result+=700;}
		else{result+=300;}
	}
	else if(s1.size()==2)
	{
		if(s1[0]=='D'){result+=600;}
		else if(s1[1]=='C'){result+=200;}
		else if(s1[1]=='D'){result+=400;}
		else if(s1[1]=='M'){result+=900;}
	}	
	else if(s1.size()==1){result+=(s1=="D")?500:100;}
	if(s2.size()==4){result+=80;}
	else if(s2.size()==3)
	{
		if(s2[0]=='L'){result+=70;}
		else{result+=30;}
	}
	else if(s2.size()==2)
	{
		if(s2[0]=='L'){result+=60;}
		else if(s2[1]=='X'){result+=20;}
		else if(s2[1]=='L'){result+=40;}
		else if(s2[1]=='C'){result+=90;}
	}	
	else if(s2.size()==1){result+=(s2=="L")?50:10;}
	if(s3.size()==4){result+=8;}
	else if(s3.size()==3)
	{
		if(s3[0]=='V'){result+=7;}
		else{result+=3;}
	}
	else if(s3.size()==2)
	{
		if(s3[0]=='V'){result+=6;}
		else if(s3[1]=='I'){result+=2;}
		else if(s3[1]=='V'){result+=4;}
		else if(s3[1]=='X'){result+=9;}
	}	
	else if(s3.size()==1){result+=(s3=="V")?5:1;}
	return result;
}
int main()
{
	queue<Number> numbers;
	char available[7]={'D','C','L','X','V','I','#'};
	Number n;
	for(int i=0;i<7;i++)
	{
		n.value=available[i];
		numbers.push(n);		
	}
	double result=0;
	while(!numbers.empty())
	{
		n=numbers.front();
		numbers.pop();
		int x=n.value.size();
		if(n.value[x-1]!='#')
		{
			vector<char> available;
			available.push_back('#');
			char a=n.value[x-1],b=(x>=2)?n.value[x-2]:'n',c=(x>=3)?n.value[x-3]:'n';
			if(n.value=="C")
			{
				available.push_back('M');
				available.push_back('D');
			}
			if(n.value=="D" || (a=='X' && (b=='D' || b=='C' || b=='M' || b=='n')) || (a=='C' && !(b=='X' || (b=='C' && c=='C')))){available.push_back('C');}
			if(!(a=='L' || (a=='X' && (b=='L' || b=='X' || b=='I')) || a=='V' || a=='I' || (a=='C' && b=='X'))){available.push_back('L');}
			if(!(((a=='L' || a=='C') && b=='X') || (a=='I' && (b=='V' || b=='I')) || (a=='X' && (b=='I' || (b=='X' && c=='X'))) || a=='V'))
			{available.push_back('X');}
			if(!(a=='V' || (a=='I' && (b=='V' || b=='I')) || (a=='X' && b=='I'))){available.push_back('V');}
			if(!((a=='V' || a=='X' || (a=='I' && c=='I')) && b=='I')){available.push_back('I');}	
			for(int i=0;i<available.size();i++)
			{
				Number n1=n;
				n1.value+=available[i];
				n1.prob/=(1-(8-available.size())*0.14);
				numbers.push(n1);
			}
		}
		else
		{
			for(int i=0;i<x-1;i++){n.prob*=0.14;}
			n.prob/=43;
			result+=convert_number(n.value)*n.prob;
		}
	}
	cout<<setprecision(11)<<result+(double)7000/43;
	getchar();
	return 0;
}
