#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  char poruka_servera[30] = "Dobrodosli na tcp digitron \n\n";

  // pravimo socket servera
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // adresa servera
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9494);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // vezi socket za IP i sin_port
  bind(server_socket, (struct sockaddr*)&server_address,
       sizeof(server_address));

  listen(server_socket, 5);

  int client_socket;
  client_socket=accept(server_socket,NULL,NULL);

  //posalji klijentu
  send(client_socket,poruka_servera, sizeof(poruka_servera),0);
  //zatvori socket
  close(server_socket);
  return 0;
}
