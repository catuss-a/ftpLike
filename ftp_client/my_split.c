/*
** my_split.c for sa in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Apr  3 06:06:38 2011 axel catusse
** Last update Sun Apr  3 06:08:46 2011 axel catusse
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int              count_separator(char *str, char separator)
{
  int                   cpt = 0;

  while (*str && *str == separator)
    {
      ++cpt;
      ++str;
    }
  return cpt;
}

static int              count_not_separator(char *str, char separator)
{
  int                   cpt = 0;

  while (*str && *str != separator)
    {
      ++cpt;
      ++str;
    }
  return cpt;
}

static int              count_case(char *str, char separator)
{
  int                   cpt = 0;

  str += count_separator(str, separator);
  while (*str)
    {
      if (*str != separator)
        ++cpt;
      str += count_not_separator(str, separator);
      str += count_separator(str, separator);
    }
  return cpt;
}

char             **split_c(char* str, char separator)
{
  char                  **tab;
  int                   i = 0;

  if (!str || (tab = malloc(sizeof(*tab)
			    * (count_case(str, separator) + 1))) == NULL)
    return NULL;
  str += count_separator(str, separator);
  while (*str)
    {
      tab[i++] = strndup(str, count_not_separator(str, separator));
      str += count_not_separator(str, separator);
      str += count_separator(str, separator);
    }
  tab[i] = 0;
  return tab;
}
