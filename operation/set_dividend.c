/*
** set_dividend.c for Bistromathique in /home/tosi_t//INF_DIV/src/misc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Sep  2 13:06:35 2013 timothee tosi
** Last update Wed Sep  4 19:03:28 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"operation.h"
#include		"uniform.h"

static char		*_int_to_base_digit(char *base, int x)
{
  char			*digit;

  if ((digit = malloc(sizeof(*digit) * 2)) == NULL)
    return (NULL);
  digit[0] = base[x];
  digit[1] = '\0';
  return (digit);
}

char			*set_dividend(char *divisor, char *base, char minus,
				      int x)
{
  char			*digit;
  char			*new_divisor;

  if ((digit = _int_to_base_digit(base, x)) == NULL)
    return (NULL);
  if ((new_divisor = inf_mul(divisor, digit, base, minus)) == NULL)
    return (NULL);
  free(digit);
  if ((new_divisor = uniform_result(new_divisor, base, minus)) == NULL)
    return (NULL);
  return (new_divisor);
}
