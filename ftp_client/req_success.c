/*
** req_success.c for succes in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 23:51:32 2011 axel catusse
** Last update Mon Mar 28 23:53:04 2011 axel catusse
*/

#include "server.h"
#include "client.h"

void			req_success(t_ftp_client *client)
{
  (void)client;
  puts_color("request success\n", GREEN);
}
