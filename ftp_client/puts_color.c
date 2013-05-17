/*
** puts_color.c for puts in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Apr  3 17:50:28 2011 axel catusse
** Last update Sun Apr  3 17:51:14 2011 axel catusse
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "color.h"

void			puts_color(char *s, char *color)
{
  write(1, color, strlen(color));
  write(1, s, strlen(s));
  write(1, WHITE, strlen(WHITE));
}
