/*
** uniform_to_zero.c for Bistromathique in /home/tosi_t//BISTRO/src/uniform
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Sep  4 13:36:30 2013 timothee tosi
** Last update Sun Sep  8 20:26:16 2013 timothee tosi
*/

#include		<stdlib.h>
#include "my_str.h"
char			*uniform_to_zero(char *base, char *origin)
{
  char			*res;

  if ((res = malloc(sizeof(*res) * 2)) == NULL)
    return (NULL);
  res[0] = base[0];
  res[1] = '\0';
  return (res);
}
