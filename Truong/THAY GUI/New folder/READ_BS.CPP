#include <stdio.h>
#include <conio.h>
#include "dos.h"
#include "stdlib.h"
#include "windows.h"

#define byte unsigned char
#define word unsigned int
#define long unsigned long

typedef struct BootSector
{
	byte Ma[3];
	byte Version[8];
	word BytePerSector;
	byte SectorPerCluster;
	word ReservedSector;
	byte FatNum;
	word RootEntry;
	word Sum_Sector;
	byte MediaDescriptor;
	word SectorPerFat;
	word SectorPerTrack;
	word HeadPerDisk;
	long HiddenSector;
	long SumSector;
	byte PhysicDisk;
	byte Danhrieng;
	byte KiHieuNhanDien;
	byte SerialNumber[4];
	byte VolumeLabel[11];
	byte FATID[8];
	byte Rest[450];
};

int main()
{
	system("cls");
	BootSector bs;
	if (absread(0,1,0,&bs) != 0)
	{
		printf("Loi doc dia");
		getch();
		exit(0);
	}
	printf("Bang tham so dia :");
	printf("\nVersion: ");
	for (int i=0; i<8; i++)
		printf("%c",bs.Version[i]);
	printf("\nSo byte cua sector = %d",bs.BytePerSector);
	printf("\nSo sector cua cluster = %d",bs.SectorPerCluster);
	getch();
	return 0;

}
