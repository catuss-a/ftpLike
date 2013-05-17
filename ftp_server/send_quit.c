/*
** send_quit.c for quit in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 18:09:04 2011 axel catusse
** Last update Sun Apr  3 18:01:01 2011 axel catusse
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void			exit_child(SOCKET csock, char *buffer)
{
  (void)buffer;
  printf("client with socket %d: socket closed\n", csock);
  close(csock);
  exit(0);
}

void			send_quit(SOCKET csock, char *buffer)
{
  (void)buffer;
  xwrite(csock, REQ_QUIT, strlen(REQ_QUIT));
  xwrite(csock, BYE, strlen(BYE));
  xwrite(csock, REQ_SUCCESS, strlen(REQ_SUCCESS));
}
