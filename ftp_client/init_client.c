/*
** init_client.c for init client in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 21:38:13 2011 axel catusse
** Last update Sun Apr  3 17:55:32 2011 axel catusse
*/

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <netdb.h>
#include "server.h"
#include "client.h"

static void		init_term_cfg(t_ftp_client *client)
{
  if (ioctl(0, TIOCGETA, &client->default_term_cfg) < 0)
    my_error(errno, "ioctl()", DIE);
}

void			init_client(char **av, t_ftp_client *client)
{
  struct hostent        *hp;
  struct sockaddr_in    sin;
  char                  *hostserver;
  PORT			port;

  memset(client, 0, sizeof(*client));
  init_term_cfg(client);
  client->auth = FAIL;
  hostserver = av[1];
  port = atoi(av[2]);
  if ((client->sock = socket(PF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    my_error(errno, "socket()", DIE);
  if ((hp = gethostbyname(hostserver)) == 0)
    my_error(errno, "gethostbyname()", DIE);
  sin.sin_addr = *(struct in_addr *)(hp->h_addr_list[0]);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (connect(client->sock, (struct sockaddr *)&sin, sizeof(sin))
      == INVALID_SOCKET)
    my_error(errno, "connect()", DIE);
}
