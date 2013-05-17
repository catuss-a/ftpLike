/*
** xmalloc.c for xmalloc in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 18:52:10 2011 axel catusse
** Last update Mon Mar 28 21:16:07 2011 axel catusse
*/

#include <unistd.h>
#include <stdlib.h>
#include "server.h"

void			*xmalloc(int size)
{
  void			*ptr;
  int			errno;

  errno = 0;
  ptr = malloc(size);
  if (!ptr)
    my_error(errno, "malloc()", DIE);
  return (ptr);
}
