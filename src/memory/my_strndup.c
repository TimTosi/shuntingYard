/*
** my_strndup.c for Bistromathque in /home/tosi_t//BISTRO/src/memory
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 14:46:53 2013 timothee tosi
** Last update Mon Jul 29 01:12:33 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"my_str.h"

char			*my_strndup(char *original, int n)
{
  char			*duplicate;
  int			i;

  i = 0;
  if ((duplicate = malloc(sizeof(*duplicate) * (n + 1))) == NULL)
    return (NULL);
  while ((original[i] != '\0') && i < n)
    {
      duplicate[i] = original[i];
      ++i;
    }
  duplicate[i] = '\0';
  return (duplicate);
}
