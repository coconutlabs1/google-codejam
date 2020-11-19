// Manhattan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>


int solve()
{
	int iTC;  

	std::cin >> iTC;

	int P;
	int Q;

	int iResultX[100];
	int iResultY[100];

	int iMatrixX[100001];
	int iMatrixY[100001];


	for(int i = 0; i < iTC; i++)
	{
		std::cin >> P;
		std::cin >> Q;
		 

		 
		for(int m = 0; m <= Q; m++)
		{
			iMatrixX[m] = 0;
			iMatrixY[m] = 0;
		}

		for(int j = 0; j < P; j++)
		{
			int x,y;
			char dir;
			std::cin >> x;
			std::cin >> y;

			std::cin >> dir;

			if(dir == 'N')
			{
				for(int k = y +  1; k <= Q ; k++)
				{
					iMatrixY[k]++;
				} 
			}
			else if(dir == 'S')
			{ 
				
				for(int k = y -  1; k >= 0 ; k--)
				{
					iMatrixY[k]++;
				} 
			}
			else if(dir == 'W')
			{ 
				for(int k = x -  1; k >= 0 ; k--)
				{
					iMatrixX[k]++;
				} 
			}
			else if(dir == 'E')
			{ 
				for(int k = x +  1; k <= Q ; k++)
				{
					iMatrixX[k]++;
				} 
			}
		}
		int iMaxX = 0;
		int iMaxY = 0;

		for(int k = 0; k <= Q; k++)
		{
			if(iMaxX < iMatrixX[k])
				iMaxX = iMatrixX[k];

			if(iMaxY < iMatrixY[k])
				iMaxY = iMatrixY[k];
		}

		for(int k = 0; k <= Q; k++)
		{
			if(iMaxX == iMatrixX[k])
			{
				iResultX[i] = k;
				break;
			}

		}
		for(int k = 0; k <= Q; k++)
		{
			if(iMaxY == iMatrixY[k])
			{
				iResultY[i] = k;
				break;
			}
		}

	}
	
		for(int i = 0; i < iTC; i++)
		{
			//std::cout << "Case #" << i+1 <<  ":" << " "<< iResultX[i] << " " << iResultY[i]<< std::endl;
			printf("Case #%d: %d %d\r\n", i+1, iResultX[i], iResultY[i]);
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

