/*
** send_ls.c for ls in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 23:21:38 2011 axel catusse
** Last update Sun Apr  3 18:01:46 2011 axel catusse
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void			send_ls(SOCKET csock, char *buffer)
{
  int			pid;
  int			status;

  (void)buffer;
  xwrite(csock, REQ_LS, strlen(REQ_LS));
  if ((pid = fork()) == -1)
    my_error(errno, "fork()", LIVE);
  if (pid == 0)
    {
      dup2(csock, 1);
      execlp("ls", "ls", "-l", NULL);
      my_error(errno, "execlp()", LIVE);
      xwrite(csock, REQ_FAILED, strlen(REQ_FAILED));
      exit(EXIT_FAILURE);
    }
  if (wait(&status) < 0)
    my_error(errno, "wait()", DIE);
  xwrite(csock, REQ_SUCCESS, strlen(REQ_SUCCESS));
}
