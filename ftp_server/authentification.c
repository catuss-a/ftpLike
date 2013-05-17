/*
** authentification.c for auth in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 19:44:33 2011 axel catusse
** Last update Sun Apr  3 06:14:32 2011 axel catusse
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

void			send_auth_request(SOCKET csock,
					  char ***clogin_pass)
{
  char			**tab;
  int			cpt;
  char			buf[BUFF_SIZE];
  int			ret;

  cpt = 0;
  do
    {
      memset(buf, 0, BUFF_SIZE);
      if (cpt)
	{
	  free_tab(tab);
	  xwrite(csock, WRONG_AUTH, strlen(WRONG_AUTH));
	}
      xwrite(csock, AUTH, strlen(AUTH));
      ret = read(csock, buf, BUFF_SIZE);
      if (ret > 0)
	buf[ret - 1] = 0;
      else
	exit(0);
      tab = split_c(buf, ' ');
      ++cpt;
    }
  while (strlen_tab(tab) != 2);
  *clogin_pass = tab;
}

int			authentification(t_ftp_server *server,
					 SOCKET csock)
{
  int			idx;
  char			**clogin_pass;
  char			*enter_log;
  char			*enter_pass;

  clogin_pass = NULL;
  send_auth_request(csock, &clogin_pass);
  idx = -1;
  while (server->login_pass[++idx])
    {
      if ((enter_log = strstr(server->login_pass[idx], clogin_pass[LOGIN_IDX]))
	  && strncmp(enter_log, clogin_pass[LOGIN_IDX],
		     strcspn(enter_log, " ")) == 0)
	if ((enter_pass = strstr(server->login_pass[idx], clogin_pass[PASS_IDX]))
	    && strlen(enter_pass) == strlen(clogin_pass[PASS_IDX])
	    && enter_log != enter_pass)
	  {
	    xwrite(csock, SUCCESS_AUTH, strlen(SUCCESS_AUTH));
	    return (SUCCESS);
	  }
    }
  return (FAIL);
}
