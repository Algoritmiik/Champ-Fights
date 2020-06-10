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
		char skill1[500]="Garen ulu kýlýcýyla rakibin kafasýna darbe vurarak hasar verir (250-280 DMG)";
		char skill2[500]="Garen, savaþ þevkiyle can deðerlerini bir miktar iyileþtirir(%40)\nNOT:Üç turda bir kullanýlabilir";
		char ulti[500]="Garen caný 200'den aþaðýda olan rakiplerini Demacia adýna anýnda infaz eder...YAÞASIN DEMACÝA!";
	} skillgaren;
	struct
	{
		int can=1300;
		int asilcan=1300;
		char skill1[500]="Lucian silahlarýyla hakimi olduðu bir ýþýk hüzmesi çaðýrýr ve bu ýþýk canýný iyileþtirir(en fazla %15)";
		char skill2[500]="Lucian direkt bir saldýrý ile rakibine kan kusturur(300-350 DMG)";
		char ulti[500]="Lucian bir sonraki saldýrýdan hemen önce bir adým kenara kayar ve saldýrýyý etkisiz kýlar. SIFIR HASAR ALIRSIN!\nNOT:Ýki turda bir kullanýlabilir";
	} skilllucian;
	printf("LoL Tactic Fights'a Hoþgeldiniz\n");
	Sleep(1000);
	basla: printf("\nOynamak istediðiniz karakterin numarasýný seçiniz..\n1.%s\n2.%s\nNOT:Skill listesini ve kurallarý görmek istiyorsanýz 3'e basýnýz\n\nSeçiminiz=",karakterler[0],karakterler[1]);
	scanf("%d",&karaktersecim);
	if(karaktersecim==3)
	{
		printf("\nYÜCE KOMUTAN GAREN:\nCan:%d\n\n1.%s\n\n2.%s\n\n3.%s\n",skillgaren.can,skillgaren.skill1,skillgaren.skill2,skillgaren.ulti);
		Sleep(1000);
		printf("\nLucian'ýn skilleri için 'ENTER' tuþuna basýn\n");
		getch();
		printf("\nULU SÝLAHÞÖR LUCÝAN:\nCan:%d\n\n1.%s\n\n2.%s\n\n3.%s\n",skilllucian.can,skilllucian.skill1,skilllucian.skill2,skilllucian.ulti);
		Sleep(1000);
		printf("\nOYUNUN KURALLARI:\n1.Her turdan sonra canlar %%5 iyileþir\n2.Bu oyunu oynuyorsan bütün arkadaþlarýna bu oyunu anlatma ve oynatma sorumluluðunu kabul etmiþ olursun\n3.KAYBEDEN AÐLAMAZ! ;)\n");
		printf("\nMenüye dönmek için için bir tuþa basýnýz...\n");
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
	printf("\nSAVAÞ BAÞLASIN!!\n");
	for(i=1;true;i++)
	{
		garensaldiri: printf("\nSýra Garen'de!!\nSeçimini yap Þövalye:");
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
				printf("\n%d kadar iyileþtin!\nGaren yeni can: %d\n",heal,skillgaren.can);
			}
			else
			{
				printf("\nBu skill bekleme süresinde. Baþka bir skill kullan\n");
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
				printf("\nTebrikler Garen... Onu alt ettin! Kýlýcýnýn namý binlerce yýl daha yaþayacak.");
				printf("\nHasar=%d\nLucian yeni can=%d\n",damage,skilllucian.can);
				break;
			}
		}
		else
		{
			printf("\nGeçerli bir skill seçiniz...\n");
			goto garensaldiri;
		}
		if(skillsecim2==3)
		{
			printf("\nO DA NE !! LUCÝAN SALDIRINDAN TEK ADIMLA KAÇINDI ! NE HAREKET AMA...\n");
			damage=0;
		}
		skilllucian.can-=damage;
		printf("\nHasar=%d\nLucian yeni can=%d\n",damage,skilllucian.can);
		damage=0;
		Sleep(500);
		if(skilllucian.can<=0)
		{
			printf("\nTebrikler Garen... Onu alt ettin! Kýlýcýnýn namý binlerce yýl daha yaþayacak.\n");
			break;
		}
		luciansaldiri: printf("\nSýra Lucian'da!!\nSeçimini yap Silahþör:");
		scanf("%d",&skillsecim2);
		Sleep(1000);
		if(skillsecim2==1)
		{
			heal=(skilllucian.can*15)/100;
			skilllucian.can+=heal;
			printf("\n%d kadar iyileþtin!\nLucian yeni can: %d\n",heal,skilllucian.can);
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
				printf("\nBir sonraki hamleden kaçýndýn!");
			}
			else
			{
				printf("\nUltin bekleme süresinde. Baþka bir skillini kullan");
				goto luciansaldiri;
			}
		}
		else
		{
			printf("\nGeçerli bir skill seçiniz...\n");
			goto luciansaldiri;
		}
		printf("\nHasar=%d\nGaren yeni can=%d\n",damage,skillgaren.can);
		damage=0;
		Sleep(1000);
		if(skillgaren.can<=0)
		{
			printf("\nTebrikler Lucian... Onu alt ettin! Silahýnýn namý binlerce yýl daha yaþayacak\n");
			break;
		}
		heal=(skilllucian.can*5)/100;
		skilllucian.can+=heal;
		heal=(skillgaren.can*5)/100;
		skillgaren.can+=heal;
		printf("\nBir sonraki turdan önce iki þampiyonun da caný %15 iyileþtiriliyor...\n");
		Sleep(1000);
		printf("\nYeni can listesi:\nGaren:%d\nLucian:%d\n\n%d. Tur BAÞLASIN!\n",skillgaren.can,skilllucian.can,i+1);
		Sleep(1000);
	}
	printf("\nTekrar oynamak için ister misiniz? E/H\n");
	scanf(" %c",&tekrarsecim);
	if(tekrarsecim=='e')
	{
		skillgaren.can=skillgaren.asilcan;
		skilllucian.can=skilllucian.asilcan;
		goto basla;
	}
	else
	{
		printf("\nVaktiniz için teþekkür ederiz :)");
	}
}
