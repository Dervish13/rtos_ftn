#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
int znak (char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    return 1;
  }
  return 0;
}


float racun( char* jednacina)
{


}
int main() {
  /* char poruka_servera[30] = "Dobrodosli na tcp digitron \n\n"; */

  // pravimo socket servera
  int server_socket;
  char jednacina[20] = {0};
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // adresa servera
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9494);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // vezi socket za IP i sin_port
  bind(server_socket, (struct sockaddr*)&server_address,
       sizeof(server_address));

  listen(server_socket, 1);
  int client_socket1, client_socket2, client_socket3, client_socket4,
      client_socket5;
  client_socket1 = accept(server_socket, NULL, NULL);
  /* client_socket2 = accept(server_socket, NULL, NULL); */
  /* client_socket3 = accept(server_socket, NULL, NULL); */
  /* client_socket4 = accept(server_socket, NULL, NULL); */
  /* client_socket5 = accept(server_socket, NULL, NULL); */
  read(client_socket1, jednacina, sizeof(jednacina));
  printf("%s", jednacina);
  float a = 33;
  // posalji klijentu
  send(client_socket1, &a, sizeof(float), 0);
  // zatvori socket
  /* send(client_socket2, poruka_servera, sizeof(poruka_servera), 0); */
  /* // zatvori socket */
  /* send(client_socket3, poruka_servera, sizeof(poruka_servera), 0); */
  /* // zatvori socket */
  /* send(client_socket4, poruka_servera, sizeof(poruka_servera), 0); */
  /* // zatvori socket */
  /* send(client_socket5, poruka_servera, sizeof(poruka_servera), 0); */
  /* // zatvori socket */
  close(server_socket);
  return 0;
}
