/*
** req_get.c for get in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Apr  2 19:38:36 2011 axel catusse
** Last update Sun Apr  3 17:52:01 2011 axel catusse
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "server.h"
#include "client.h"

void			get_file_size(t_ftp_client *client,
				      int *size, int *flag, int *fd)
{
  char			*buffer;

  buffer = gnl(client->sock);
  *size = atoi(buffer);
  printf("size of file: %d octets\n", *size);
  free(buffer);
  *flag = 1;
  if ((*fd = open("FILEGET", O_CREAT | O_TRUNC | O_RDWR, 0644)) < 0)
    my_error(errno, "open()", LIVE);
}

void			write_on_file(t_ftp_client *client,
				      int fd, int size)
{
  char			buf[BUFF_SIZE];
  int			i;
  int			j;

  i = 0;
  memset(buf, 0, BUFF_SIZE);
  while (i < size && (j = (int)read(client->sock, buf, BUFF_SIZE)) != -1)
    {
      i += j;
      if (fd > 0)
	write(fd, buf, j);
      memset(buf, 0, BUFF_SIZE);
    }
  puts_color("request success\n", GREEN);
}

void			aff_data(char *buffer)
{
  puts_color(buffer, RED);
  puts_color("\n", RED);
}

void			req_get(t_ftp_client *client)
{
  char			*buffer;
  int			size;
  int			fd;
  int			value;
  int			file_flag;

  file_flag = 0;
  while (!file_flag)
    {
      if ((buffer = gnl(client->sock)))
	{
	  value = exec_request(client, buffer);
	  if (value == 3 || value == 4)
	    break ;
	  else if (!strncmp(buffer, FILE_SIZE, strlen(FILE_SIZE) - 1))
	    get_file_size(client, &size, &file_flag, &fd);
	  else
	    aff_data(buffer);
	  free(buffer);
	}
    }
  if (file_flag)
    write_on_file(client, fd, size);
}
