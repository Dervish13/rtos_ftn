#include <stdio.h>
#include <string.h>


int broj;
struct student a;
int while_broj=1;

struct student
{
	char _ime[20];
	char *_prezime;
	char *_br_indeksa;
};
struct student unos_studenta ()
{	

	char *ime;
	char *prezime="test";
	char *br_indeksa="test";
	printf("Unesi ime studenta\n");
	scanf("%s",ime);
	struct student a={ime,prezime,br_indeksa};
	return a;
}



int main ()
{
//	struct student a={"test","test","test"};

while (while_broj==1)
{
	printf ("unesi broj\n");
	scanf("%d",&broj);
	switch(broj)
	{
		case 1:  //unos studenta
			a=unos_studenta();
			printf("CASE 1\n");
			break;
		case 2: // pretraga po prezimenu
			printf("CASE 2\n");
			break;
		case 3: // ispis svih upisanih 
			printf("CASE 3\n");

			printf("%s\n",a._ime);
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
