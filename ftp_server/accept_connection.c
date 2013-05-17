/*
** accept_connection.c for accept_connection in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 25 01:21:58 2011 axel catusse
** Last update Sun Apr  3 06:13:58 2011 axel catusse
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

t_server_req		serv_req[] = {
  { REQ_LS, send_ls },
  { REQ_GET, send_get },
  { REQ_CD, send_cd },
  { REQ_QUIT, send_quit },
  { REQ_PWD, send_pwd },
  { REQ_EXITCHILD, exit_child }
};

void                    exec_cmd(char *buffer, SOCKET csock)
{
  unsigned int		idx;
  static unsigned int   size = sizeof(serv_req) / sizeof(*serv_req);

  idx = 0;
  while (idx < size)
    {
      if (!strncmp(serv_req[idx].request, buffer,
		   strlen(serv_req[idx].request) - 1))
        {
          serv_req[idx].send_req(csock, buffer);
          return ;
        }
      ++idx;
    }
  write(csock, REQ_NOTFOUND, strlen(REQ_NOTFOUND));
}

void			talk_to_client(t_ftp_server *server,
				       SOCKET csock)
{
  char			buffer[BUFF_SIZE];
  int			ret;

  while (authentification(server, csock) == FAIL)
    xwrite(csock, WRONG_AUTH, strlen(WRONG_AUTH));
  memset(buffer, 0, sizeof(buffer));
  while ((ret = read(csock, buffer, BUFF_SIZE)))
    {
      if (ret < 1)
	my_error(errno, "read()", DIE);
      printf("client with socket %d: %s\n", csock,
	     buffer);
      exec_cmd(buffer, csock);
      memset(buffer, 0, sizeof(buffer));
    }
  printf("client with socket %d left\n", csock);
  close(csock);
}

void			accept_connection(t_ftp_server *server)
{
  socklen_t		caddrsize;
  struct sockaddr_in	csin;
  SOCKET		csock;
  int			pid;

  caddrsize = sizeof(csin);
  while (1)
    {
      if ((csock = accept(server->sock,
			  (struct sockaddr *)&csin, &caddrsize)) == INVALID_SOCKET)
	{
	  my_error(errno, "accept()", LIVE);
	  continue ;
	}
      if ((pid = fork()) == -1)
	my_error(errno, "fork()", LIVE);
      if (pid == 0)
	talk_to_client(server, csock);
      else
	close(csock);
    }
}
