/*
** send_login_pass.c for send in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 21:50:06 2011 axel catusse
** Last update Sun Apr  3 06:12:32 2011 axel catusse
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server.h"
#include "client.h"

static void		set_term_cfg(void)
{
  struct termios	term;

  if (ioctl(0, TIOCGETA, &term) < 0)
    my_error(errno, "ioctl()", DIE);
  term.c_lflag &= ~(ICANON | ECHO);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (ioctl(0, TIOCSETA, &term) < 0)
    my_error(errno, "ioctl()", DIE);
}

static void		set_term_default_cfg(t_ftp_client *client)
{
  if (ioctl(0, TIOCSETA, &client->default_term_cfg) < 0)
    my_error(errno, "ioctl()", DIE);
}

void			send_login_pass(t_ftp_client *client)
{
  char			buffer[BUFF_SIZE + 1];
  char			request[BUFF_SIZE + 1];
  int			ret;
  int			i;

  memset(buffer, 0, BUFF_SIZE + 1);
  memset(request, 0, BUFF_SIZE + 1);
  write(1, "login: ", strlen("login: "));
  if ((ret = read(0, buffer, BUFF_SIZE)) == -1)
    my_error(errno, "read()", DIE);
  buffer[ret - 1] = ' ';
  write(1, "password: ", strlen("password: "));
  set_term_cfg();
  while ((i = read(0, buffer + ret, BUFF_SIZE - ret)))
    {
      if (i < 0)
	my_error(errno, "read()", DIE);
      ret += i;
      if (buffer[ret - 1] == '\n')
	break ;
      write(1, "*", 1);
    }
  set_term_default_cfg(client), printf("\n");
  strncpy(request, buffer, strlen(buffer));
  xwrite(client->sock, buffer, strlen(buffer));
}
