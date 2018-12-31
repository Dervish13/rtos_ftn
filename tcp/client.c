#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // napravi socket
  int network_socket;
  char jednacina[20];
  char odgovor_servera[20];

  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9494);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int status_konekcije =
      connect(network_socket, (struct sockaddr *)&server_address,
              sizeof(server_address));

  // provera konekcije

  if (status_konekcije == -1) {
    fprintf(stderr, " Greska u konekciji sa serverom\n\n");
    return 1;
  }
  printf(" Posaljite jednacinu za vas TCP digitron\n");
  scanf("%s", jednacina);

  send(network_socket, jednacina, strlen(jednacina), 0);
  printf("Izracunavanje u procesu... \n");
  float resenje;
  // dobiti od servera
  recv(network_socket, &resenje, sizeof(float),0);
  snprintf(odgovor_servera,20,"%.2f",resenje);
  printf(" Server je rekao: %s\n",odgovor_servera);

  close(network_socket);
  return 0;
}
