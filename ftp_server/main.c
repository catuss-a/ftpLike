/*
** main.c for my_ftp in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 25 00:17:11 2011 axel catusse
** Last update Mon Mar 28 19:39:49 2011 axel catusse
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "server.h"

void			ftp_server(char *port)
{
  t_ftp_server		server;

  init_server(&server, atoi(port));
  print_welcome();
  accept_connection(&server);
}

int			main(int ac, char **av)
{
  if (ac != 2)
    {
      fprintf(stderr, "USAGE: ./serveur port\n");
      return (0);
    }
  ftp_server(av[1]);
  return (0);
}
