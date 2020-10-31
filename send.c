#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
  int socket_fd;
  struct sockaddr_in serv;
  char buffer[256];
  int i;

  //Link to the socket
  socket_fd = socket(AF_INET,SOCK_STREAM,0);

  serv.sin_family=AF_INET;

  inet_aton(argv[1],&(serv.sin_addr));
  serv.sin_port=htons(2006);

  i = connect(socket_fd,(struct sockaddr *)&serv, sizeof(serv));

  while(1)
    {
      fgets(buffer,256,stdin);
      write(socket_fd,buffer,strlen(buffer));
      if (!strncmp(buffer,"end",3))
	{
	  break;
	}
      printf("Sent: %s\n",buffer);
    }
  close(socket_fd);
  return 0;
}

