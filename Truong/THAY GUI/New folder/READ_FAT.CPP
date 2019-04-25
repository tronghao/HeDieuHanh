#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void ChuanHoa(char* s)
{
	int len = strlen(s);
	for (int i=0; i<len; i++)
		s[i] = toupper(s[i]);
	for (int j=len; j<8; j++)
		s[j] = ' ';
}

int GetFatValue(int k, unsigned char* Fat)
{
	int i = (k*3)/2;
	int nHi = Fat[i+1];
	int nLo = Fat[i];

	if (k%2 == 0) return (nLo | ((nHi & 0xF) << 8));
	else return ((nHi << 4) | (nLo >> 4));
}

void HienThi(int sector)
{
	BYTE buf[513];
	if (absread(1,1,sector,buf) != 0)
	{
		printf("loi doc sector %d",sector);
		getch();
		exit(0);
	}
	buf[512]='\0';
	printf("%s",buf);
}

void main()
{
	clrscr();
	char s[256];
	printf("Nhap ten tap tin: ");
	//gets(s);
	scanf("%s",s);
	ChuanHoa(s);
	ENTRY RDET[224];
	BYTE FAT[9*512];
	if (absread(1,14,19,RDET) != 0)
	{
		printf("loi doc RDET");
		getch();
		exit(0);
	}
	if (absread(1,9,1,FAT) != 0)
	{
		printf("loi doc FAT");
		getch();
		exit(0);
	}
	for (int i=0; i<224; i++)
	{
		if (strncmp(s,RDET[i].FileName,8) == 0)
		{
			printf("Ten tap tin tim duoc: ");
			for (int j=0; j<8; j++)
				printf("%c",RDET[i].FileName[j]);
			printf(".");
			for (int k=0; k<3; k++)
				printf("%c",RDET[i].FileExt[k]);
			printf("\n");

			printf("Cac phan tu FAT: ");
			int cluster = RDET[i].FirstCluster;
			while (cluster != 0xFFF)
			{
				printf("%d ",cluster);
				cluster = GetFatValue(cluster,FAT);
			}

			printf("\nNoi dung cua tap tin: \n");
			cluster = RDET[i].FirstCluster;
			while (cluster != 0xFFF)
			{
				getch();
				HienThi(cluster+31);
				cluster = GetFatValue(cluster,FAT);
			}
		}
	}

	printf("\nNhan phim bat ky de thoat ...");
	getch();
}