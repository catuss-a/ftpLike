/*
** auth.successful.c for auth succes in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 21:53:27 2011 axel catusse
** Last update Mon Mar 28 22:59:15 2011 axel catusse
*/

#include <stdio.h>
#include "server.h"
#include "client.h"

void			auth_successful(t_ftp_client *client)
{
  client->auth = SUCCESS;
  puts_color("authentification: success.\n", GREEN);
  print_welcome();
}
