#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0,line=1;
	ifstream file("p054_poker.txt");
	while(!file.eof())
	{
		bool samesuit[2],consecutive[2],highest=true;
		int maxpair[2]={0,0},points[2]={0,0},pairstate[2]={0,0};
		vector<int> values[2];
		string cards[5];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<5;j++)
			{
				file>>cards[j];
				if(cards[j][0]=='T'){values[i].push_back(10);}
				else if(cards[j][0]=='J'){values[i].push_back(11);}
				else if(cards[j][0]=='Q'){values[i].push_back(12);}
				else if(cards[j][0]=='K'){values[i].push_back(13);}
				else if(cards[j][0]=='A'){values[i].push_back(14);}
				else {values[i].push_back(cards[j][0]-'0');}	
			}
			sort(values[i].begin(),values[i].end());
			consecutive[i]=(values[i][0]+1==values[i][1] && values[i][1]+1==values[i][2] && values[i][2]+1==values[i][3] && values[i][3]+1==values[i][4]);
			samesuit[i]=(cards[0][1]==cards[1][1] && cards[1][1]==cards[2][1] && cards[2][1]==cards[3][1] && cards[3][1]==cards[4][1]);
			for(int a=0;a<2;a++)
			{
				if(values[i][a]==values[i][a+1] && values[i][a+1]==values[i][a+2] && values[i][a+2]==values[i][a+3])
				{
					pairstate[i]=7;
					maxpair[i]=values[i][1];
				}
			}
			if(pairstate[i]==0)
			{
				for(int a=0;a<3;a++)
				{	
					if(values[i][a]==values[i][a+1] && values[i][a+1]==values[i][a+2])
					{
						if((a==0 && values[i][3]==values[i][4]) || (a==2 && values[i][0]==values[i][1]))
                                                {
                                                        pairstate[i]=6;
                                                        maxpair[i]=values[i][3];
                                                }
						else
                                                {
                                                        pairstate[i]=3;
                                                        maxpair[i]=values[i][2];
                                                }
					}
				}
			}
			if(pairstate[i]==0)
			{
				int x=0;
				for(int a=0;a<4;a++)
				{
					if(values[i][a]==values[i][a+1])
					{
						x++;
						maxpair[i]=values[i][a];
					}
					pairstate[i]=x;
				}
			}
                        if(consecutive[i] && samesuit[i]){points[i]=(values[i][0]==10)?9:8;}
			else if(samesuit[i]){points[i]=5;}
			else if(consecutive[i]){points[i]=4;}
			else{points[i]=pairstate[i];}
                } 
		for(int x=4;x>=0;x--)
		{
			if(values[0][x]!=values[1][x])
			{
				highest=(values[0][x]>values[1][x]);
				break;
			}
		}
		if(points[0]>points[1]){result++;}
		else if(points[0]==points[1])
                {
                        if(maxpair[0]>maxpair[1]){result++;}
                        else if(maxpair[0]==maxpair[1]){result+=highest;}
                }
	}
        file.close();
	cout<<result;
	getchar();
	return 0;
}
