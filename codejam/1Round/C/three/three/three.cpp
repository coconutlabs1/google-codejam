// three.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdio.h"
#include <algorithm>
#include <vector>

using namespace std;

int T;
int h, w;
int win;

#define M_SIZE 15

#define BECCA 0
#define TERRY 1


char CELL[M_SIZE+1][M_SIZE+1];
char CELL3[M_SIZE+1][M_SIZE+1];

void input()
{
	scanf("%d", &T);

}

int checked[16];
bool checkHSafe(int a, int b)
{
	bool bHSafe = true;
	
	checked[b] = 1;
	if(CELL[a][b] == '#')
		return false;
	else if(CELL[a][b] == '|')
		return true;

    bool bHSafe1 = true;
	bool bHSafe2 = true;
	if( (b-1 >= 0) && checked[b-1] == 0)
	{
		bHSafe1 = checkHSafe(a, b-1);
	}

	if( (b+1 < h) && checked[b+1] == 0)
	{ 
		bHSafe2 = checkHSafe(a, b+1);
	 
	}
		if(bHSafe1 && bHSafe2)
	bHSafe = true;
	else bHSafe = false;

	return bHSafe;
}	

bool checkVSafe(int a, int b)
{
	
	bool bHSafe = true;

	checked[a] = 1;

	if(CELL[a][b] == '#')
		return false;
	else if(CELL[a][b] == '|')
		return true;
	
    bool bHSafe1 = true;
	bool bHSafe2 = true;
	if( (a-1 >= 0)  && checked[a-1] == 0)
	{

	bHSafe1 = checkVSafe(a-1, b);
	}

	if(a+1 < w  && checked[a+1] == 0)
	{ 
    	bHSafe2 = checkVSafe(a+1, b); 
	}
	if(bHSafe1 && bHSafe2)
	bHSafe = true;
	else bHSafe = false;

	return bHSafe; 
}	
bool checkSafe(int a, int b)
{
	for(int i = 0; i < 16; i++)
	{
		checked[i] = 0;
	}
	bool bHSafe = checkHSafe(a, b); 

	for(int i = 0; i < 16; i++)
	{
		checked[i] = 0;
	}
	bool bVSafe = checkVSafe(a, b); 

	bool bSafe;
	
	if(!bHSafe && !bVSafe)
		bSafe = false; 
	else bSafe = true;

	return bSafe;
}


void FillHCell(int a, int b)
{
	if((b >= 0) && ( b < w) &&  (CELL[a][b] == '.'))
	{
		CELL[a][b] = '|';

		FillHCell(a, b-1);
		FillHCell(a, b+1);
	}
}

void FillVCell(int a, int b)
{
	if((a >= 0) && ( a < h) &&  (CELL[a][b] == '.'))
	{
		CELL[a][b] = '|';

		FillVCell(a-1, b);
		FillVCell(a+1, b);
	}
}


void dfs(int a, int b, int who)
{
	
	if(win != 0)
		return;
	
	char CELL2[M_SIZE][M_SIZE];
	if(checkSafe(a, b) && CELL[a][b] != '|')
	{
		for(int i = 0; i < 16; i++)
		{
			checked[i] = 0;
		}
		if(checkHSafe(a, b))
		{ 
			for(int j = 0; j < w; j++)
			{
				CELL2[a][j] = CELL[a][j];			 
			}

			FillHCell(a, b);

			bool bFound = false;

			for( int i = 0; i < h; i++)
				for(int j = 0; j < w; j++)
				{
					if(checkSafe(i, j) && CELL[i][j] != '|')
					{
						bFound = true;
						if(who == BECCA)
							dfs(i, j, TERRY);
						else if(who == TERRY)
							dfs(i, j, BECCA);
					}
				}

				if(!bFound)
				{
					if(who == BECCA)
					{
						win++;
						return;
					}
				} 

				for(int j = 0; j < w; j++)
			{
			 CELL[a][j] = CELL2[a][j]; 
			}
		}
		for(int i = 0; i < 16; i++)
		{
			checked[i] = 0;
		}
		if(checkVSafe(a, b))
		{
			for(int i = 0; i < h; i++)
			{
				
				CELL2[i][b]= CELL[i][b]; 
			}
			FillVCell(a, b);
			bool bFound = false;

			for( int i = 0; i < h; i++)
				for(int j = 0; j < w; j++)
				{
					if(checkSafe(i, j) && CELL[i][j] != '|')
					{
						bFound = true;
						if(who == BECCA)
							dfs(i, j, TERRY);
						else if(who == TERRY)
							dfs(i, j, BECCA);
					}
				}

				if(!bFound)
				{
					if(who == BECCA)
					{
						win++;
						return;
					}
				} 

				for(int i = 0; i < h; i++)
			{
				
				 CELL[i][b] = CELL2[i][b]; 
			}
		}
	}
}

