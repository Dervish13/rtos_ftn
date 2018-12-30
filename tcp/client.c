#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // napravi socket
  int network_socket;

  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9494);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int status_konekcije =
      connect(network_socket, (struct sockaddr*)&server_address,
              sizeof(server_address));

  // provera konekcije

  if (status_konekcije == -1) {
    fprintf(stderr, " Greska u konekciji sa serverom\n\n");
  }

  // dobiti od servera
  char odgovor_servera[40];

  recv(network_socket, &odgovor_servera, sizeof(odgovor_servera), 0);

  printf(" Server je rekao: %s\n", odgovor_servera);

  close(network_socket);
  return 0;
}
