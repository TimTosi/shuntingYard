/*
** inf_div.c for Bistromathique in /home/tosi_t//TESTBASE
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Aug 13 15:34:51 2013 timothee tosi
** Last update Sun Sep  8 19:49:02 2013 timothee tosi
*/

#include	<stdlib.h>
#include	"operation.h"
#include	"uniform.h"
#include	"memory.h"
#include	"my_str.h"
#include	"my_flags.h"

static char	*_set_dividend(char *str, char digit, int n, char *base)
{
  char		*dividend;

  if ((my_strlen(str) == 1) && (str[0] == base[0]))
    {
      str[0] = digit;
      return (str);
    }
  n += my_strlen(str);
  if ((dividend = malloc(sizeof(*dividend) * (n + 1))) == NULL)
    return (NULL);
  dividend[n] = '\0';
  dividend = my_strcpy(str, dividend);
  dividend[n - 1] = digit;
  free(str);
  return (dividend);
}

static char	*_set_res(char *dividend, char *base)
{
  char		*res;

  if ((res = malloc(sizeof(*res) * (my_strlen(dividend) + 1))) == NULL)
    return (NULL);
  res[my_strlen(dividend)] = '\0';
  my_memset(res, base[0], my_strlen(dividend));
  return (res);
}

static char	*_calc_div(char *dividend, char *divisor, char *base, char *res,
			   char minus)
{
  char		*real_divisor;
  int		x;

  x = 1;
  real_divisor = divisor;
  if ((str_base_cmp(dividend, divisor, base) == RETURN_FAILURE) ||
      dividend[0] == base[0])
    {
      res[0] = base[0];
      return (uniform_result(dividend, base, minus));
    }
  while ((str_base_cmp(dividend, real_divisor, base) != RETURN_FAILURE) &&
	 (str_base_cmp(dividend, real_divisor, base) != 0))
    {
      ++x;
      if ((real_divisor = set_dividend(divisor, base, minus, x)) == NULL)
	return (NULL);
    }
  if (str_base_cmp(dividend, real_divisor, base) != 0)
    --x;
  *res = base[x];
  if (((real_divisor = set_dividend(divisor, base, minus, x)) == NULL) ||
      ((real_divisor = inf_sub(dividend, real_divisor, base, minus)) == NULL))
    return (NULL);
  return (uniform_result(real_divisor, base, minus));
}

char		*inf_div(char *f_op, char *s_op, char *base, char minus)
{
  char		*res;
  char		*dividend;
  int		x;
  int		y;

  if (str_base_cmp(f_op, s_op, base) == RETURN_FAILURE)
    return (uniform_to_zero(base, NULL));
  x = my_strlen(s_op);
  y = 0;
  if (((dividend = my_strndup(f_op, x)) == NULL) ||
      ((res = _set_res(f_op, base)) == NULL))
    return (NULL);
  dividend = _calc_div(dividend, s_op, base, &res[y], minus);
  ++y;
  while (f_op[x] != '\0')
    {
      if (((dividend = _set_dividend(dividend, f_op[x], 1, base)) == NULL) ||
	  ((dividend = _calc_div(dividend, s_op, base, &res[y], minus)) == NULL))
	return (NULL);
      ++x;
      ++y;
    }
  res[y] = '\0';
  return (uniform_result(res, base, minus));
}
