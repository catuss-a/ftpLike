/*
** req_cd.c for cd in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 01:17:26 2011 axel catusse
** Last update Sun Apr  3 06:10:08 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "server.h"
#include "client.h"

void			req_cd(t_ftp_client *client)
{
  char			*buffer;
  char			*ret;
  int			i;

  buffer = xmalloc(sizeof(*buffer) * BUFF_SIZE);
  memset(buffer, 0, BUFF_SIZE);
  while (42)
    {
      if (read(client->sock, buffer, BUFF_SIZE) < 0)
	my_error(errno, "read():", DIE);
      if ((ret = strstr(buffer, REQ_SUCCESS)))
	break ;
      if ((ret = strstr(buffer, REQ_NOTFOUND)))
	{
	  i = -1, write(1, RED, strlen(RED));
	  while (buffer[++i] && (buffer + i) != ret)
	    write(1, &buffer[i], 1);
	  write(1, WHITE, strlen(WHITE));
	  break ;
	}
      puts_color(buffer, WHITE);
      memset(buffer, 0, BUFF_SIZE);
    }
  exec_request(client, ret);
  free(buffer);
}
