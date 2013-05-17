/*
** send_cd.c for cd in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 00:53:20 2011 axel catusse
** Last update Sun Apr  3 06:15:12 2011 axel catusse
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void			send_cd(SOCKET csock, char *buffer)
{
  char			**tab;
  char			buf_err[BUFF_SIZE];

  xwrite(csock, REQ_CD, strlen(REQ_CD));
  tab = split_c(buffer, ' ');
  if (strlen_tab(tab) != 2)
    {
      xwrite(csock, REQ_NOTFOUND, strlen(REQ_NOTFOUND));
      return ;
    }
  if (chdir(tab[1]) == -1)
    {
      memset(buf_err, 0, BUFF_SIZE);
      sprintf(buf_err, "error: cd(): %s\n%s", strerror(errno), REQ_NOTFOUND);
      xwrite(csock, buf_err, strlen(buf_err));
      return ;
    }
  xwrite(csock, REQ_SUCCESS, strlen(REQ_SUCCESS));
}
