// Fair Fight.cpp : Defines the entry point for the console application.
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

	int iResult[100];
	
	for(int i = 0; i < iTC; i++)
	{
		int C[100000];
		int D[100000];
		int N;
		int K;
		std::cin >> N >> K;

		for(int j = 0; j < N; j++)
		{
			std::cin >> C[j];
		}
		for(int j = 0; j < N; j++)
		{
			std::cin >> D[j];
		}

		int iMatch = 0;

		int iMatchCase = 0;
		 
		for(int j = 0; j < N; j++)
		{ 
			
			int iMaxC = 0;
			int iMaxD = 0;
			for(int m = j ; m < N; m++)
			{  
                   if( C[m] > iMaxC)
					   iMaxC = C[m];
	
                  if( D[m] > iMaxD)
					   iMaxD = D[m];
	

					if(iMaxC >= iMaxD)
					{
						if( (iMaxC -  iMaxD) <= K)
						{
							iMatch++;
							 
						}
					}
					else
					{

						if( (iMaxD -  iMaxC) <= K)
						{
							iMatch++;
							 
						}
					} 
			}
		}

		iResult[i] = iMatch; 
		 


	}

		for(int i = 0; i < iTC; i++)
	{
		printf("Case #%d: %d\r\n", i+1, iResult[i]);
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

