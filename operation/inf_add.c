/*
** inf_add.c for Bistromathique in 
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Aug 13 15:34:51 2013 timothee tosi
** Last update Sun Sep  8 22:35:50 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"operation.h"

static char	_add_digit(char first_digit, char second_digit,
			   char *base, t_add *add, char minus)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (first_digit != minus)
    while (first_digit != base[i])
      ++i;
  if (second_digit != minus)
    while (second_digit != base[j])
      ++j;
  j += add->carry;
  add->carry = 0;
  while (j > 0)
    {
      ++i;
      --j;
      if (base[i] == '\0')
	{
	  i = 0;
	  add->carry += 1;
	}
    }
  return (base[i]);
}

char		*inf_add(char *first_op, char *sec_op, char *base, char minus)
{
  t_add		add;
  char		*result;

  if ((result = op_init(&add, first_op, sec_op, base)) == NULL)
    return (NULL);
  while ((add.i >= 0) || (add.j >= 0))
    {
      if ((add.i >= 0) && (add.j >= 0))
	result[add.k] = _add_digit(first_op[add.i], sec_op[add.j], base, &add,
				   minus);
      else if ((add.i >= 0) && (add.j < 0))
	result[add.k] = _add_digit(first_op[add.i], base[0], base, &add, minus);
      else
	result[add.k] = _add_digit(base[0], sec_op[add.j], base, &add, minus);
      --(add).i;
      --(add).j;
      --(add).k;
    }
  result[add.k] = _add_digit(base[0], base[0], base, &add, minus);
  if (first_op[0] == minus)
    result[0] = minus;
  return (result);
}
