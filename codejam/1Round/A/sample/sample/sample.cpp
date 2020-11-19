// sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
 
 

void ff()
{
	fflush(stdout);
}

int n, m;

int wek{16, 9, 5, 7, 11, 13, 17};

void test()
{
	int mod=1;
	int w=0;
	for (int i : wek)
	{
		for (int j=1; j<=18; j++)
			printf("%d ", i);
		printf("\n");
		ff();
		int x=0;
		for (int j=1; j<=18; j++)
		{
			int y;
			scanf("%d", &y);
			x=(x+y)%i;
		}
		while((w%i)!=x)
			w+=mod;
		mod*=i;
	}
	printf("%d\n", w);
	ff();
	int x;
	scanf("%d", &x);
	assert(x==1);
}
 
int _tmain(int argc, _TCHAR* argv[])
{ 
  	int t;
	scanf("%d%d%d", &t, &n, &m);
	for (int i=1; i<=t; i++)
		test(); 
	return 0;
}
 