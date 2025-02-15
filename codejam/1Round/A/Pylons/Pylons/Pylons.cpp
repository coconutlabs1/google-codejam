// Pylons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAZE_LENGTH 20
#define MAZE_SIZE 400

char maze[MAZE_LENGTH][MAZE_LENGTH];
char traceX[MAZE_SIZE];
char traceY[MAZE_SIZE];
char traceXTotal[MAZE_SIZE];
char traceYTotal[MAZE_SIZE];

int m_R;
int m_C;
int m_Size;

bool mazeRun(int iX, int iY, int iStep)
{
    traceX[iStep] = iX;
    traceY[iStep] = iY;
    iStep++;
    if(iStep == m_Size)
        return true;
    
    maze[iX][iY] = 1;
    
    for(int x = 0; x < m_R; x++)
    {
        for(int y = 0; y < m_C; y++)
        {
            if((x != iX) && (y != iY)
              && ((x - y) != (iX - iY))
              && ((x + y) != (iX + iY)))
              {
                  if(maze[x][y] != 1)
                  {
                      if(mazeRun(x, y, iStep))
                        return true;
                  }
              }
        }
    }
    
    maze[iX][iY] = 0;
    
    return false;
}


 int solve()
 {
	int iTC;  

	scanf("%d\n", &iTC);
	
	for(int i = 0; i < iTC; i++)
	{
	    int iR;
	    scanf("%d", &iR);
	    m_R = iR;
	    int iC;
	    scanf("%d", &iC);
	    m_C = iC;
	    m_Size = iR*iC;
	    
	    for(int x = 0; x <iR; x++)
	    {
	      for(int y = 0; y <iC; y++)
	        {
	            maze[x][y] = 0;
	         }
	    }
	    
	    for(int j = 0; j < iR*iC; j++)
	    {
	        traceX[j] = 0;
	        traceY[j] = 0;
	    }
	    
	    bool bPossible = false;
		bool bEnd = false;

		if(iR == 2)
			if(iC <=4 )
				bEnd = true;
		
		if(iR == 3)
			if(iC <=3 )
				bEnd = true;

		
		if(iR == 4)
			if(iC <=2 )
				bEnd = true;

		if(!bEnd)
		{

			for(int r= 0; r < iR; r++ )
			{
				for(int c = 0; c < iC; c++)
				{
					if(mazeRun(r, c, 0))
					{
						bPossible = true;
						break;
					}
				}
				if(bPossible)
					break;
			}
	    
		}

	    if(bPossible)
	    { 
	       	printf("Case #%d: POSSIBLE\r\n", i+1);
	   
	        for(int j = 0; j < iR*iC; j++)
	        {
	           printf("%d %d\r\n", traceX[j]+1, traceY[j]+1); 
	            
	        }
	   
	    }
	    else
	    {
	       	printf("Case #%d: IMPOSSIBLE\r\n", i+1);
	    }
	    
	}
 
	return 0;
 }

 /*
int main()
{
    solve();
    return 0;
}
*/
int _tmain(int argc, _TCHAR* argv[])
{
    solve();
    return 0;
}

