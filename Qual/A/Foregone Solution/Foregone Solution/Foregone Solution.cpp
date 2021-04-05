// Foregone Solution.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h" 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
 
 int solve()
 {
	int iTC; 

//	fopen_s(&f, "c.txt", "r");
//	fopen_s(&fw, "result.txt", "w");

	scanf("%d\n", &iTC);


	for(int i = 0; i < iTC; i++)
	{
		int iN, iA, iB; 
		bool bFour;
		int iLen;

		char str[20];

		scanf("%d\n", &iN);

		iA = 0; iB = 0;


		sprintf(str, "%d",  iN);
		iLen = strlen(str);
			
		for(int j = 0; j< iLen -1; j++)
		{
			if(str[j] == '4')
			{
				iA = iA + pow(10.0, (int)(iLen - j -1));
			}		 
		}


		while(1)
		{
			iA++;
			iB = iN - iA;


			//A
			sprintf(str, "%d",  iA);
			 
			bFour = false;
			iLen = strlen(str);

			for(int j = 0; j< iLen; j++)
			{
				if(str[j] == '4')
					bFour = true;
			}
  
			if(bFour)
				continue;

			//B
			sprintf(str, "%d",  iB);
			 
			bFour = false;
			iLen = strlen(str);

			for(int j = 0; j< iLen; j++)
			{
				if(str[j] == '4')
					bFour = true;
			}
  
			if(bFour)
				continue;
			else
			{
				printf("Case #%d: %d %d\r\n", i+1, iA, iB);
				break;
			}
		} 
	} 
	return 0;
 }

int _tmain(int argc, _TCHAR* argv[])
{
	 

	solve();

	return 0;
}

