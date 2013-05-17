/*
** free_tab.c for freetab in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 20:15:13 2011 axel catusse
** Last update Mon Mar 28 20:24:29 2011 axel catusse
*/

#include <stdlib.h>

void			free_tab(char **tab)
{
  int			idx;

  idx = -1;
  if (tab)
    {
      while (tab[++idx])
	free(tab[++idx]);
      free(tab);
    }
}
