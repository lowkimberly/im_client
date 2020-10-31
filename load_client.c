#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "im.h"

struct sockaddr_in serv;
int socket_id;

void load_client()
{
  //Create a socket on 2006
  socket_id=socket(AF_INET,SOCK_STREAM,0);

  //Set up the stuff 
  serv.sin_family=AF_INET;
  serv.sin_addr.s_addr=INADDR_ANY;
  serv.sin_port=htons(2006);

  //Bind
  int i = bind(socket_id,(struct sockaddr *)&serv, sizeof(serv));

  //listen
  i = listen(socket_id,1);
}
