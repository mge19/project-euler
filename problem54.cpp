#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0;
	ifstream file("p054_poker.txt");
	while(!file.eof())
	{
		bool highest=true;
		int maxpair[2]={0,0},points[2]={0,0};
		vector<int> values[2];
		for(int i=0;i<2;i++)
		{
                        bool samesuit=true;
                        char suit;
			for(int j=0;j<5;j++)
			{
				char x=file.get();
				if(x=='T'){values[i].push_back(10);}
				else if(x=='J'){values[i].push_back(11);}
				else if(x=='Q'){values[i].push_back(12);}
				else if(x=='K'){values[i].push_back(13);}
				else if(x=='A'){values[i].push_back(14);}
				else {values[i].push_back(x-'0');}
                                x=file.get();
                                if(j==0){x=suit;}
	                        else if(x!=suit){samesuit=false;}
                                if(!file.eof()){file.get();}
			}
			sort(values[i].begin(),values[i].end());
                        if(values[i][0]+1==values[i][1] && values[i][0]+2==values[i][2] && values[i][0]+3==values[i][3] && values[i][0]+4==values[i][4])
                        {
                                if(samesuit){points[i]=(values[i][0]==10)?9:8;}
                                else{points[i]=4;}
                        } 
			for(int a=0;a<2;a++)
			{
				if(values[i][a]==values[i][a+1] && values[i][a+1]==values[i][a+2] && values[i][a+2]==values[i][a+3])
			 	{
					points[i]=7;
					maxpair[i]=values[i][1];
				}
			}
			if(points[i]==0)
			{
				for(int a=0;a<3;a++)
				{	
					if(values[i][a]==values[i][a+1] && values[i][a+1]==values[i][a+2])
					{
						if((a==0 && values[i][3]==values[i][4]) || (a==2 && values[i][0]==values[i][1]))
                                                {
                                                        points[i]=6;
                                                        maxpair[i]=values[i][3];
                                                }
						else
                                                {
                                                        points[i]=3;
                                                        maxpair[i]=values[i][2];
                                                }
					}
				}
			}
                        if(samesuit && points[i]<5){points[i]=5;}
			if(points[i]==0)
			{
				int x=0;
				for(int a=0;a<4;a++)
				{
					if(values[i][a]==values[i][a+1])
					{
						x++;
						maxpair[i]=values[i][a];
					}
					points[i]=x;
				}
			}
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
