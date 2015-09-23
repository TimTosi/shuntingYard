/*
** my_strdup.c for Bistromathique in /home/tosi_t//BISTRO/src/memory
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Jul 18 17:57:03 2013 timothee tosi
** Last update Tue Jul 23 14:48:11 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"my_str.h"

char			*my_strdup(char *original)
{
  char			*duplicate;
  int			i;

  i = 0;
  if ((duplicate = malloc(sizeof(*duplicate) * (my_strlen(original) + 1)))
      == NULL)
    return (NULL);
  while (original[i] != '\0')
    {
      duplicate[i] = original[i];
      ++i;
    }
  duplicate[i] = '\0';
  return (duplicate);
}
