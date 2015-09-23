/*
** set_div_rest.c for Bistromathique in /home/tosi_t//INF_DIV/src/misc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Aug 20 02:53:40 2013 timothee tosi
** Last update Sun Sep  8 21:41:00 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"uniform.h"

static char	*_set_final_rest(char *rest, char *final_rest,
				 char minus, int i, char sym)
{
  int		j;

  j = 0;
  if (sym == minus)
    {
      final_rest[0] = minus;
      ++j;
    }
  while (rest[i] != '\0')
    {
      final_rest[j] = rest[i];
      ++i;
      ++j;
    }
  final_rest[j] = '\0';
  free(rest);
  return (final_rest);
}

char		*uniform_result(char *rest, char *base, char minus)
{
  char		*final_rest;
  char		sym;
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  sym = rest[0];
  if (rest[0] == minus)
    ++k;
  while ((rest[i] == base[0]) || (rest[i] == minus))
    ++i;
  if (rest[i] == '\0')
    return (uniform_to_zero(base, rest));
  j = i;
  while (rest[i] != '\0')
    {
      ++i;
      ++k;
    }
  if ((final_rest = malloc(sizeof(*final_rest) * (k + 1))) == NULL)
    return (NULL);
  return (_set_final_rest(rest, final_rest, minus, j, sym));
}
