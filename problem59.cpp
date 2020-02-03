#include <bits/stdc++.h>
using namespace std;
void candidate_key(vector<char>& v1,vector<char>& v2,int i)
{
	for(char x='a';x<='z';x++)
	{
		if((v1[i] xor x)>='a' && (v1[i] xor x)<='z'){v2.push_back(x);}
		else if((v1[i] xor x)>='A' && (v1[i] xor x)<='Z'){v2.push_back(x);}
		else if((v1[i] xor x)==' '){v2.push_back(x);}
	}	
}
void eliminate_key(vector<char>& v1,vector<char>& v2,int i)
{
	for(int j=0;j<v2.size();j++)
	{
		if((v1[i] xor v2[j])<'a')
		{
			if((v1[i] xor v2[j])<'A' || (v1[i] xor v2[j])>'Z')
			{
				if((v1[i] xor v2[j])!=' '){v2.erase(v2.begin()+j);}
			}
		}
		else if((v1[i] xor v2[j])>'z'){v2.erase(v2.begin()+j);}
	}
}
int main()
{
	ifstream file("p059_cipher.txt");
	vector<char> text,passcode1,passcode2,passcode3;
	long int result=0;
	while(!file.eof())
	{
		char x=file.get(),c=0;
		while(x!=',' && !file.eof())
		{
			c=10*c+x-'0';
			x=file.get();
		}
		text.push_back(c);
	}
	file.close();
	for(int i=0;passcode1.size()!=1 || passcode2.size()!=1 || passcode3.size()!=1;i++)
	{
		if(i%3==0 && passcode1.size()!=1)
		{
			if(i==0){candidate_key(text,passcode1,i);}
			else{eliminate_key(text,passcode1,i);}
		}
		else if(i%3==1 && passcode2.size()!=1)
		{
			if(i==1){candidate_key(text,passcode2,i);}
			else{eliminate_key(text,passcode2,i);}			
		}
		else if(i%3==2 && passcode3.size()!=1)
		{
			if(i==2){candidate_key(text,passcode3,i);}
			else{eliminate_key(text,passcode3,i);}				
		}
	}
	for(int i=0;i<text.size();i++)
	{
		if(i%3==0){result+=(text[i] xor passcode1[0]);}
		else if(i%3==1){result+=(text[i] xor passcode2[0]);}
		else{result+=(text[i] xor passcode3[0]);;}
	}
	cout<<result;
	getchar();
	return 0;
}
