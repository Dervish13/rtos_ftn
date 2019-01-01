#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 20

//check whether the symbol is operator?
int isOperator(char symbol) {
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/')
    {return 1;}
    return 0;
}

void ObrisiRazmake(char* niz)
{
  char* i = niz;
  char* j = niz;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

float izracunaj (char *racun,int velicina_jedn)
{
  char tmp1[10],tmp2[10],tmp3[10];
  int i=0;
  int k=0;
  char znak;
  float rez;
  while (isOperator(racun[i])!=1){
    tmp1[i]=racun[i];
    i++;

  }

  strcpy(tmp3,tmp1);
  znak=racun[i];
  while (i<=velicina_jedn){
  ++i;
  tmp2[k]=racun[i];
  k++;
  }

  if (znak=='+')
  { rez=(atof(tmp3)+atof(tmp2));
  return rez;
  }
  if (znak=='-')
  { rez=(atof(tmp3)-atof(tmp2));
  return rez;
  }
  if (znak=='*')
  { rez=(atof(tmp3)*atof(tmp2));
  return rez;
  }
  if (znak=='/')
  { rez=(atof(tmp3)/atof(tmp2));
  return rez;
  }
}
int main() {
  int server_socket; // pravimo socket servera
  float a;
  int velicina_jednacine;
  char jednacina[20]={0};

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  // adresa servera
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9494);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // vezi socket za IP i sin_port
  bind(server_socket, (struct sockaddr*)&server_address,
       sizeof(server_address));

  listen(server_socket, 1); // cekanje konekcije
  int client_socket1;
  client_socket1 = accept(server_socket, NULL, NULL);
  read(client_socket1, jednacina, sizeof(jednacina));
  ObrisiRazmake(jednacina);
  velicina_jednacine=(sizeof(jednacina)/sizeof(char));

  a=izracunaj(jednacina,velicina_jednacine);
  // posalji klijentu
  send(client_socket1, &a, sizeof(a), 0);
  // zatvori socket
  close(server_socket);
  return 0;
}
