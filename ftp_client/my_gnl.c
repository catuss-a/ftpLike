/*
** my_gnl.c for gnl in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Apr  3 17:30:03 2011 axel catusse
** Last update Sun Apr  3 17:30:04 2011 axel catusse
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include "server.h"

static char			buff[BUFF_SIZE];
static int			len_buf = 0;
static int			begin;

static int			read_from_file(int fd)
{
  len_buf = read(fd, buff, BUFF_SIZE);
  begin = 0;
  return (len_buf);
}

static char			*add_to_line(char *line, int current)
{
  char				*new_elem;
  int				old_len;

  if (!(new_elem = malloc((old_len = (line?strlen(line):0)) + current + 1)))
    {
      printf("add_to_line : error malloc\n");
      return (0);
    }
  strcpy(new_elem, line?line:"");
  memcpy(new_elem + old_len, buff + begin, current);
  new_elem[old_len + current] = 0;
  if (line)
    free(line);
  begin += current + 1;
  return (new_elem);
}

char				*gnl(const int fd)
{
  int				 current;
  char				 *line;

  line = 0, current = 0;
  while (1)
    {
      if (begin >= len_buf)
	{
	  if (!read_from_file(fd))
	    return (line);
	  current = 0;
	}
      if (buff[begin + current] == '\n')
	{
	  line = add_to_line(line, current);
	  return (line);
	}
      if (begin + current == len_buf - 1)
	line = add_to_line(line, current + 1);
      ++current;
    }
}
