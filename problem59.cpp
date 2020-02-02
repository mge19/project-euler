#include <bits/stdc++.h>
using namespace std;
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
			c*=10;
			c+=(x-'0');
			x=file.get();
		}
		text.push_back(c);
	}
	file.close();
	for(int i=0;passcode1.size()!=1 || passcode2.size()!=1 || passcode3.size()!=1;i++)
	{
		if(i%3==0 && passcode1.size()!=1)
		{
			if(i==0)
			{
				for(char x='a';x<='z';x++)
				{
					if((text[i] xor x)>='a' && (text[i] xor x)<='z'){passcode1.push_back(x);}
					else if((text[i] xor x)>='A' && (text[i] xor x)<='Z'){passcode1.push_back(x);}
					else if((text[i] xor x)==' '){passcode1.push_back(x);}
				}
			}
			else
			{
				for(int j=0;j<passcode1.size();j++)
				{
					if((text[i] xor passcode1[j])<'a')
					{
						if((text[i] xor passcode1[j])<'A' || (text[i] xor passcode1[j])<'Z')
						{
							if((text[i] xor passcode1[j])!=' '){passcode1.erase(passcode1.begin()+j);}
						}
					}
					else if((text[i] xor passcode1[j])>'z'){passcode1.erase(passcode1.begin()+j);}
				}	
			}
		}
		else if(i%3==1 && passcode2.size()!=1)
		{
			if(i==1)
			{
				for(char x='a';x<='z';x++)
				{
					if((text[i] xor x)>='a' && (text[i] xor x)<='z'){passcode2.push_back(x);}
					else if((text[i] xor x)>='A' && (text[i] xor x)<='Z'){passcode2.push_back(x);}
					else if((text[i] xor x)==' '){passcode2.push_back(x);}	
				}		
			}
			else
			{
				for(int j=0;j<passcode2.size();j++)
				{
					if((text[i] xor passcode2[j])<'a')
					{
						if((text[i] xor passcode2[j])<'A' || (text[i] xor passcode2[j])<'Z')
						{
							if((text[i] xor passcode2[j])!=' '){passcode2.erase(passcode2.begin()+j);}
						}
					}
					else if((text[i] xor passcode2[j])>'z'){passcode2.erase(passcode2.begin()+j);}
				}				
			}			
		}
		else if(i%3==2 && passcode3.size()!=1)
		{
			if(i==2)
			{
				for(char x='a';x<='z';x++)
				{
					if((text[i] xor x)>='a' && (text[i] xor x)<='z'){passcode3.push_back(x);}
					else if((text[i] xor x)>='A' && (text[i] xor x)<='Z'){passcode3.push_back(x);}
					else if((text[i] xor x)==' '){passcode3.push_back(x);}
				}				
			}
			else
			{
				for(int j=0;j<passcode3.size();j++)
				{
					if((text[i] xor passcode3[j])<'a')
					{
						if((text[i] xor passcode3[j])<'A' || (text[i] xor passcode3[j])<'Z')
						{
							if((text[i] xor passcode3[j])!=' '){passcode1.erase(passcode3.begin()+j);}
						}
					}
					else if((text[i] xor passcode3[j])>'z'){passcode3.erase(passcode3.begin()+j);}
				}				
			}				
		}
	}
	for(int i=0;i<text.size();i++)
	{
		if(i%3==0){result+=(text[i] xor passcode1[0]);}
		else if(i%3==1){result+=(text[i] xor passcode2[0]);}
		else{result+=(text[i] xor passcode3[0]);}
	}
	cout<<result;
	getchar();
	return 0;
}
