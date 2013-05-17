/*
** req_pwd.c for pwd in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 17:31:20 2011 axel catusse
** Last update Sat Apr  2 18:05:00 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "server.h"
#include "client.h"

void			req_pwd(t_ftp_client *client)
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
	  i = -2;
	  break ;
	}
      puts_color(buffer, WHITE);
      memset(buffer, 0, BUFF_SIZE);
    }
  exec_request(client, ret);
  if (i == -2)
    if (read(client->sock, buffer, BUFF_SIZE) < 0)
      my_error(errno, "read():", DIE);
  free(buffer);
}

