// one.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "stdio.h"
#include <algorithm>
#include <vector>
#include "string.h"

using namespace std;

int T;
int n;

char str[7][5];
char robot[5];
char result[5];

#define R 0
#define S 1
#define P 2

#define WIN		0
#define LOSE	1
#define DRAW	2

bool bFound;

void input()
{
	scanf("%d", &T);

}

int win()
{
	bool bWin = true;

	for(int i = 0; i < n; i++)
	{ 
		
		int iStr = strlen(str[i]);
		int iRobot = strlen(robot);
		for(int j = 0; j <= iStr * iRobot ; j++)
		{

			if(str[i][j%iStr] == 'R')
			{
				if(robot[j%iRobot] == 'S')
				{
					bWin = false;
					break;
				}
				else if(robot[j%iRobot] == 'P')
				{
					break;
				}
			}
			else if(str[i][j%iStr] == 'S')
			{
				if(robot[j%iRobot] == 'P')
				{
					bWin = false;
					break;
				}
				else if(robot[j%iRobot] == 'R')
				{
					break;
				}
			}
			else if(str[i][j%iStr] == 'P')
			{
				if(robot[j%iRobot] == 'R')
				{
					bWin = false;
					break;
				}
				else if(robot[j%iRobot] == 'S')
				{
					break;
				}
			}

			if(j == iStr * iRobot)
			{
				bWin = false;
				break;
			}
		}


		if(!bWin)
			break;
	}


	return bWin;
}

void dfs(int i)
{
	if(bFound)
		return;

	if(i == 5)
		return;

	if(i>0)
	{
		if(win())
		{
			for(int k= 0; k < 5; k++)
				result[k] = robot[k];

			bFound = true;
			return;
		}
	}

	robot[i] = 'R';
	dfs(i+1); 
	robot[i] = 'S';
	dfs(i+1); 
	robot[i] = 'P';
	dfs(i+1);
	robot[i] = 0;
}



void solve()
{
	for(int i = 0; i < T; i++)
	{
		scanf("%d", &n);

		for(int j = 0; j < n; j++)
		{
			scanf("%s", &str[j]);
		}

		bFound = false;
		dfs(0);


		if(strlen(result) > 0)
		{
			printf("Case #%d: %s\r\n",i+1,  result);
		}
		else
			printf("Case #%d: IMPOSSIBLE\r\n",i+1);

		for(int k = 0; k < 5; k++)
			result[k] = 0;
	}
}


/*
int main()
{
	input();
	solve();

return 0;
}

*/

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	input();
	solve();
	return 0;
}

