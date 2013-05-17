/*
** req_notfound.c for req in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 23:38:39 2011 axel catusse
** Last update Mon Mar 28 23:42:34 2011 axel catusse
*/

#include "server.h"
#include "client.h"

void			req_notfound(t_ftp_client *client)
{
  (void)client;
  puts_color("error: invalid request\n", RED);
}
