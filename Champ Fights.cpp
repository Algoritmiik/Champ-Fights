#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	srand(time(NULL));
	int karaktersecim, i, damage=0, can1=1000, can2=1000, skillsecim1=0, skillsecim2=0, heal=0;
	char tekrarsecim;
	char karakterler[100][50]={"Garen","Lucian",};
	struct
	{
		int can=1500;
		int asilcan=1500;
		char skill1[500]="Garen ulu k�l�c�yla rakibin kafas�na darbe vurarak hasar verir (250-280 DMG)";
		char skill2[500]="Garen, sava� �evkiyle can de�erlerini bir miktar iyile�tirir(%40)\nNOT:�� turda bir kullan�labilir";
		char ulti[500]="Garen can� 200'den a�a��da olan rakiplerini Demacia ad�na an�nda infaz eder...YA�ASIN DEMAC�A!";
	} skillgaren;
	struct
	{
		int can=1300;
		int asilcan=1300;
		char skill1[500]="Lucian silahlar�yla hakimi oldu�u bir ���k h�zmesi �a��r�r ve bu ���k can�n� iyile�tirir(en fazla %15)";
		char skill2[500]="Lucian direkt bir sald�r� ile rakibine kan kusturur(300-350 DMG)";
		char ulti[500]="Lucian bir sonraki sald�r�dan hemen �nce bir ad�m kenara kayar ve sald�r�y� etkisiz k�lar. SIFIR HASAR ALIRSIN!\nNOT:�ki turda bir kullan�labilir";
	} skilllucian;
	printf("LoL Tactic Fights'a Ho�geldiniz\n");
	Sleep(1000);
	basla: printf("\nOynamak istedi�iniz karakterin numaras�n� se�iniz..\n1.%s\n2.%s\nNOT:Skill listesini ve kurallar� g�rmek istiyorsan�z 3'e bas�n�z\n\nSe�iminiz=",karakterler[0],karakterler[1]);
	scanf("%d",&karaktersecim);
	if(karaktersecim==3)
	{
		printf("\nY�CE KOMUTAN GAREN:\nCan:%d\n\n1.%s\n\n2.%s\n\n3.%s\n",skillgaren.can,skillgaren.skill1,skillgaren.skill2,skillgaren.ulti);
		Sleep(1000);
		printf("\nLucian'�n skilleri i�in 'ENTER' tu�una bas�n\n");
		getch();
		printf("\nULU S�LAH��R LUC�AN:\nCan:%d\n\n1.%s\n\n2.%s\n\n3.%s\n",skilllucian.can,skilllucian.skill1,skilllucian.skill2,skilllucian.ulti);
		Sleep(1000);
		printf("\nOYUNUN KURALLARI:\n1.Her turdan sonra canlar %%5 iyile�ir\n2.Bu oyunu oynuyorsan b�t�n arkada�lar�na bu oyunu anlatma ve oynatma sorumlulu�unu kabul etmi� olursun\n3.KAYBEDEN A�LAMAZ! ;)\n");
		printf("\nMen�ye d�nmek i�in i�in bir tu�a bas�n�z...\n");
		getch();
		goto basla;
	}
	else
	{
		if(karaktersecim==1)
		{
			printf("\nKarakteriniz:%s\n",karakterler[0]);
		}
		else
		{
			printf("\nKarakteriniz:%s\n",karakterler[1]);
		}
	}
	printf("\nSAVA� BA�LASIN!!\n");
	for(i=1;true;i++)
	{
		garensaldiri: printf("\nS�ra Garen'de!!\nSe�imini yap ��valye:");
		scanf("%d",&skillsecim1);
		Sleep(1000);
		if(skillsecim1==1)
		{
			damage=250+rand()%31;
		}
		else if(skillsecim1==2)
		{
			if(i%3==0)
			{
				heal=(skillgaren.can*40)/100;
				skillgaren.can+=heal;
				printf("\n%d kadar iyile�tin!\nGaren yeni can: %d\n",heal,skillgaren.can);
			}
			else
			{
				printf("\nBu skill bekleme s�resinde. Ba�ka bir skill kullan\n");
				goto garensaldiri;
			}
		}
		else if(skillsecim1==3)
		{
			if(skilllucian.can>200)
			{
				damage=200;
			}
			else
			{
				skilllucian.can=0;
				printf("\nTebrikler Garen... Onu alt ettin! K�l�c�n�n nam� binlerce y�l daha ya�ayacak.");
				printf("\nHasar=%d\nLucian yeni can=%d\n",damage,skilllucian.can);
				break;
			}
		}
		else
		{
			printf("\nGe�erli bir skill se�iniz...\n");
			goto garensaldiri;
		}
		if(skillsecim2==3)
		{
			printf("\nO DA NE !! LUC�AN SALDIRINDAN TEK ADIMLA KA�INDI ! NE HAREKET AMA...\n");
			damage=0;
		}
		skilllucian.can-=damage;
		printf("\nHasar=%d\nLucian yeni can=%d\n",damage,skilllucian.can);
		damage=0;
		Sleep(500);
		if(skilllucian.can<=0)
		{
			printf("\nTebrikler Garen... Onu alt ettin! K�l�c�n�n nam� binlerce y�l daha ya�ayacak.\n");
			break;
		}
		luciansaldiri: printf("\nS�ra Lucian'da!!\nSe�imini yap Silah��r:");
		scanf("%d",&skillsecim2);
		Sleep(1000);
		if(skillsecim2==1)
		{
			heal=(skilllucian.can*15)/100;
			skilllucian.can+=heal;
			printf("\n%d kadar iyile�tin!\nLucian yeni can: %d\n",heal,skilllucian.can);
		}
		else if(skillsecim2=2)
		{
			damage=300+rand()%51;
			skillgaren.can-=damage;
		}
		else if(skillsecim2==3)
		{
			if(i%2==0)
			{
				printf("\nBir sonraki hamleden ka��nd�n!");
			}
			else
			{
				printf("\nUltin bekleme s�resinde. Ba�ka bir skillini kullan");
				goto luciansaldiri;
			}
		}
		else
		{
			printf("\nGe�erli bir skill se�iniz...\n");
			goto luciansaldiri;
		}
		printf("\nHasar=%d\nGaren yeni can=%d\n",damage,skillgaren.can);
		damage=0;
		Sleep(1000);
		if(skillgaren.can<=0)
		{
			printf("\nTebrikler Lucian... Onu alt ettin! Silah�n�n nam� binlerce y�l daha ya�ayacak\n");
			break;
		}
		heal=(skilllucian.can*5)/100;
		skilllucian.can+=heal;
		heal=(skillgaren.can*5)/100;
		skillgaren.can+=heal;
		printf("\nBir sonraki turdan �nce iki �ampiyonun da can� %15 iyile�tiriliyor...\n");
		Sleep(1000);
		printf("\nYeni can listesi:\nGaren:%d\nLucian:%d\n\n%d. Tur BA�LASIN!\n",skillgaren.can,skilllucian.can,i+1);
		Sleep(1000);
	}
	printf("\nTekrar oynamak i�in ister misiniz? E/H\n");
	scanf(" %c",&tekrarsecim);
	if(tekrarsecim=='e')
	{
		skillgaren.can=skillgaren.asilcan;
		skilllucian.can=skilllucian.asilcan;
		goto basla;
	}
	else
	{
		printf("\nVaktiniz i�in te�ekk�r ederiz :)");
	}
}
