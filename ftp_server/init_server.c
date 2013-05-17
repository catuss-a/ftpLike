/*
** init_server.c for init_server in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 25 01:20:54 2011 axel catusse
** Last update Sun Apr  3 06:15:01 2011 axel catusse
*/

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "server.h"

static void		fill_login_pass(t_ftp_server *server, int fd, int *len)
{
  char                  *line;

  if ((line = gnl(fd)) == NULL)
    {
      if (*len)
	{
	  server->login_pass = xmalloc(sizeof(*server->login_pass) * (*len + 1));
	  server->login_pass[*len] = NULL;
	}
      return ;
    }
  *len += 1;
  if (*len > 5000)
    {
      fprintf(stderr, "error: file %s is too large\n", LOGIN_PASS);
      exit(EXIT_FAILURE);
    }
  fill_login_pass(server, fd, len);
  server->login_pass[*len - 1] = line;
  *len -= 1;
}

static void		init_login_database(t_ftp_server *server)
{
  int			fd;
  int			len;

  errno = 0;
  if ((fd = open(LOGIN_PASS, O_RDWR | O_APPEND)) == -1)
    my_error(errno, "open()", DIE);
  len = 0;
  fill_login_pass(server, fd, &len);
  print_login_db(server->login_pass);
}

void			init_server(t_ftp_server *server, PORT port)
{
  int			on;

  memset(server, 0, sizeof(*server));
  if ((server->sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    my_error(errno, "socket()", DIE);
  server->sin.sin_addr.s_addr = htonl(INADDR_ANY);
  server->sin.sin_family = AF_INET;
  server->sin.sin_port = htons(port);
  if ((setsockopt(server->sock, SOL_SOCKET,
		  SO_REUSEADDR, (char *)&on, sizeof(SOCKET))) == -1)
    my_error(errno, "setsockopt()", DIE);
  if (bind(server->sock, (struct sockaddr*)&server->sin,
	   sizeof(server->sin)) == -1)
    my_error(errno, "bind()", DIE);
  if (listen(server->sock, 5) == -1)
    my_error(errno, "listen()", DIE);
  init_login_database(server);
}