void dfsH(int a, int b, int who)
{
	if(win != 0)
		return;
	
	char CELL2[M_SIZE][M_SIZE];
	if(checkSafe(a, b) && CELL[a][b] != '|')
	{
			for(int i = 0; i < 16; i++)
	{
		checked[i] = 0;
	}
		if(checkHSafe(a, b))
		{ 
			for(int j = 0; j < w; j++)
			{
				CELL2[a][j] = CELL[a][j];			 
			}

			FillHCell(a, b);

			bool bFound = false;

			for( int i = 0; i < h; i++)
				for(int j = 0; j < w; j++)
				{
					if(checkSafe(i, j) && CELL[i][j] != '|')
					{
						bFound = true;
						if(who == BECCA)
							dfs(i, j, TERRY);
						else if(who == TERRY)
							dfs(i, j, BECCA);
					}
				}

				if(!bFound)
				{
					if(who == BECCA)
					{
						win++;
						return;
					}
				} 

				for(int j = 0; j < w; j++)
			{
			 CELL[a][j] = CELL2[a][j]; 
			}
		} 
	}
}


void dfsV(int a, int b, int who)
{
	
	if(win != 0)
		return;

	char CELL2[M_SIZE][M_SIZE];
	if(checkSafe(a, b) && CELL[a][b] != '|')
	{ 
			for(int i = 0; i < 16; i++)
	{
		checked[i] = 0;
	}
		if(checkVSafe(a, b))
		{
			for(int i = 0; i < h; i++)
			{
				
				CELL2[i][b]= CELL[i][b]; 
			}
			FillVCell(a, b);
			bool bFound = false;

			for( int i = 0; i < h; i++)
				for(int j = 0; j < w; j++)
				{
					if(checkSafe(i, j) && CELL[i][j] != '|')
					{
						bFound = true;
						if(who == BECCA)
							dfs(i, j, TERRY);
						else if(who == TERRY)
							dfs(i, j, BECCA);
					}
				}

				if(!bFound)
				{
					if(who == BECCA)
					{
						win++;
						return;
					}
				} 

				for(int i = 0; i < h; i++)
			{
				
				 CELL[i][b] = CELL2[i][b]; 
			}
		}
	}
}

void solve()
{
	for(int t = 0; t < T; t++)
	{
		scanf("%d %d", &h, &w);

		for( int i = 0; i < h; i++) 
		{
				scanf("%s", &CELL[i]);
				 strcpy(CELL3[i], CELL[i]);
		}

		//Becca
		//Terry
		
		int ans = 0;
		for( int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				for( int k = 0; k < h; k++) 
				{ 
					strcpy(CELL[k], CELL3[k]);
				}

				win = 0;
				dfsH(i, j, BECCA);
				if(win != 0)
					ans++;
				
				
				for( int k = 0; k < h; k++) 
				{ 
					strcpy(CELL[k], CELL3[k]);
				}

				win = 0;
				dfsV(i, j, BECCA);
				if(win != 0)
					ans++;
			}


			printf("Case #%d: %d\r\n", t+1, ans);
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

