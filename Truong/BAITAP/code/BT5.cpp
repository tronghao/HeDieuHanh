#include "stdio.h"
#include "math.h"
#include "conio.h"
#define byte char

typedef struct PhanTuBS
{
	byte value;
	int flag=0;
}PTBS;

typedef struct BootSector
{
	PTBS Ma[3];
	PTBS Version[8];
	PTBS BytePerSector[2];
	PTBS SectorPerCluster[1];
	PTBS ReservedSector[2];
	PTBS FatNum[1];
	PTBS RootEntry[2];
	PTBS Sum_Sector[2];
	PTBS MediaDescriptor[1];
	PTBS SectorPerFat[2];
	PTBS SectorPerTrack[2];
	PTBS HeadPerDisk[2];
	PTBS HiddenSector[4];
	PTBS SumSector[4];
	PTBS PhysicDisk[1];
	PTBS Danhrieng[1];
	PTBS KiHieuNhanDien[1];
	PTBS SerialNumber[4];
	PTBS VolumeLabel[11];
	PTBS FATID[8];
	PTBS Rest[450];
}BS;


void docBS(BS &bs, char * path, int &soPhanTu,int &soByte);
void xuatBS(BS bs, int soPhanTu, int soByte);
void thongTinBS(BS bs, int soPhanTu, int soByte);

//--ham phu--
int hexToDec(char a[], int n);
int hexToDec_1char(char a);
void doc1PhanTu_BS(PTBS a[], int soPhanTu,FILE *f, int &n);
void xuat1PhanTu_BS(PTBS a[], int soPhanTu, int &n, int soByte);
void xuatNguoc1PT_BS(PTBS a[], int soPhanTu);
void decToHex_2char(int a, char kq[]);
char decToHex_1char(int a);


int main()
{
	int soPhanTu=0, soByte=0;
	BS bs; 
	docBS(bs,(char *) "vd.txt", soPhanTu, soByte);
	xuatBS(bs, soPhanTu, soByte);
	thongTinBS(bs, soPhanTu, soByte);
	
	getch();
	return 0;
}

void docBS(BS &bs, char * path, int &soPhanTu,int &soByte)
{	
	char giaTriRac;
	int n = 0; 
	int i=0;
	FILE *f = fopen(path, "rb");
	if(f==NULL)
		printf("\nLoi mo file!");
	else
	{
		while(!feof(f))
		{
			switch(i)
			{
				case 0:
					doc1PhanTu_BS(bs.Ma, 3, f, n);
					break;
				case 1: 
					doc1PhanTu_BS(bs.Version,8,f, n);
					break;
				case 2:
					doc1PhanTu_BS(bs.BytePerSector, 2, f, n);
					break;
				case 3: 
					doc1PhanTu_BS(bs.SectorPerCluster,1,f, n);
					break;
				case 4:
					doc1PhanTu_BS(bs.ReservedSector, 2, f, n);
					break;
				case 5: 
					doc1PhanTu_BS(bs.FatNum,1,f, n);
					break;
				case 6:
					doc1PhanTu_BS(bs.RootEntry, 2, f, n);
					break;
				case 7: 
					doc1PhanTu_BS(bs.Sum_Sector,2,f, n);
					break;
				case 8:
					doc1PhanTu_BS(bs.MediaDescriptor, 1, f, n);
					break;
				case 9: 
					doc1PhanTu_BS(bs.SectorPerFat,2,f, n);
					break;
				case 10:
					doc1PhanTu_BS(bs.SectorPerTrack, 2, f, n);
					break;
				case 11: 
					doc1PhanTu_BS(bs.HeadPerDisk,2,f, n);
					break;
				case 12:
					doc1PhanTu_BS(bs.HiddenSector, 4, f, n);
					break;
				case 13: 
					doc1PhanTu_BS(bs.SumSector,4,f, n);
					break;
				case 14:
					doc1PhanTu_BS(bs.PhysicDisk, 1, f, n);
					break;
				case 15: 
					doc1PhanTu_BS(bs.Danhrieng,1,f, n);
					break;
				case 16: 
					doc1PhanTu_BS(bs.KiHieuNhanDien,1,f, n);
					break;
				case 17:
					doc1PhanTu_BS(bs.SerialNumber, 4, f, n);
					break;
				case 18: 
					doc1PhanTu_BS(bs.VolumeLabel,11,f, n);
					break;
				case 19:
					doc1PhanTu_BS(bs.FATID, 8, f, n);
					break;
				case 20: 
					doc1PhanTu_BS(bs.Rest,450,f, n);
					break;
			}				
			i++;
		}
	
	}
	soPhanTu = i;
	soByte = n;
}

