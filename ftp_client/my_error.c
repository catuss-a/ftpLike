/*
** my_error.c for error in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 25 01:19:11 2011 axel catusse
** Last update Mon Mar 28 19:16:56 2011 axel catusse
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

void			my_error(int err, char *func, int wht)
{
  fprintf(stderr, "error: %s: %s\n", func, strerror(err));
  if (wht == DIE)
    exit(EXIT_FAILURE);
}
