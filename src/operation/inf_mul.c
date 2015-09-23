/*
** inf_mul.c for Bistromathique in /home/tosi_t//TESTBASE
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Aug 13 15:34:51 2013 timothee tosi
** Last update Sun Sep  8 22:39:07 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"operation.h"
#include	"uniform.h"
#include	"my_flags.h"

static char	_add_digit(char first_digit, char second_digit, char *base,
			   t_add *add)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (in_array(first_digit, base) != RETURN_FAILURE)
    while (first_digit != base[i])
      ++i;
  if (in_array(second_digit, base) != RETURN_FAILURE)
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

static void	_init_mul(char first_digit, char second_digit, char *base,
			  int *j, int *buff)
{
  *j = 0;
  *buff = 0;
  if (in_array(first_digit, base) != RETURN_FAILURE)
    while (first_digit != base[*buff])
      ++(*buff);
  if (in_array(second_digit, base) != RETURN_FAILURE)
    while (second_digit != base[*j])
      ++(*j);
}

static char	_mul_digit(char first_digit, char second_digit, char *base,
			   t_add *add)
{
  int		i;
  int		j;
  int		buff;
  int		time;

  i = 0;
  _init_mul(first_digit, second_digit, base, &j, &buff);
  while (j > 0)
    {
      time = buff;
      while (time > 0)
	{
	  ++i;
	  --time;
	  if (base[i] == '\0')
	    {
	      i = 0;
	      add->carry2 += 1;
	    }
	}
      --j;
    }
  return (base[i]);
}

static char	*_set_sym(char *res, char *f_op, char *s_op, char *base)
{
  if (((in_array(f_op[0], base) != RETURN_FAILURE) &&
       (in_array(s_op[0], base) != RETURN_FAILURE)) ||
      ((in_array(f_op[0], base) == RETURN_FAILURE) &&
       (in_array(s_op[0], base) == RETURN_FAILURE)))
    return (res);
  else if (in_array(f_op[0], base) == RETURN_FAILURE)
    {
      res[0] = f_op[0];
      return (res);
    }
  res[0] = s_op[0];
  return (res);
}

char		*inf_mul(char *f_op, char *s_op, char *base, char minus)
{
  t_add		add;
  char		*res;
  int		x;

  x = 0;
  if ((res = op_init(&add, f_op, s_op, base)) == NULL)
    return (NULL);
  while (add.j >= 0)
    {
      add.k = (my_strlen(res) - (1 + x));
      add.i = (my_strlen(f_op) - 1);
      while (add.i >= 0)
	{
	  res[add.k] = _add_digit(_mul_digit(f_op[add.i], s_op[add.j], base,
					     &add), res[add.k], base, &add);
	  --(add.i);
	  --(add.k);
	  add.carry += add.carry2;
	  add.carry2 = 0;
	}
      res[add.k] = _add_digit(res[add.k], base[0], base, &add);
      ++x;
      --(add.j);
    }
  return (uniform_result(_set_sym(res, f_op, s_op, base), base, minus));
}
