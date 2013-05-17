/*
** client.h for client in /home/catuss_a//Desktop/my_ftp/ftp_client
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 20:55:30 2011 axel catusse
** Last update Sun Apr  3 17:50:14 2011 axel catusse
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

#include <termios.h>
#include <sys/ioctl.h>
#include "server.h"
#include "color.h"

# ifndef TIOCGETA
#  define TIOCGETA TCGETS
# endif

# ifndef TIOCSETA
#  define TIOCSETA TCSETS
# endif

typedef struct		s_ftp_client
{
  SOCKET		sock;
  char			auth;
  char			*buffer;
  struct termios	default_term_cfg;
}			t_ftp_client;

typedef struct		s_request
{
  const char		*request;
  void			(*req_func)(t_ftp_client *client);
}			t_request;

void			puts_color(char *s, char *color);
void			xfree(void *ptr);
void			req_quit(t_ftp_client *client);
int			exec_request(t_ftp_client *client,
				     char *buffer);
void			init_client(char **av, t_ftp_client *client);
void			send_login_pass(t_ftp_client *client);
void			auth_successful(t_ftp_client *client);
void			auth_wrongful(t_ftp_client *client);
void			req_notfound(t_ftp_client *client);
void			req_success(t_ftp_client *client);
void			req_ls(t_ftp_client *client);
void			req_cd(t_ftp_client *client);
void			req_pwd(t_ftp_client *client);
void			req_get(t_ftp_client *client);

#endif /* !_CLIENT_H_ */
