/*
** inf_sub.c for Bistromathique in
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Aug 13 15:34:51 2013 timothee tosi
** Last update Fri Aug 16 23:18:24 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"operation.h"
#include	"my_str.h"

static char	_sub_digit(char first_digit, char second_digit,
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
      if ((i == 0) && (j > 0))
	{
	  i = (my_strlen(base) - 1);
	  add->carry += 1;
	}
      else
	--i;
	  --j;
    }
  return (base[i]);
}

static int	_swap_op(char **f_o, char **sec_o, char *first_op, char *sec_op,
			 char *base)
{
  int		i;

  i = str_base_cmp(first_op, sec_op, base);
  if (i == -1)
    {
      *f_o = sec_op;
      *sec_o = first_op;
      return (1);
    }
  else
    {
      *f_o = first_op;
      *sec_o = sec_op;
      return (0);
    }
}

static void	_handle_sign(char **result, int carry, char minus, char *first_op,
			     char *sec_op)
{
  if (((carry == 1) && (first_op[0] != minus) && (sec_op[0] != minus)) ||
      ((carry == 0) && (first_op[0] == minus) && (sec_op[0] != minus)) ||
      ((carry == 1) && (sec_op[0] == minus)))
    *result[0] = minus;
}

char		*inf_sub(char *first_op, char *sec_op, char *base, char minus)
{
  t_add		add;
  char		*first_o;
  char		*sec_o;
  char		*result;
  int		carry;

  carry = _swap_op(&first_o, &sec_o, first_op, sec_op, base);
  if ((result = op_init(&add, first_o, sec_o, base)) == NULL)
    return (NULL);
  while ((add.i >= 0) || (add.j >= 0))
    {
      if ((add.i >= 0) && (add.j >= 0))
	result[add.k] = _sub_digit(first_o[add.i], sec_o[add.j], base, &add,
				   minus);
      else if ((add.i >= 0) && (add.j < 0))
	result[add.k] = _sub_digit(first_o[add.i], base[0], base, &add, minus);
      else
	result[add.k] = _sub_digit(base[0], sec_o[add.j], base, &add, minus);
      --(add).i;
      --(add).j;
      --(add).k;
    }
  _handle_sign(&result, carry, minus, first_op, sec_op);
  return (result);
}