void xuatBS(BS bs, int soPhanTu, int soByte)
{
	int n=0;
	printf("Bootsector:\n");
	for(int i=0; i<16; i++)
	{
		printf("   %c", decToHex_1char(i));
	}
	printf("\n");
	for(int i=0; i<soPhanTu; i++)
	{
		switch(i)
		{
			case 0: 
				xuat1PhanTu_BS(bs.Ma, 3, n, soByte);
				break;
			case 1:
				xuat1PhanTu_BS(bs.Version, 8, n, soByte);
				break;
			case 2:
				xuat1PhanTu_BS(bs.BytePerSector, 2, n, soByte);
				break;
			case 3: 
				xuat1PhanTu_BS(bs.SectorPerCluster,1, n, soByte);
				break;
			case 4:
				xuat1PhanTu_BS(bs.ReservedSector, 2, n, soByte);
				break;
			case 5: 
				xuat1PhanTu_BS(bs.FatNum,1, n, soByte);
				break;
			case 6:
				xuat1PhanTu_BS(bs.RootEntry, 2, n, soByte);
				break;
			case 7: 
				xuat1PhanTu_BS(bs.Sum_Sector,2, n, soByte);
				break;
			case 8:
				xuat1PhanTu_BS(bs.MediaDescriptor, 1, n, soByte);
				break;
			case 9: 
				xuat1PhanTu_BS(bs.SectorPerFat,2, n, soByte);
				break;
			case 10:
				xuat1PhanTu_BS(bs.SectorPerTrack, 2, n, soByte);
				break;
			case 11: 
				xuat1PhanTu_BS(bs.HeadPerDisk,2, n, soByte);
				break;
			case 12:
				xuat1PhanTu_BS(bs.HiddenSector, 4, n, soByte);
				break;
			case 13: 
				xuat1PhanTu_BS(bs.SumSector,4, n, soByte);
				break;
			case 14:
				xuat1PhanTu_BS(bs.PhysicDisk, 1, n, soByte);
				break;
			case 15: 
				xuat1PhanTu_BS(bs.Danhrieng,1, n, soByte);
				break;
			case 16: 
				xuat1PhanTu_BS(bs.KiHieuNhanDien,1, n, soByte);
				break;
			case 17:
				xuat1PhanTu_BS(bs.SerialNumber, 4, n, soByte);
				break;
			case 18: 
				xuat1PhanTu_BS(bs.VolumeLabel,11, n, soByte);
				break;
			case 19:
				xuat1PhanTu_BS(bs.FATID, 8, n, soByte);
				break;
			case 20: 
				xuat1PhanTu_BS(bs.Rest,450, n, soByte);
				break;
		}
	}
}

