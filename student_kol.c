#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char _ime[20];
	char _prezime[20];
	char _br_indeksa[20];
}student;

int broj;
student stud;

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

while (1)
{
	printf ("unesi broj\n");
	scanf("%d",&broj);
	switch(broj)
	{
		case 1:  //unos studenta
			svi_studenti[i]=unos_studenta();
			++i;
			break;
		case 2: // pretraga po prezimenu
			printf("CASE 2\n");
			break;
		case 3: // ispis svih upisanih 
			for(k=0;k<i;k++)
			{
				printf("%d. student je  %s %s sa brojem indeksa %s\n",k+1,svi_studenti[k]._ime,svi_studenti[k]._prezime,svi_studenti[k]._br_indeksa);
			}
			break;
		case 4: // menjanje podataka studenta
			printf("CASE 4\n");
			break;
		case 5: //izlaz
			return 0;
		default:
		printf ("nisi uneo pravi broj\n");
	}
}
}
