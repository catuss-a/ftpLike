/*
** strlen_tab.c for strentab in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar 28 20:11:12 2011 axel catusse
** Last update Mon Mar 28 20:12:03 2011 axel catusse
*/

int			strlen_tab(char **tab)
{
  int			idx;

  idx = -1;
  while (tab[++idx]);
  return (idx);
}
