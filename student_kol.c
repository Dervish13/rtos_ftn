#include <stdio.h>
#include <string.h>

typedef struct
{
	char _ime[20];
	char _prezime[20];
	char _br_indeksa[20];
}student;

int broj;
student stud;
FILE* baza;

student unos_studenta ()
{	

	student a;
	char ime[20];
	char prezime[20];
	char br_indeksa[20];
	printf("Unesi ime studenta\n");
	scanf("%s",ime);

	printf("Unesi prezime studenta\n");
	scanf("%s",prezime);

	printf("Unesi broj indeksa studenta\n");
	scanf("%s",br_indeksa);

	strcpy(a._ime,ime);
	strcpy(a._prezime,prezime);
	strcpy(a._br_indeksa,br_indeksa);
	return a;
}

int main ()
{
student svi_studenti[500];
int i=0;
int k=0;
int redni_broj,opcija;
int duzina_prezimena;
char ime[20];
char prezime[20];
char br_indeksa[20];


baza=fopen("/tmp/baza","r");
if (baza!=NULL)
{
	while(EOF!=fscanf(baza,"%s %s %s\n",ime,prezime,br_indeksa))
	{

		strcpy(svi_studenti[i]._ime,ime);
		strcpy(svi_studenti[i]._prezime,prezime);
		strcpy(svi_studenti[i]._br_indeksa,br_indeksa);
		i++;
	}
}
printf("\n\nDobrodosli u vasu listu studenata\n");
while (1)
{
	printf ("\nOdaberite opciju\n");
	printf("1) Unesite novog studenta\n");
	printf("2) Pretraga studenata po prezimenu\n");
	printf("3) Ispis svih studenata\n");
	printf("4) Promena studenata\n");
	printf("5) Save & Exit\n\n");

	scanf("%d",&broj);
	switch(broj)
	{
		case 1:  //unos studenta
			svi_studenti[i]=unos_studenta();
			++i;
			break;
		case 2: // pretraga po prezimenu
				printf("\nUnesite prezime ili deo prezimena koji zelite da pronadjete\n");
				scanf("%s",prezime),	
				duzina_prezimena=strlen(prezime);
				printf ("\n Rezultat pretrade: \n");

				for (k=0;k<i;k++)
					{
						if (strncmp(prezime,svi_studenti[k]._prezime,duzina_prezimena)==0)
						{
							printf("%d. student je %s %s sa brojem indeksa %s\n",k+1,svi_studenti[k]._ime,svi_studenti[k]._prezime,svi_studenti[k]._br_indeksa);

						}





					}
			break;
		case 3: // ispis svih upisanih 
			for(k=0;k<i;k++)
			{
				printf("%d. student je  %s %s sa brojem indeksa %s\n",k+1,svi_studenti[k]._ime,svi_studenti[k]._prezime,svi_studenti[k]._br_indeksa);
			}
			break;
		case 4: // menjanje podataka studenta
			printf("\n Molim vas upisite redni broj studenta koga zelite da promenite\n");
			scanf("%d",&redni_broj);
			if (redni_broj>=i+1)
			{
				printf("\n Ne postoji student sa tim rednim brojem\n\n");
			}
			else
			{
				printf("\n Koji parametar zelite da promenite?\n\n");
				printf ("1) Ime studenta: %s\n",svi_studenti[redni_broj-1]._ime);
				printf ("2) Prezime studenta: %s\n",svi_studenti[redni_broj-1]._prezime);
				printf ("3) Broj indeksa studenta: %s\n",svi_studenti[redni_broj-1]._br_indeksa);
				printf ("4) Ne zelim promenu (povratak) \n\n");
				scanf("%d",&opcija);
				switch(opcija)
				{
				case 1:
					printf("Unesite novo ime studenta: ");
					scanf("%s",ime);
					strcpy(svi_studenti[redni_broj-1]._ime,ime);
					break;
				case 2:
					printf("Unesite novo prezime studenta: ");
					scanf("%s",prezime);
					strcpy(svi_studenti[redni_broj-1]._prezime,prezime);
					break;
				case 3:
					printf("Unesite novi broj indeksa studenta: ");
					scanf("%s",br_indeksa);
					strcpy(svi_studenti[redni_broj-1]._br_indeksa,br_indeksa);
					break;
				case 4:
					break;
				default:
				printf ("Ne postoji opcija\n");


				}
			}

			
			break;
		case 5: //izlaz
			baza=fopen("/tmp/baza","w");
			for(k=0;k<i;k++)
			{
				fprintf(baza,"%s %s %s\n",svi_studenti[k]._ime,svi_studenti[k]._prezime,svi_studenti[k]._br_indeksa);

			}
			fclose(baza);
			return 0;
		default:
		printf ("Ne postoji opcija koju ste odabrali\n Molim vas odaberite opciju sa liste\n");
	}
}


}
