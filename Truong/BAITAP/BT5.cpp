#include "stdio.h"
#define byte char
#define word int
#include"dos.h"

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
}BS;


void docBS(BS &bs, char * path);
void xuatBS(BS bs);

int main()
{
	BS bs;
	docBS(bs,(char *) "vd.txt");
	xuatBS(bs);
	
	return 0;
}

void docBS(BS &bs, char * path)
{
	int i=0;
	char a;
	FILE *f = fopen(path, "rb");
	if(f==NULL)
		printf("\nLoi mo file!");
	else
	{
		fread(&bs.Ma, sizeof(bs.Ma), 1, f);
		while(!feof(f))
		{
			
			if(!feof(f))
			{
				if(i==0)
				{
					
				}
				else if(i==1)
				{
					
				}
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
			}
			fread(&bs.Ma, sizeof(bs.Ma), 1, f);			
		}
	
	}
}

void xuatBS(BS bs)
{
	
}
