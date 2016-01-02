#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
  //create a socket
  int network_socket; //socket descriptor
  network_socket = socket(AF_INET,SOCK_STREAM,0);

  //specify an address for the socket
  struct sockaddr_in server_address; //struct type is defined in socket.h
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9077);
  server_address.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY means localhost

  //calling the connect function
  int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  //check for the error with the connection
  if (connection_status == -1) {
    printf("Error connecting to source. \n");
  }

  //receive the data
  char server_response[254];
  recv(network_socket, &server_response, sizeof(server_response), 0);

  //print out the server's response
  printf("The server sentthe data %s\n", server_response );

  //close the socket
  close(socket);


  return 0;
}
