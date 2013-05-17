/*
** xwrite.c for write in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 20:04:26 2011 axel catusse
** Last update Sat Apr  2 00:09:40 2011 axel catusse
*/

#include <errno.h>
#include <unistd.h>
#include "server.h"

int			xwrite(int fd, const void *buf, int len)
{
  int			ret;

  if ((ret = write(fd, buf, len)) == -1)
    my_error(errno, "write()", LIVE);
  return (ret);
}
