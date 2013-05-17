/*
** main.c for my_ftp in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 25 00:17:11 2011 axel catusse
** Last update Sun Apr  3 17:58:44 2011 axel catusse
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "color.h"

t_request		req_tab[] = {
  { AUTH, send_login_pass },
  { SUCCESS_AUTH, auth_successful },
  { WRONG_AUTH, auth_wrongful },
  { REQ_NOTFOUND, req_notfound },
  { REQ_SUCCESS, req_success },
  { REQ_LS, req_ls },
  { REQ_CD, req_cd },
  { REQ_QUIT, req_quit },
  { REQ_GET, req_get },
  { REQ_PWD, req_pwd }
};

int			exec_request(t_ftp_client *client,
				     char *buffer)
{
  unsigned int		idx;
  static unsigned int	size = sizeof(req_tab) / sizeof(*req_tab);

  idx = 0;
  while (idx < size)
    {
      if (buffer && !strncmp(req_tab[idx].request, buffer,
			     strlen(req_tab[idx].request) - 1))
	{
	  req_tab[idx].req_func(client);
	  return (idx);
	}
      ++idx;
    }
  return (idx);
}

void			read_req(t_ftp_client *client)
{
  char			*buf;

  buf = gnl(client->sock);
  exec_request(client, buf);
  free(buf);
}

void			ftp_client(char **av)
{
  t_ftp_client		client;
  char			buffer[BUFF_SIZE];
  int			ret;

  init_client(av, &client);
  while (1)
    {
      memset(buffer, 0, BUFF_SIZE);
      if (client.auth == SUCCESS)
	{
	  puts_color("client -> ", YELLOW);
	  if ((ret = read(0, buffer, BUFF_SIZE)) < 1)
	    {
	      close(client.sock);
	      break ;
	    }
	  else if (buffer[0] == '\n')
	    continue ;
	  buffer[ret - 1] = 0;
	  xwrite(client.sock, buffer, strlen(buffer));
	}
      read_req(&client);
    }
}

int			main(int ac, char **av)
{
  if (ac != 3)
    {
      fprintf(stderr, "USAGE: ./client ip port\n");
      return (0);
    }
  ftp_client(av);
  return (0);
}
