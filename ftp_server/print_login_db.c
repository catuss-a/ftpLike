/*
** print_login_db.c for print db in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 19:30:39 2011 axel catusse
** Last update Mon Mar 28 19:37:39 2011 axel catusse
*/

#include <stdio.h>

void			print_login_db(char **login_pass)
{
  int			i;

  i = -1;
  printf("+-------------------------+\n");
  printf("+   LOGIN PASS DATABASE\n");
  printf("+-------------------------+\n");
  while (login_pass && login_pass[++i])
    printf("+ %02d %s\n", i, login_pass[i]);
  printf("+ NULL\n");
}
