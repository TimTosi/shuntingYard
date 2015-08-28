/*
** uniform_sym.c for Bistromathqiue in /home/tosi_t//BISTRO/src/uniform
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Sep  4 17:27:49 2013 timothee tosi
** Last update Wed Sep  4 18:02:51 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*_set_new_res(char *origin, const int size, char minus)
{
  int		i;
  int		j;
  char		*new_res;

  if ((new_res = malloc(sizeof(*new_res) * (size + 1))) == NULL)
    return (NULL);
  new_res[0] = minus;
  new_res[size] = '\0';
  i = 1;
  j = 0;
  while (origin[j])
    {
      new_res[i] = origin[j];
      ++j;
      ++i;
    }
  free(origin);
  return (new_res);
}

char		*uniform_sym(char *op1, char *op2, char *res, char minus)
{
  int		res_size;

  if (((op1[0] == minus) && (op2[0] != minus)) ||
      ((op1[0] != minus) && (op2[0] == minus)))
    {
      res_size = (my_strlen(res)) + 1;
      if ((res = _set_new_res(res, res_size, minus)) == NULL)
	return (NULL);
    }
  return (res);
}
