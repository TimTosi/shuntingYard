/*
** my_getnbr.c for Bistromathique in /home/tosi_t//BISTRO/src/str
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Jul 22 10:44:20 2013 timothee tosi
** Last update Tue Jul 23 09:44:24 2013 timothee tosi
*/

#include	"my_str.h"

/* nb negative, limit */

int		my_getnbr(char *str)
{
  int		res;
  int		i;
  int		pow;

  i = my_strlen(str) - 1;
  res = 0;
  pow = 1;
  while (i >= 0)
    {
      res = res + ((str[i] - '0') * pow);
      --i;
      pow = pow * 10;
    }
  return (res);
}
