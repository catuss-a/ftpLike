/*
** send_get.c for get in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 19:42:46 2011 axel catusse
** Last update Sun Apr  3 17:38:51 2011 axel catusse
*/

#include <sys/wait.h>
#include <dirent.h>
#include <linux/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void			send_file2(int csock, char **tab)
{
  dup2(csock, 1);
  execlp("cat", "cat", tab[1], NULL);
  my_error(errno, "execlp()", LIVE);
  xwrite(csock, REQ_FAILED, strlen(REQ_FAILED));
  exit(EXIT_FAILURE);
}

int			send_file(int fd, SOCKET csock,
				  char **tab)
{
  unsigned int		size;
  char			buf_err[BUFF_SIZE];
  int			pid;
  int			status;

  if ((int)(size = lseek(fd, 0, SEEK_END)) == -1)
    {
      memset(buf_err, 0, BUFF_SIZE);
      sprintf(buf_err, "error: lseek: %s\n%s", strerror(errno), REQ_NOTFOUND);
      xwrite(csock, buf_err, strlen(buf_err)), close(fd);
      return (0);
    }
  sprintf(buf_err, "%s%d\n", FILE_SIZE, size);
  xwrite(csock, buf_err, strlen(buf_err));
  if ((pid = fork()) == -1)
    my_error(errno, "fork()", LIVE);
  if (pid == 0)
    {
      send_file2(csock, tab);
    }
  if (wait(&status) < 0)
    my_error(errno, "wait()", DIE);
  return (1);
}

void			finish_get(char **tab, int csock)
{
  int			fd;
  char			buf_err[BUFF_SIZE];

  if ((fd = open(tab[1], O_RDONLY, 0)) == -1)
    {
      memset(buf_err, 0, BUFF_SIZE);
      sprintf(buf_err, "error: get(): %s\n%s", strerror(errno), REQ_NOTFOUND);
      xwrite(csock, buf_err, strlen(buf_err));
      return ;
    }
  send_file(fd, csock, tab);
}

void			send_get(SOCKET csock, char *buffer)
{
  char			**tab;
  char			buf_err[BUFF_SIZE];

  xwrite(csock, REQ_GET, strlen(REQ_GET));
  tab = split_c(buffer, ' ');
  if (strlen_tab(tab) != 2)
    {
      xwrite(csock, REQ_NOTFOUND, strlen(REQ_NOTFOUND));
      return ;
    }
  if ((void*)opendir(tab[1]) != NULL)
    {
      memset(buf_err, 0, BUFF_SIZE);
      sprintf(buf_err, "error: get(): %s is a directory\n%s",
	      tab[1], REQ_NOTFOUND);
      xwrite(csock, buf_err, strlen(buf_err));
      return ;
    }
  finish_get(tab, csock);
}
