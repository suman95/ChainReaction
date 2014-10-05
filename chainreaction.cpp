//chain reaction
/*
Developed and designed by 
SUMAN KUMAR SAHU
Computer Science and Engineering
National Institute Of Technology, Rourkela
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct node
{
	int item;
	char ch;
};

typedef struct node node;
node board[8][6];
int toggle;
int check();
void move(int x,int y,int player);
int reaction();
void disp()
{
	int i,j,k;
	for(i=0;i<6;i++)
	{
		if(i==0)
		{
			cout<<"    ";
		}
		cout<<"  "<<i+1<<" "<<(char)179;
	}
	cout<<endl<<endl;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(j==0)
			{
				cout<<" "<<i+1<<" "<<(char)179;
			}
			cout<<board[i][j].ch<<" ";
			if(board[i][j].item==0)
			{
				cout<<" "<<" "<<(char)179;	
			}
			else
			{
				cout<<board[i][j].item<<" "<<(char)179;
			}
		}
		cout<<endl;
		cout<<endl;
		for(k=0;k<6;k++)
		{
			if(k==0)
			{
				cout<<"    ";
			}
			cout<<"____"<<(char)179;
		}
		cout<<endl;
		cout<<endl;
	}
}

void move(int x,int y,int player)
{
	if(board[x][y].ch==(char)1||board[x][y].ch==(char)2)
	{
		if(board[x][y].ch!=(char)player)
		{
			cout<<"\n INVALID MOVE ..";
			toggle=!toggle;
			return;
		}
	}
	board[x][y].ch=(char)player;
	board[x][y].item+=1;
	while(reaction());
	return;
}

int reaction()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(board[i][j].item==2)
			{
				if(i==0&&j==0)
				{
					board[i+1][j].item+=1;
					board[i+1][j].ch=board[i][j].ch;
					board[i][j+1].item+=1;
					board[i][j+1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
				if(i==0&&j==5)
				{
					board[i+1][j].item+=1;
					board[i+1][j].ch=board[i][j].ch;
					board[i][j-1].item+=1;
					board[i][j-1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
				
				if(i==7&&j==5)
				{
					board[i-1][j].item+=1;
					board[i-1][j].ch=board[i][j].ch;
					board[i][j-1].item+=1;
					board[i][j-1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
				if(i==7&&j==0)
				{
					board[i-1][j].item+=1;
					board[i-1][j].ch=board[i][j].ch;
					board[i][j+1].item+=1;
					board[i][j+1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
			}
			if(board[i][j].item==3)
			{
				if(i==0)
				{	board[i+1][j].item+=1;
					board[i+1][j].ch=board[i][j].ch;
					board[i][j+1].item+=1;
					board[i][j+1].ch=board[i][j].ch;
					board[i][j-1].item+=1;
					board[i][j-1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
				if(i==7)
				{	board[i-1][j].item+=1;
					board[i-1][j].ch=board[i][j].ch;
					board[i][j+1].item+=1;
					board[i][j+1].ch=board[i][j].ch;
					board[i][j-1].item+=1;
					board[i][j-1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
				if(j==0)
				{	board[i][j+1].item+=1;
					board[i][j+1].ch=board[i][j].ch;
					board[i+1][j].item+=1;
					board[i+1][j].ch=board[i][j].ch;
					board[i-1][j].item+=1;
					board[i-1][j].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
				if(j==5)
				{	board[i][j-1].item+=1;
					board[i][j-1].ch=board[i][j].ch;
					board[i+1][j].item+=1;
					board[i+1][j].ch=board[i][j].ch;
					board[i-1][j].item+=1;
					board[i-1][j].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
					return 1;
				}
			}
			if(board[i][j].item==4)
			{
				board[i+1][j].item+=1;
				board[i+1][j].ch=board[i][j].ch;
				board[i-1][j].item+=1;
				board[i-1][j].ch=board[i][j].ch;
				board[i][j+1].item+=1;
				board[i][j+1].ch=board[i][j].ch;
				board[i][j-1].item+=1;
				board[i][j-1].ch=board[i][j].ch;
					board[i][j].item=0;
					board[i][j].ch=' ';
				return 1;
			}
		}
	}
	return 0;
}
int check()
{
	int i,j;
	char ch;
	int init=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(board[i][j].ch==(char)1||board[i][j].ch==(char)2)
			{
				ch=board[i][j].ch;
				break;
			}
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			if(board[i][j].ch==(char)1||board[i][j].ch==(char)2)
			{
				if(board[i][j].ch!=ch)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	
	int i,j,k,x,y;
	//initialisation
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			board[i][j].ch=' ';
			board[i][j].item=0;
		}
	}
	board[0][0].ch=(char)1;
	board[0][0].item=1;
	board[7][5].ch=(char)2;
	board[7][5].item=1;
	cout<<"\n##################################################################";
	cout<<"\n#                                                                #";
	cout<<"\n#                      CHAIN  REACTION                           #";
	cout<<"\n#                                                                #";
	cout<<"\n##################################################################";
	cout<<"\n\n";
	toggle=1;
	while(check())
	{	cout<<endl<<endl<<endl;
		cout<<"_________________________________________________________________________";
		cout<<endl<<endl<<endl;
		disp();
		toggle=!toggle;
		cout<<"Enter coordinates for player "<<toggle+1<<"  (0 0 for exit)>";
		cin>>x>>y;
		if(x==0 && y==0)
		{
			cout<<"Press any key to continue..";
			getch();
			exit(0);
		}
		if((x>8||x<1)||(y>6||y<1))
		{
			cout<<"INVALID MOVE ..";
			toggle=!toggle;
			continue;
		}
		else
		{
			move(x-1,y-1,toggle+1);
		}
	}
	cout<<endl<<endl;
	cout<<"____________________________________________________________________";
	cout<<endl;
	cout<<"\t\t"<<"Victory for Player "<<toggle+1<<endl<<endl;
	cout<<"____________________________________________________________________\n";
	cout<<"Press any key to continue..";
	getch();
	return 0;
}
