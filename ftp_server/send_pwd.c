/*
** send_pwd.c for pwd in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 17:34:17 2011 axel catusse
** Last update Sun Apr  3 06:18:14 2011 axel catusse
*/

#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void			send_pwd(SOCKET csock, char *buffer)
{
  int			pid;
  int			status;

  (void)buffer;
  xwrite(csock, REQ_PWD, strlen(REQ_PWD));
  if ((pid = fork()) == -1)
    my_error(errno, "fork()", LIVE);
  if (pid == 0)
    {
      dup2(csock, 1);
      execlp("pwd", "pwd", NULL);
      my_error(errno, "execlp()", LIVE);
      xwrite(csock, REQ_NOTFOUND, strlen(REQ_NOTFOUND));
      exit(EXIT_FAILURE);
    }
  if (wait(&status) < 0)
    my_error(errno, "wait()", DIE);
  xwrite(csock, REQ_SUCCESS, strlen(REQ_SUCCESS));
}