void thongTinBS(BS bs, int soPhanTu, int soByte)
{
	int n=0;
	char kq[2];
	int sum = 0;
	printf("\nThong Tin Tren Bootsector: ");
	for(int i=0; i < soPhanTu; i++)
	{
		switch(i)
		{
			case 0: 
				printf("\n\t-Ma Boot:                             <3 byte tai 0h> = ");
				xuat1PhanTu_BS(bs.Ma, 3, n, soByte);
				break;
			case 1:
				printf("\n\t-Ten congty/Version he dieu hanh:     <8 byte tai 3h> = ");
				for(int i=0; i<8; i++)
				{
					printf("%c", bs.Version[i].value);
				}
				break;
			case 2:
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.BytePerSector[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.BytePerSector[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.BytePerSector[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.BytePerSector[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				printf("\n\t-So byte cua sector:                  <2 byte tai Bh> = ");
				xuatNguoc1PT_BS(bs.BytePerSector, 2);
				printf("h = %dd", sum);
				break;
			case 3: 
				sum=0;
				switch(bs.SectorPerCluster[0].flag)
				{
					case 0:
						decToHex_2char((int)bs.SectorPerCluster[0].value, kq);					
						break;
					case 1:
						decToHex_2char(((int)bs.SectorPerCluster[0].value+127), kq);
						break;
					case 2:
						decToHex_2char(((int)bs.SectorPerCluster[0].value + 128), kq);
						break;
				}
				sum = hexToDec(kq, 2);
				printf("\n\t-So sector cua cluster:          SC = <1 byte tai Dh> = ");
				xuatNguoc1PT_BS(bs.SectorPerCluster, 1);
				printf("h = %dd", sum);
				break;
			case 4:
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.ReservedSector[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.ReservedSector[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.ReservedSector[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.ReservedSector[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				printf("\n\t-So sector truoc bang FAT:       SB = <2 byte tai Eh> = ");
				xuatNguoc1PT_BS(bs.ReservedSector, 2);
				printf("h = %dd", sum);
				break;
			case 5: 
				sum=0;
				switch(bs.FatNum[0].flag)
				{
					case 0:
						decToHex_2char((int)bs.FatNum[0].value, kq);					
						break;
					case 1:
						decToHex_2char(((int)bs.FatNum[0].value+127), kq);
						break;
					case 2:
						decToHex_2char(((int)bs.FatNum[0].value + 128), kq);
						break;
				}
				sum = hexToDec(kq, 2);
				printf("\n\t-So luong bang FAT:              NF = <1 byte tai 10h> = ");
				xuatNguoc1PT_BS(bs.FatNum, 1);
				printf("h = %dd", sum);
				break;
			case 6:
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.RootEntry[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.RootEntry[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.RootEntry[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.RootEntry[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				printf("\n\t-So entry cua RDET:              SR = <2 byte tai 11h> = ");
				xuatNguoc1PT_BS(bs.RootEntry, 2);
				printf("h = %dd", sum);
				break;
			case 7: 
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.Sum_Sector[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.Sum_Sector[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.Sum_Sector[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.Sum_Sector[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				if(sum>0)
				{
					printf("\n\t-So sector cua VOL:              SV = <2 byte tai 13h> = ");
					xuatNguoc1PT_BS(bs.RootEntry, 2);
					printf("h = %dd", sum);	
				}
				else 
				{
					sum=0;
					for(int i=3; i>=0; i--)
					{
						switch(bs.SumSector[i].flag)
						{
							case 0:
								decToHex_2char((int)bs.SumSector[i].value, kq);
							
								break;
							case 1:
								decToHex_2char(((int)bs.SumSector[i].value+127), kq);
								break;
							case 2:
								decToHex_2char(((int)bs.SumSector[i].value + 128), kq);
								break;
						}
						if(i==3)
						{
							sum += hexToDec_1char(kq[0]) * pow(16,i+4);
							sum += hexToDec_1char(kq[1]) * pow(16,i+3);
						}
						else if(i==2)
						{
							sum += hexToDec_1char(kq[0]) * pow(16,i+3);
							sum += hexToDec_1char(kq[1]) * pow(16,i+2);
						}
						else if(i==1)
						{
							sum += hexToDec_1char(kq[0]) * pow(16,i+2);
							sum += hexToDec_1char(kq[1]) * pow(16,i+1);
						}
						else
						{
							sum += hexToDec_1char(kq[0]) * pow(16,i+1);
							sum += hexToDec_1char(kq[1]) * pow(16,i);
						}
					}
					printf("\n\t-Kich thuoc cua VOL:             SV = <4 byte tai 20h> = ");
					xuatNguoc1PT_BS(bs.RootEntry, 4);
					printf("h = %dd  (13h = 0)", sum);
				}
				break;/*
			case 8:
				
				break;*/
			case 9: 
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.SectorPerFat[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.SectorPerFat[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.SectorPerFat[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.SectorPerFat[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				printf("\n\t-So sector cua FAT:              SF = <2 byte tai 16h> = ");
				xuatNguoc1PT_BS(bs.SectorPerFat, 2);
				printf("h = %dd", sum);
				break;
			case 10:
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.SectorPerTrack[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.SectorPerTrack[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.SectorPerTrack[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.SectorPerTrack[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				printf("\n\t-So sector cua track:                 <2 byte tai 18h> = ");
				xuatNguoc1PT_BS(bs.SectorPerTrack, 2);
				printf("h = %dd", sum);
				break;
			case 11: 
				sum=0;
				for(int i=1; i>=0; i--)
				{
					switch(bs.HeadPerDisk[i].flag)
					{
						case 0:
							decToHex_2char((int)bs.HeadPerDisk[i].value, kq);
						
							break;
						case 1:
							decToHex_2char(((int)bs.HeadPerDisk[i].value+127), kq);
							break;
						case 2:
							decToHex_2char(((int)bs.HeadPerDisk[i].value + 128), kq);
							break;
					}
					if(i==1)
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+2);
						sum += hexToDec_1char(kq[1]) * pow(16,i+1);
					}
					else
					{
						sum += hexToDec_1char(kq[0]) * pow(16,i+1);
						sum += hexToDec_1char(kq[1]) * pow(16,i);
					}
				}
				printf("\n\t-So luong dau doc:                    <2 byte tai 1Ah> = ");
				xuatNguoc1PT_BS(bs.HeadPerDisk, 2);
				printf("h = %dd", sum);
				break;/*
			case 12:
				xuat1PhanTu_BS(bs.HiddenSector, 4, n, soByte);
				break;
			case 13: 
				xuat1PhanTu_BS(bs.SumSector,4, n, soByte);
				break;*/
			case 14:
				sum=0;
				switch(bs.PhysicDisk[0].flag)
				{
					case 0:
						decToHex_2char((int)bs.PhysicDisk[0].value, kq);					
						break;
					case 1:
						decToHex_2char(((int)bs.PhysicDisk[0].value+127), kq);
						break;
					case 2:
						decToHex_2char(((int)bs.PhysicDisk[0].value + 128), kq);
						break;
				}
				if(kq[0] == '8' && kq[1] == '0')
					sum=1;
				printf("\n\t-Ki hieu vat ly cua dia:              <1 byte tai 24h> = ");
				xuatNguoc1PT_BS(bs.PhysicDisk, 1);
				printf("h");
				if(sum==0) printf("  (Dia Mem)");
				else printf("  (Dia Cung)");
				break;/*
			case 16: 
				xuat1PhanTu_BS(bs.KiHieuNhanDien,1, n, soByte);
				break;*/
			case 17:
				printf("\n\t-Volume Lable:                        <B byte tai 2Bh> = ");
				for(int i=0; i<11; i++)
				{
					printf("%c", bs.VolumeLabel[i].value);
				}
				break;
			case 18: 
				printf("\n\t-Loai FAT:                            <8 byte tai 36h> = ");
				for(int i=0; i<8; i++)
				{
					printf("%c", bs.FATID[i].value);
				}
				break;/*
			case 19:
				xuat1PhanTu_BS(bs.FATID, 8, n, soByte);
				break;
			case 20: 
				xuat1PhanTu_BS(bs.Rest,450, n, soByte);
				break;*/
		}
	}
}










//--ham phu--
int hexToDec(char a[], int n)
{
	int sum = 0;
	for(int i=n; i>0; i--)
	{
		sum += (pow(16,i-1) * hexToDec_1char(a[n-i]));
	}
	return sum;
}

int hexToDec_1char(char a)
{
	switch(a)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
	}
}

void doc1PhanTu_BS(PTBS a[], int soPhanTu,FILE *f, int &n)
{
	int giaTriDec;
	char tam[2], giaTriRac;
	for(int i=0; i<soPhanTu; i++)
	{
		if(feof(f)) break;
		n++;
		
		fread(&tam, 2, 1, f);
		giaTriDec = hexToDec(tam,2);
		if(giaTriDec <= 127)
		{
			a[i].value = (char)giaTriDec;
		}
		else if(giaTriDec == 255)
		{
			a[i].value = (char)(giaTriDec-128);
			a[i].flag=2;
		}
		else
		{
			a[i].value = (char)(giaTriDec-127);
			a[i].flag=1;
		}
		fread(&giaTriRac, 1, 1, f);	
		
	}
}

void xuat1PhanTu_BS(PTBS a[], int soPhanTu, int &n, int soByte)
{
	char kq[2];
	for(int i=0; i<soPhanTu; i++)
	{
		n++;
		if(n>soByte) break;
		
		
		if(a[i].flag==0)
		{
			decToHex_2char((int)a[i].value, kq);
			printf("  %c%c", kq[0], kq[1]);
		}
		else if(a[i].flag == 1)
		{
			decToHex_2char(((int)a[i].value+127), kq);
			printf("  %c%c", kq[0], kq[1]);
		}
		else
		{
			decToHex_2char(((int)a[i].value+128), kq);
			printf("  %c%c", kq[0], kq[1]);
		}	
		if(n%16 == 0) printf("\n");
	}	
}

void xuatNguoc1PT_BS(PTBS a[], int soPhanTu)
{
	char kq[2];
	for(int i=soPhanTu-1; i>=0; i--)
	{	
		if(a[i].flag==0)
		{
			decToHex_2char((int)a[i].value, kq);
			printf("%c%c", kq[0], kq[1]);
		}
		else if(a[i].flag == 1)
		{
			decToHex_2char(((int)a[i].value+127), kq);
			printf("%c%c", kq[0], kq[1]);
		}
		else
		{
			decToHex_2char(((int)a[i].value+128), kq);
			printf("%c%c", kq[0], kq[1]);
		}	
	}
}

void decToHex_2char(int a, char kq[])
{
	kq[0] = decToHex_1char(a / 16);
	kq[1] = decToHex_1char(a - 16 * (a/16));
}

char decToHex_1char(int a)
{
	switch(a)
	{
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
	}
}
