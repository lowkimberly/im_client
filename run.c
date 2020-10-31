#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#include "im.h"

void run()
{
  //Set up some variables
  extern struct sockaddr_in serv;
  extern int socket_id;

  socklen_t len;
  int socket_fd;
  char* buffer=malloc(256);
  int bytes_read;
  int i;


  //Do things
  while(1)
    {
      printf("About to accept a connection\n");
      len = sizeof(serv);
      //accept a connection and return a fd for it
      socket_fd = accept(socket_id,(struct sockaddr *)&serv,&len);
      
      while (1)
	{
	  //read input into buffer
	  bytes_read = read(socket_fd,buffer,sizeof(buffer));
	  if (!strncmp(buffer,"end",3)) 
	    {	
	      break;
	    }
	  printf("Recieved: %s\n",buffer);	  
	  write(socket_fd,buffer,strlen(buffer)); 

	}
      close(socket_fd);
      printf("Waiting for the next connection\n");
    }  
}
