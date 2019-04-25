#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

typedef unsigned char BYTE;
typedef unsigned int WORD;
typedef unsigned long DWORD;

typedef struct ENTRY
{
	BYTE FileName[8];
	BYTE FileExt[3];
	BYTE Attrib;
	BYTE Reserved[10];
	WORD Time;
	WORD Date;
	WORD FirstCluster;
	DWORD FileSize;
};

void main()
{
	clrscr();
	ENTRY RDET[224];
	if (absread(0,14,19,RDET) != 0)
	{
		printf("loi doc sector");
		getch();
		exit(0);
	}
	for (int i=0; i<224; i++)
	{
		if ((RDET[i].FileName[0] != 0) &&
		(RDET[i].FileName[0] != 0xE5))
		{
			for (int j=0; j<8; j++)
				printf("%c",RDET[i].FileName[j]);
			printf(".");
			for (int k=0; k<3; k++)
				printf("%c",RDET[i].FileExt[k]);
			printf("\n");
		}
	}

	getch();
}